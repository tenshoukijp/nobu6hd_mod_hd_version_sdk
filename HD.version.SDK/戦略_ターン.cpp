#include "GameDataStruct.h"

int �헪�^�[�����^::�^�[���喼�ԍ�::get()
{
	int attr = nb6turn.daimyo;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_DAIMYO_NUM) {
		return attr;
	}

	return 0xFFFF;
}

int �헪�^�[�����^::�^�[���R�c�ԍ�::get()
{
	int attr = nb6turn.gundan;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_GUNDAN_NUM) {
		return attr;
	}

	return 0xFFFF;
}
