#include "GameDataStruct.h"

int —ïî•ñŒ^::¼—ï::get()
{
	return getYearAD();
}

void —ïî•ñŒ^::¼—ï::set(int value)
{
	if (getStartYearAD() <= value && value <= getStartYearAD() + LIMIT_BYTE_MAX) {
		nb6year.year = value - getStartYearAD();
	}
}

int —ïî•ñŒ^::‹Gß::get()
{
	int attr = nb6year.season;
	return attr;
}

void —ïî•ñŒ^::‹Gß::set(int value)
{
	if (—ñ‹“::—ï::‹Gß::t <= value && value <= —ñ‹“::—ï::‹Gß::“~) {
		nb6year.season = value;
	}
}

int —ïî•ñŒ^::“VãÄ‹LŠî€”N::get()
{
	return getStartYearAD();
}

˜a—ïŒ^^ —ïî•ñŒ^::Get_˜a—ï() {
	return Get_˜a—ï(getYearAD(), 12, 31);
}

˜a—ïŒ^^ —ïî•ñŒ^::Get_˜a—ï(int ”N, int Œ, int “ú) {
	// ¡‚ÌŒ³†
	NB6WAREKI native_wrk = getWarekiFromYMD(”N, Œ, “ú);
	˜a—ïŒ^^ managed_wrk = gcnew ˜a—ïŒ^();
	managed_wrk->Œ³† = to_managed_string(string(native_wrk.gengou));
	managed_wrk->Š¿š‹I”N = to_managed_string(string(native_wrk.kanjiyear));
	managed_wrk->”’l‹I”N = native_wrk.iyear;

	return managed_wrk;
}

