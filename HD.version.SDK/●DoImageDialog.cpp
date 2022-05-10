#include "GameDataStruct.h"


//---------------------�摜�̃_�C�A���O-------------------------
/*
�x�[�X
01371000   56               PUSH ESI

0147E520   55               PUSH EBP
0147E521   8BEC             MOV EBP,ESP
0147E523   A1 58A46E01      MOV EAX,DWORD PTR DS:[16EA458]
0147E528   FF75 08          PUSH DWORD PTR SS:[EBP+8]
0147E52B   8B40 04          MOV EAX,DWORD PTR DS:[EAX+4]
0147E52E   99               CDQ
0147E52F   2BC2             SUB EAX,EDX
0147E531   68 94010000      PUSH 194
0147E536   D1F8             SAR EAX,1
0147E538   68 D4020000      PUSH 2D4
0147E53D   2D 33010000      SUB EAX,133
0147E542   50               PUSH EAX
0147E543   68 FFFF0000      PUSH 0FFFF
0147E548   E8 333A0600      CALL NOBU6HD_.014E1F80
0147E54D   83C4 14          ADD ESP,14
0147E550   C745 08 0A000000 MOV DWORD PTR SS:[EBP+8],0A
0147E557   5D               POP EBP
0147E558   E9 93F20000      JMP NOBU6HD_.0148D7F0

*/
int pCallFromFuncConfirmImageDialogStartAsm = 0x147E520 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��
int pImageIDOfFuncConfirmImageDialogStart = 0;
void FuncConfirmImageDialogStartAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push pImageIDOfFuncConfirmImageDialogStart // �摜�ԍ�
												   // �����Ȃ�
		call pCallFromFuncConfirmImageDialogStartAsm

		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

// iImageID�Ƃ��Ă�0x1ea3�Ȃ�
void FuncConfirmImageDialogStart(int iImageID) {
	pImageIDOfFuncConfirmImageDialogStart = iImageID;

	// TENSHOU.EXE���̊֐��Ăяo��
	FuncConfirmImageDialogStartAsm();
}



//---------------------------------------------------- �摜�̏���

/*
�x�[�X
01371000   56               PUSH ESI

01484B07   83C4 14          ADD ESP, 14
01484B0A   E8 C1D40500      CALL NOBU6HD_.014E1FD0
01484B0F   B9 B0686F01      MOV ECX, NOBU6HD_.016F68B0		  �� ����Ȃ̂��K���Z�b�g�̖͗l
01484B14   E8 67BD0700      CALL NOBU6HD_.01500880				�� ������ �摜�����H
01484B19   B9 68676F01      MOV ECX, NOBU6HD_.016F6768
01484B1E   E8 5DBD0700      CALL NOBU6HD_.01500880			�� �E���̐����o���̉摜�����H
01484B23   6A 00            PUSH 0
*/


int pECXFromFuncConfirmImageDialogEndAsm  = 0x16F68B0 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��
int pCallFromFuncConfirmImageDialogEndAsm = 0x1500880 - 0x1370000; // ���XTENSHOU.EXE���ɂ�����CALL��
void FuncConfirmImageDialogEndAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		mov ecx, pECXFromFuncConfirmImageDialogEndAsm // �摜�ԍ�
												 // �����Ȃ�
		call pCallFromFuncConfirmImageDialogEndAsm
	}

	_asm {
		POPFD
		POPAD
	}
}

// iImageID�Ƃ��Ă�0x1ea3�Ȃ�
void FuncConfirmImageDialogEnd() {

	// TENSHOU.EXE���̊֐��Ăяo��
	FuncConfirmImageDialogEndAsm();
}




//----------------------------------------------------


// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExFuncImageDialog() {
	WriteAsmJumperAndFunc(pCallFromFuncConfirmImageDialogStartAsm);

	WriteAsmJumperAndFunc(pECXFromFuncConfirmImageDialogEndAsm);
	WriteAsmJumperAndFunc(pCallFromFuncConfirmImageDialogEndAsm);
}
