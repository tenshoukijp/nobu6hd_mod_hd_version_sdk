
#include "GameDataStruct.h"



�喼���^::�喼���^(int i�ԍ�) {
	iDaimyoID = i�ԍ�;
}

int �喼���^::�喼_�����ԍ�::get() {
	int attr = nb6daimyo[iDaimyoID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �喼���^::����ԍ�::get() {
	int attr = nb6daimyo[iDaimyoID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �喼���^::�G�Α喼�ԍ�::get() {
	int attr = nb6daimyo[iDaimyoID].hostile;
	// 0xFF��MAX�������ƍ��킹��
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void �喼���^::�G�Α喼�ԍ�::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFF��MAX�œG�΂Ȃ�
		nb6daimyo[iDaimyoID].hostile = 0xFF;
	}
}

int �喼���^::�F�D�喼�ԍ�::get() {
	int attr = nb6daimyo[iDaimyoID].friendship;
	// 0xFF��MAX�������ƍ��킹��
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void �喼���^::�F�D�喼�ԍ�::set(int value) {
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6daimyo[iDaimyoID].hostile = value + 1;
	}
	else {
		// 0xFF��MAX�œG�΂Ȃ�
		nb6daimyo[iDaimyoID].friendship = 0xFF;
	}
}

int �喼���^::�Ɩ�ԍ�::get() {
	return nb6daimyo[iDaimyoID].symbol;
}

void �喼���^::�Ɩ�ԍ�::set(int value) {
	nb6daimyo[iDaimyoID].symbol = value;
}

int �喼���^::����F�D�x::get() {
	return nb6daimyo[iDaimyoID].tyotei;
}

void �喼���^::����F�D�x::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].tyotei = value;
	}
}

int �喼���^::��p���l::get() {
	return nb6daimyo[iDaimyoID].merchantHuman;
}

void �喼���^::��p���l::set(int value) {
	if (0 <= value && value <= ��::�喼::��p���l::�D���ЗR) {
		nb6daimyo[iDaimyoID].merchantHuman = value;
	}
}

int �喼���^::���l�F�D�x::get() {
	return nb6daimyo[iDaimyoID].merchant;
}

void �喼���^::���l�F�D�x::set(int value) {
	if (0 <= value && value <= 100) {
		nb6daimyo[iDaimyoID].merchant = value;
	}
}

bool �喼���^::���l�s��::get() {
	return nb6daimyo[iDaimyoID].bMerchantAngry;
}

void �喼���^::���l�s��::set(bool value) {
	nb6daimyo[iDaimyoID].bMerchantAngry = value;
}


bool �喼���^::�z����::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void �喼���^::�z����::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

bool �喼���^::�]���::get() {
	return nb6daimyo[iDaimyoID].bPropagate;
}

void �喼���^::�]���::set(bool value) {
	nb6daimyo[iDaimyoID].bPropagate = value;
}

int �喼���^::��E::get() {
	return getNormalizedDaimyoPosition(iDaimyoID);
}

void �喼���^::��E::set(int value) {
	if (��::�喼::��E::���� <= value && value <= ��::�喼::��E::�H�B�T��) {
		tryChangeDaimyoYakusyoku(iDaimyoID, value);
	}
}

int �喼���^::Get_�F�D�֌W(int �喼�ԍ�) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		return getYuukouKankei(iDaimyoID, �喼�ԍ�);
	}
	return 0;
}

void �喼���^::Set_�F�D�֌W(int �喼�ԍ�, int �F�D�l) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		setYuukouKankei(iDaimyoID, �喼�ԍ�, �F�D�l);
	}
}

bool �喼���^::Is_�����֌W(int �喼�ԍ�) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isDoumeiKankei(iDaimyoID, �喼�ԍ�)) {
			return true;
		}
	}
	return false;
}

void �喼���^::Set_�����֌W(int �喼�ԍ�) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		setDoumeiKankei(iDaimyoID, �喼�ԍ�);
	}
}

bool �喼���^::Is_�����֌W(int �喼�ԍ�) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		if (isKoninKankei(iDaimyoID, �喼�ԍ�)) {
			return true;
		}
	}
	return false;
}

void �喼���^::Set_�����֌W(int �喼�ԍ�) {
	if (0 <= �喼�ԍ� && �喼�ԍ� < GAMEDATASTRUCT_DAIMYO_NUM) {
		setKoninKankei(iDaimyoID, �喼�ԍ�);
	}
}

List<int>^ �喼���^::�����R�c�ԍ����X�g::get() {
	vector<int> list = getGovernedGundanList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iGundanID in list) {
		m_list->Add(iGundanID);
	}

	return m_list;
}

List<int>^ �喼���^::������ԍ����X�g::get() {
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

List<int>^ �喼���^::�����όR�c�C���ԍ����X�g::get() {
	vector<int> list = getGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

List<int>^ �喼���^::�������R�c�C���ԍ����X�g::get() {
	vector<int> list = getNotGovernedGundanWariateNumList(iDaimyoID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iNinmeiNo in list) {
		m_list->Add(iNinmeiNo);
	}

	return m_list;
}

bool �喼���^::Is_�v���C���S���喼::get() {
	return isPlayerDaimyo(iDaimyoID);
}


�喼���X�g���^::�喼���X�g���^() {
	�z�� = gcnew List<�喼���^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_DAIMYO_NUM; i++)
	{
		�z��->Add(gcnew �喼���^(i));
	}

	�푈 = gcnew �푈�喼���X�g���^();
}

List<int>^ �喼���X�g���^::�L���喼�ԍ����X�g::get() {
	// �S�L���喼�̃��X�g��Ԃ��B�^�[���喼���g�������Ă�̂Œ��ӁB
	vector<int> list = getDaimyoList(TRUE);

	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;

}



List<int>^ �喼���X�g���^::�푈�喼���X�g���^::�Q��喼�ԍ����X�g::get() {
	vector<int> list = GetCurWarJointDaimyoIDList();
	List<int>^ m_list = gcnew List<int>();
	for each (int iDaimyoID in list) {
		m_list->Add(iDaimyoID);
	}

	return m_list;
}




