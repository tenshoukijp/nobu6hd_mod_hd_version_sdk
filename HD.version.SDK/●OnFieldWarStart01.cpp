
/*

�푈�J�n���Ƃقړ����悤�ȃ^�C�~���O�œǂݍ��܂��B

���̎��̃x�[�X�A�h���X
00811000   56               PUSH ESI

008FDC7C   C705 D0DBB800 00000000                          MOV DWORD PTR DS : [B8DBD0], 0
008FDC86   C705 F867B700 29000000                          MOV DWORD PTR DS : [B767F8], 29		�� ���̉��}�X
008FDC90   C705 FC67B700 18000000                          MOV DWORD PTR DS : [B767FC], 18	�@�@�� ���̏c�}�X
008FDC9A   C705 0068B700 03000000                          MOV DWORD PTR DS : [B76800], 3
008FDCA4   C705 0468B700 D8030000                          MOV DWORD PTR DS : [B76804], 3D8
008FDCAE   C705 C8DBB800 FFFF0000                          MOV DWORD PTR DS : [B8DBC8], 0FFFF
*/


#include "GameDataStruct.h"

static void OnTenshouExeFieldWarStart01Execute() {
	�f�o�b�O�o�� << "FieldWarStart01 ���}�b�v�Ǎ���" << endl;
	// �푈�J�n�p�����^�^^ param = gcnew �푈�J�n�p�����^�^();
	// int iCastleID = GetWarCenterCastle();
	// �V�ċL�N���X::On_�푈�J�n��(iCastleID, param);
}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095DCCC   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095DCD6   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29   �� ���̉��}�X
�������� JMP TSMod.OnTSExeFieldWarStart01 �Ə��������Ă����ۂ̏����B10�o�C�g�̏�������
0095DCE0   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18   �� ���̏c�}�X
0095DCEA   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095DCF4   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8      �� 0x29 x 0x18�̂���
0095DCFE   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095DD08   E8 B32A0300                   CALL NOBU6HD_.009907C0
0095DD0D   A3 A4DBBE00                   MOV DWORD PTR DS:[BEDBA4],EAX

�x�[�X
00871000   56               PUSH ESI

00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=�o�߃^�[������[02]=�V�C  0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..�@(�U���̎��́A����0x12=18,  �c��0x10=16)
*/

static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart01 = 0x95DCD6 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeFieldWarStart01�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01 = 0x95DCE0 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w

static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart01() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		mov iEAXOFTemp, eax
		mov eax, nb6hex_xy

		// ���X�̏����������ɋL�q
		MOV DWORD PTR DS : [eax], 0x29

		// eax��߂��B
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeFieldWarStart01Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeFieldWarStart01() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart01,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart01,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart01,	    // �����ւƖ߂�
		10													// 10�o�C�g
		);
}


