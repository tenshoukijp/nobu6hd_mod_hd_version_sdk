/*
�x�[�X
00AA1000   56               PUSH ESI
*/
#include "GameDataStruct.h"

extern int iLastCallFuncBGMLocation;
void OnTenshouExeCallFuncBGM_LOCATION_45Execute() {
	iLastCallFuncBGMLocation = BGM_LOCATION_45;
	�f�o�b�O�o�� << "BGM�V�[���ԍ�:" << "BGM_LOCATION_45" << endl;
}



static int pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_45 = 0xBBD33F - 0xAA0000;   // �֐��͂��̃A�h���X����AOnTenshouExeCallFuncBGM_00�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_45 = 0xC40680 - 0xAA0000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_45 = 0xBBD33F - 0xAA0000 + 5; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCallFuncBGM_LOCATION_45() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCallFuncBGM_LOCATION_45Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD
		
		// ���X�̏���
		call pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_45

		jmp pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_45
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_45() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCallFuncBGM_LOCATION_45,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_45,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_45	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_45
	);

}


