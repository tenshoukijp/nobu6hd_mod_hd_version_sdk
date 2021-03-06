
#include "GameDataStruct.h"



大名情報型::大名情報型(int i番号) {
	iDaimyoID = i番号;
}

int 大名情報型::大名_武将番号::get() {
	int attr = nb6daimyo[iDaimyoID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 大名情報型::居城番号::get() {
	int attr = nb6daimyo[iDaimyoID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 大名情報型::敵対大名番号::get() {
	int attr = nb6daimyo[iDaimyoID].hostile;
	// 0xFFがMAXだが他と合わせる
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void 大名情報型::敵対大名番号::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFFがMAXで敵対なし
		nb6daimyo[iDaimyoID].hostile = 0xFF;
	}
}

int 大名情報型::友好大名番号::get() {
	int attr = nb6daimyo[iDaimyoID].friendship;
	// 0xFFがMAXだが他と合わせる
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void 大名情報型::友好大名番号::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFFがMAXで敵対なし
		nb6daimyo[iDaimyoID].friendship = 0xFF;
	}
}

int 大名情報型::家紋番号::get() {
	return nb6daimyo[iDaimyoID].symbol;
}

void 大名情報型::家紋番号::set(int value) {
	nb6daimyo[iDaimyoID].symbol = value;
}

int 大名情報型::朝廷友好度::get() {
	return nb6daimyo[iDaimyoID].tyotei;
}

void 大名情報型::朝廷友好度::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].tyotei = value;
	}
}

int 大名情報型::御用商人::get() {
	return nb6daimyo[iDaimyoID].merchantHuman;
}

void 大名情報型::御用商人::set(int value) {
	if (0 <= value && value <= 列挙::大名::御用商人::灰屋紹由) {
		nb6daimyo[iDaimyoID].merchantHuman = value;
	}
}

int 大名情報型::商人友好度::get() {
	return nb6daimyo[iDaimyoID].merchant;
}

void 大名情報型::商人友好度::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].merchant = value;
	}
}

bool 大名情報型::商人不在::get() {
	return nb6daimyo[iDaimyoID].bMerchantAngry;
}

void 大名情報型::商人不在::set(bool value) {
	nb6daimyo[iDaimyoID].bMerchantAngry = value;
}


bool 大名情報型::布教済::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void 大名情報型::布教済::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

bool 大名情報型::評定済::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void 大名情報型::評定済::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

int 大名情報型::役職::get() {
	return getNormalizedDaimyoPosition(iDaimyoID);
}

void 大名情報型::役職::set(int value) {
	if (列挙::大名::役職::無し <= value && value <= 列挙::大名::役職::羽州探題) {
		tryChangeDaimyoYakusyoku(iDaimyoID, value);
	}
}

int 大名情報型::Get_友好関係(int 大名番号) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		return getYuukouKankei(iDaimyoID, 大名番号);
	}
	return 0;
}

void 大名情報型::Set_友好関係(int 大名番号, int 友好値) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		setYuukouKankei(iDaimyoID, 大名番号, 友好値);
	}
}

bool 大名情報型::Is_同盟関係(int 大名番号) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isDoumeiKankei(iDaimyoID, 大名番号)) {
			return true;
		}
	}
	return false;
}

void 大名情報型::Set_同盟関係(int 大名番号) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		setDoumeiKankei(iDaimyoID, 大名番号);
	}
}

bool 大名情報型::Is_婚姻関係(int 大名番号) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isKoninKankei(iDaimyoID, 大名番号)) {
			return true;
		}
	}
	return false;
}

void 大名情報型::Set_婚姻関係(int 大名番号) {
	if (0 <= 大名番号 && 大名番号 < GAMEDATASTRUCT_DAIMYO_NUM) {
		setKoninKankei(iDaimyoID, 大名番号);
	}
}

List<int>^ 大名情報型::麾下軍団番号リスト::get() {
	vector<int> list = getGovernedGundanList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}

	return m_list;
}

List<int>^ 大名情報型::麾下城番号リスト::get() {
	List<int>^ m_list = gcnew List<int>();
	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		int iGundanID = nb6castle[iCastleID].attach - 1;
		if ( 0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				m_list->Add(iCastleID);
			}
		}
	}
	return m_list;
}

List<int>^ 大名情報型::割当済軍団任命番号リスト::get() {
	vector<int> list = getGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

List<int>^ 大名情報型::未割当軍団任命番号リスト::get() {
	vector<int> list = getNotGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

bool 大名情報型::Is_プレイヤ担当大名::get() {
	return isPlayerDaimyo(iDaimyoID);
}


大名リスト情報型::大名リスト情報型() {
	配列 = gcnew List<大名情報型^>();
	配列->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_DAIMYO_NUM; i++)
	{
		配列->Add(gcnew 大名情報型(i));
	}

	戦争 = gcnew 戦争大名リスト情報型();
}

List<int>^ 大名リスト情報型::有効大名番号リスト::get() {
	// 全有効大名のリストを返す。ターン大名自身も入ってるので注意。
	vector<int> list = getDaimyoList(TRUE);

	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;

}



List<int>^ 大名リスト情報型::戦争大名リスト情報型::参戦大名番号リスト::get() {
	vector<int> list = GetCurWarJointDaimyoIDList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;
}




