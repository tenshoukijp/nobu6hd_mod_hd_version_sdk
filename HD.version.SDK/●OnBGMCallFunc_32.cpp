/*
�x�[�X
00AA1000   56               PUSH ESI
*/
#include "GameDataStruct.h"

extern int iLastCallFuncBGMLocation;
void OnTenshouExeCallFuncBGM_LOCATION_32Execute() {
	iLastCallFuncBGMLocation = BGM_LOCATION_32;
	�f�o�b�O�o�� << "BGM�V�[���ԍ�:" << "BGM_LOCATION_32" << endl;
}



static int pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_32 = 0xBB788D - 0xAA0000;   // �֐��͂��̃A�h���X����AOnTenshouExeCallFuncBGM_00�ւƃW�����v���Ă���B
static int pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32 = 0xC40680 - 0xAA0000; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
static int pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32 = 0xBB788D - 0xAA0000 + 5; // �֐����Ō�܂ł����ƁA����TENSHOU.EXE���ɒ��ڃW�����v����Ƃ����Ȃ�Ƃ��댯�ȍs��w
																						  // ���̊֐���TENSHOU.EXE�����b�Z�[�W��ǂ݂��I���邽�тɁA���ڎ��s�����B
EXPORT_AND_NAKED void WINAPI OnTenshouExeCallFuncBGM_LOCATION_32() {
	// �X�^�b�N�ɂ��߂Ă���
	__asm {

		PUSHAD
		PUSHFD

	}

	
	OnTenshouExeCallFuncBGM_LOCATION_32Execute();

	// �X�^�b�N�Ɉ����o��
	__asm {
		POPFD
		POPAD
		
		// ���X�̏���
		call pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32

		jmp pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32
	}
}



// �j�[���j�b�N���������p
void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_32() {

	WriteAsmJumperAndReturn(
		(int)OnTenshouExeCallFuncBGM_LOCATION_32,						// ����naked�֐���
		pTenshouExeJumpFromToOnTenshouExeCallFuncBGM_LOCATION_32,		// �������痈��
		pTenshouExeRetnBacktoOnTenshouExeCallFuncBGM_LOCATION_32	    // �����ւƖ߂�
		);

	WriteAsmJumperAndFunc(
		pTenshouExeCallFuncToOnTenshouExeCallFuncBGM_LOCATION_32
	);

}


