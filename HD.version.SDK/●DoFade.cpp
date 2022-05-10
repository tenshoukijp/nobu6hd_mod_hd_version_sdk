#include "GameDataStruct.h"

/*
ベース
01371000   56               PUSH ESI

01484860   E8 1BC00700      CALL NOBU6HD_.01500880
01484865   E8 F68B0000      CALL NOBU6HD_.0148D460				← フェイドアウト
0148486A   6A 01            PUSH 1
0148486C   6A 01            PUSH 1
0148486E   68 BD000000      PUSH 0BD
01484873   B9 50436F01      MOV ECX,NOBU6HD_.016F4350			← 何やら必要らしい
01484878   E8 C3AC0500      CALL NOBU6HD_.014DF540				← カメラ
0148487D   E8 BE8B0000      CALL NOBU6HD_.0148D440				← フェイドイン
*/


//---------------------フェイドアウト-------------------------
int pCallFromFuncFadeOut = 0x148D460 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncFadeOutAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		// 引数なし
		call pCallFromFuncFadeOut
		// 引数なしなのでスタックのずれ込みは無し
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncFadeOut() {

	// TENSHOU.EXE内の関数呼び出し
	FuncFadeOutAsm();

}


//---------------------フェイドイン-------------------------
int pCallFromFuncFadeIn = 0x148D440 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncFadeInAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		// 引数なし
		call pCallFromFuncFadeIn
		// 引数なしなのでスタックのずれ込みは無し
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncFadeIn() {
	// TENSHOU.EXE内の関数呼び出し
	FuncFadeInAsm();
}


// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExFuncFade() {
	WriteAsmJumperAndFunc(pCallFromFuncFadeIn);
	WriteAsmJumperAndFunc(pCallFromFuncFadeOut);
}
