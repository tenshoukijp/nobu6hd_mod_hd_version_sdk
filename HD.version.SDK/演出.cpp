#include "GameDataStruct.h"

void ���o���^::Do_�t�F�C�h�A�E�g() {
	FuncFadeOut();
}

void ���o���^::Do_�t�F�C�h�C��() {
	FuncFadeIn();
}

bool ���o���^::Do_�J�����ړ�(int ��ԍ�) {
	if (0 <= ��ԍ� && ��ԍ� < GAMEDATASTRUCT_CASTLE_NUM) {
		FuncMoveCamera(��ԍ�);
		return true;
	}
	return false;
}