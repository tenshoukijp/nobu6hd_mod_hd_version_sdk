#include "GameDataStruct.h"
#include "DijkstraCastle.h"

城情報型::城情報型(int i番号)
{
	iCastleID = i番号;
}

String^ 城情報型::城名::get() {
	return gcnew String(nb6castle[iCastleID].name);
}

void 城情報型::城名::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 8) {
		strcpy(nb6castle[iCastleID].name, native_value.c_str());
	}
}

String^ 城情報型::城称::get() {
	int iCastleType = nb6castle[iCastleID].title;
	return gcnew String(getCastleTypeName(iCastleType));
}

String^ 城情報型::城名称::get() {
	return 城名 + 城称;
}

int 城情報型::城主_武将番号::get() {
	int attr = nb6castle[iCastleID].master;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 城情報型::所属軍団番号::get() {
	int attr = nb6castle[iCastleID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}


List<int>^ 城情報型::麾下武将番号リスト::get() {
	List<int>^ list = gcnew List<int>();
	for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
		// 大名・軍団長・現役
		if (nb6bushouname[iBushouID].State <= 2) {
			if (nb6bushou[iBushouID].castle - 1 == iCastleID) {
				list->Add(iBushouID);
			}
		}
	}

	return list;
}

bool 城情報型::Is_軍団長本城::get() {
	if (nb6castle[iCastleID].honjo == 1 || nb6castle[iCastleID].honjo == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool 城情報型::Is_大名本城::get() {
	if (nb6castle[iCastleID].honjo == 1) {
		return true;
	}
	else {
		return false;
	}
}

int 城情報型::城郭::get() {
	return nb6castle[iCastleID].build;
}

void 城情報型::城郭::set(int value) {
	if (0 <= value && value <= 250) {
		nb6castle[iCastleID].build = value;
	}
}


int 城情報型::石高::get() {
	return nb6castle[iCastleID].grain;
}

void 城情報型::石高::set(int value) {
	if (0 <= value && value <= (LIMIT_BYTE_MAX * 10)) {
		// 必要な最大石高を割り出す。
		double need_kokudaka = value;
		need_kokudaka = need_kokudaka / 10.0;
		need_kokudaka = Math::Ceiling(need_kokudaka);
		need_kokudaka = need_kokudaka * 10;
		if (need_kokudaka > (LIMIT_BYTE_MAX * 10)) {
			need_kokudaka = (LIMIT_BYTE_MAX * 10);
		}

		if (nb6castlemax[iCastleID].maxgrain < need_kokudaka / 10 ) {
			// 必要な最大石高を増加
			nb6castlemax[iCastleID].maxgrain = byte(need_kokudaka / 10);
		}

		// 石高を設定
		nb6castle[iCastleID].grain = value;
	}
}

int 城情報型::最大石高::get() {
	return nb6castlemax[iCastleID].maxgrain * 10;
}

void 城情報型::最大石高::set(int value) {
	if (0 <= value && value <= (LIMIT_BYTE_MAX * 10)) {
		double need_kokudaka = value;
		need_kokudaka = need_kokudaka / 10.0;
		need_kokudaka = Math::Ceiling(need_kokudaka);
		need_kokudaka = need_kokudaka * 10;
		if (need_kokudaka > (LIMIT_BYTE_MAX * 10)) {
			need_kokudaka = (LIMIT_BYTE_MAX * 10);
		}
		nb6castlemax[iCastleID].maxgrain = byte(need_kokudaka / 10);

	}
}

int 城情報型::商業::get() {
	return nb6castle[iCastleID].town;
}

void 城情報型::商業::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		// 必要な最大石高を増加
		if (nb6castlemax[iCastleID].maxtown < value) {
			nb6castlemax[iCastleID].maxtown = value;
		}
		nb6castle[iCastleID].town = value;
	}
}

int 城情報型::最大商業::get() {
	return nb6castlemax[iCastleID].maxtown;
}

void 城情報型::最大商業::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].maxtown = value;
	}
}


int 城情報型::人口::get() {
	return nb6castle[iCastleID].population;
}

void 城情報型::人口::set(int value) {
	if (0 <= value && value <= 9999) {
		nb6castle[iCastleID].population = value;
	}
}

int 城情報型::民忠::get() {
	return nb6castle[iCastleID].loyal;
}

void 城情報型::民忠::set(int value) {
	if (0 <= value && value <= 100) {
		nb6castle[iCastleID].loyal = value;
	}
}

int 城情報型::徴兵可::get() {
	return nb6castle[iCastleID].soldier;
}

void 城情報型::徴兵可::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].soldier = value;
	}
}

int 城情報型::兵質::get() {
	return nb6castle[iCastleID].quality;
}

void 城情報型::兵質::set(int value) {
	if (列挙::城::兵質::悪 <= value && value <= 列挙::城::兵質::良) {
		nb6castle[iCastleID].quality = value;
	}
}

int 城情報型::兵士::get() {
	return getCastleHeisuCnt(iCastleID);
}


bool 城情報型::鍛冶::get() {
	return nb6castle[iCastleID].bSmith;
}

void 城情報型::鍛冶::set(bool value) {
	nb6castle[iCastleID].bSmith = value;
}

bool 城情報型::馬産地::get() {
	return nb6castle[iCastleID].bHorse;
}

void 城情報型::馬産地::set(bool value) {
	nb6castle[iCastleID].bHorse = value;
}

bool 城情報型::港::get() {
	return nb6castle[iCastleID].bPort;
}

void 城情報型::港::set(bool value) {
	nb6castle[iCastleID].bPort = value;
}

bool 城情報型::国際港::get() {
	return nb6castle[iCastleID].blPort;
}

