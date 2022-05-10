#include "GameDataStruct.h"



�R�c���^::�R�c���^(int i�ԍ�) {
	iGundanID = i�ԍ�;

	�푈 = gcnew �푈�R�c���^(i�ԍ�);
}



int �R�c���^::������ԍ�::get()
{
	int attr = nb6gundan[iGundanID].residence;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �R�c���^::�R�c��_�����ԍ�::get()
{
	int attr = nb6gundan[iGundanID].leader;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �R�c���^::�����喼�ԍ�::get()
{
	int attr = nb6gundan[iGundanID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �R�c���^::�s����::get() {
	return nb6gundan[iGundanID].act;
}

void �R�c���^::�s����::set(int value) {
	nb6gundan[iGundanID].act = value;
}

int �R�c���^::��::get() {
	return nb6gundan[iGundanID].money;
}

void �R�c���^::��::set(int value) {
	nb6gundan[iGundanID].money = value;
}

int �R�c���^::��::get() {
	return nb6gundan[iGundanID].rise;
}

void �R�c���^::��::set(int value) {
	nb6gundan[iGundanID].rise = value;
}

int �R�c���^::�n::get() {
	return nb6gundan[iGundanID].horse;
}

void �R�c���^::�n::set(int value) {
	nb6gundan[iGundanID].horse = value;
}

int �R�c���^::�S�C::get() {
	return nb6gundan[iGundanID].gun;
}

void �R�c���^::�S�C::set(int value) {
	nb6gundan[iGundanID].gun = value;
}

int �R�c���^::���m::get() {
	return getGundanHeisuCnt(iGundanID);
}

int �R�c���^::�C���ԍ�::get() {
	return nb6gundan[iGundanID].number;
}

void �R�c���^::�C���ԍ�::set(int value) {
	if (2 <= value && value <= 8) {
		tryChangeGundanWariateNum(iGundanID, value);
	}
}

int �R�c���^::��E::get() {
	return getNormalizedDaimyoPosition(iGundanID);
}

void �R�c���^::��E::set(int value) {
	if (��::�R�c::��E::���� <= value && value <= ��::�R�c::��E::�H�B�T��) {
		tryChangeGundanYakusyoku(iGundanID, value);
	}
}

List<int>^ �R�c���^::���������ԍ����X�g::get() {
	vector<int> list = getGundanBushouList(iGundanID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iBushouID in list) {
		m_list->Add(iBushouID);
	}

	return m_list;
}

List<int>^ �R�c���^::������ԍ����X�g::get() {
	List<int>^ m_list = gcnew List<int>();
	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		if ( nb6castle[iCastleID].attach - 1 == iGundanID ) {
			m_list->Add(iCastleID);
		}
	}

	return m_list;
}


bool �R�c���^::Is_�v���C�������R�c::get() {
	return isPlayerGundan(iGundanID);
}

bool �R�c���^::Is_�v���C���S���R�c::get() {
	return nb6gundan[iGundanID].number == 1 && isPlayerGundan(iGundanID);
}


bool �R�c���^::Do_�����喼�ύX(int �喼�ԍ�) {
	return setGundanReAttachDaimyo(iGundanID, �喼�ԍ�);
}

int �R�c���^::�푈�R�c���^::���叫_�����ԍ�::get() {
	return GetWarSoudaishoTheGundan(iGundanID);
}

int �R�c���^::�푈�R�c���^::�Q�헧��::get() {
	return GetWarStandPointTheGundan(iGundanID);
}

�R�c���X�g���^::�R�c���X�g���^() {
	�z�� = gcnew List<�R�c���^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_GUNDAN_NUM; i++)
	{
		�z��->Add(gcnew �R�c���^(i));
	}

	�푈 = gcnew �푈�R�c���X�g���^();
}


List<int>^ �R�c���X�g���^::�L���R�c�ԍ����X�g::get() {
	vector<int> list = getValidGundanList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}
	return m_list;
}


List<int>^ �R�c���X�g���^::�푈�R�c���X�g���^::�Q��R�c�ԍ����X�g::get() {
	vector<int> list = GetCurWarJointGundanIDList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}

	return m_list;
}

