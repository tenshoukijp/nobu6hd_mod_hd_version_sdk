#include "GameDataStruct.h"
#include "DijkstraCastle.h"

����^::����^(int i�ԍ�)
{
	iCastleID = i�ԍ�;
}

String^ ����^::�閼::get() {
	return gcnew String(nb6castle[iCastleID].name);
}

void ����^::�閼::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 8) {
		strcpy(nb6castle[iCastleID].name, native_value.c_str());
	}
}

String^ ����^::���::get() {
	int iCastleType = nb6castle[iCastleID].title;
	return gcnew String(getCastleTypeName(iCastleType));
}

String^ ����^::�閼��::get() {
	return �閼 + ���;
}

int ����^::���_�����ԍ�::get() {
	int attr = nb6castle[iCastleID].master;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ����^::�����R�c�ԍ�::get() {
	int attr = nb6castle[iCastleID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}


List<int>^ ����^::���������ԍ����X�g::get() {
	List<int>^ list = gcnew List<int>();
	for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
		// �喼�E�R�c���E����
		if (nb6bushouname[iBushouID].State <= 2) {
			if (nb6bushou[iBushouID].castle - 1 == iCastleID) {
				list->Add(iBushouID);
			}
		}
	}

	return list;
}

bool ����^::Is_�R�c���{��::get() {
	if (nb6castle[iCastleID].honjo == 1 || nb6castle[iCastleID].honjo == 2) {
		return true;
	}
	else {
		return false;
	}
}

bool ����^::Is_�喼�{��::get() {
	if (nb6castle[iCastleID].honjo == 1) {
		return true;
	}
	else {
		return false;
	}
}

int ����^::��s::get() {
	return nb6castle[iCastleID].build;
}

void ����^::��s::set(int value) {
	if (0 <= value && value <= 250) {
		nb6castle[iCastleID].build = value;
	}
}


int ����^::�΍�::get() {
	return nb6castle[iCastleID].grain;
}

void ����^::�΍�::set(int value) {
	if (0 <= value && value <= (LIMIT_BYTE_MAX * 10)) {
		// �K�v�ȍő�΍�������o���B
		double need_kokudaka = value;
		need_kokudaka = need_kokudaka / 10.0;
		need_kokudaka = Math::Ceiling(need_kokudaka);
		need_kokudaka = need_kokudaka * 10;
		if (need_kokudaka > (LIMIT_BYTE_MAX * 10)) {
			need_kokudaka = (LIMIT_BYTE_MAX * 10);
		}

		if (nb6castlemax[iCastleID].maxgrain < need_kokudaka / 10 ) {
			// �K�v�ȍő�΍��𑝉�
			nb6castlemax[iCastleID].maxgrain = byte(need_kokudaka / 10);
		}

		// �΍���ݒ�
		nb6castle[iCastleID].grain = value;
	}
}

int ����^::�ő�΍�::get() {
	return nb6castlemax[iCastleID].maxgrain * 10;
}

void ����^::�ő�΍�::set(int value) {
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

int ����^::����::get() {
	return nb6castle[iCastleID].town;
}

void ����^::����::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		// �K�v�ȍő�΍��𑝉�
		if (nb6castlemax[iCastleID].maxtown < value) {
			nb6castlemax[iCastleID].maxtown = value;
		}
		nb6castle[iCastleID].town = value;
	}
}

int ����^::�ő古��::get() {
	return nb6castlemax[iCastleID].maxtown;
}

void ����^::�ő古��::set(int value) {
	if (0 <= value && value <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].maxtown = value;
	}
}


int ����^::�l��::get() {
	return nb6castle[iCastleID].population;
}

void ����^::�l��::set(int value) {
	if (0 <= value && value <= 9999) {
		nb6castle[iCastleID].population = value;
	}
}

int ����^::����::get() {
	return nb6castle[iCastleID].loyal;
}

void ����^::����::set(int value) {
	if (0 <= value && value <= 100) {
		nb6castle[iCastleID].loyal = value;
	}
}

int ����^::������::get() {
	return nb6castle[iCastleID].soldier;
}

void ����^::������::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].soldier = value;
	}
}

