
/*

���}�b�v�Ǎ���!!
�푈���n�܂��āA���}�b�v�̉�ʂւƎ��ۂɕς��n�߂����ɁA������ʉ߂���B


���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095F120   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095F12A   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
0095F134   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095F13E   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095F148   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095F152   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095F15C   E8 5F160300                   CALL NOBU6HD_.009907C0

*/


#include "GameDataStruct.h"

extern BOOL isCountValidOfChangeFieldWarTurnExecute;

static void OnTenshouExeFieldWarStart02Execute() {
	isFieldWarOrCastleWar = warstatus::���\���˓��O; //��킪�n�܂����B�o�w�O
	isCountValidOfChangeFieldWarTurnExecute = TRUE;

	�f�o�b�O�o�� << "FieldWarStart02 ���}�b�v�Ǎ���" << endl;
	
	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�푈�Q�����͌��蒼��");
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_�푈�Q�����͌��蒼�� ���\�b�h������");
		}

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�푈�Q�����͌��蒼��" << endl;

		// ���������Ŏ��s
		method->Invoke(nullptr, nullptr);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�푈�Q�����͌��蒼��" << endl;
		�V�ċL�N���X::On_�푈�Q�����͌��蒼��();
	}


}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0095F120   C705 D8DBBE00 00000000        MOV DWORD PTR DS:[BEDBD8],0
0095F12A   C705 F867BD00 29000000        MOV DWORD PTR DS:[BD67F8],29
�������� JMP TSMod.OnTSExeFieldWarStart02 �Ə��������Ă����ۂ̏����B10�o�C�g�̏�������
0095F134   C705 FC67BD00 18000000        MOV DWORD PTR DS:[BD67FC],18
0095F13E   C705 0068BD00 03000000        MOV DWORD PTR DS:[BD6800],3
0095F148   C705 0468BD00 D8030000        MOV DWORD PTR DS:[BD6804],3D8
0095F152   C705 D0DBBE00 FFFF0000        MOV DWORD PTR DS:[BEDBD0],0FFFF
0095F15C   E8 5F160300                   CALL NOBU6HD_.009907C0


00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00
00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29]  [17]=�o�߃^�[������[02]=�V�C  0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..�@(�U���̎��́A����0x12=18,  �c��0x10=16)
*/


static int pTenshouExeJumpFromToOnTenshouExeFieldWarStart02 = 0x95F12A - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeFieldWarStart02�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02 = 0x95F134 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w

static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeFieldWarStart02() {
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

	
	OnTenshouExeFieldWarStart02Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeFieldWarStart02() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeFieldWarStart02,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeFieldWarStart02,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeFieldWarStart02,	    // �����ւƖ߂�
		10													// 10�o�C�g
		);
}


