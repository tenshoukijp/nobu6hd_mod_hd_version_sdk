#include "GameDataStruct.h"
#include "DijkstraCastle.h"

éî•ñŒ^::éî•ñŒ^(int i”Ô†)
{
	iCastleID = i”Ô†;
}

String^ éî•ñŒ^::é–¼::get() {
	return gcnew String(nb6castle[iCastleID].name);
}

void éî•ñŒ^::é–¼::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 8) {
		strcpy(nb6castle[iCastleID].name, native_value.c_str());
	}
}

String^ éî•ñŒ^::éÌ::get() {
	int iCastleType = nb6castle[iCastleID].title;
	return gcnew String(getCastleTypeName(iCastleType));
}

String^ éî•ñŒ^::é–¼Ì::get() {
	return é–¼ + éÌ;
}

int éî•ñŒ^::éå_•«”Ô†::get() {
	int attr = nb6castle[iCastleID].master;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int éî•ñŒ^::Š‘®ŒR’c”Ô†::get() {
	int attr = nb6castle[iCastleID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}


List<int>^ éî•ñŒ^::Ÿ€‰º•«”Ô†ƒŠƒXƒg::get() {
	List<int>^ list = gcnew List<int>();
	for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
		// ‘å–¼EŒR’c’·EŒ»–ğ
		if (nb6bushouname[iBushouID].State <= 2) {
			if (nb6bushou[iBushouID].castle - 1 == iCastleID) {
				list->Add(iBushouID);
			}
		}
	}

	return list;
}

bool éî•ñŒ^::Is_ŒR’c’·–{é::get() {
	if (nb6castle[iCastleID].honjo == 1 || nb6castle[iCastleID].honjo == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool éî•ñŒ^::Is_‘å–¼–{é::get() {
	if (nb6castle[iCastleID].honjo == 1) {
		return true;
	}
	else {
		return false;
	}
}

int éî•ñŒ^::éŠs::get() {
	return nb6castle[iCastleID].build;
}

void éî•ñŒ^::éŠs::set(int value) {
	if (0 <= value && value <= 250) {
		nb6castle[iCastleID].build = value;
	}
}


int éî•ñŒ^::Î‚::get() {
	return nb6castle[iCastleID].grain;
}

void éî•ñŒ^::Î‚::set(int value) {
	if (0 <= value && value <= (LIMIT_BYTE_MAX * 10)) {
		// •K—v‚ÈÅ‘åÎ‚‚ğŠ„‚èo‚·B
		double need_kokudaka = value;
		need_kokudaka = need_kokudaka / 10.0;
		need_kokudaka = Math::Ceiling(need_kokudaka);
		need_kokudaka = need_kokudaka * 10;
		if (need_kokudaka > (LIMIT_BYTE_MAX * 10)) {
			need_kokudaka = (LIMIT_BYTE_MAX * 10);
		}

		if (nb6castlemax[iCastleID].maxgrain < need_kokudaka / 10 ) {
			// •K—v‚ÈÅ‘åÎ‚‚ğ‘‰Á
			nb6castlemax[iCastleID].maxgrain = byte(need_kokudaka / 10);
		}

		// Î‚‚ğİ’è
		nb6castle[iCastleID].grain = value;
	}
}

int éî•ñŒ^::Å‘åÎ‚::get() {
	return nb6castlemax[iCastleID].maxgrain * 10;
}

void éî•ñŒ^::Å‘åÎ‚::set(int value) {
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

int éî•ñŒ^::¤‹Æ::get() {
	return nb6castle[iCastleID].town;
}

void éî•ñŒ^::¤‹Æ::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		// •K—v‚ÈÅ‘åÎ‚‚ğ‘‰Á
		if (nb6castlemax[iCastleID].maxtown < value) {
			nb6castlemax[iCastleID].maxtown = value;
		}
		nb6castle[iCastleID].town = value;
	}
}

int éî•ñŒ^::Å‘å¤‹Æ::get() {
	return nb6castlemax[iCastleID].maxtown;
}

void éî•ñŒ^::Å‘å¤‹Æ::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].maxtown = value;
	}
}


int éî•ñŒ^::lŒû::get() {
	return nb6castle[iCastleID].population;
}

void éî•ñŒ^::lŒû::set(int value) {
	if (0 <= value && value <= 9999) {
		nb6castle[iCastleID].population = value;
	}
}

int éî•ñŒ^::–¯’‰::get() {
	return nb6castle[iCastleID].loyal;
}

void éî•ñŒ^::–¯’‰::set(int value) {
	if (0 <= value && value <= 100) {
		nb6castle[iCastleID].loyal = value;
	}
}

int éî•ñŒ^::’¥•º‰Â::get() {
	return nb6castle[iCastleID].soldier;
}

void éî•ñŒ^::’¥•º‰Â::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].soldier = value;
	}
}

int éî•ñŒ^::•º¿::get() {
	return nb6castle[iCastleID].quality;
}

