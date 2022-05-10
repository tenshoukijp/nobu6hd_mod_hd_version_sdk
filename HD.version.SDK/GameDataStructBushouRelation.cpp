#include "GameDataStruct.h"

bool is�����͑���̖�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent == nb6bushouname[i2nd_BushouID].number &&
			getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}

bool is�����͑���̑��q(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent == nb6bushouname[i2nd_BushouID].number &&
			getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is�����͑���̎q(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i2nd_BushouID].parent == nb6bushouname[i1st_BushouID].number &&
			getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID)) {

			return true;
		}
	}
	return false;
}

bool is�����͑���̐e(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		if (nb6bushou[i2nd_BushouID].parent == nb6bushouname[i1st_BushouID].number &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID)) {

			return true;
		}
	}
	return false;
}

bool is�����͑���̕�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i2nd_BushouID].parent == nb6bushouname[i1st_BushouID].number &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is����͎����̕�(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̕�(i2nd_BushouID, i1st_BushouID);
}



bool is�����͑���̕�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i2nd_BushouID].parent == nb6bushouname[i1st_BushouID].number &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}

bool is����͎����̕�(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̕�(i2nd_BushouID, i1st_BushouID);
}

bool is�����͑���̒�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is����͎����̒�(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̒�(i2nd_BushouID, i1st_BushouID);
}

bool is�����͑���̖�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) < getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}

bool is����͎����̖�(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̖�(i2nd_BushouID, i1st_BushouID);
}

bool is�����͑���̌Z(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is����͎����̌Z(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̌Z(i2nd_BushouID, i1st_BushouID);
}


bool is�����͑���̎o(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}

bool is����͎����̎o(int i1st_BushouID, int i2nd_BushouID) {
	return is�����͑���̎o(i2nd_BushouID, i1st_BushouID);
}

bool is�����Ƒ���͌Z��(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0 && nb6bushouname[i2nd_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is�����Ƒ���͎o��(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1 && nb6bushouname[i2nd_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}


bool is�����Ƒ���͎o��(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 1 && nb6bushouname[i2nd_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}



bool is�����Ƒ���͌Z��(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].parent < 5000 &&
			nb6bushou[i1st_BushouID].parent == nb6bushou[i2nd_BushouID].parent &&
			getYearsOld(i1st_BushouID) > getYearsOld(i2nd_BushouID) &&
			nb6bushouname[i1st_BushouID].sex == 0 && nb6bushouname[i2nd_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}




bool is�����͑���̕v(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].spouse != 0xFF &&
			nb6bushou[i1st_BushouID].spouse == nb6bushou[i2nd_BushouID].spouse &&
			nb6bushouname[i1st_BushouID].sex == 0) {

			return true;
		}
	}
	return false;
}

bool is�����͑���̍�(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].spouse != 0xFF &&
			nb6bushou[i1st_BushouID].spouse == nb6bushou[i2nd_BushouID].spouse &&
			nb6bushouname[i1st_BushouID].sex == 1) {

			return true;
		}
	}
	return false;
}


bool is�����͑���̌���(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushou[i1st_BushouID].blood != 0xFF &&
			nb6bushou[i1st_BushouID].blood == nb6bushou[i2nd_BushouID].blood) {

			return true;
		}
	}
	return false;
}

bool is����͎����̉Ɛb(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// ��P�l�̂͑喼
		if (nb6bushouname[i1st_BushouID].State == 0) {
			// ��Q�l�̂͑喼�ɂ����Ə������Ă���B
			if (0 < nb6bushou[i2nd_BushouID].attach && nb6bushou[i2nd_BushouID].attach <= GAMEDATASTRUCT_DAIMYO_NUM) {
				int iAttachDaimyoID = nb6bushou[i2nd_BushouID].attach - 1;
				if (i1st_BushouID == nb6daimyo[iAttachDaimyoID].attach - 1) {
					return true;
				}
			}
		}
	}
	return false;
}

bool is����͎����̑喼(int i1st_BushouID, int i2nd_BushouID) {
	return is����͎����̉Ɛb(i2nd_BushouID, i1st_BushouID);
}

// �Ɛb�͂������A�喼���g�������̑喼�Ƃɏ������Ă���Ƃ݂Ȃ����B
bool is�����Ƒ���͓����喼�Ə���(int i1st_BushouID, int i2nd_BushouID) {
	if (0 <= i1st_BushouID && i1st_BushouID < GAMEDATASTRUCT_BUSHOU_NUM &&
		0 <= i2nd_BushouID && i2nd_BushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		int i1stAttachDaimyoID = -1;
		int i2ndAttachDaimyoID = -1;

		// ��P�l�̂͑喼�ɂ����Ə������Ă���B
		if (0 < nb6bushou[i1st_BushouID].attach && nb6bushou[i1st_BushouID].attach <= GAMEDATASTRUCT_DAIMYO_NUM) {
			i1stAttachDaimyoID = nb6bushou[i1st_BushouID].attach - 1;
		}

		// ��Q�l�̂͑喼�ɂ����Ə������Ă���B
		if (0 < nb6bushou[i2nd_BushouID].attach && nb6bushou[i2nd_BushouID].attach <= GAMEDATASTRUCT_DAIMYO_NUM) {
			i2ndAttachDaimyoID = nb6bushou[i2nd_BushouID].attach - 1;
		}

		if (i1stAttachDaimyoID != -1 && i2ndAttachDaimyoID != -1) {
			if (i1stAttachDaimyoID == i2ndAttachDaimyoID) {
				return true;
			}
		}
	}
	return false;
}
