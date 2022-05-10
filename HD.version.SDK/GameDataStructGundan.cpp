#include <algorithm>
#include "GameDataStruct.h"

using namespace std;


// ‚Æ‚ ‚é‘å–¼¨—Í‚Ì“¡ŒR’c”Ô†ƒŠƒXƒg‚ğ“¾‚éB
vector<int> getGovernedGundanList(int iDaimyoID) {
	// ‚»‚êˆÈŠO‚Í‰½‚à“ü‚ê‚¸‚É•Ô‚·B
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(iGundanID);
			}
		}
	}

	return list;
}

// ŒR’c‚ÉŠ‘®‚·‚é•«ƒŠƒXƒg‚ğ“¾‚é
vector<int> getGundanBushouList(int iGundanID) {
	// ‚»‚êˆÈŠO‚Í‰½‚à“ü‚ê‚¸‚É•Ô‚·B
	vector<int> list;

	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // ‘å–¼, ŒR’c’·, Œ»–ğ ‚ÅƒJƒEƒ“ƒg
				list.push_back(i);
			}
		}
	}
	return list;
}

/// Œ»İ(‚»‚ÌuŠÔ)A“VãÄ‹L‚É‘¶İ‚·‚éŒR’c‚ÌuŒR’c”Ô†y”z—ñ—pzv‚ğƒŠƒXƒg‚Å“¾‚éB
vector<int> getValidGundanList() {
	vector<int> list;

	// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
	for (int iGundanID = 0; iGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
		if (nb6gundan[iGundanID].leader != 0xFFFF) {
			list.push_back(iGundanID);
		}
	}

	return list;
}


// ŒR’c‚ÉŠ‘®‚·‚é•º”‚ğ“¾‚é
int getGundanHeisuCnt(int iGundanID) {
	int iSoldierCnt = 0;
	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // ‘å–¼, ŒR’c’·, Œ»–ğ ‚ÅƒJƒEƒ“ƒg
				iSoldierCnt += nb6bushou[i].soldier;
			}
		}
	}
	return iSoldierCnt;
}

// ‚Æ‚ ‚é‘å–¼¨—Í‚Ì“¡ŒR’cŠ„‚è‚ ‚Ä”Ô†ƒŠƒXƒg‚ğ“¾‚éB
vector<int> getGovernedGundanWariateNumList(int iDaimyoID) {
	// ‚»‚êˆÈŠO‚Í‰½‚à“ü‚ê‚¸‚É•Ô‚·B
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(nb6gundan[iGundanID].number);
			}
		}
	}

	std::sort(list.begin(), list.end());//¸‡ƒ\[ƒg

	return list;
}



// ‚Æ‚ ‚é‘å–¼”z‰º‚ÌŒR’c‰º‚É‚ ‚éŒR’cu–¢vŠ„“–”Ô†‚ÌƒŠƒXƒg‚ğ“¾‚éB
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID) {

	// Š„‚è“–‚Ä‚ç‚ê‚Ä‚é‚à‚Ì‚ÉA‚P‚ğ“ü‚ê‚é
	int wariate_array[8] = { 0,0,0,0,0,0,0,0 };

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// ŠY“–‚Ì‘å–¼‚h‚c‚É‘®‚·‚éŒR’c‚ğƒŠƒXƒg‚É‰Á‚¦‚é
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				int g = nb6gundan[iGundanID].number;
				if (1 <= g && g <= 8) {
					// Š„‚è“–‚Ä‚ç‚ê‚Ä‚é‚à‚Ì‚ÉA‚P‚ğ“ü‚ê‚é
					wariate_array[g - 1] = 1;
				}
			}
		}
	}

	vector<int> list;
	for (int ix = 0; ix<8; ix++) {
		if (wariate_array[ix] == 0) { // ŒR’cŠ„“–‚ª‚È‚¯‚ê‚Î
			list.push_back(ix + 1);
		}
	}

	std::sort(list.begin(), list.end());//¸‡ƒ\[ƒg

	return list;
}

