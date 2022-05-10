#include "GameDataStruct.h"

#include "GameDataStructBushouRelation.h"

�������^::�������^(int i�ԍ�)
{
	iBushouID = i�ԍ�;

	�푈 = gcnew �푈�������^(i�ԍ�);
}

String^ �������^::����::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname);
}

void �������^::����::set(String^ value)
{
	string str_native = to_native_string(value);
	// �S�p�S�����ȉ�
	if ( str_native.size() <= 8 ) {
		strcpy(nb6bushouname[iBushouID].familyname, str_native.c_str());
	}
}

String^ �������^::���O::get()
{
	return gcnew String(nb6bushouname[iBushouID].fastname);
}

void �������^::���O::set(String^ value)
{
	string str_native = to_native_string(value);
	// �S�p�S�����ȉ�
	if (str_native.size() <= 8) {
		strcpy(nb6bushouname[iBushouID].fastname, str_native.c_str());
	}
}

String^ �������^::����::get()
{
	return gcnew String(nb6bushouname[iBushouID].familyname) + gcnew String(nb6bushouname[iBushouID].fastname);
}


int �������^::����::get()
{
	return nb6bushouname[iBushouID].sex;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= 1)
	{
		nb6bushouname[iBushouID].sex = value;
	}
}


int �������^::��`�ԍ�::get()
{
	return nb6bushouname[iBushouID].number;
}

void �������^::��`�ԍ�::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].number = value;
	}
}

int �������^::������ԍ�::get()
{
	return nb6bushouname[iBushouID].face;
}

void �������^::������ԍ�::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushouname[iBushouID].face = value;
	}
}

int �������^::�������˔\::get()
{
	return getBushouPureGovMax(iBushouID);
}

int �������^::�����˔\::get()
{
	return nb6bushou[iBushouID].maxgov;
}

void �������^::�����˔\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxgov = value;
	}
}

int �������^::���퓬�˔\::get()
{
	return getBushouPureBatMax(iBushouID);
}


int �������^::�퓬�˔\::get()
{
	return nb6bushou[iBushouID].maxbat;
}

void �������^::�퓬�˔\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxbat = value;
	}
}

int �������^::���q�d�˔\::get()
{
	return getBushouPureIntMax(iBushouID);
}

int �������^::�q�d�˔\::get()
{
	return nb6bushou[iBushouID].maxint;
}

void �������^::�q�d�˔\::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].maxint = value;
	}
}


int �������^::�����n��::get()
{
	return nb6bushou[iBushouID].expgov;
}

void �������^::�����n��::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expgov = value;
	}
}

int �������^::�퓬�n��::get()
{
	return nb6bushou[iBushouID].expbat;
}

void �������^::�퓬�n��::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expbat = value;
	}
}


int �������^::�q�d�n��::get()
{
	return nb6bushou[iBushouID].expint;
}

void �������^::�q�d�n��::set(int value)
{
	if (0 <= value && value <= 2000)
	{
		nb6bushou[iBushouID].expint = value;
	}
}

int �������^::�����K��::get()
{
	return nb6bushou[iBushouID].aptitudegov;
}

void �������^::�����K��::set(int value)
{
	if (0 <= value && value <= ��::����::�����K��::�`)
	{
		nb6bushou[iBushouID].aptitudegov = value;
	}
}

int �������^::�퓬�K��::get()
{
	return nb6bushou[iBushouID].aptitudebat;
}

void �������^::�퓬�K��::set(int value)
{
	if (0 <= value && value <= ��::����::�퓬�K��::�`)
	{
		nb6bushou[iBushouID].aptitudebat = value;
	}
}

int �������^::�q�d�K��::get()
{
	return nb6bushou[iBushouID].aptitudeint;
}

