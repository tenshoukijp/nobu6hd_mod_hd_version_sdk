#include "GameDataStruct.h"

/*
�ߗ��̏���
*/

static void OnTenshouExeHoryoSyoguExecutePrev() {

	�f�o�b�O�o�� << "�ߗ������O" << endl;
}
static void OnTenshouExeHoryoSyoguExecutePost() {
	�f�o�b�O�o�� << "�ߗ�������" << endl;
}

/*
���̎��̃x�[�X�A�h���X
00871000   56               PUSH ESI

00995F66   68 00200000      PUSH 2000
00995F6B   E8 305C0000      CALL NOBU6HD_.0099BBA0
�������́A���X JMP TSMod.OnTSExeWarScreenEnd 
00995F70   E8 BBF7FFFF      CALL NOBU6HD_.00995730
�������� JMP TSMod.OnTSExeHoryoSyogu �Ə��������Ă����ۂ̏���
00995F75   57               PUSH EDI
*/
static int pTenshouExeJumpFromToOnTenshouExeHoryoSyogu = 0x995F70 - 0x870000;   // �֐��͂��̃A�h���X����AOnTenshouExeHoryoSyogu�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeHoryoSyogu = 0x995730 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu = 0x995F75 - 0x870000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																			  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeHoryoSyogu() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeHoryoSyoguExecutePrev();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD

		call pTenshouExeCallFuncToOnTenshouExeHoryoSyogu		//	�� �ߗ������ƁA�e�����̋A�Q�p�̊֐�


		PUSHAD
		PUSHFD
	}

	
	OnTenshouExeHoryoSyoguExecutePost();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD
	
		jmp pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu
	}


}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeHoryoSyogu() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeHoryoSyogu,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeHoryoSyogu,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeHoryoSyogu	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeHoryoSyogu
		);

}


