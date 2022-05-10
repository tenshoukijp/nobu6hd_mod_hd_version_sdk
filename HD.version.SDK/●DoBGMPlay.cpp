#include "GameDataStruct.h"

/*
ベース
00081000   56               PUSH ESI

曲の再生
0019D34B   6A 01            PUSH 1							← 多分ループフラグ
0019D34D   6A 09            PUSH 9							← ＢＧＭ番号
0019D34F   E8 2C330800      CALL NOBU6HD_.00220680			← ＢＧＭ関数
0019D354   83C4 08          ADD ESP,8
0019D357   5F               POP EDI
0019D358   5E               POP ESI
0019D359   5D               POP EBP
0019D35A   C3               RETN
0019D35B   CC               INT3
0019D35C   CC               INT3
0019D35D   CC               INT3
0019D35E   CC               INT3

*/


//---------------------ＢＧＭ再生-------------------------
static int pCallFromFuncPlayBGM = 0x220680 - 0x80000; // 元々TENSHOU.EXE内にあったCALL先

static int iBgmIdFuncLoopBGM = 1;
static int iBgmIdFuncPlayBGM = -1;

void FuncPlayBGMAsm() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		push iBgmIdFuncLoopBGM  // 何なのかはわからん…

		push iBgmIdFuncPlayBGM

		call pCallFromFuncPlayBGM

		add esp, 8
	}

	_asm {
		POPFD
		POPAD
	}

}

extern int iLastCallFuncBGMLocation; // 天翔記exe内の再生場所

// 指定のＢＧＭを再生する
void FuncPlayBGM(int iBGM, bool isLoop) {

	iBgmIdFuncPlayBGM = iBGM;
	iBgmIdFuncLoopBGM = isLoop;

	// 再生場所をどこでもない状態にしておく
	iLastCallFuncBGMLocation = 0xFFFF;

	// TENSHOU.EXE内の関数呼び出し
	FuncPlayBGMAsm();
}


// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExFuncPlayBGM() {
	WriteAsmJumperAndFunc(pCallFromFuncPlayBGM);
}
