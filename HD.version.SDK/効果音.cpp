#include "GameDataStruct.h"


���ʉ��n���h���^ ���ʉ����^::Do_���ʉ��Đ�(int ���ʉ�����) {
	if (0 <= ���ʉ����� && ���ʉ����� <= ��::���ʉ�::���ʉ�����::��) {
		FuncPlaySound(���ʉ�����);
		iSoundID++;
		return iSoundID;
	}
	return 0;
}
