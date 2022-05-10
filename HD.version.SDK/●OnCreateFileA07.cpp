#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA07 = NULL;

static void OnTenshouExeCreateFileA07Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA07;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA07);
	デバッグ出力 << "CreateFileA07" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
008EFDA8   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA07 と書き換えてやる実際の処理
008EFDAD   6A 03            PUSH 3
008EFDAF   6A 00            PUSH 0
008EFDB1   6A 00            PUSH 0
008EFDB3   68 00000080      PUSH 80000000
008EFDB8   50               PUSH EAX
008EFDB9   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
008EFDBF   6A 00            PUSH 0
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA07 = 0x8EFDA8 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA07へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA07 = 0x8EFDAD - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA07() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA07, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA07Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA07
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA07() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA07,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA07,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA07	    // ここへと戻る
	);
}


