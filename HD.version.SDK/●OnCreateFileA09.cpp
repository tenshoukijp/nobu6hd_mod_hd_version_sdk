#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA09 = NULL;

static void OnTenshouExeCreateFileA09Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA09;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA09);
	デバッグ出力 << "CreateFileA09" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00990F85   6A 00            PUSH 0
00990F87   6A 20            PUSH 20
00990F89   6A 05            PUSH 5
00990F8B   6A 00            PUSH 0
00990F8D   6A 00            PUSH 0
00990F8F   68 000000C0      PUSH C0000000
└ここを JMP TSMod.OnTSExeCreateFileA09 と書き換えてやる実際の処理
00990F94   FF75 08          PUSH DWORD PTR SS:[EBP+8]
00990F97   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00990F9D   5E               POP ESI
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA09 = 0x990F8F - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA09へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA09 = 0x990F94 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA09() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA09, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0xC0000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA09Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA09
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA09() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA09,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA09,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA09	    // ここへと戻る
	);
}


