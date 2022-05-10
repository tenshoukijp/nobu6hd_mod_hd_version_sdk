#include "GameDataStruct.h"

/*
捕虜の処理
*/

static void OnTenshouExeHoryoSyoguExecutePrev() {

	デバッグ出力 << "捕虜処遇前" << endl;
}
static void OnTenshouExeHoryoSyoguExecutePost() {
	デバッグ出力 << "捕虜処遇後" << endl;
}

/*
この時のベースアドレス
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
└ここは、元々 JMP TSMod.OnTSExeWarScreenEnd 
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
└ここを JMP TSMod.OnTSExeHoryoSyogu と書き換えてやる実際の処理
00995F75   57               PUSH EDI
*/
static int pTenshouExeJumpFromToOnTenshouExeHoryoSyogu = 0x995F70 - 0x870000;   // 関数はこのアドレスから、OnTenshouExeHoryoSyoguへとジャンプしてくる。
static int pTenshouExeCallFuncToOnTenshouExeHoryoSyogu = 0x995730 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
static int pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu = 0x995F75 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																			  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
EXPORT_AND_NAKED void WINAPI OnTenshouExeHoryoSyogu() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeHoryoSyoguExecutePrev();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		call pTenshouExeCallFuncToOnTenshouExeHoryoSyogu		//	← 捕虜処遇と、各武将の帰参用の関数


		PUSHAD
		PUSHFD
	}

	
	OnTenshouExeHoryoSyoguExecutePost();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD
	
		jmp pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu
	}


}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeHoryoSyogu() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeHoryoSyogu,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeHoryoSyogu,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu	    // ここへと戻る
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeHoryoSyogu
		);

}


