#include "GameDataStruct.h"

int isFieldWarOrCastleWar = -1; // 1:���ŏo�w���I�������(�܂��ɖ�킪�n�܂����B) 2:�U���
bool Is_FieldWar() {
	bool iswar = IsDoingWar();
	if (!iswar) {
		return false;
	}

	if (isFieldWarOrCastleWar == warstatus::���\���˓��O || isFieldWarOrCastleWar == warstatus::���^�[����) {
		return true;
	}

	return false;
}

bool Is_CastleWar() {

	bool iswar = IsDoingWar();
	if (!iswar) {
		return false;
	}

	if (isFieldWarOrCastleWar == warstatus::��\���˓��O) {
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


// �V�C���𓾂� 0:���� 1:�܂� 2:�J 3:��
int GetWeather() {

	return int(nb6weather);
}


// �푈�������������̒����̏�ԍ�(�z��p)�B�푈���������Ă��Ȃ�����0xFFFF��Ԃ��B
int GetWarCenterCastle() {
	int iCastleID = nb6battle_center_castle - 1;
	if (iCastleID >= 0xFFFE) { // WORD�ő�l�t�߂ł���΁A
		return 0xFFFF;			// �푈�͔������Ă��Ȃ��B 
	}
	else if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		return iCastleID;		// ���ʂ̏�
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

