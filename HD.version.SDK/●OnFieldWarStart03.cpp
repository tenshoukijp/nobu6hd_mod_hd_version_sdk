
/*
���}�b�v�ւ̐؂�ւ���!!
���^�[���̐؂�ւ�莞�ɂ�����ʉ߂���B
���������͏d�v!!

���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095FC66   75 2B                         JNZ SHORT NOBU6HD_.0095FC93
0095FC68   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
0095FC72   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095FC7C   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095FC86   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095FC90   50                            PUSH EAX
0095FC91   EB 2F                         JMP SHORT NOBU6HD_.0095FCC2
*/


#include "GameDataStruct.h"

static void OnTenshouExeFieldWarStart03Execute() {
	isFieldWarOrCastleWar = warstatus::���^�[����; //���œ��͉\�ƂȂ����B
	�f�o�b�O�o�� << "FieldWarStart03 ���}�b�v�L�������O" << endl;
	// �푈�J�n�p�����^�^^ param = gcnew �푈�J�n�p�����^�^();
	// int iCastleID = GetWarCenterCastle();
	// �V�ċL�N���X::On_�푈�J�n��(iCastleID, param);
}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095FC68   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
�������� JMP TSMod.OnTSExeFieldWarStart03 �Ə��������Ă����ۂ̏����B10�o�C�g�̏�������
0095FC72   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095FC7C   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095FC86   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095FC90   50                            PUSH EAX


00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=�o�߃^�[������[02]=�V�C  0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..�@(�U���̎��́A����0x12=18,  �c��0x10=16)
*/


static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart03 = 0x95FC68 - 0x870000; // �֐��͂��̃A�h���X����AOnTenshouExeFieldWarStart03�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03 = 0x95FC72 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w

static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart03() {
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

	
	OnTenshouExeFieldWarStart03Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeFieldWarStart03() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart03,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart03,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart03,	    // �����ւƖ߂�
		10													// 10�o�C�g
	);
}


