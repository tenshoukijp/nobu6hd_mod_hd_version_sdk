
/*

�ď��؂�ւ����ɐ؂�ւ��x�ɌĂ΂��

���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095FC98   69C0 60030000              IMUL EAX,EAX,360
0095FC9E   05 28080000                ADD EAX,828
0095FCA3   C705 F867BD00 12000000     MOV DWORD PTR DS:[BD67F8],12
0095FCAD   C705 FC67BD00 10000000     MOV DWORD PTR DS:[BD67FC],10
0095FCB7   C705 0468BD00 20010000     MOV DWORD PTR DS:[BD6804],120
0095FCC1   50                         PUSH EAX


*/


#include "GameDataStruct.h"

extern int isFieldWarOrCastleWar;
static void OnTenshouExeCastleWarStart01Execute() {
	isFieldWarOrCastleWar = warstatus::��\���˓��O;
	�f�o�b�O�o�� << "CastleWarStart01 �ď��L�������O:" << endl;
	// �푈�J�n�p�����^�^^ param = gcnew �푈�J�n�p�����^�^();
	// int iCastleID = GetWarCenterCastle();
	// �V�ċL�N���X::On_�푈�J�n��(iCastleID, param);
}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095FC98   69C0 60030000              IMUL EAX,EAX,360
0095FC9E   05 28080000                ADD EAX,828
0095FCA3   C705 F867BD00 12000000     MOV DWORD PTR DS:[BD67F8],12    �ď��̉��܂�
�������� JMP TSMod.OnTSExeCastleWarStart01 �Ə��������Ă����ۂ̏����B10�o�C�g�̏�������
0095FCAD   C705 FC67BD00 10000000     MOV DWORD PTR DS:[BD67FC],10    �ď��̏c�}�X		
0095FCB7   C705 0468BD00 20010000     MOV DWORD PTR DS:[BD6804],120   �ď��̏c�����}�X	
0095FCC1   50                         PUSH EAX
*/

/*
�x�[�X
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  �E�O�E
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=�o�߃^�[������[02]=�V�C  0x29=41�Ƃ͖��̉���HEX���̂���  0x12�̎��͍U�Đ��HEX���̉��̃}�X���ł���18�̂��ƁB
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
*/

static int pTenshouExeJumpFromToOnTenshouExeCastleWarStart01 = 0x95FCA3 - 0x870000; // �֐��͂��̃A�h���X����AOnTenshouExeCastleWarStart01�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01 = 0x95FCAD - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w

static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCastleWarStart01() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		mov iEAXOFTemp, eax
		mov eax, nb6hex_xy

		// ���X�̏����������ɋL�q
		MOV DWORD PTR DS : [eax], 0x12

		// eax��߂��B
		mov eax, iEAXOFTemp

		
		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCastleWarStart01Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCastleWarStart01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCastleWarStart01,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCastleWarStart01,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCastleWarStart01,	    // �����ւƖ߂�
		10													// 10�o�C�g
		);
}