int ����^::����::get() {
	return nb6castle[iCastleID].quality;
}

void ����^::����::set(int value) {
	if (��::��::����::�� <= value && value <= ��::��::����::��) {
		nb6castle[iCastleID].quality = value;
	}
}

int ����^::���m::get() {
	return getCastleHeisuCnt(iCastleID);
}


bool ����^::�b��::get() {
	return nb6castle[iCastleID].bSmith;
}

void ����^::�b��::set(bool value) {
	nb6castle[iCastleID].bSmith = value;
}

bool ����^::�n�Y�n::get() {
	return nb6castle[iCastleID].bHorse;
}

void ����^::�n�Y�n::set(bool value) {
	nb6castle[iCastleID].bHorse = value;
}

bool ����^::�`::get() {
	return nb6castle[iCastleID].bPort;
}

void ����^::�`::set(bool value) {
	nb6castle[iCastleID].bPort = value;
}

bool ����^::���ۍ`::get() {
	return nb6castle[iCastleID].blPort;
}

void ����^::���ۍ`::set(bool value) {
	nb6castle[iCastleID].blPort = value;
}

bool ����^::��R::get() {
	return nb6castle[iCastleID].bSilver;
}

void ����^::��R::set(bool value) {
	nb6castle[iCastleID].bSilver = value;
}

bool ����^::���R::get() {
	return nb6castle[iCastleID].bGold;
}

void ����^::���R::set(bool value) {
	nb6castle[iCastleID].bGold = value;
}

bool ����^::�Ꝅ�::get() {
	return nb6castle[iCastleID].bRevolt;
}

void ����^::�Ꝅ�::set(bool value) {
	nb6castle[iCastleID].bRevolt = value;
}

bool ����^::����::get() {
	return nb6castle[iCastleID].bLarge;
}

void ����^::����::set(bool value) {
	nb6castle[iCastleID].bLarge = value;
}

int ����^::��G�w�i::get() {
	return nb6castle[iCastleID].bgback;
}

void ����^::��G�w�i::set(int value) {
	if (0 <= value && value <= 999) {
		nb6castle[iCastleID].bgback = value;
	}
}

int ����^::�������ԍ�::get() {

	int attr = nb6castlemax[iCastleID].chiiki;
	if (attr >= 0xFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CHIMEI_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int ����^::�������ԍ�::get() {

	int attr = getCastleTodouhukenNum(iCastleID);
	return attr;
}


��ʒu�^^ ����^::�ʒu::get() {
	��ʒu�^^ pos = gcnew ��ʒu�^();
	pos->�w = nb6castlemax[iCastleID].x;
	pos->�x = nb6castlemax[iCastleID].y;
	return pos;
}

void ����^::�ʒu::set(��ʒu�^^ value) {
	if (0 <= value->�w && value->�w <= LIMIT_BYTE_MAX &&
		0 <= value->�x && value->�x <= LIMIT_BYTE_MAX) {
		nb6castlemax[iCastleID].x = value->�w;
		nb6castlemax[iCastleID].y = value->�x;
	}
}

��O���b�h�ʒu�^^ ����^::�O���b�h�ʒu::get() {
	GRID_POSITION native_grid = getCastlePosInMainGrid(iCastleID);
	��O���b�h�ʒu�^^ manage_grid = gcnew ��O���b�h�ʒu�^();
	manage_grid->�w = native_grid.x;
	manage_grid->�x = native_grid.y;
	return manage_grid;
}

bool ����^::Is_�א�(int ��a�ԍ�) {
	vector<int> list = getRinsetsuCastles(iCastleID);
	for each (int iCID in list) {
		if (iCID == ��a�ԍ�) {
			return true;
		}
	}
	return false;
}

List<int>^ ����^::�אڏ�ԍ����X�g::get() {
	vector<int> list = getRinsetsuCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}

List<int>^ ����^::�o�H�אڏ�ԍ����X�g::get() {
	vector<int> list = getWayConnectCastles(iCastleID);
	List<int>^ m_list = gcnew List<int>();
	for each (int iCID in list) {
		m_list->Add(iCID);
	}
	return m_list;
}



�郊�X�g���^::�郊�X�g���^() {
	�z�� = gcnew List<����^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_CASTLE_NUM; i++)
	{
		�z��->Add(gcnew ����^(i));
	}

}



bool isAllCastleNodeAndEdge = false; // �o�H��S��x�[�X�ō\�z���Ă��邩�ǂ����̃t���O

List<int>^ �郊�X�g���^::Get_�o�H��̏�ԍ����X�g(int �J�n��ԍ�, int �ړI��ԍ�) {

	List<int>^ m_list = gcnew List<int>();

	// �J�n����ړI����ԍ����͈͓��ɓ����Ă���B
	if (0 <= �J�n��ԍ� && �J�n��ԍ� < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= �ړI��ԍ� && �ړI��ԍ� < GAMEDATASTRUCT_CASTLE_NUM) {

		// �o�H�\�z���S��ł͂Ȃ��ꍇ
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // �S��Ōo�H���\�z
			isAllCastleNodeAndEdge = true; // �S��Ōo�H���\�z���Ă���Ƃ����t���O�𗧂Ă�B
		}

		// �X�^�[�g�m�[�h�̐ݒ�
		SetStartCastleNode(�J�n��ԍ�);

		// �S�[���m�[�h�̐ݒ�
		SetGoalCastleNode(�ړI��ԍ�);

		// �X�^�[�g���S�[���ւ̃��[�g���v�Z���A�o�H�ƂȂ�����ID�̃��X�g��Ԃ��B
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}
	}

	return m_list;

}

