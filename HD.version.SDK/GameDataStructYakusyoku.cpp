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

// ‘å–¼ID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
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

// ŒR’cID‚©‚ç³‹K‰»‚³‚ê‚½–ğEID‚ğ“¾‚é
int getNormalizedGundanPosition(int iGundanID) {
	return nb6gundan[iGundanID].position;
}

bool tryChangeDaimyoYakusyoku(int iDaimyoID, int iYakusyokuValue) {
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		if (—ñ‹“::‘å–¼::–ğE::–³‚µ <= iYakusyokuValue && iYakusyokuValue <= —ñ‹“::‘å–¼::–ğE::‰HB’T‘è) {

			int DenormalizeyakusyokuValue = DeNormalizeDaimyoYakusyokuValue(iYakusyokuValue);

			// ‘å–¼‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// ŒR’c‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// ©•ª‚É‘ÎÛ‚Ì–ğE‚ğ‚Â‚¯‚éB
			nb6daimyo[iDaimyoID].position = DenormalizeyakusyokuValue;

			return true;
		}
	}

	return false;
}


bool tryChangeGundanYakusyoku(int iGundanID, int iYakusyokuValue) {

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// ‘å–¼©g‚È‚çA•Êˆ—
		if (nb6gundan[iGundanID].number == 1) {
			int iDaimyoID = nb6gundan[iGundanID].attach - 1;
			tryChangeDaimyoYakusyoku(iDaimyoID, iYakusyokuValue);
		}

		if (—ñ‹“::ŒR’c::–ğE::–³‚µ <= iYakusyokuValue && iYakusyokuValue <= —ñ‹“::ŒR’c::–ğE::‰HB’T‘è) {

			// ‘å–¼‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iDID = 0; iDID < GAMEDATASTRUCT_DAIMYO_NUM; iDID++) {
				int iDaimyoYakusyokuID = getNormalizedDaimyoPosition(iDID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iDaimyoYakusyokuID == iYakusyokuValue) {
					nb6daimyo[iDID].position = 0;
				}
			}

			// ŒR’c‚Å–Ú“I‚ÌID‚Ì–ğE‚ğ‚Á‚Ä‚¢‚él
			for (int iGID = 0; iGID < GAMEDATASTRUCT_GUNDAN_NUM; iGID++) {
				int iGundanYakusyokuID = getNormalizedGundanPosition(iGID);
				// ‚»‚Ì–ğE‚ğ‚Á‚Ä‚¢‚ê‚ÎA‚Í‚­’D
				if (iGundanYakusyokuID == iYakusyokuValue) {
					nb6gundan[iGID].position = 0;
				}
			}

			// ©•ª‚É‘ÎÛ‚Ì–ğE‚ğ‚Â‚¯‚éB
			nb6gundan[iGundanID].position = iYakusyokuValue;

			return true;
		}
	}

	return false;
}
