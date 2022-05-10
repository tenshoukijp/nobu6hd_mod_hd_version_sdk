#pragma once

#include "GameDataStruct.h"

extern char szLastestRequestScenarioOriginalFileName[MAX_PATH];
extern char szLastestRequestScenarioFileName[MAX_PATH];

namespace Native {
	string On_ファイル要求時(string strFileName, int iBufAdress);
}