#include "GameDataStruct.h"

/*
�x�[�X
01371000   56               PUSH ESI

01484860   E8 1BC00700      CALL NOBU6HD_.01500880
01484865   E8 F68B0000      CALL NOBU6HD_.0148D460				�� �t�F�C�h�A�E�g
0148486A   6A 01            PUSH 1
0148486C   6A 01            PUSH 1
0148486E   68 BD000000      PUSH 0BD
01484873   B9 50436F01      MOV ECX,NOBU6HD_.016F4350			�� �����K�v�炵��
01484878   E8 C3AC0500      CALL NOBU6HD_.014DF540				�� �J����
0148487D   E8 BE8B0000      CALL NOBU6HD_.0148D440				�� �t�F�C�h�C��
*/


//---------------------�t�F�C�h�A�E�g-------------------------
int pCallFromFuncFadeOut = 0x148D460 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��

void FuncFadeOutAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		// �����Ȃ�
		call pCallFromFuncFadeOut
		// �����Ȃ��Ȃ̂ŃX�^�b�N�̂��ꍞ�݂͖���
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncFadeOut() {

	// TENSHOU.EXE���̊֐��Ăяo��
	FuncFadeOutAsm();

}


//---------------------�t�F�C�h�C��-------------------------
int pCallFromFuncFadeIn = 0x148D440 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��

void FuncFadeInAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		// �����Ȃ�
		call pCallFromFuncFadeIn
		// �����Ȃ��Ȃ̂ŃX�^�b�N�̂��ꍞ�݂͖���
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncFadeIn() {
	// TENSHOU.EXE���̊֐��Ăяo��
	FuncFadeInAsm();
}


// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExFuncFade() {
	WriteAsmJumperAndFunc(pCallFromFuncFadeIn);
	WriteAsmJumperAndFunc(pCallFromFuncFadeOut);
}