List<int>^ �郊�X�g���^::Get_�o�H��̏�ԍ����X�g(int �J�n��ԍ�, int �ړI��ԍ�, List<int>^ �o�H�\�z������ԍ����X�g) {

	List<int>^ m_list = gcnew List<int>();

	// �J�n����ړI����ԍ����͈͓��ɓ����Ă���B
	if (0 <= �J�n��ԍ� && �J�n��ԍ� < GAMEDATASTRUCT_CASTLE_NUM &&
		0 <= �ړI��ԍ� && �ړI��ԍ� < GAMEDATASTRUCT_CASTLE_NUM) {

		// �o�H�\�z���S��ł͂Ȃ��ꍇ
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // �S��Ōo�H���\�z
			isAllCastleNodeAndEdge = true; // �S��Ōo�H���\�z���Ă���Ƃ����t���O�𗧂Ă�B
		}

		// �X�^�[�g�m�[�h�̐ݒ�
		SetStartCastleNode(�J�n��ԍ�);

		// �S�[���m�[�h�̐ݒ�
		SetGoalCastleNode(�ړI��ԍ�);

		// �������X�g
		for each (int iCID in �o�H�\�z������ԍ����X�g) {
			if (0 <= iCID && iCID < GAMEDATASTRUCT_CASTLE_NUM) {
				// �Ώۂ̏���o�H�T������폜����B
				RemoveCastleNode(iCID);
				isAllCastleNodeAndEdge = false; // �S��Ōo�H���\�z���Ă���Ƃ����t���O�͐������Ȃ��Ȃ�B
			}
		}

		// �X�^�[�g���S�[���ւ̃��[�g���v�Z���A�o�H�ƂȂ�����ID�̃��X�g��Ԃ��B
		vector<int> list = SearchCastleWayRoot();

		for each (int w in list) {
			m_list->Add(w);
		}

		// �o�H�\�z���S��ł͂Ȃ��ꍇ
		if (!isAllCastleNodeAndEdge) {
			InitCastleNodeAndEdge(); // �S��Ōo�H���\�z
			isAllCastleNodeAndEdge = true; // �S��Ōo�H���\�z���Ă���Ƃ����t���O�𗧂Ă�B
		}

	}

	return m_list;

}

��ʒu�^::��ʒu�^(int �w, int �x) {
	this->�w = �w;
	this->�x = �x;
}

��O���b�h�ʒu�^::��O���b�h�ʒu�^(int �w, int �x) {
	this->�w = �w;
	this->�x = �x;
}