void �������^::�q�d�K��::set(int value)
{
	if (0 <= value && value <= ��::����::�q�d�K��::�`)
	{
		nb6bushou[iBushouID].aptitudeint = value;
	}
}

int �������^::�����l::get()
{
	return getBushouGov(iBushouID);
}

int �������^::�퓬�l::get()
{
	return getBushouBat(iBushouID);
}

int �������^::�q�d�l::get()
{
	return getBushouInt(iBushouID);
}



int �������^::���y�K��::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU);
}

void �������^::���y�K��::set(int value)
{
	if (0 <= value && value <= ��::����::���y�K��::�r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_ASIGARU, value);
	}
}

int �������^::�R�n�K��::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA);
}

void �������^::�R�n�K��::set(int value)
{
	if (0 <= value && value <= ��::����::�R�n�K��::�r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_KIBA, value);
	}
}

int �������^::�S�C�K��::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU);
}

void �������^::�S�C�K��::set(int value)
{
	if (0 <= value && value <= ��::����::�S�C�K��::�r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_TEPPOU, value);
	}
}

int �������^::���R�K��::get()
{
	return getBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN);
}

void �������^::���R�K��::set(int value)
{
	if (0 <= value && value <= ��::����::���R�K��::�r)
	{
		setBushouAptitude(iBushouID, APTITUDE::APTITUDE_SUIGUN, value);
	}
}

int �������^::������::get()
{
	return getBushouPureCharm(iBushouID);
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].charm;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].charm = value;
	}
}

int �������^::����]::get()
{
	return getBushouPureAmbition(iBushouID);
}

int �������^::��]::get()
{
	return nb6bushou[iBushouID].ambition;
}

void �������^::��]::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].ambition = value;
	}
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].loyal;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= LIMIT_CHAR_MAX)
	{
		nb6bushou[iBushouID].loyal = value;
	}
}

int �������^::�M��::get()
{
	return nb6bushou[iBushouID].merits;
}

void �������^::�M��::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].merits = value;
	}
}


int �������^::���ؔԍ�::get()
{
	return nb6bushou[iBushouID].blood;
}

void �������^::���ؔԍ�::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].blood = value;
	}
}

int �������^::�����喼�ԍ�::get()
{
	int attr = nb6bushou[iBushouID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �������^::�����R�c�ԍ�::get()
{
	int attr = nb6bushou[iBushouID].gundan;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �������^::������ԍ�::get()
{
	int attr = nb6bushou[iBushouID].castle;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_CASTLE_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �������^::������喼�ԍ�::get()
{
	int attr = nb6bushou[iBushouID].rise;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void �������^::������喼�ԍ�::set(int value)
{
	if (0 <= value && value < GAMEDATASTRUCT_DAIMYO_NUM) {
		nb6bushou[iBushouID].rise = value + 1;
	}
	else if (value == 0xFFFF) {
		nb6bushou[iBushouID].rise = 0xFFFF;
	}
}


int �������^::���m::get()
{
	return nb6bushou[iBushouID].soldier;
}

int �������^::�ő啺�m::get()
{
	int position = nb6bushouname[iBushouID].position;
	if (��::����::�g��::�B�� <= position && position <= ��::����::�g��::���y��) {
		return nb6soldier_max[position].soldiermax;
	}
	return 0;
}

void �������^::���m::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].soldier = value;
	}
}

int �������^::�P��::get()
{
	return nb6bushou[iBushouID].training;
}

void �������^::�P��::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].training = value;
	}
}

int �������^::�m�C::get()
{
	return nb6bushou[iBushouID].solloyal;
}

void �������^::�m�C::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].solloyal = value;
	}
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].form;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].form = value;
	}
}

int �������^::�m���N��::get()
{
	return nb6bushou[iBushouID].work;
}

void �������^::�m���N��::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].work = value;
	}
}

int �������^::���N::get()
{
	return GAMEDATASTRUCT_TENSHOUKI_GANNEN + nb6bushou[iBushouID].birth - 1;
}

void �������^::���N::set(int value)
{
	if (GAMEDATASTRUCT_TENSHOUKI_GANNEN <= value && value <= GAMEDATASTRUCT_TENSHOUKI_GANNEN + LIMIT_BYTE_MAX)
	{
		int birth = value - GAMEDATASTRUCT_TENSHOUKI_GANNEN + 1;
		nb6bushou[iBushouID].birth = birth;
	}
}

int �������^::�N��::get()
{
	return getYearsOld(iBushouID);
}


int �������^::�e��`�ԍ�::get()
{
	return nb6bushou[iBushouID].parent;
}

void �������^::�e��`�ԍ�::set(int value)
{
	if (0 <= value && value <= LIMIT_WORD_MAX)
	{
		nb6bushou[iBushouID].parent = value;
	}
}


int �������^::�v�l::get()
{
	return nb6bushou[iBushouID].algo;
}

void �������^::�v�l::set(int value)
{
	if (0 <= value && value <= LIMIT_BYTE_MAX)
	{
		nb6bushou[iBushouID].algo = value;
	}
}

int �������^::�`��::get()
{
	return nb6bushou[iBushouID].duty;
}

void �������^::�`��::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].duty = value;
	}
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].affinity;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= 15)
	{
		nb6bushou[iBushouID].affinity = value;
	}
}


bool �������^::�Z�\�ꊅ::get()
{
	return nb6bushou[iBushouID].tech_ikkatsu;
}

void �������^::�Z�\�ꊅ::set(bool value)
{
	nb6bushou[iBushouID].tech_ikkatsu = value;
}

bool �������^::�Z�\�ÎE::get()
{
	return nb6bushou[iBushouID].tech_ansatsu;
}

void �������^::�Z�\�ÎE::set(bool value)
{
	nb6bushou[iBushouID].tech_ansatsu = value;
}

bool �������^::�Z�\���o::get()
{
	return nb6bushou[iBushouID].tech_ryusyutsu;
}

void �������^::�Z�\���o::set(bool value)
{
	nb6bushou[iBushouID].tech_ryusyutsu = value;
}

bool �������^::�Z�\����::get()
{
	return nb6bushou[iBushouID].tech_sendou;
}

void �������^::�Z�\����::set(bool value)
{
	nb6bushou[iBushouID].tech_sendou = value;
}

bool �������^::�Z�\����::get()
{
	return nb6bushou[iBushouID].tech_ryugen;
}

void �������^::�Z�\����::set(bool value)
{
	nb6bushou[iBushouID].tech_ryugen = value;
}

bool �������^::�Z�\�ِ�::get()
{
	return nb6bushou[iBushouID].tech_benzetsu;
}

void �������^::�Z�\�ِ�::set(bool value)
{
	nb6bushou[iBushouID].tech_benzetsu = value;
}

bool �������^::�Z�\�ē�::get()
{
	return nb6bushou[iBushouID].tech_yakiuchi;
}

void �������^::�Z�\�ē�::set(bool value)
{
	nb6bushou[iBushouID].tech_yakiuchi = value;
}

bool �������^::�Z�\����::get()
{
	return nb6bushou[iBushouID].tech_chohatsu;
}

void �������^::�Z�\����::set(bool value)
{
	nb6bushou[iBushouID].tech_chohatsu = value;
}

int �������^::�E��::get()
{
	return nb6bushou[iBushouID].job;
}

void �������^::�E��::set(int value)
{
	if (0 <= value && value <= ��::����::�E��::�m��)
	{
		nb6bushou[iBushouID].job = value;
	}
}

bool �������^::��C::get()
{
	return nb6bushou[iBushouID].biggun;
}

void �������^::��C::set(bool value)
{
	nb6bushou[iBushouID].biggun = value;
}

bool �������^::�R�n�S�C::get()
{
	return nb6bushou[iBushouID].horsegun;
}

void �������^::�R�n�S�C::set(bool value)
{
	nb6bushou[iBushouID].horsegun = value;
}

bool �������^::�S�b�D::get()
{
	return nb6bushou[iBushouID].steelship;
}

void �������^::�S�b�D::set(bool value)
{
	nb6bushou[iBushouID].steelship = value;
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].job;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].life = value;
	}
}

int �������^::�E��::get()
{
	return nb6bushou[iBushouID].job;
}

void �������^::�E��::set(int value)
{
	if (0 <= value && value <= 7)
	{
		nb6bushou[iBushouID].brave = value;
	}
}

int �������^::�Ɨ�::get()
{
	return getBushouIndependence(iBushouID);
}

void �������^::�Ɨ�::set(int value)
{
	if (0 <= value && value <= 7)
	{
		setBushouIndependence(iBushouID, value);
	}
}

int �������^::����::get()
{
	return nb6bushou[iBushouID].tone;
}

void �������^::����::set(int value)
{
	if (0 <= value && value <= ��::����::����::���)
	{
		nb6bushou[iBushouID].tone = value;
	}
}


bool �������^::�s����::get()
{
	return nb6bushou[iBushouID].bEnd;
}

void �������^::�s����::set(bool value)
{
	nb6bushou[iBushouID].bEnd = value;
}

bool �������^::�������::get()
{
	return nb6bushou[iBushouID].bRise;
}

void �������^::�������::set(bool value)
{
	nb6bushou[iBushouID].bRise = value;
}

bool �������^::�⍦���::get()
{
	return nb6bushou[iBushouID].grudge;
}

void �������^::�⍦���::set(bool value)
{
	nb6bushou[iBushouID].grudge = value;
}

bool �������^::���::get()
{
	return nb6bushou[iBushouID].kaiken;
}

void �������^::���::set(bool value)
{
	nb6bushou[iBushouID].kaiken = value;
}

int �������^::���::get()
{
	// ���Ő펀�����Ă��Ă����S�̏�Ԃ�Ԃ��Ă���
	if (nb6bushouname[iBushouID].battleDeath) {
		return ��::����::���::���S;
	}

	return nb6bushouname[iBushouID].State;
}

void �������^::���::set(int value)
{
	// �����ł�Q�l�ɂ���
	if (nb6bushouname[iBushouID].State == ��::����::���::���� && value== ��::����::���::�Q�l) {

		setGenekiToRounin(iBushouID);
	}

	// �Q�l�������ɂ���
	else if (nb6bushouname[iBushouID].State == ��::����::���::�Q�l && value == ��::����::���::����) {

		setRouninToGeneki(iBushouID);
	}

}



int �������^::�g��::get()
{
	return nb6bushouname[iBushouID].position;
}

void �������^::�g��::set(int value)
{
	// �R�c���������͌����ł���B
	if (nb6bushouname[iBushouID].State == ��::����::���::�R�c�� || nb6bushouname[iBushouID].State == ��::����::���::����) {

		if (��::����::�g��::�h�V <= value && value <= ��::����::�g��::���y��) {
			nb6bushouname[iBushouID].State = value;
		}
	}
}


bool �������^::Do_���() {
	return setGenekiToJyosyu(iBushouID);
}

bool �������^::Do_�]��(int ��ԍ�) {
	if (0 <= ��ԍ� && ��ԍ� < GAMEDATASTRUCT_CASTLE_NUM) {
		return setBushouTransport(iBushouID, ��ԍ�);
	}
	else {
		return false;
	}
}

int �������^::���������ԍ�::get() {
	return getHanryoBushouID(iBushouID);
}

bool �������^::Do_����(int ���蕐���ԍ�) {
	if (0 <= ���蕐���ԍ� && ���蕐���ԍ� < GAMEDATASTRUCT_BUSHOU_NUM) {
		int iOtto = -1;
		int iHime = -1;
		// ���蕐���ԍ����P
		if (nb6bushouname[���蕐���ԍ�].State == ��::����::���::�P) {
			iHime = ���蕐���ԍ�;
			iOtto = iBushouID;
			setHimeMarriage(iHime, iOtto, true);
		}
		// �������P
		else if(nb6bushouname[iBushouID].State == ��::����::���::�P) {
			iHime = iBushouID;
			iOtto = ���蕐���ԍ�;
			setHimeMarriage(iHime, iOtto, true);
		}
		else {
			return false;
		}
		
	}

	return false;

}

bool �������^::Do_����() {
	int iHime = -1;
	// �������P
	if (nb6bushouname[iBushouID].State == ��::����::���::�P) {
		iHime = iBushouID;
		setHimeDivorce(iHime, true);
	}
	// �����͕P�ł͂Ȃ��B
	else if (nb6bushouname[iBushouID].State != ��::����::���::�P) {
		// �Ȃ͋��Ȃ��B
		if (nb6bushou[iBushouID].spouse == 0xFF) {
			return false;
		}

		iHime = nb6bushou[iBushouID].spouse + 500;
		if (0 <= iHime && iHime < GAMEDATASTRUCT_BUSHOU_NUM) {
			setHimeDivorce(iHime, true);
		}
	}

	return false;

}

int �������^::Get_������(int ���蕐���ԍ�) {
	if (0 <= ���蕐���ԍ� && ���蕐���ԍ� < GAMEDATASTRUCT_BUSHOU_NUM) {
		return getBushouAishoDiff(iBushouID, ���蕐���ԍ�);
	}
	else {
		return 8; // �ň��̑�������Ԃ��Ă����B
	}
}

bool �������^::Is_�v���C����������::get() {
	return isPlayerBushou(iBushouID);
}

bool �������^::Is_�v���C���S������::get() {
	int iGundanID = nb6bushou[iBushouID].gundan - 1;
	if ( 0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM ) {
		int number = nb6gundan[iGundanID].number;
		if (number == 1) {
			return isPlayerBushou(iBushouID);
		}
		return false;
	}
	return false;
}

bool �������^::Is_�����͑���̖�(int ���蕐���ԍ�) {
	return is�����͑���̖�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̑��q(int ���蕐���ԍ�) {
	return is�����͑���̑��q(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̎q(int ���蕐���ԍ�) {
	return is�����͑���̎q(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̐e(int ���蕐���ԍ�) {
	return is�����͑���̐e(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̕�(int ���蕐���ԍ�) {
	return is�����͑���̕�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̕�(int ���蕐���ԍ�) {
	return is����͎����̕�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̕�(int ���蕐���ԍ�) {
	return is�����͑���̕�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̕�(int ���蕐���ԍ�) {
	return is����͎����̕�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̒�(int ���蕐���ԍ�) {
	return is�����͑���̒�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̒�(int ���蕐���ԍ�) {
	return is����͎����̒�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̖�(int ���蕐���ԍ�) {
	return is�����͑���̖�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̖�(int ���蕐���ԍ�) {
	return is����͎����̖�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̌Z(int ���蕐���ԍ�) {
	return is�����͑���̌Z(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̌Z(int ���蕐���ԍ�) {
	return is����͎����̌Z(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̎o(int ���蕐���ԍ�) {
	return is�����͑���̎o(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̎o(int ���蕐���ԍ�) {
	return is����͎����̎o(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����Ƒ���͌Z��(int ���蕐���ԍ�) {
	return is�����Ƒ���͌Z��(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����Ƒ���͎o��(int ���蕐���ԍ�) {
	return is�����Ƒ���͎o��(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����Ƒ���͎o��(int ���蕐���ԍ�) {
	return is�����Ƒ���͎o��(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����Ƒ���͌Z��(int ���蕐���ԍ�) {
	return is�����Ƒ���͌Z��(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̕v(int ���蕐���ԍ�) {
	return is�����͑���̕v(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̍�(int ���蕐���ԍ�) {
	return is�����͑���̍�(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����͑���̌���(int ���蕐���ԍ�) {
	return is�����͑���̌���(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̉Ɛb(int ���蕐���ԍ�) {
	return is����͎����̉Ɛb(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_����͎����̑喼(int ���蕐���ԍ�) {
	return is����͎����̑喼(iBushouID, ���蕐���ԍ�);
}

bool �������^::Is_�����Ƒ���͓����喼�Ə���(int ���蕐���ԍ�) {
	return is�����Ƒ���͓����喼�Ə���(iBushouID, ���蕐���ԍ�);
}

bool �������^::�푈�������^::�ދp��::get()
{
	return nb6bushouname[iBushouID].battleRetreat;
}

int �������^::�푈�������^::�Q�헧��::get() {
	return GetWarStandPointTheBushou(iBushouID);
}

int �������^::�푈�������^::�������::get() {
	return GetKonranStatus(iBushouID);
}

bool �������^::�푈�������^::�s����::get() {
	if (IsActionEndInBattle(iBushouID)) {
		return true;
	}
	return false;
}

int �������^::�푈�������^::�@����::get() {
	return GetBushouMovePower(iBushouID);
}

void �������^::�푈�������^::�@����::set(int value) {
	if ( 0 <= value && value < 100 ) {
		SetBushouMovePower(iBushouID, value);
	}
}


bool �������^::�푈�������^::�o�w��::get() {
	vector<int> list = GetSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

bool �������^::�푈�������^::�o�w��_�\�����::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	for each (int iBID in list) {
		if (iBID == iBushouID) {
			return true;
		}
	}
	return false;
}

�w�b�N�X�ʒu�^^ �������^::�푈�������^::�w�b�N�X�ʒu::get() {
	�w�b�N�X�ʒu�^^ pos = gcnew �w�b�N�X�ʒu�^();
	if (Is_FieldWar()) {
		HEX_POSITION p = GetFieldHexUnitPos(iBushouID);
		pos->�w = p.x;
		pos->�x = p.y;
	}
	else {
		pos->�w = 0xFFFF;
		pos->�x = 0xFFFF;
	}

	return pos;
}


�������X�g���^::�������X�g���^() {

	�z�� = gcnew List<�������^^>();
	�z��->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++)
	{
		�z��->Add(gcnew �������^(i));
	}

	�푈 = gcnew �푈�������X�g���^();
}

int �������X�g���^::Find_�����ԍ�(int ��`�ԍ�) {
	int iBushouID = getBushouIDFromFaceID(��`�ԍ�);
	return iBushouID;
}

int �������X�g���^::Find_�����ԍ�(String^ ����) {

	for (int i = 0; i < GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (���� == gcnew String(nb6bushouname[i].familyname) + gcnew String(nb6bushouname[i].fastname) ) {
			return i;
		}
	}

	return 0xFFFF;
}

List<int>^ �������X�g���^::�푈�������X�g���^::�o�w��_�����ԍ����X�g::get() {
	vector<int> list = GetSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

List<int>^ �������X�g���^::�푈�������X�g���^::�o�w��_�\�����_�����ԍ����X�g::get() {
	vector<int> list = GetCurMapSyutujinBushouArray();
	List<int>^ m_list = gcnew List<int>();
	for each (int iBID in list) {
		m_list->Add(iBID);
	}
	return m_list;
}

