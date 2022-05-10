#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA05 = NULL;

static void OnTenshouExeCreateFileA05Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA05;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA05);
	デバッグ出力 << "CreateFileA05" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック

00872D06   56               PUSH ESI
00872D07   6A 00            PUSH 0
00872D09   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA05 と書き換えてやる実際の処理
00872D0E   6A 02            PUSH 2
00872D10   6A 00            PUSH 0
00872D12   6A 01            PUSH 1
00872D14   68 00000040      PUSH 40000000
00872D19   53               PUSH EBX
00872D1A   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872D20   8BF0             MOV ESI,EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA05 = 0x872D09 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA05へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA05 = 0x872D0E - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA05() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, ebx // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA05, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA05Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA05
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA05() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA05,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA05,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA05	    // ここへと戻る
	);
}


