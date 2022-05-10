#include "GameDataStruct.h"

int DeNormalizeDaimyoYakusyokuValue(int iYakusyokuValue) {
	switch (iYakusyokuValue) {
	case 1:
		return 0x01;
	case 2:
		return 0x02;
	case 3:
		return 0x04;
	case 4:
		return 0x08;
	case 5:
		return 0x10;
	case 6:
		return 0x20;
	case 7:
		return 0x40;
	default:
		return 0;
	}
}

// �喼ID���琳�K�����ꂽ��EID�𓾂�
int getNormalizedDaimyoPosition(int iDaimyoID) {
	switch (nb6daimyo[iDaimyoID].position) {
	case 0x01:
		return 1;
	case 0x02:
		return 2;
	case 0x04:
		return 3;
	case 0x08:
		return 4;
	case 0x10:
		return 5;
	case 0x20:
		return 6;
	case 0x40:
		return 7;
	default:
		return 0;
	}
}

// �R�cID���琳�K�����ꂽ��EID�𓾂�
int getNormalizedGundanPosition(int iGundanID) {
	return nb6gundan[iGundanID].position;
}

bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		if (��::�喼::��E::���� <= iYakusyokuValue && iYakusyokuValue <= ��::�喼::��E::�H�B�T��) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// �喼�ŖړI��ID�̖�E�������Ă���l
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// �R�c�ŖړI��ID�̖�E�������Ă���l
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// �����ɑΏۂ̖�E������B
			nb6daimyo[iDaimyoID].position = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// �喼���g�Ȃ�A�ʏ���
		if (nb6gundan[iGundanID].number == 1) {
			int iDaimyoID = nb6gundan[iGundanID].attach - 1;
			tryChangeDaimyoYakusyoku(iDaimyoID, iYakusyokuValue);
		}

		if (��::�R�c::��E::���� <= iYakusyokuValue && iYakusyokuValue <= ��::�R�c::��E::�H�B�T��) {

			// �喼�ŖړI��ID�̖�E�������Ă���l
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// �R�c�ŖړI��ID�̖�E�������Ă���l
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// ���̖�E�������Ă���΁A�͂��D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// �����ɑΏۂ̖�E������B
			nb6gundan[iGundanID].position = iYakusyokuValue;

			return true;
		}
	}

	return false;
}
