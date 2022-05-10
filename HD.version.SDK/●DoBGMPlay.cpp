#include "GameDataStruct.h"

/*
�x�[�X
00081000   56               PUSH ESI

�Ȃ̍Đ�
0019D34B   6A 01            PUSH 1							�� �������[�v�t���O
0019D34D   6A 09            PUSH 9							�� �a�f�l�ԍ�
0019D34F   E8 2C330800      CALL NOBU6HD_.00220680			�� �a�f�l�֐�
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


//---------------------�a�f�l�Đ�-------------------------
static int pCallFromFuncPlayBGM = 0x220680 - 0x80000; // ���XTENSHOU.EXE���ɂ�����CALL��

static int iBgmIdFuncLoopBGM = 1;
static int iBgmIdFuncPlayBGM = -1;

void FuncPlayBGMAsm() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		push iBgmIdFuncLoopBGM  // ���Ȃ̂��͂킩���c

		push iBgmIdFuncPlayBGM

		call pCallFromFuncPlayBGM

		add esp, 8
	}

	_asm {
		POPFD
		POPAD
	}

}

extern int iLastCallFuncBGMLocation; // �V�ċLexe���̍Đ��ꏊ

// �w��̂a�f�l���Đ�����
void FuncPlayBGM(int iBGM, bool isLoop) {

	iBgmIdFuncPlayBGM = iBGM;
	iBgmIdFuncLoopBGM = isLoop;

	// �Đ��ꏊ���ǂ��ł��Ȃ���Ԃɂ��Ă���
	iLastCallFuncBGMLocation = 0xFFFF;

	// TENSHOU.EXE���̊֐��Ăяo��
	FuncPlayBGMAsm();
}


// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExFuncPlayBGM() {
	WriteAsmJumperAndFunc(pCallFromFuncPlayBGM);
}