void 城情報型::国際港::set(bool value) {
	nb6castle[iCastleID].blPort = value;
}

bool 城情報型::銀山::get() {
	return nb6castle[iCastleID].bSilver;
}

void 城情報型::銀山::set(bool value) {
	nb6castle[iCastleID].bSilver = value;
}

bool 城情報型::金山::get() {
	return nb6castle[iCastleID].bGold;
}

void 城情報型::金山::set(bool value) {
	nb6castle[iCastleID].bGold = value;
}

bool 城情報型::一揆扇動::get() {
	return nb6castle[iCastleID].bRevolt;
}

void 城情報型::一揆扇動::set(bool value) {
	nb6castle[iCastleID].bRevolt = value;
}

bool 城情報型::巨城::get() {
	return nb6castle[iCastleID].bLarge;
}

void 城情報型::巨城::set(bool value) {
	nb6castle[iCastleID].bLarge = value;
}

int 城情報型::城絵背景::get() {
	return nb6castle[iCastleID].bgback;
}

void 城情報型::城絵背景::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].bgback = value;
	}
}

int 城情報型::所属国番号::get() {

	int attr = nb6castlemax[iCastleID].chiiki;
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CHIMEI_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 城情報型::所属県番号::get() {

	int attr = getCastleTodouhukenNum(iCastleID);
	return attr;
}


城位置型^ 城情報型::位置::get() {
	城位置型^ pos = gcnew 城位置型();
	pos->Ｘ = nb6castlemax[iCastleID].x;
	pos->Ｙ = nb6castlemax[iCastleID].y;
	return pos;
}

void 城情報型::位置::set(城位置型^ value) {
	if (0 <= value->Ｘ && value->Ｘ <= LIMIT_BYTE_MAX &&
		0 <= value->Ｙ && value->Ｙ <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].x = value->Ｘ;
		nb6castlemax[iCastleID].y = value->Ｙ;
	}
}

城グリッド位置型^ 城情報型::グリッド位置::get() {
	GRID_POSITION native_grid = getCastlePosInMainGrid(iCastleID);
	城グリッド位置型^ manage_grid = gcnew 城グリッド位置型();
	manage_grid->Ｘ = native_grid.x;
	manage_grid->Ｙ = native_grid.y;
	return manage_grid;
}

bool 城情報型::Is_隣接(int 城Ｂ番号) {
	vector<int> list = getRinsetsuCastles(iCastleID);
	for each (int iCID in list) {
		if (iCID == 城Ｂ番号) {
			return true;
		}
	}
	return false;
}

List<int>^ 城情報型::隣接城番号リスト::get() {
	vector<int> list = getRinsetsuCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}

List<int>^ 城情報型::経路隣接城番号リスト::get() {
	vector<int> list = getWayConnectCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}



城リスト情報型::城リスト情報型() {
	配列 = gcnew List<城情報型^>();
	配列->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_CASTLE_NUM; i++)
	{
		配列->Add(gcnew 城情報型(i));
	}

}



bool isAllCastleNodeAndEdge = false; // 経路を全城ベースで構築しているかどうかのフラグ

List<int>^ 城リスト情報型::Get_経路上の城番号リスト(int 開始城番号, int 目的城番号) {

	List<int>^ m_list = gcnew List<int>();

	// 開始城も目的城も番号が範囲内に入っている。
	if (0 <= 開始城番号 && 開始城番号 < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= 目的城番号 && 目的城番号 < GAMEDATASTRUCT_CASTLE_NUM) {

		// 経路構築が全城ではない場合
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // 全城で経路を構築
			isAllCastleNodeAndEdge = true; // 全城で経路を構築しているというフラグを立てる。
		}

		// スタートノードの設定
		SetStartCastleNode(開始城番号);

		// ゴールノードの設定
		SetGoalCastleNode(目的城番号);

		// スタート→ゴールへのルートを計算し、経路となった城IDのリストを返す。
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}
	}

	return m_list;

}

List<int>^ 城リスト情報型::Get_経路上の城番号リスト(int 開始城番号, int 目的城番号, List<int>^ 経路構築除去城番号リスト) {

	List<int>^ m_list = gcnew List<int>();

	// 開始城も目的城も番号が範囲内に入っている。
	if (0 <= 開始城番号 && 開始城番号 < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= 目的城番号 && 目的城番号 < GAMEDATASTRUCT_CASTLE_NUM) {

		// 経路構築が全城ではない場合
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // 全城で経路を構築
			isAllCastleNodeAndEdge = true; // 全城で経路を構築しているというフラグを立てる。
		}

		// スタートノードの設定
		SetStartCastleNode(開始城番号);

		// ゴールノードの設定
		SetGoalCastleNode(目的城番号);

		// 除去リスト
		for each (int iCID in 経路構築除去城番号リスト) {
			if (0 <= iCID && iCID < GAMEDATASTRUCT_CASTLE_NUM) {
				// 対象の城を経路探索から削除する。
				RemoveCastleNode(iCID);
				isAllCastleNodeAndEdge = false; // 全城で経路を構築しているというフラグは成立しなくなる。
			}
		}

		// スタート→ゴールへのルートを計算し、経路となった城IDのリストを返す。
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}

		// 経路構築が全城ではない場合
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // 全城で経路を構築
			isAllCastleNodeAndEdge = true; // 全城で経路を構築しているというフラグを立てる。
		}

	}

	return m_list;

}

城位置型::城位置型(int Ｘ, int Ｙ) {
	this->Ｘ = Ｘ;
	this->Ｙ = Ｙ;
}

城グリッド位置型::城グリッド位置型(int Ｘ, int Ｙ) {
	this->Ｘ = Ｘ;
	this->Ｙ = Ｙ;
}