// ŒR’c”C–½”Ô†‚Ì•ÏX(“ü‘Ö)‚ğ‚İ‚éB¸”s‚·‚ê‚Îfalse
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum) {

	// ‘æ‚PŒR’c‚Í‘å–¼©gB•ÏX‚Í–³—B
	if (nb6gundan[iGundanID].number == 1) {
		return false;
	}

	if (!(1 <= iNewWariateNum && iNewWariateNum <= 8) ) {
		return false;
	}

	// ©•ª‚ÌŒR’c‚Ì‘å–¼‚ÌID
	int iDaimyoID = nb6gundan[iGundanID].attach - 1;

	// ‘å–¼Ÿ€‰º‚Å‹ó‚«ƒXƒƒbƒg‚Æ‚È‚Á‚Ä‚¢‚é”C–½”Ô†ˆê——
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		vector<int> sameDaimyoGundanList = getGovernedGundanList(iDaimyoID);
		int iOldNinmeiNum = nb6gundan[iGundanID].number; // ¡‚Ü‚Å‚Ì”C–½”Ô†

														 // •ÊŒR’c‚ªw’è‚ÌŒR’c‚ğ—˜—p‚µ‚Ä‚¢‚é‚È‚ç‚ÎA©•ª‚ÌŒR’c”Ô†‚ğ‚»‚ÌŒR’c‚É·‚µã‚°‚éB
		for each (int iGID in sameDaimyoGundanList) {
			// ‚·‚Å‚É•ÊŒR’c‚Å—˜—p‚³‚ê‚Ä‚¢‚é‚È‚ç‚Î
			if (nb6gundan[iGID].number == iNewWariateNum) {
				nb6gundan[iGID].number = iOldNinmeiNum;
				break;
			}
		}

		// ©•ª‚Íw’è‚ÌŒR’c”Ô†‚Æ‚È‚éB
		nb6gundan[iGundanID].number = iNewWariateNum;

		return true;
	}

	return false;

}


