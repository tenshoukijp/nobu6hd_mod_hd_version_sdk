#include "GameDataStruct.h"

/*
�R�c�^�[����0xFFFF�Ƃ������悤�ɁA�N�̃^�[���ł��������̂ւƐ؂�ւ�����

���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0099BCFC   CC               INT3
0099BCFD   CC               INT3
0099BCFE   CC               INT3
0099BCFF   CC               INT3
0099BD00   B8 FFFF0000      MOV EAX,0FFFF
0099BD05   66:A3 DFF8BC00   MOV WORD PTR DS:[BCF8DF],AX			�� �����BFFFF�ƂȂ�B
0099BD0B   C3               RETN


00BCF8DD  19 00 [23] 00 FF FF 1D 00 01 00 39 00 25 00 31 00
00BCF8ED  34 00 02 00 08 00 23 00 30 00 12 00 14 00 28 00
00BCF8FD  0A 00 1B 00 0D 00 1A 00 03 00 04 00 11 00 32 00
*/




static void OnTenshouExeChangeGundanTurnUndefExecute() {

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
		prms[0] = 0xFFFF;

		�f�o�b�O�o�� << "���[�U�[�V�ċL�N���X::My_�헪_�R�c�^�[���ύX��" << endl;

		// �Ԃ�l�����Ŏ��s
		method->Invoke(nullptr, prms);
	}

	// �G���[�Ȃ̂œ����̂��̂����s����B
	catch (Exception^) {
		�f�o�b�O�o�� << "�V�ċL�N���X::On_�헪_�R�c�^�[���ύX��" << endl;
		�V�ċL�N���X::On_�헪_�R�c�^�[���ύX��(0xFFFF);
	}

}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

0099BCFC   CC               INT3
0099BCFD   CC               INT3
0099BCFE   CC               INT3
0099BCFF   CC               INT3
0099BD00   B8 FFFF0000      MOV EAX,0FFFF
0099BD05   66:A3 DFF8BC00   MOV WORD PTR DS:[BCF8DF],AX			�� �����BFFFF�ƂȂ�B 6�o�C�g��������
�������� JMP TSMod.OnTSExeChangeGundanTurnUndef �Ə��������Ă����ۂ̏���
0099BD0B   C3               RETN

*/
static int pTenshouExeJumpFromToOnTenshouExeChangeGundanTurnUndef = 0x99BD05 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeChangeGundanTurnUndef�ւƃW�����v���Ă���B
static int pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef = 0x99BD0B - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						 // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
static int iEAXOFTemp = 0;
																						 // TENSHOU.EXE���Ń��b�Z�[�W���\�z�����^�C�~���O�ł���naked�֐����Ă΂��B
EXPORT_AND_NAKED void WINAPI OnTenshouExeChangeGundanTurnUndef() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {
		// eax�Ԏ؂�
		mov iEAXOFTemp, eax
		mov eax, nb6turn_gundan_ptr

		// ���X�̏����������ɋL�q
		MOV WORD PTR DS : [eax], AX

		// eax�߂�
		mov eax, iEAXOFTemp

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeChangeGundanTurnUndefExecute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		jmp pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeChangeGundanTurnUndef() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeChangeGundanTurnUndef,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeChangeGundanTurnUndef,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeChangeGundanTurnUndef,	    // �����ւƖ߂�
		6															// 6�o�C�g��������
		);
}