void éî•ñŒ^::•º¿::set(int value) {
	if (—ñ‹“::é::•º¿::ˆ« <= value && value <= —ñ‹“::é::•º¿::—Ç) {
		nb6castle[iCastleID].quality = value;
	}
}

int éî•ñŒ^::•ºm::get() {
	return getCastleHeisuCnt(iCastleID);
}


bool éî•ñŒ^::’b–è::get() {
	return nb6castle[iCastleID].bSmith;
}

void éî•ñŒ^::’b–è::set(bool value) {
	nb6castle[iCastleID].bSmith = value;
}

bool éî•ñŒ^::”nY’n::get() {
	return nb6castle[iCastleID].bHorse;
}

void éî•ñŒ^::”nY’n::set(bool value) {
	nb6castle[iCastleID].bHorse = value;
}

bool éî•ñŒ^::`::get() {
	return nb6castle[iCastleID].bPort;
}

void éî•ñŒ^::`::set(bool value) {
	nb6castle[iCastleID].bPort = value;
}

bool éî•ñŒ^::‘Û`::get() {
	return nb6castle[iCastleID].blPort;
}

void éî•ñŒ^::‘Û`::set(bool value) {
	nb6castle[iCastleID].blPort = value;
}

bool éî•ñŒ^::‹âR::get() {
	return nb6castle[iCastleID].bSilver;
}

void éî•ñŒ^::‹âR::set(bool value) {
	nb6castle[iCastleID].bSilver = value;
}

bool éî•ñŒ^::‹àR::get() {
	return nb6castle[iCastleID].bGold;
}

void éî•ñŒ^::‹àR::set(bool value) {
	nb6castle[iCastleID].bGold = value;
}

bool éî•ñŒ^::ˆê„î“®::get() {
	return nb6castle[iCastleID].bRevolt;
}

void éî•ñŒ^::ˆê„î“®::set(bool value) {
	nb6castle[iCastleID].bRevolt = value;
}

bool éî•ñŒ^::‹é::get() {
	return nb6castle[iCastleID].bLarge;
}

void éî•ñŒ^::‹é::set(bool value) {
	nb6castle[iCastleID].bLarge = value;
}

int éî•ñŒ^::éŠG”wŒi::get() {
	return nb6castle[iCastleID].bgback;
}

void éî•ñŒ^::éŠG”wŒi::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].bgback = value;
	}
}

int éî•ñŒ^::Š‘®‘”Ô†::get() {

	int attr = nb6castlemax[iCastleID].chiiki;
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CHIMEI_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int éî•ñŒ^::Š‘®Œ§”Ô†::get() {

	int attr = getCastleTodouhukenNum(iCastleID);
	return attr;
}


éˆÊ’uŒ^^ éî•ñŒ^::ˆÊ’u::get() {
	éˆÊ’uŒ^^ pos = gcnew éˆÊ’uŒ^();
	pos->‚w = nb6castlemax[iCastleID].x;
	pos->‚x = nb6castlemax[iCastleID].y;
	return pos;
}

void éî•ñŒ^::ˆÊ’u::set(éˆÊ’uŒ^^ value) {
	if (0 <= value->‚w && value->‚w <= LIMIT_BYTE_MAX &&
		0 <= value->‚x && value->‚x <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].x = value->‚w;
		nb6castlemax[iCastleID].y = value->‚x;
	}
}

éƒOƒŠƒbƒhˆÊ’uŒ^^ éî•ñŒ^::ƒOƒŠƒbƒhˆÊ’u::get() {
	GRID_POSITION native_grid = getCastlePosInMainGrid(iCastleID);
	éƒOƒŠƒbƒhˆÊ’uŒ^^ manage_grid = gcnew éƒOƒŠƒbƒhˆÊ’uŒ^();
	manage_grid->‚w = native_grid.x;
	manage_grid->‚x = native_grid.y;
	return manage_grid;
}

bool éî•ñŒ^::Is_—×Ú(int é‚a”Ô†) {
	vector<int> list = getRinsetsuCastles(iCastleID);
	for each (int iCID in list) {
		if (iCID == é‚a”Ô†) {
			return true;
		}
	}
	return false;
}

List<int>^ éî•ñŒ^::—×Úé”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getRinsetsuCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}

List<int>^ éî•ñŒ^::Œo˜H—×Úé”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getWayConnectCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}



éƒŠƒXƒgî•ñŒ^::éƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<éî•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_CASTLE_NUM; i++)
	{
		”z—ñ->Add(gcnew éî•ñŒ^(i));
	}

}



bool isAllCastleNodeAndEdge = false; // Œo˜H‚ğ‘Séƒx[ƒX‚Å\’z‚µ‚Ä‚¢‚é‚©‚Ç‚¤‚©‚Ìƒtƒ‰ƒO

