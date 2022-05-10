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

int pCallFromFuncMoveCamera = 0x14DF540 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先
int pCallFromECXMoveCamera  = 0x16F4350 - 0x1370000;  // 元々TENSHOU.EXE内にあったCALL先

WORD iCastleIdInFuncMoveCamera = 1L;

// メイン画面でのカメラ移動
void FuncMoveCameraAsm() {
	// スタックにためておく
	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		push ecx  // ecx の値を保存

				// 引数1～3 2バイトずつ
		mov ecx, pCallFromECXMoveCamera  // (中身は2710=10000か。なにやら必要らしい);
		push 1
		push 1
		push dword ptr iCastleIdInFuncMoveCamera;
		call pCallFromFuncMoveCamera

		pop ecx  // ecxの値を元へと戻す
	}

	_asm {
		POPFD
		POPAD
	}

}


// カメラを指定の城IDへと移動
void FuncMoveCamera(int iCastleID) {

	if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		// 関数用のやつは、1つ多いので、足しこみ
		iCastleIdInFuncMoveCamera = (WORD)iCastleID + 1;

		// TENSHOU.EXE内の関数呼び出し
		FuncMoveCameraAsm();

	}
}




// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExFuncMoveCamera() {
	WriteAsmJumperAndFunc(pCallFromFuncMoveCamera);
	WriteAsmJumperAndFunc(pCallFromECXMoveCamera);
}
