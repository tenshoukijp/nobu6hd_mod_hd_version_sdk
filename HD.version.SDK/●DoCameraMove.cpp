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

int pCallFromFuncMoveCamera = 0x14DF540 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��
int pCallFromECXMoveCamera  = 0x16F4350 - 0x1370000;  // ���XTENSHOU.EXE���ɂ�����CALL��

WORD iCastleIdInFuncMoveCamera = 1L;

// ���C����ʂł̃J�����ړ�
void FuncMoveCameraAsm() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	__asm {
		push ecx  // ecx �̒l��ۑ�

				// ����1�`3 2�o�C�g����
		mov ecx, pCallFromECXMoveCamera  // (���g��2710=10000���B�Ȃɂ��K�v�炵��);
		push 1
		push 1
		push dword ptr iCastleIdInFuncMoveCamera;
		call pCallFromFuncMoveCamera

		pop ecx  // ecx�̒l�����ւƖ߂�
	}

	_asm {
		POPFD
		POPAD
	}

}


// �J�������w��̏�ID�ւƈړ�
void FuncMoveCamera(int iCastleID) {

	if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		// �֐��p�̂�́A1�����̂ŁA��������
		iCastleIdInFuncMoveCamera = (WORD)iCastleID + 1;

		// TENSHOU.EXE���̊֐��Ăяo��
		FuncMoveCameraAsm();

	}
}




// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExFuncMoveCamera() {
	WriteAsmJumperAndFunc(pCallFromFuncMoveCamera);
	WriteAsmJumperAndFunc(pCallFromECXMoveCamera);
}