List<int>^ éƒŠƒXƒgî•ñŒ^::Get_Œo˜Hã‚Ìé”Ô†ƒŠƒXƒg(int ŠJné”Ô†, int –Ú“Ié”Ô†) {

	List<int>^ m_list = gcnew List<int>();

	// ŠJné‚à–Ú“Ié‚à”Ô†‚ª”ÍˆÍ“à‚É“ü‚Á‚Ä‚¢‚éB
	if (0 <= ŠJné”Ô† && ŠJné”Ô† < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= –Ú“Ié”Ô† && –Ú“Ié”Ô† < GAMEDATASTRUCT_CASTLE_NUM) {

		// Œo˜H\’z‚ª‘Sé‚Å‚Í‚È‚¢ê‡
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // ‘Sé‚ÅŒo˜H‚ğ\’z
			isAllCastleNodeAndEdge = true; // ‘Sé‚ÅŒo˜H‚ğ\’z‚µ‚Ä‚¢‚é‚Æ‚¢‚¤ƒtƒ‰ƒO‚ğ—§‚Ä‚éB
		}

		// ƒXƒ^[ƒgƒm[ƒh‚Ìİ’è
		SetStartCastleNode(ŠJné”Ô†);

		// ƒS[ƒ‹ƒm[ƒh‚Ìİ’è
		SetGoalCastleNode(–Ú“Ié”Ô†);

		// ƒXƒ^[ƒg¨ƒS[ƒ‹‚Ö‚Ìƒ‹[ƒg‚ğŒvZ‚µAŒo˜H‚Æ‚È‚Á‚½éID‚ÌƒŠƒXƒg‚ğ•Ô‚·B
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}
	}

	return m_list;

}

List<int>^ éƒŠƒXƒgî•ñŒ^::Get_Œo˜Hã‚Ìé”Ô†ƒŠƒXƒg(int ŠJné”Ô†, int –Ú“Ié”Ô†, List<int>^ Œo˜H\’zœ‹é”Ô†ƒŠƒXƒg) {

	List<int>^ m_list = gcnew List<int>();

	// ŠJné‚à–Ú“Ié‚à”Ô†‚ª”ÍˆÍ“à‚É“ü‚Á‚Ä‚¢‚éB
	if (0 <= ŠJné”Ô† && ŠJné”Ô† < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= –Ú“Ié”Ô† && –Ú“Ié”Ô† < GAMEDATASTRUCT_CASTLE_NUM) {

		// Œo˜H\’z‚ª‘Sé‚Å‚Í‚È‚¢ê‡
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // ‘Sé‚ÅŒo˜H‚ğ\’z
			isAllCastleNodeAndEdge = true; // ‘Sé‚ÅŒo˜H‚ğ\’z‚µ‚Ä‚¢‚é‚Æ‚¢‚¤ƒtƒ‰ƒO‚ğ—§‚Ä‚éB
		}

		// ƒXƒ^[ƒgƒm[ƒh‚Ìİ’è
		SetStartCastleNode(ŠJné”Ô†);

		// ƒS[ƒ‹ƒm[ƒh‚Ìİ’è
		SetGoalCastleNode(–Ú“Ié”Ô†);

		// œ‹ƒŠƒXƒg
		for each (int iCID in Œo˜H\’zœ‹é”Ô†ƒŠƒXƒg) {
			if (0 <= iCID && iCID < GAMEDATASTRUCT_CASTLE_NUM) {
				// ‘ÎÛ‚Ìé‚ğŒo˜H’Tõ‚©‚çíœ‚·‚éB
				RemoveCastleNode(iCID);
				isAllCastleNodeAndEdge = false; // ‘Sé‚ÅŒo˜H‚ğ\’z‚µ‚Ä‚¢‚é‚Æ‚¢‚¤ƒtƒ‰ƒO‚Í¬—§‚µ‚È‚­‚È‚éB
			}
		}

		// ƒXƒ^[ƒg¨ƒS[ƒ‹‚Ö‚Ìƒ‹[ƒg‚ğŒvZ‚µAŒo˜H‚Æ‚È‚Á‚½éID‚ÌƒŠƒXƒg‚ğ•Ô‚·B
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}

		// Œo˜H\’z‚ª‘Sé‚Å‚Í‚È‚¢ê‡
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // ‘Sé‚ÅŒo˜H‚ğ\’z
			isAllCastleNodeAndEdge = true; // ‘Sé‚ÅŒo˜H‚ğ\’z‚µ‚Ä‚¢‚é‚Æ‚¢‚¤ƒtƒ‰ƒO‚ğ—§‚Ä‚éB
		}

	}

	return m_list;

}

éˆÊ’uŒ^::éˆÊ’uŒ^(int ‚w, int ‚x) {
	this->‚w = ‚w;
	this->‚x = ‚x;
}

éƒOƒŠƒbƒhˆÊ’uŒ^::éƒOƒŠƒbƒhˆÊ’uŒ^(int ‚w, int ‚x) {
	this->‚w = ‚w;
	this->‚x = ‚x;
}