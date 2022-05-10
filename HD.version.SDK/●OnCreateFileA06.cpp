#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA06 = NULL;

static void OnTenshouExeCreateFileA06Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA06;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA06);
	デバッグ出力 << "CreateFileA06" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
0089387A   6A 00            PUSH 0
0089387C   6A 40            PUSH 40
0089387E   6A 03            PUSH 3
00893880   6A 00            PUSH 0
00893882   6A 03            PUSH 3
00893884   68 00000080      PUSH 80000000
└ここを JMP TSMod.OnTSExeCreateFileA06 と書き換えてやる実際の処理
00893889   50               PUSH EAX
0089388A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00893890   8BD8             MOV EBX,EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA06 = 0x893884 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA06へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA06 = 0x893889 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA06() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA06, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA06Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA06
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA06() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA06,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA06,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA06	    // ここへと戻る
	);
}


