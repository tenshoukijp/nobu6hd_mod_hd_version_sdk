#include "GameDataStruct.h"

int isFieldWarOrCastleWar = -1; // 1:野戦で出陣が終わった後(まさに野戦が始まった。) 2:攻城戦
bool Is_FieldWar() {
	bool iswar = IsDoingWar();
	if (!iswar) {
		return false;
	}

	if (isFieldWarOrCastleWar == warstatus::野戦表示突入前 || isFieldWarOrCastleWar == warstatus::野戦ターン時) {
		return true;
	}

	return false;
}

bool Is_CastleWar() {

	bool iswar = IsDoingWar();
	if (!iswar) {
		return false;
	}

	if (isFieldWarOrCastleWar == warstatus::城表示突入前) {
		return true;
	}
	return false;
}

int getFieldTurnInBattle() {
	if (iFieldTurnOfChangeFieldWarTurnExecute == 0xFFFF) {
		return 0xFFFF;
	}
	else {
		return (31 - iFieldTurnOfChangeFieldWarTurnExecute);
	}

}


// 天気情報を得る 0:晴れ 1:曇り 2:雨 3:雪
int GetWeather() {

	return int(nb6weather);
}


// 戦争が発生した時の中央の城番号(配列用)。戦争が発生していない時は0xFFFFを返す。
int GetWarCenterCastle() {
	int iCastleID = nb6battle_center_castle - 1;
	if (iCastleID >= 0xFFFE) { // WORD最大値付近であれば、
		return 0xFFFF;			// 戦争は発生していない。 
	}
	else if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		return iCastleID;		// 普通の城
	}
	else {
		return -1;
	}
}


bool IsDoingWar() {
	int iCastleID = GetWarCenterCastle();
	if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		return true;
	}

	return false;
}

