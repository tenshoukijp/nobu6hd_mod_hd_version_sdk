#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA01 = NULL;


static void OnTenshouExeCreateFileA01Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA01;
	Native::On_ファイル要求時( string(szFileName), pFileNameOfCreateFileA01);
	デバッグ出力 << "CreateFileA01" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック
00A3DCD0   56               PUSH ESI
00A3DCD1   6A 00            PUSH 0
00A3DCD3   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA01 と書き換えてやる実際の処理
00A3DCD8   50               PUSH EAX
00A3DCD9   6A 00            PUSH 0
00A3DCDB   52               PUSH EDX
00A3DCDC   51               PUSH ECX
00A3DCDD   FF75 08          PUSH DWORD PTR SS:[EBP+8] ← このEBP+8の評価した中身が、ファイル名へのポインタ
00A3DCE0   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A3DCE6   8B75 10          MOV ESI,DWORD PTR SS:[EBP+10]

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA01 = 0xA3DCD3 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA01へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA01 = 0xA3DCD8 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																					  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

// TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA01() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0x8] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA01, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

		// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA01Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA01
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA01,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA01,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA01	    // ここへと戻る
	);
}


