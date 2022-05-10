
#include "GameDataStruct.h"



‘å–¼î•ñŒ^::‘å–¼î•ñŒ^(int i”Ô†) {
	iDaimyoID = i”Ô†;
}

int ‘å–¼î•ñŒ^::‘å–¼_•«”Ô†::get() {
	int attr = nb6daimyo[iDaimyoID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ‘å–¼î•ñŒ^::‹é”Ô†::get() {
	int attr = nb6daimyo[iDaimyoID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ‘å–¼î•ñŒ^::“G‘Î‘å–¼”Ô†::get() {
	int attr = nb6daimyo[iDaimyoID].hostile;
	// 0xFF‚ªMAX‚¾‚ª‘¼‚Æ‡‚í‚¹‚é
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void ‘å–¼î•ñŒ^::“G‘Î‘å–¼”Ô†::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFF‚ªMAX‚Å“G‘Î‚È‚µ
		nb6daimyo[iDaimyoID].hostile = 0xFF;
	}
}

int ‘å–¼î•ñŒ^::—FD‘å–¼”Ô†::get() {
	int attr = nb6daimyo[iDaimyoID].friendship;
	// 0xFF‚ªMAX‚¾‚ª‘¼‚Æ‡‚í‚¹‚é
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void ‘å–¼î•ñŒ^::—FD‘å–¼”Ô†::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFF‚ªMAX‚Å“G‘Î‚È‚µ
		nb6daimyo[iDaimyoID].friendship = 0xFF;
	}
}

int ‘å–¼î•ñŒ^::‰Æ–ä”Ô†::get() {
	return nb6daimyo[iDaimyoID].symbol;
}

void ‘å–¼î•ñŒ^::‰Æ–ä”Ô†::set(int value) {
	nb6daimyo[iDaimyoID].symbol = value;
}

int ‘å–¼î•ñŒ^::’©’ì—FD“x::get() {
	return nb6daimyo[iDaimyoID].tyotei;
}

void ‘å–¼î•ñŒ^::’©’ì—FD“x::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].tyotei = value;
	}
}

int ‘å–¼î•ñŒ^::Œä—p¤l::get() {
	return nb6daimyo[iDaimyoID].merchantHuman;
}

void ‘å–¼î•ñŒ^::Œä—p¤l::set(int value) {
	if (0 <= value && value <= —ñ‹“::‘å–¼::Œä—p¤l::ŠD‰®Ğ—R) {
		nb6daimyo[iDaimyoID].merchantHuman = value;
	}
}

int ‘å–¼î•ñŒ^::¤l—FD“x::get() {
	return nb6daimyo[iDaimyoID].merchant;
}

void ‘å–¼î•ñŒ^::¤l—FD“x::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].merchant = value;
	}
}

bool ‘å–¼î•ñŒ^::¤l•sİ::get() {
	return nb6daimyo[iDaimyoID].bMerchantAngry;
}

void ‘å–¼î•ñŒ^::¤l•sİ::set(bool value) {
	nb6daimyo[iDaimyoID].bMerchantAngry = value;
}


bool ‘å–¼î•ñŒ^::•z‹³Ï::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void ‘å–¼î•ñŒ^::•z‹³Ï::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

bool ‘å–¼î•ñŒ^::•]’èÏ::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void ‘å–¼î•ñŒ^::•]’èÏ::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

int ‘å–¼î•ñŒ^::–ğE::get() {
	return getNormalizedDaimyoPosition(iDaimyoID);
}

void ‘å–¼î•ñŒ^::–ğE::set(int value) {
	if (—ñ‹“::‘å–¼::–ğE::–³‚µ <= value && value <= —ñ‹“::‘å–¼::–ğE::‰HB’T‘è) {
		tryChangeDaimyoYakusyoku(iDaimyoID, value);
	}
}

int ‘å–¼î•ñŒ^::Get_—FDŠÖŒW(int ‘å–¼”Ô†) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		return getYuukouKankei(iDaimyoID, ‘å–¼”Ô†);
	}
	return 0;
}

void ‘å–¼î•ñŒ^::Set_—FDŠÖŒW(int ‘å–¼”Ô†, int —FD’l) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		setYuukouKankei(iDaimyoID, ‘å–¼”Ô†, —FD’l);
	}
}

bool ‘å–¼î•ñŒ^::Is_“¯–¿ŠÖŒW(int ‘å–¼”Ô†) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isDoumeiKankei(iDaimyoID, ‘å–¼”Ô†)) {
			return true;
		}
	}
	return false;
}

void ‘å–¼î•ñŒ^::Set_“¯–¿ŠÖŒW(int ‘å–¼”Ô†) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		setDoumeiKankei(iDaimyoID, ‘å–¼”Ô†);
	}
}

bool ‘å–¼î•ñŒ^::Is_¥ˆ÷ŠÖŒW(int ‘å–¼”Ô†) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isKoninKankei(iDaimyoID, ‘å–¼”Ô†)) {
			return true;
		}
	}
	return false;
}

void ‘å–¼î•ñŒ^::Set_¥ˆ÷ŠÖŒW(int ‘å–¼”Ô†) {
	if (0 <= ‘å–¼”Ô† && ‘å–¼”Ô† < GAMEDATASTRUCT_DAIMYO_NUM) {
		setKoninKankei(iDaimyoID, ‘å–¼”Ô†);
	}
}

List<int>^ ‘å–¼î•ñŒ^::Ÿ€‰ºŒR’c”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getGovernedGundanList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}

	return m_list;
}

List<int>^ ‘å–¼î•ñŒ^::Ÿ€‰ºé”Ô†ƒŠƒXƒg::get() {
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

List<int>^ ‘å–¼î•ñŒ^::Š„“–ÏŒR’c”C–½”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

List<int>^ ‘å–¼î•ñŒ^::–¢Š„“–ŒR’c”C–½”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getNotGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

bool ‘å–¼î•ñŒ^::Is_ƒvƒŒƒCƒ„’S“–‘å–¼::get() {
	return isPlayerDaimyo(iDaimyoID);
}


‘å–¼ƒŠƒXƒgî•ñŒ^::‘å–¼ƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<‘å–¼î•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_DAIMYO_NUM; i++)
	{
		”z—ñ->Add(gcnew ‘å–¼î•ñŒ^(i));
	}

	í‘ˆ = gcnew í‘ˆ‘å–¼ƒŠƒXƒgî•ñŒ^();
}

List<int>^ ‘å–¼ƒŠƒXƒgî•ñŒ^::—LŒø‘å–¼”Ô†ƒŠƒXƒg::get() {
	// ‘S—LŒø‘å–¼‚ÌƒŠƒXƒg‚ğ•Ô‚·Bƒ^[ƒ“‘å–¼©g‚à“ü‚Á‚Ä‚é‚Ì‚Å’ˆÓB
	vector<int> list = getDaimyoList(TRUE);

	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;

}



List<int>^ ‘å–¼ƒŠƒXƒgî•ñŒ^::í‘ˆ‘å–¼ƒŠƒXƒgî•ñŒ^::Qí‘å–¼”Ô†ƒŠƒXƒg::get() {
	vector<int> list = GetCurWarJointDaimyoIDList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;
}




