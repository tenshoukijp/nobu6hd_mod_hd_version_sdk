/*
ベース
00AA1000   56               PUSH ESI
*/
#include "GameDataStruct.h"

extern int iLastCallFuncBGMLocation;
void OnTenshouExeCallFuncBGM_LOCATION_57Execute() {
	iLastCallFuncBGMLocation = BGM_LOCATION_57;
	デバッグ出力 << "BGMシーン番号:" << "BGM_LOCATION_57" << endl;
}



static int pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_57 = 0xBD99C5 - 0xAA0000;   // 関数はこのアドレスから、OnTenshouExeCallFuncBGM_00へとジャンプしてくる。
static int pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_57 = 0xC40680 - 0xAA0000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
static int pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_57 = 0xBD99C5 - 0xAA0000 + 5; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																						  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCallFuncBGM_LOCATION_57() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCallFuncBGM_LOCATION_57Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD
		
		// 元々の処理
		call pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_57

		jmp pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_57
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_57() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCallFuncBGM_LOCATION_57,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_57,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_57	    // ここへと戻る
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_57
	);

}


