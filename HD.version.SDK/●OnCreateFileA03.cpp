#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA03 = NULL;

static void OnTenshouExeCreateFileA03Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA03;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA03);
	デバッグ出力 << "CreateFileA03" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI

この時のCreateFileAの１番目付近のニーモニック

00872066   6A 00            PUSH 0
00872068   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA03 と書き換えてやる実際の処理
0087206D   6A 02            PUSH 2
0087206F   6A 00            PUSH 0
00872071   6A 01            PUSH 1
00872073   68 00000040      PUSH 40000000
00872078   FF75 0C          PUSH DWORD PTR SS:[EBP+C]
0087207B   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872081   8945 F0          MOV DWORD PTR SS:[EBP-10],EAX
*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA03 = 0x872068 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA03へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA03 = 0x87206D - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA03() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov eax, DWORD PTR SS : [EBP + 0xC] // eaxの値が、ファイル名へのポインタ
		mov pFileNameOfCreateFileA03, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA03Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA03
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA03() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA03,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA03,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA03	    // ここへと戻る
		);
}


