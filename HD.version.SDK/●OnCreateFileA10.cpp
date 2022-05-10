#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA10 = NULL;

static void OnTenshouExeCreateFileA10Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA10;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA10);
	デバッグ出力 << "CreateFileA10" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00991149   6A 00            PUSH 0
0099114B   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA10 と書き換えてやる実際の処理
00991150   6A 03            PUSH 3
00991152   6A 00            PUSH 0
00991154   6A 00            PUSH 0
00991156   50               PUSH EAX
00991157   FF75 08          PUSH DWORD PTR SS:[EBP+8]
0099115A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00991160   5D               POP EBP

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA10 = 0x99114B - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA10へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA10 = 0x991150 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA10() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA10, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA10Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA10
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA10() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA10,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA10,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA10	    // ここへと戻る
		);
}


