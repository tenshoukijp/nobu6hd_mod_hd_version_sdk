#include "GameDataStruct.h"

/*
�R�c�^�[����؂�ւ�����

�x�[�X
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI


0099C26C   0F46D0           CMOVBE EDX,EAX
0099C26F   66:8915 DFF8BC00 MOV WORD PTR DS:[BCF8DF],DX			�� �����ɌR�c�ԍ��������Ă�͂�
0099C276   5E               POP ESI
0099C277   5D               POP EBP
0099C278   C3               RETN



00BCF8DD  19 00 [23] 00 FF FF 1D 00 01 00 39 00 25 00 31 00 
00BCF8ED  34 00 02 00 08 00 23 00 30 00 12 00 14 00 28 00  
00BCF8FD  0A 00 1B 00 0D 00 1A 00 03 00 04 00 11 00 32 00 

*/


WORD iGundanIDOfChangeGundanTurnExecute = 0xFFFF;

static void OnTenshouExeChangeGundanTurnExecute() {
	int iGundanID = (int)iGundanIDOfChangeGundanTurnExecute - 1;
	if (iGundanID >= 0xFFFE) {
		iGundanID = 0xFFFF;
	}

	try {
		// ���[�U�[�N���X���G���[
		if (���[�U�[�N���X::IsErrorUserVersionDLL()) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X �N���X������");
		}

		//�P�p�����[�^�̌^��z��ɓ���� 
		cli::array<Type^>^ types = gcnew cli::array<Type^>(1);
		types[0] = int::typeid;

		//���\�b�h�̏����擾 
		MethodInfo^ method = ���[�U�[�N���X::masterType->GetMethod("My_�헪_�R�c�^�[���ύX��", types);
		if (!method) {
			throw gcnew Exception("���[�U�[�V�ċL�N���X My_�헪_�R�c�^�[���ύX�� ���\�b�h������");
		}

		//�P�̃p�����^�����ۂɓ����
		cli::array<Object^>^ prms = gcnew cli::array<Object^>(1);
		prms[0] = iGundanID;

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�헪_�R�c�^�[���ύX��" << endl;

		// �Ԃ�l�����Ŏ��s
		method->Invoke(nullptr, prms);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�헪_�R�c�^�[���ύX��" << endl;
		�V�ċL�N���X::On_�헪_�R�c�^�[���ύX��(iGundanID);

	}


}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI


0099C26C   0F46D0           CMOVBE EDX,EAX
0099C26F   66:8915 DFF8BC00 MOV WORD PTR DS:[BCF8DF],DX			�� �����ɌR�c�ԍ��������Ă�͂�
�������� JMP TSMod.OnTSExeChangeGundanTurn �Ə��������Ă����ۂ̏���
0099C276   5E               POP ESI
0099C277   5D               POP EBP
0099C278   C3               RETN

*/
static int pTenshouExeJumpFromToOnTenshouExeChangeGundanTurn = 0x99C26F - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeChangeGundanTurn�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn = 0x99C276 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																					// ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOFTemp = 0;
// TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeGundanTurn() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		// eax�Ԏ؂�
		mov iEAXOFTemp, eax
		mov eax, nb6turn_gundan_ptr

		// ���X�̏����������ɋL�q
		MOV WORD PTR DS : [eax], DX

		// eax�߂�
		mov eax, iEAXOFTemp

		// �R�c�ԍ��̕ۑ�
		mov iGundanIDOfChangeGundanTurnExecute, DX;

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeGundanTurnExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeChangeGundanTurn() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeGundanTurn,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeChangeGundanTurn,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurn,	    // �����ւƖ߂�
		7														// 7�o�C�g��������
		);
}


