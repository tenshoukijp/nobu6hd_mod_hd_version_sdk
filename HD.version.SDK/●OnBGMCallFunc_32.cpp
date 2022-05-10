/*
ベース
00AA1000   56               PUSH ESI
*/
#include "GameDataStruct.h"

extern int iLastCallFuncBGMLocation;
void OnTenshouExeCallFuncBGM_LOCATION_32Execute() {
	iLastCallFuncBGMLocation = BGM_LOCATION_32;
	デバッグ出力 << "BGMシーン番号:" << "BGM_LOCATION_32" << endl;
}



static int pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_32 = 0xBB788D - 0xAA0000;   // 関数はこのアドレスから、OnTenshouExeCallFuncBGM_00へとジャンプしてくる。
static int pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32 = 0xC40680 - 0xAA0000; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
static int pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32 = 0xBB788D - 0xAA0000 + 5; // 関数が最後までいくと、このTENSHOU.EXE内に直接ジャンプするというなんとも危険な行為w
																						  // この関数はTENSHOU.EXEがメッセージを読みを終えるたびに、直接実行される。
EXPORT_AND_NAKED void WINAPI OnTenshouExeCallFuncBGM_LOCATION_32() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCallFuncBGM_LOCATION_32Execute();

	// スタックに引き出す
	__asm {
		POPFD
		POPAD
		
		// 元々の処理
		call pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32

		jmp pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32
	}
}



// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_32() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCallFuncBGM_LOCATION_32,						// このnaked関数は
		pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_32,		// ここから来て
		pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32	    // ここへと戻る
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32
	);

}