// w’è‚ÌŒR’c‚ÌŠ‘®‚·‚é‘å–¼‚ğ¨—Í‚ğ‰z‚¦‚ÄA•ÏX‚·‚éB
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID) {

	// V‘å–¼‚ª³“–‚Å‚Í‚È‚¢B
	if (!(0 <= iNewDaimyoID && iNewDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM)) {
		return false;
	}

	// ŒR’c‚ª‘S•”–„‚Ü‚Á‚Ä‚¢‚é‚È‚ç‚ÎA
	vector<int> glist = getGovernedGundanWariateNumList(iNewDaimyoID);
	if (glist.size() == 8) { // ŒR’c‚Í‘S•”–„‚Ü‚Á‚Ä‚¢‚é
							 // ‰½‚à‚Å‚«‚È‚¢
		return false;
	}

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// w’è‚ÌŒR’c‚ªŒ»İŠ‘®‚µ‚Ä‚¢‚é‘å–¼”Ô†‚ğ‹‚ß‚é
		int iDaimyoID = nb6gundan[iGundanID].attach - 1;
		// VŠ‘®æ‚Ì‘å–¼‚ªA¡Š‘®‚µ‚Ä‚¢‚é‘å–¼‚Å‚ ‚ê‚ÎA‰½‚à‚·‚é‚±‚Æ‚Í‚È‚¢B
		if (iDaimyoID == iNewDaimyoID) {
			return true;
		}

		// ŒR’cŠ„‚è“–‚Ä”Ô†‚ª‚P”Ô‚Í‘å–¼©gB‚±‚ê‚ÍŒÅ’èB‚±‚Ìê‡A‰½‚à‚¹‚¸¸”s‚Æ‚·‚éB
		if (nb6gundan[iGundanID].number == 1) {
			return false;
		}

		// Œ»İAV‘å–¼‚ÉŠ‘®‚µ‚Ä‚¢‚ÄAnext‚ª0xFFFF‚É‚È‚Á‚Ä‚¢‚éŒR’c‚ªA‚Ô‚ç‰º‚ª‚é‚×‚«ƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚¾B
		// ‚Ô‚ç‰º‚ª‚é‚±‚Æ‚ªo—ˆ‚é‚©A–‘O‚Éƒ`ƒFƒbƒN‚µ‚Ä‚¨‚­B
		int iLinkEndGundanID = -1;
		for (int iCurGundanID = 0; iCurGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iCurGundanID++) {
			// 
			int iCurDaimyoID = nb6gundan[iCurGundanID].attach - 1;

			// w’è‚ÌV‘å–¼‚ÉŠ‘®‚µ‚Ä‚¢‚é‚È‚ç‚ÎA
			if (iCurDaimyoID == iNewDaimyoID) {
				// Ÿ‚ÌŒR’c‚ª–³‚¢‚Ì‚Å‚ ‚ê‚ÎA‚»‚¢‚Â‚ªÅIŒR’c”Ô†
				if (nb6gundan[iCurGundanID].next == 0xFFFF) {
					iLinkEndGundanID = iCurGundanID + 1;
				}

			}

		}

		// ‚»‚ê‚ª”ÍˆÍ‚É“ü‚Á‚Ä‚¢‚È‚¢‚È‚ç‚ÎAV‘å–¼‚ÌŒR’cƒŠƒ“ƒNƒŠƒXƒg‚ÍA‰ü‘¢‚©‰½‚©‚µ‚ç‚È‚¢‚ªî•ñ‚ª‰ó‚ê‚Ä‚¢‚éB
		// ˆ—I—¹
		if (!(0 < iLinkEndGundanID && iLinkEndGundanID <= GAMEDATASTRUCT_GUNDAN_NUM)) {
			return false;
		}

		/* @©ŒR’c
		«
		›-œ-›-›

		‚Æ‚¢‚¤‚Ì‚ğ

		›-›-›

		‚Æ‚·‚éB
		*/

		int iPrevID = nb6gundan[iGundanID].prev;
		int iNextID = nb6gundan[iGundanID].next;

		// ©•ª‚Ìprev‚Í—LŒø‚ÈŒR’c‚¾B
		if (0 < iPrevID && iPrevID <= GAMEDATASTRUCT_GUNDAN_NUM) {

			// ©•ª‚ªæ“ª‚Å‚Í‚È‚¢ŒR’c‚ÅA
			// ‚P‚Â‘O‚ÌŒR’c‚ÌŸ‚ÌƒŠƒ“ƒNæ‚ª©ŒR’c‚Ìê‡
			if (iPrevID != 0xFFFF && nb6gundan[(iPrevID - 1)].next == iGundanID + 1) {
				// ©ŒR’c‚Å‚Í‚È‚­AŸ‚ÌŒR’c‚Ö‚ÆŒq‚¬‚©‚¦‚éB
				nb6gundan[(iPrevID - 1)].next = iNextID;
			}
		}

		// ©•ª‚Ìnext‚Í—LŒø‚ÈŒR’c‚¾B
		if (0 < iNextID && iNextID <= GAMEDATASTRUCT_GUNDAN_NUM) {
			// ‚P‚ÂŒã‚ÌŒR’c‚Ì‘O‚ÌƒŠƒ“ƒNæ‚ª©ŒR’c‚Ìê‡
			if (iNextID != 0xFFFF && nb6gundan[(iNextID - 1)].prev == iGundanID + 1) {
				// ©ŒR’c‚Å‚Í‚È‚­A‘O‚ÌŒR’c‚Ö‚ÆŒq‚¬‚©‚¦‚éB
				nb6gundan[(iNextID - 1)].prev = iPrevID;
			}
		}


		/* @

		›-›

		‚Æ‚¢‚¤‚Ì‚ğ

		›-›-œ

		‚Æ‚·‚éB
		*/



		nb6gundan[iLinkEndGundanID - 1].next = iGundanID + 1; // ƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚ÌŒR’c‚Ìnext‚ğ©ŒR’c‚É

		nb6gundan[iGundanID].prev = iLinkEndGundanID; // ©ŒR’c‚Ì‘O‚ÌŒR’c‚ÍAŒR’c‚ÌƒŠƒ“ƒNƒŠƒXƒg‚ÌÅŒã‚ÌŒR’c

													  // ©ŒR’c‚ÍAŒR’cƒŠƒXƒg‚Ìˆê”ÔÅŒã‚É‚­‚Á‚Â‚­B©ŒR’c‚Ìnext‚Í‹‚È‚¢
		nb6gundan[iGundanID].next = 0xFFFF; // 

											// ƒƒ‚ƒŠ‘‚«Š·‚¦
		{
			nb6gundan[iGundanID].number = 8; // Œ³‚Ì”Ô†‚Æ‚¢‚¤‚í‚¯‚É‚Í‚¢‚©‚È‚¢‚Ì‚ÅA–œ‚ªˆê‚Ì‚½‚ß‚ÉA‚Æ‚è‚ ‚¦‚¸AÅ‚à‚‚¢Šm—¦‚Å‹ó‚¢‚Ä‚éƒZ[ƒt‚È‚à‚Ì‚ğæ‚é

			vector<int> milist = getNotGovernedGundanWariateNumList(iNewDaimyoID);
			if (milist.size() > 0) {
				nb6gundan[iGundanID].number = milist[0]; // ‹ó”Ô†‚ÌÅ‰‚Ì‚à‚Ì‚ğ•ú‚è‚Ş
			}

			nb6gundan[iGundanID].attach = iNewDaimyoID + 1;
		}

		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
			// w’è‚ÌŒR’c‚ÉŠ‘®‚µ‚Ä‚¢‚é•«‚ÍA‘S‚ÄAV‘å–¼‚ÉŠ‘®‚ğ•ÏX‚·‚éB
			if (nb6bushou[iBushouID].gundan == iGundanID + 1) {
				nb6bushou[iBushouID].attach = iNewDaimyoID + 1;
				nb6bushou[iBushouID].work = 0; // mŠ¯”N”ƒŠƒZƒbƒg
				nb6bushou[iBushouID].rise = 0xFFFF; // “à‰æƒŠƒZƒbƒg
				nb6bushou[iBushouID].bRise = 0; // “à‰ó‘Ô‚È‚µ
				nb6bushou[iBushouID].grudge = 0; // ˆâ¦‚È‚µ
			}
		}

		return true;

	}

	return false;
}
