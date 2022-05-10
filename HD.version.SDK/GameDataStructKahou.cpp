#include "GameDataStruct.h"

// �ƕ�𕐏��ɃA�^�b�`����B���X�ʕ����������Ă����ꍇ�́A���̕�������w�肵�������ւƃA�^�b�`���ς��B
// �\�͒l�̕ύX�𔺂��B���l�ɖ߂��ꍇ�́A0xFFFF���w�肷�邱�ƁB
bool ReAttachKahou(int iKahouID, int iNewBushouID) {
	if (!(0 <= iKahouID && iKahouID < GAMEDATASTRUCT_KAHOU_NUM)) {
		return false;
	}

	// �����͍~�낷
	nb6kahou[iKahouID].bLost = false;
	// ���o��͍~�낷�B
	nb6kahou[iKahouID].bMitojo = false;

	int iOldBushouID = nb6kahou[iKahouID].attach - 1;
	// �{�l���B��������K�v���Ȃ��B
	if (iOldBushouID == iNewBushouID) {
		return true;
	}
	// ���X���l�������Ă��āA�V���Ȏw������l���B��������K�v���Ȃ��B
	if (iOldBushouID >= 0xFFFE && iNewBushouID >= 0xFFFE) {
		return true;
	}

	// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
	if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {

		// ���̕����̐����\�͂̑f�l
		int iOldBushouPureGovMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureGovMax = getBushouPureGovMax(iOldBushouID);
			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureGovMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureGovMax = getBushouPureGovMax(iNewBushouID);

			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// �Ώۂ̉ƕ�̏����҂�ύX����B
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouGovMaxUpByKahou = getBushouGovMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxgov = iOldBushouPureGovMax + iOldBushouGovMaxUpByKahou;
		}

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouGovMaxUpByKahou = getBushouGovMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxgov = iNewBushouPureGovMax + iNewBushouGovMaxUpByKahou;
		}

		// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
	}
	else if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {

		// ���̕����̐����\�͂̑f�l
		int iOldBushouPureBatMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureBatMax = getBushouPureBatMax(iOldBushouID);
			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureBatMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureBatMax = getBushouPureBatMax(iNewBushouID);

			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// �Ώۂ̉ƕ�̏����҂�ύX����B
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouBatMaxUpByKahou = getBushouBatMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxbat = iOldBushouPureBatMax + iOldBushouBatMaxUpByKahou;
		}

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouBatMaxUpByKahou = getBushouBatMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxbat = iNewBushouPureBatMax + iNewBushouBatMaxUpByKahou;
		}


		// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
	}
	else if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {

		// ���̕����̐����\�͂̑f�l
		int iOldBushouPureIntMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureIntMax = getBushouPureIntMax(iOldBushouID);
			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureIntMax = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureIntMax = getBushouPureIntMax(iNewBushouID);

			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// �Ώۂ̉ƕ�̏����҂�ύX����B
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouIntMaxUpByKahou = getBushouIntMaxUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].maxint = iOldBushouPureIntMax + iOldBushouIntMaxUpByKahou;
		}

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouIntMaxUpByKahou = getBushouIntMaxUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].maxint = iNewBushouPureIntMax + iNewBushouIntMaxUpByKahou;
		}

		// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
	}
	else if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {

		// ���̕����̐����\�͂̑f�l
		int iOldBushouPureAmbition = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iOldBushouPureAmbition = getBushouPureAmbition(iOldBushouID);
			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iOldBushouID = 0xFFFF;
		}

		int iNewBushouPureAmbition = 0;
		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			iNewBushouPureAmbition = getBushouPureAmbition(iNewBushouID);

			// �s���Ȕԍ��͏��l�Ƃ������Ƃɂ���B
		}
		else {
			iNewBushouID = 0xFFFF;
		}

		// �Ώۂ̉ƕ�̏����҂�ύX����B
		nb6kahou[iKahouID].attach = (iNewBushouID == 0xFFFF) ? 0xFFFF : (iNewBushouID + 1);

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iOldBushouID && iOldBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iOldBushouAmbitionUpByKahou = getBushouAmbitionUpByKahou(iOldBushouID);
			nb6bushou[iOldBushouID].ambition = iOldBushouPureAmbition + iOldBushouAmbitionUpByKahou;
		}

		// �V�����w��̕����͐��K�̕����ł���A���l�ł͂Ȃ��B
		if (0 <= iNewBushouID && iNewBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			int iNewBushouAmbitionUpByKahou = getBushouAmbitionUpByKahou(iNewBushouID);
			nb6bushou[iNewBushouID].ambition = iNewBushouPureAmbition + iNewBushouAmbitionUpByKahou;
		}

	}

	return true;
}


