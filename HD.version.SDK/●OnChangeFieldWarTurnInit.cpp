#include "GameDataStruct.h"



/*
�x�[�X
00871000   56               PUSH ESI

���ł̌o�߃^�[����
References in NOBU6HD_:.text to 00BD67EA..00BD67EA
Address    Disassembly                               Comment
00973040   MOV DWORD PTR DS:[BD67EA],0               DS:[00BD67EA]=0000000D  �� �����Ƀ^�[�����̒l���N���A���Ă���B
00973090   MOV EAX,DWORD PTR DS:[BD67EA]             [00BD67EA]=0000000D
00973176   MOV DWORD PTR DS:[BD67EA],EAX                                     �� �����Ƀ^�[�����̒l���������Ă���B

0097303F   CC                                    INT3
00973040   C705 EA67BD00 00000000                MOV DWORD PTR DS:[BD67EA],0
0097304A   C3                                    RETN
0097304B   CC                                    INT3

* /

/*
�x�[�X
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  �E�O�E
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=�o�߃^�[������[02]=�V�C  0x29=41�Ƃ͖��̉���HEX���̂���  0x12�̎��͍U�Đ��HEX���̉��̃}�X���ł���18�̂��ƁB
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/





static void OnTenshouExeChangeFieldWarTurnInitExecute() {
	�f�o�b�O�o�� << "���^�[���̏�����" << endl;
	// �V�ċL�N���X::On_�R�c�^�[���ύX�s�헪��ʁt(0xFFFF);

}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

00973040   C705 EA67BD00 00000000                MOV DWORD PTR DS:[BD67EA],0
�������� JMP TSMod.OnTSExeChangeFieldWarTurnInit �Ə��������Ă����ۂ̏����B10�o�C�g�̏�������
0097304A   C3                                    RETN
*/
static int pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurnInit = 0x973040 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeChangeFieldWarTurnInit�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit = 0x97304A - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeFieldWarTurnInit() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		// eax�Ԏ؂�
		mov iEAXOFTemp, eax
		mov eax, nb6battle_field_turn

		// ���X�̏����������ɋL�q
		MOV DWORD PTR DS : [eax], 0

		// eax�߂�
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeFieldWarTurnInitExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeChangeFieldWarTurnInit() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeFieldWarTurnInit,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeChangeFieldWarTurnInit,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeChangeFieldWarTurnInit,	    // �����ւƖ߂�
		10															    // 10�o�C�g��������
		);
}



