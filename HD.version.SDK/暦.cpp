#include "GameDataStruct.h"

int ďîń^::źď::get()
{
	return getYearAD();
}

void ďîń^::źď::set(int value)
{
	if (getStartYearAD() <= value && value <= getStartYearAD() + LIMIT_BYTE_MAX) {
		nb6year.year = value - getStartYearAD();
	}
}

int ďîń^::Gß::get()
{
	int attr = nb6year.season;
	return attr;
}

void ďîń^::Gß::set(int value)
{
	if (ń::ď::Gß::t <= value && value <= ń::ď::Gß::~) {
		nb6year.season = value;
	}
}

int ďîń^::VăÄLîN::get()
{
	return getStartYearAD();
}

aď^^ ďîń^::Get_aď() {
	return Get_aď(getYearAD(), 12, 31);
}

aď^^ ďîń^::Get_aď(int N, int , int ú) {
	// ĄĚł
	NB6WAREKI native_wrk = getWarekiFromYMD(N, , ú);
	aď^^ managed_wrk = gcnew aď^();
	managed_wrk->ł = to_managed_string(string(native_wrk.gengou));
	managed_wrk->żIN = to_managed_string(string(native_wrk.kanjiyear));
	managed_wrk->lIN = native_wrk.iyear;

	return managed_wrk;
}

