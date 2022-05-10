#include "GameDataStruct.h"

#include "OnFileRequest.h"

// このCreateFileAの１番目では、主に、「メッセージ系ファイルの読み込み」「シナリオファイルの読み込み」が行われる。

static int pFileNameOfCreateFileA04 = NULL;

static void OnTenshouExeCreateFileA04Execute() {
	char *szFileName = (char *)pFileNameOfCreateFileA04;
	Native::On_ファイル要求時(string(szFileName), pFileNameOfCreateFileA04);
	デバッグ出力 << "CreateFileA04" << szFileName << endl;
}


/*
この時のベースアドレス
00871000   56               PUSH ESI


この時のCreateFileAの１番目付近のニーモニック
00872029   53               PUSH EBX
0087202A   57               PUSH EDI
0087202B   56               PUSH ESI
0087202C   68 80000000      PUSH 80
└ここを JMP TSMod.OnTSExeCreateFileA04 と書き換えてやる実際の処理
00872031   6A 03            PUSH 3
00872033   56               PUSH ESI
00872034   6A 01            PUSH 1
00872036   68 00000080      PUSH 80000000
0087203B   50               PUSH EAX
0087203C   FF15 30A3B300    CALL DWORD PTR DS:[<&KERNEL32.CreateFile>; KERNEL32.CreateFileA
00872042   8B7D 1C          MOV EDI,DWORD PTR SS:[EBP+1C]

*/
static int pTenshouExeJumpFromToOnTenshouExeCreateFileA04 = 0x87202C - 0x870000;   // 関数はこのアドレスから、OnTenshouExeCreateFileA04へとジャンプしてくる。
static int pTenshouExeRetnBacktoOnTenshouExeCreateFileA04 = 0x872031 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				 // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
static int iEAXOfTemp = 0; // EAX用の一時変数

						   // TENSHOU.EXE内でメッセージが構築されるタイミングでこのnaked関数が呼ばれる。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCreateFileA04() {
	// スタックにためておく
	__asm {
		mov iEAXOfTemp, eax

		mov pFileNameOfCreateFileA04, eax   // eaxを取っておく

		mov eax, iEAXOfTemp // eaxを元へと戻す。

							// 元々あったやつ
		PUSH 0x80

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCreateFileA04Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCreateFileA04
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCreateFileA04() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCreateFileA04,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCreateFileA04,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCreateFileA04	    // ここへと戻る
		);
}


