#include "GameDataStruct.h"

int ����^::����::get()
{
	return getYearAD();
}

void ����^::����::set(int value)
{
	if (getStartYearAD() <= value && value <= getStartYearAD() + LIMIT_BYTE_MAX) {
		nb6year.year = value - getStartYearAD();
	}
}

int ����^::�G��::get()
{
	int attr = nb6year.season;
	return attr;
}

void ����^::�G��::set(int value)
{
	if (��::��::�G��::�t <= value && value <= ��::��::�G��::�~) {
		nb6year.season = value;
	}
}

int ����^::�V�ċL��N::get()
{
	return getStartYearAD();
}

�a��^^ ����^::Get_�a��() {
	return Get_�a��(getYearAD(), 12, 31);
}

�a��^^ ����^::Get_�a��(int �N, int ��, int ��) {
	// ���̌���
	NB6WAREKI native_wrk = getWarekiFromYMD(�N, ��, ��);
	�a��^^ managed_wrk = gcnew �a��^();
	managed_wrk->���� = to_managed_string(string(native_wrk.gengou));
	managed_wrk->�����I�N = to_managed_string(string(native_wrk.kanjiyear));
	managed_wrk->���l�I�N = native_wrk.iyear;

	return managed_wrk;
}

