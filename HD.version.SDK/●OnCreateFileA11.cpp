#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA11 = NULL;

static void OnTenshouExeCreateFileA11Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA11;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA11);
	デバッグ出力 << "CreateFileA11" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00A3DF95   6A 00            PUSH 0
00A3DF97   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA11 と書き換えてやる実際の処理
00A3DF9C   6A 03            PUSH 3
00A3DF9E   6A 00            PUSH 0
00A3DFA0   6A 00            PUSH 0
00A3DFA2   68 00000040      PUSH 40000000
00A3DFA7   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00A3DFAA   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A3DFB0   8BC8             MOV ECX,EAX

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA11 = 0xA3DF97 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA11へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA11 = 0xA3DF9C - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA11() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA11, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA11Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA11
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA11() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA11,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA11,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA11	    // ここへと戻る
		);
}


