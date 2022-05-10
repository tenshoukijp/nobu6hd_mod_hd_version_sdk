#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA02 = NULL;

static void OnTenshouExeCreateFileA02Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA02;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA02);
	デバッグ出力 << "CreateFileA02" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00871826   56               PUSH ESI
00871827   57               PUSH EDI
00871828   6A 00            PUSH 0
0087182A   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA02 と書き換えてやる実際の処理
0087182F   6A 03            PUSH 3
00871831   6A 00            PUSH 0
00871833   6A 01            PUSH 1
00871835   68 00000080      PUSH 80000000
0087183A   50               PUSH EAX
0087183B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00871841   8BF8             MOV EDI,EAX

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA02 = 0x87182A - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA02へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA02 = 0x87182F - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA02() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA02, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA02Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA02
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA02() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA02,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA02,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA02	    // ここへと戻る
		);
}


