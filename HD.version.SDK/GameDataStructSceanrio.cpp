#include "GameDataStruct.h"


void SetScenatioTitle(char *pszTitle, char *szNewString) {
	strncpy(pszTitle, szNewString, 32); // �^�C�g����32�o�C�g��
	pszTitle[31] = NULL; // �Ō�͕K��NULL;
}