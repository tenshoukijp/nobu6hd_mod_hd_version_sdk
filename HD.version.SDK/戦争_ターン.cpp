#include "GameDataStruct.h"

int �푈�^�[�����^::�c��^�[��::get() {
	if (Is_FieldWar() || Is_CastleWar()) {
		return getFieldTurnInBattle();
	}

	return 0xFFFF;
}