#pragma once

#include <windows.h>

#include "GetWarekiFromYMD.h"


////////////////////////////////////////////////////////////////////////////
// NB6 �V�ċL
/*
[�N�����(3*1)]

0-1		�N��(1454����̌o�ߐ�)
2		�G��(0=�t,1=��,2=�H,3=�~)
*/
struct NB6YEAR
{
	WORD year;			// �N��(1454����̌o�ߐ�)	 �� �������ڂł͂Ȃ��AgetYearAD�œ��邱��
	char season;		// �G��(0=�t,1=��,2=�H,3=�~) �� �������ڂł͂Ȃ�getSeasonName�œ��邱��
};



// 1454�N����̍����ƂȂ��Ă���N�𐼗�ɒ���
int getYearAD();

// �Q�[���̊J�n�N�B�f�t�H���g��1454�N
constexpr int getStartYearAD();


// ���݂̋G�ߖ��𓾂�
char* getSeasonName();



