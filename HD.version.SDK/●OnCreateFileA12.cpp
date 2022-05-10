#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA12 = NULL;

static void OnTenshouExeCreateFileA12Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA12;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA12);
	デバッグ出力 << "CreateFileA12" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック

00A5721B   6A 00            PUSH 0
00A5721D   6A 00            PUSH 0
00A5721F   6A 03            PUSH 3
00A57221   6A 00            PUSH 0
00A57223   6A 01            PUSH 1
00A57225   68 00000080      PUSH 80000000
└ここを JMP TSMod.OnTSExeCreateFileA12 と書き換えてやる実際の処理
00A5722A   53               PUSH EBX
00A5722B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00A57231   8BD8             MOV EBX,EAX



*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA12 = 0xA57225 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA12へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA12 = 0xA5722A - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA12() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, ebx // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA12, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80000000

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA12Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA12
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA12() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA12,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA12,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA12	    // ここへと戻る
		);
}


