/*
ベースアドレス
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
00995F75   57               PUSH EDI
*/

#include "GameDataStruct.h"

extern BOOL isCountValidOfChangeFieldWarTurnExecute;


void OnTenshouExeWarScreenEndExecute() {
	// 野戦か籠城戦かの情報を降ろす
	isFieldWarOrCastleWar = -1;
	isCountValidOfChangeFieldWarTurnExecute = FALSE;

	// 経過ターン数をリセット
	iFieldTurnOfChangeFieldWarTurnExecute = 0xFFFF;

	デバッグ出力 << "戦争画面終了・捕虜前" << endl;
}

/*
この時のベースアドレス
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
└ここを JMP TSMod.OnTSExeWarScreenEnd と書き換えてやる実際の処理
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
00995F75   57               PUSH EDI
*/
static int pTenshouExeJumpFromToOnTenshouExeWarScreenEnd = 0x995F6B - 0x870000;   // 関数はこのアドレスから、OnTenshouExeWarScreenEndへとジャンプしてくる。
static int pTenshouExeCallFuncToOnTenshouExeWarScreenEnd = 0x99BBA0 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
static int pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd = 0x995F70 - 0x870000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																				// この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
EXPORT_AND_NAKED void WINAPI OnTenshouExeWarScreenEnd() {
	// スタックにためておく
	__asm {
		call pTenshouExeCallFuncToOnTenshouExeWarScreenEnd

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeWarScreenEndExecute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeWarScreenEnd() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeWarScreenEnd,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeWarScreenEnd,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeWarScreenEnd	    // ここへと戻る
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeWarScreenEnd
		);

}


