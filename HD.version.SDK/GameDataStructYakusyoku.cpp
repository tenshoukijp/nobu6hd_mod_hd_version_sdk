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

// 大名IDから正規化された役職IDを得る
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

// 軍団IDから正規化された役職IDを得る
int getNormalizedGundanPosition(int iGundanID) {
	return nb6gundan[iGundanID].position;
}

bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		if (列挙::大名::役職::無し <= iYakusyokuValue && iYakusyokuValue <= 列挙::大名::役職::羽州探題) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// 大名で目的のIDの役職を持っている人
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// その役職を持っていれば、はく奪
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// 軍団で目的のIDの役職を持っている人
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// その役職を持っていれば、はく奪
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// 自分に対象の役職をつける。
			nb6daimyo[iDaimyoID].position = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// 大名自身なら、別処理
		if (nb6gundan[iGundanID].number == 1) {
			int iDaimyoID = nb6gundan[iGundanID].attach - 1;
			tryChangeDaimyoYakusyoku(iDaimyoID, iYakusyokuValue);
		}

		if (列挙::軍団::役職::無し <= iYakusyokuValue && iYakusyokuValue <= 列挙::軍団::役職::羽州探題) {

			// 大名で目的のIDの役職を持っている人
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// その役職を持っていれば、はく奪
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// 軍団で目的のIDの役職を持っている人
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// その役職を持っていれば、はく奪
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// 自分に対象の役職をつける。
			nb6gundan[iGundanID].position = iYakusyokuValue;

			return true;
		}
	}

	return false;
}
