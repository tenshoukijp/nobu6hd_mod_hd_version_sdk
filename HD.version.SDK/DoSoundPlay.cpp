#include "GameDataStruct.h"

/*
�x�[�X
01371000   56               PUSH ESI


���ʉ��̍Đ�
0147FA73   6A 00            PUSH 0
0147FA75   6A 00            PUSH 0
0147FA77   6A 02            PUSH 2
0147FA79   6A 11            PUSH 11
0147FA7B   E8 500C0900      CALL NOBU6HD_.015106D0
0147FA80   83C4 10          ADD ESP,10


*/


//---------------------�a�f�l�Đ�-------------------------
static int pCallFromFuncPlaySound = 0x15106D0 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��

static int iSoundIdFuncLoopSound = 1;
static int iSoundIdFuncPlaySound = -1;

void FuncPlaySoundAsm() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		push 0
		push 0
		push 2
		push iSoundIdFuncPlaySound

		call pCallFromFuncPlaySound

		add esp, 0x10
	}

	_asm {
		POPFD
		POPAD
	}

}


// �w��̂a�f�l���Đ�����
void FuncPlaySound(int iSound, bool isLoop) {

	iSoundIdFuncPlaySound = iSound;
	// TENSHOU.EXE���̊֐��Ăяo��
	FuncPlaySoundAsm();
}


// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExFuncPlaySound() {
	WriteAsmJumperAndFunc(pCallFromFuncPlaySound);
}
