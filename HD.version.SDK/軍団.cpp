#include "GameDataStruct.h"



ŒR’cî•ñŒ^::ŒR’cî•ñŒ^(int i”Ô†) {
	iGundanID = i”Ô†;

	í‘ˆ = gcnew í‘ˆŒR’cî•ñŒ^(i”Ô†);
}



int ŒR’cî•ñŒ^::Š‘®é”Ô†::get()
{
	int attr = nb6gundan[iGundanID].residence;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ŒR’cî•ñŒ^::ŒR’c’·_•«”Ô†::get()
{
	int attr = nb6gundan[iGundanID].leader;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ŒR’cî•ñŒ^::Š‘®‘å–¼”Ô†::get()
{
	int attr = nb6gundan[iGundanID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ŒR’cî•ñŒ^::s“®—Í::get() {
	return nb6gundan[iGundanID].act;
}

void ŒR’cî•ñŒ^::s“®—Í::set(int value) {
	nb6gundan[iGundanID].act = value;
}

int ŒR’cî•ñŒ^::‹à::get() {
	return nb6gundan[iGundanID].money;
}

void ŒR’cî•ñŒ^::‹à::set(int value) {
	nb6gundan[iGundanID].money = value;
}

int ŒR’cî•ñŒ^::•Ä::get() {
	return nb6gundan[iGundanID].rise;
}

void ŒR’cî•ñŒ^::•Ä::set(int value) {
	nb6gundan[iGundanID].rise = value;
}

int ŒR’cî•ñŒ^::”n::get() {
	return nb6gundan[iGundanID].horse;
}

void ŒR’cî•ñŒ^::”n::set(int value) {
	nb6gundan[iGundanID].horse = value;
}

int ŒR’cî•ñŒ^::“S–C::get() {
	return nb6gundan[iGundanID].gun;
}

void ŒR’cî•ñŒ^::“S–C::set(int value) {
	nb6gundan[iGundanID].gun = value;
}

int ŒR’cî•ñŒ^::•ºm::get() {
	return getGundanHeisuCnt(iGundanID);
}

int ŒR’cî•ñŒ^::”C–½”Ô†::get() {
	return nb6gundan[iGundanID].number;
}

void ŒR’cî•ñŒ^::”C–½”Ô†::set(int value) {
	if (2 <= value && value <= 8) {
		tryChangeGundanWariateNum(iGundanID, value);
	}
}

int ŒR’cî•ñŒ^::–ğE::get() {
	return getNormalizedDaimyoPosition(iGundanID);
}

void ŒR’cî•ñŒ^::–ğE::set(int value) {
	if (—ñ‹“::ŒR’c::–ğE::–³‚µ <= value && value <= —ñ‹“::ŒR’c::–ğE::‰HB’T‘è) {
		tryChangeGundanYakusyoku(iGundanID, value);
	}
}

List<int>^ ŒR’cî•ñŒ^::Ÿ€‰º•«”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getGundanBushouList(iGundanID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iBushouID in list) {
		m_list->Add(iBushouID);
	}

	return m_list;
}

List<int>^ ŒR’cî•ñŒ^::Ÿ€‰ºé”Ô†ƒŠƒXƒg::get() {
	List<int>^ m_list = gcnew List<int>();
	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		if ( nb6castle[iCastleID].attach - 1 == iGundanID ) {
			m_list->Add(iCastleID);
		}
	}

	return m_list;
}


bool ŒR’cî•ñŒ^::Is_ƒvƒŒƒCƒ„Ÿ€‰ºŒR’c::get() {
	return isPlayerGundan(iGundanID);
}

bool ŒR’cî•ñŒ^::Is_ƒvƒŒƒCƒ„’S“–ŒR’c::get() {
	return nb6gundan[iGundanID].number == 1 && isPlayerGundan(iGundanID);
}


bool ŒR’cî•ñŒ^::Do_Š‘®‘å–¼•ÏX(int ‘å–¼”Ô†) {
	return setGundanReAttachDaimyo(iGundanID, ‘å–¼”Ô†);
}

int ŒR’cî•ñŒ^::í‘ˆŒR’cî•ñŒ^::‘‘å«_•«”Ô†::get() {
	return GetWarSoudaishoTheGundan(iGundanID);
}

int ŒR’cî•ñŒ^::í‘ˆŒR’cî•ñŒ^::Qí—§ê::get() {
	return GetWarStandPointTheGundan(iGundanID);
}

ŒR’cƒŠƒXƒgî•ñŒ^::ŒR’cƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<ŒR’cî•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_GUNDAN_NUM; i++)
	{
		”z—ñ->Add(gcnew ŒR’cî•ñŒ^(i));
	}

	í‘ˆ = gcnew í‘ˆŒR’cƒŠƒXƒgî•ñŒ^();
}


List<int>^ ŒR’cƒŠƒXƒgî•ñŒ^::—LŒøŒR’c”Ô†ƒŠƒXƒg::get() {
	vector<int> list = getValidGundanList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}
	return m_list;
}


List<int>^ ŒR’cƒŠƒXƒgî•ñŒ^::í‘ˆŒR’cƒŠƒXƒgî•ñŒ^::QíŒR’c”Ô†ƒŠƒXƒg::get() {
	vector<int> list = GetCurWarJointGundanIDList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}

	return m_list;
}

