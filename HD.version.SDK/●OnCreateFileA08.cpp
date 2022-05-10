#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA08 = NULL;

static void OnTenshouExeCreateFileA08Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA08;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA08);
	デバッグ出力 << "CreateFileA08" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00990F43   56               PUSH ESI
00990F44   6A 00            PUSH 0
00990F46   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA08 と書き換えてやる実際の処理
00990F4B   6A 01            PUSH 1
00990F4D   6A 00            PUSH 0
00990F4F   6A 00            PUSH 0
00990F51   68 000000C0      PUSH C0000000
00990F56   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00990F59   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA08 = 0x990F46 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA08へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA08 = 0x990F4B - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA08() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA08, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA08Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA08
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA08() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA08,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA08,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA08	    // ここへと戻る
	);
}


