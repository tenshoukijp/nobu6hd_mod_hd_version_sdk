/*
�x�[�X
00AA1000   56               PUSH ESI
*/
#include "GameDataStruct.h"

extern int iLastCallFuncBGMLocation;
void OnTenshouExeCallFuncBGM_LOCATION_62Execute() {
	iLastCallFuncBGMLocation = BGM_LOCATION_62;
	�f�o�b�O�o�� << "BGM�V�[���ԍ�:" << "BGM_LOCATION_62" << endl;
}



static int pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_62 = 0xC24316 - 0xAA0000;   // �֐��͂��̃A�h���X����AOnTenshouExeCallFuncBGM_00�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_62 = 0xC40680 - 0xAA0000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_62 = 0xC24316 - 0xAA0000 + 5; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCallFuncBGM_LOCATION_62() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCallFuncBGM_LOCATION_62Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD
		
		// ���X�̏���
		call pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_62

		jmp pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_62
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_62() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCallFuncBGM_LOCATION_62,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_62,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_62	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_62
	);

}


