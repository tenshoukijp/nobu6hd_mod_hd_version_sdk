#include "GameDataStruct.h"

//----------------------------------------------------------------------------------

static char* nb6kanitypelist[GAMEDATASTRUCT_KANITYPE_NUM] = {
	"�����",
	"�]���",
	"�����",
	"�]���",
	"���O��",
	"�]�O��",
	"���l�ʏ�",
	"���l�ʉ�",
	"�]�l�ʏ�",
	"�]�l�ʉ�",
	"���܈ʏ�",
	"���܈ʉ�",
	"�]�܈ʏ�",
	"�]�܈ʉ�",
	"���Z�ʏ�",
	"���Z�ʉ�",
	"�]�Z�ʏ�",
	"�]�Z�ʉ�",
	"�����ʏ�",
	"�����ʉ�",
	"�]���ʏ�",
	"�]���ʉ�",
	"�����ʏ�",
};

char* getKaniTypeName(byte type) {
	return nb6kanitypelist[type];
}

// ���ʂ𕐏��ɃA�^�b�`����B���X�ʕ����������Ă����ꍇ�́A���̕�������w�肵�������ւƃA�^�b�`���ς��B
// �\�͒l�̕ύX�𔺂��B����ɖ߂��ꍇ�́A0xFFFF���w�肷�邱�ƁB
bool ReAttachKani(int iKaniID, int iNewBushouID) {
	if (!(0 <= iKaniID && iKaniID < GAMEDATASTRUCT_KANI_NUM)) {
		return false;
	}

	int iOldBushouID = nb6kani[iKaniID].attach - 1;
	// �{�l���B��������K�v���Ȃ��B
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// ���X���삪�����Ă��āA�V���Ȏw������삾�B��������K�v���Ȃ��B
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE) {
		return true;
	}


	// ���̕����̐����\�͂̑f�l
	int iOldBushouPureCharm = 0;
	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		iOldBushouPureCharm = getBushouPureCharm(iOldBushouID);
		// �s���Ȕԍ��͒���Ƃ������Ƃɂ���B
	}
	else {
		iOldBushouID = 0xFFFF;
	}

	int iNewBushouPureCharm = 0;
	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		iNewBushouPureCharm = getBushouPureCharm(iNewBushouID);

		// �s���Ȕԍ��͒���Ƃ������Ƃɂ���B
	}
	else {
		iNewBushouID = 0xFFFF;
	}

	// �Ώۂ̉ƕ�̏����҂�ύX����B
	nb6kani[iKaniID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

	// ���̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iOldBushouCharmUpByKani = getBushouCharmUpByKani(iOldBushouID);
		nb6bushou[iOldBushouID].charm = iOldBushouPureCharm + iOldBushouCharmUpByKani;
	}

	// �V�����w��̕����͐��K�̕����ł���A����ł͂Ȃ��B
	if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iNewBushouCharmUpByKani = getBushouCharmUpByKani(iNewBushouID);
		nb6bushou[iNewBushouID].charm = iNewBushouPureCharm + iNewBushouCharmUpByKani;
	}

	return true;
}
