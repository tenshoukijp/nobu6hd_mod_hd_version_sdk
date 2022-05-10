#include "GameDataStruct.h"

// ���݂̃Q�[���i�s���̔N���𓾂�B
int getYearAD() {
	return nb6year.year + getStartYearAD();
}


// �Q�[���̊J�n�N�B�f�t�H���g��1454�N�ł���B
constexpr int getStartYearAD() {
	return 1454;
}


// ���݂̃Q�[���i�s���̋G�߂𓾂�
static char szSeasonName[5][3] = { "�t", "��", "�H", "�~", "��" };
char* getSeasonName() {
	char season = nb6year.season;

	if (0 <= season && season <= 3) {
		return szSeasonName[season];
	}
	return szSeasonName[4];
}
