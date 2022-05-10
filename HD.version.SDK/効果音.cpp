#include "GameDataStruct.h"


Œø‰Ê‰¹ƒnƒ“ƒhƒ‹Œ^ Œø‰Ê‰¹î•ñŒ^::Do_Œø‰Ê‰¹Ä¶(int Œø‰Ê‰¹‰¹Œ¹) {
	if (0 <= Œø‰Ê‰¹‰¹Œ¹ && Œø‰Ê‰¹‰¹Œ¹ <= —ñ‹“::Œø‰Ê‰¹::Œø‰Ê‰¹‰¹Œ¹::á) {
		FuncPlaySound(Œø‰Ê‰¹‰¹Œ¹);
		iSoundID++;
		return iSoundID;
	}
	return 0;
}
