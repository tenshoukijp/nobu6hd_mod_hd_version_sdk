#include "GameDataStruct.h"


void SetScenatioTitle(char *pszTitle, char *szNewString) {
	strncpy(pszTitle, szNewString, 32); // タイトルは32バイト幅
	pszTitle[31] = NULL; // 最後は必ずNULL;
}