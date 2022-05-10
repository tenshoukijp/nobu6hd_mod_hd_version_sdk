#include "GameDataStruct.h"

int 戦争ターン情報型::残りターン::get() {
	if (Is_FieldWar() || Is_CastleWar()) {
		return getFieldTurnInBattle();
	}

	return 0xFFFF;
}