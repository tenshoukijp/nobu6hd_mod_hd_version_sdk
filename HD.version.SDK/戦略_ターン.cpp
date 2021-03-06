#include "GameDataStruct.h"

int 戦略ターン情報型::ターン大名番号::get()
{
	int attr = nb6turn.daimyo;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int 戦略ターン情報型::ターン軍団番号::get()
{
	int attr = nb6turn.gundan;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}
