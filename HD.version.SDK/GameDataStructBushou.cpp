#include "GameDataStruct.h"

// �����̔N��𓾂�
int getYearsOld(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		return nb6year.year - nb6bushou[iBushouID].birth + 1;
	}
	return 0xFF;
}


// ���y�E�R�n�E�S�C�E���R�̓K���𐔒l�œ���B(0=E,1=D,2=C,3=B,4=A,5=S)
int getBushouAptitude(int iBushouID, APTITUDE eAptitude) {
	if (eAptitude == APTITUDE_ASIGARU) {
		return nb6bushou[iBushouID].aptitudeasi;
	}
	else if (eAptitude == APTITUDE_KIBA) {
		return nb6bushou[iBushouID].aptitudekib;
	}
	else if (eAptitude == APTITUDE_TEPPOU) {
		// �S�C�͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
		int ret = nb6bushou[iBushouID]._aptitudegun_lo << 2;
		ret += nb6bushou[iBushouID]._aptitudegun_hi;
		return ret;
	}
	else if (eAptitude == APTITUDE_SUIGUN) {
		return nb6bushou[iBushouID].aptitudesui;
	}
	return -1;
}



// ���y�E�R�n�E�S�C�E���R�̓K���𐔒l�Őݒ肷��B(0=E,1=D,2=C,3=B,4=A,5=S)
void setBushouAptitude(int iBushouID, APTITUDE eAptitude, int iTekisei) {
	if (eAptitude == APTITUDE_ASIGARU) {
		nb6bushou[iBushouID].aptitudeasi = iTekisei;
	}
	else if (eAptitude == APTITUDE_KIBA) {
		nb6bushou[iBushouID].aptitudekib = iTekisei;
	}
	else if (eAptitude == APTITUDE_TEPPOU) {
		// �S�C�͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
		nb6bushou[iBushouID]._aptitudegun_hi = iTekisei & 0x0003;  // 0b000000HH
		nb6bushou[iBushouID]._aptitudegun_lo = iTekisei >> 2;      // 0b00000L00
	}
	else if (eAptitude == APTITUDE_SUIGUN) {
		nb6bushou[iBushouID].aptitudesui = iTekisei;
	}
}



// �����̓Ɨ��l�𓾂�
int getBushouIndependence(int iBushouID) {
	// �S�C�͂Q�̃t�B�b�g�t�B�[���h�ɕ�����Ă��܂��Ă���̂ŁA�v�Z
	int ret = nb6bushou[iBushouID]._independence_lo << 2;
	ret += nb6bushou[iBushouID]._independence_hi;
	return ret;
}

// �����̓Ɨ��l��ݒ肷��
void setBushouIndependence(int iBushouID, int iIndependence) {
	nb6bushou[iBushouID]._independence_hi = iIndependence & 0x0003;  // 0b000000HH
	nb6bushou[iBushouID]._independence_lo = iIndependence >> 2;      // 0b00000L00
}

// �����̐퓬�l
int getBushouBat(int iBushouID) {
	// ��ˁ~��m/2000��
	return int(nb6bushou[iBushouID].maxbat * (float(nb6bushou[iBushouID].expbat) / float(2000)));
}
// �����̒q�d�l
int getBushouInt(int iBushouID) {
	// ��ˁ~��m/2000��
	return int(nb6bushou[iBushouID].maxint * (float(nb6bushou[iBushouID].expint) / float(2000)));
}
// �����̐����l
int getBushouGov(int iBushouID) {
	// ��ˁ~��m/2000��
	return int(nb6bushou[iBushouID].maxgov * (float(nb6bushou[iBushouID].expgov) / float(2000)));
}


// �ƕ�Ȃǂ��܂߂Ȃ��f�̐����˔\
int getBushouPureGovMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
			if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�l
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxgov = nb6bushou[iBushouID].maxgov;
		return (maxgov - upparam) > 0 ? (maxgov - upparam) : 1;
	}
	else {
		return 0;
	}
}

// �ƕ�Ȃǂ��܂߂Ȃ��f�̐퓬�˔\
int getBushouPureBatMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
			if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxbat = nb6bushou[iBushouID].maxbat;
		return (maxbat - upparam) > 0 ? (maxbat - upparam) : 1;
	}
	else {
		return 0;
	}
}

// �ƕ�Ȃǂ��܂߂Ȃ��f�̒q�d�˔\
int getBushouPureIntMax(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
			if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int maxint = nb6bushou[iBushouID].maxint;
		return (maxint - upparam) > 0 ? (maxint - upparam) : 1;
	}
	else {
		return 0;
	}
}

// �ƕ�Ȃǂ��܂߂Ȃ��f�̖�]
int getBushouPureAmbition(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
			if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		int ambition = nb6bushou[iBushouID].ambition;
		return (ambition - upparam) > 0 ? (ambition - upparam) : 1;
	}
	else {
		return 0;
	}
}

// ���ʂȂǂ��܂߂Ȃ��f�̖���
int getBushouPureCharm(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKaniID = 0; iKaniID < GAMEDATASTRUCT_KANI_NUM; iKaniID++) {
			// ������Ǝw�蕐������v����
			if (nb6kani[iKaniID].attach == iBushouID + 1) {
				// ���܂łōő�̏㏸�n
				if (nb6kani[iKaniID].param > upparam) {
					upparam = nb6kani[iKaniID].param;
				}
			}
		}

		int charm = nb6bushou[iBushouID].charm;
		return (charm - upparam) > 0 ? (charm - upparam) : 1;
	}
	else {
		return 0;
	}
}



// �ƕ�ɂ�鐭���̏グ��
int getBushouGovMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// ���������^�C�v�F0 ���q  1 ����  2 ����  3 ����  4 �ԓ�  
			if (0 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 4) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�l
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}

// �ƕ�ɂ��퓬�̏グ��
int getBushouBatMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// �퓬�����^�C�v�F5 ����  6 ��  7 �  8 �n  9 ��  A �w�H�D   
			if (5 <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xA) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}

// �ƕ�ɂ��q�d�̏グ��
int getBushouIntMaxUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// �q�d�����^�C�v�FB ���q�{  C �����Ԗ{
			if (0xB <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0xC) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}

		return upparam;
	}
	else {
		return 0;
	}
}

// �ƕ�ɂ���]�̏グ��
int getBushouAmbitionUpByKahou(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKahouID = 0; iKahouID < GAMEDATASTRUCT_KAHOU_NUM; iKahouID++) {
			// ��]�����^�C�v�FD ����  E �n���V  F ��؎��v  10 ���n��  11 �\����  12 ����  13 �ʎ蔠  14 �r�[�h���t  15 ���ዾ  16 ���\����  17 ����
			if (0xD <= nb6kahou[iKahouID].type && nb6kahou[iKahouID].type <= 0x17) {
				// ������Ǝw�蕐������v����
				if (nb6kahou[iKahouID].attach == iBushouID + 1) {
					// ���܂łōő�̏㏸�n
					if (nb6kahou[iKahouID].param > upparam) {
						upparam = nb6kahou[iKahouID].param;
					}
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}


// ���ʂɂ�閣�͂̏グ��
int getBushouCharmUpByKani(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		int upparam = 0; // �㏸�l
		for (int iKaniID = 0; iKaniID < GAMEDATASTRUCT_KANI_NUM; iKaniID++) {
			// ������Ǝw�蕐������v����
			if (nb6kani[iKaniID].attach == iBushouID + 1) {
				// ���܂łōő�̏㏸�n
				if (nb6kani[iKaniID].param > upparam) {
					upparam = nb6kani[iKaniID].param;
				}
			}
		}
		return upparam;
	}
	else {
		return 0;
	}
}




// ��ID���畐��ID�����߂�B���s����0xFFFF
int getBushouIDFromFaceID(int iFaceID) {
	for (int iBushouID = 0; iBushouID<GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
		if (nb6bushouname[iBushouID].number == iFaceID) {
			return iBushouID;
		}
	}
	return 0xFFFF;
}


// �w�蕐���̔�����iBushouID�𓾂�B���������Ȃ��ꍇ�ɂ́A0xFFFF���Ԃ��Ă���B
int getHanryoBushouID(int iBushouID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �w��̕����̔������
		int iBushouIDSpouse = nb6bushou[iBushouID].spouse; //

														   // �������Ă��Ȃ�
		if (iBushouIDSpouse == 0xFF) {
			return 0xFFFF;
		}

		int iTsumaBushouID = iBushouIDSpouse + 500;

		// �����̔ԍ����������g��������A�����͍ȑ��̗���
		if (iTsumaBushouID == iBushouID) {
			for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
				// �������g�ȊO�ŁA���������ԍ��������Ă�̂��A�����̕���
				if (i != iBushouID &&  nb6bushou[i].spouse == iBushouIDSpouse) {
					return i;
				}
			}
			return 0xFFFF;

			// �����͕v���B�Ȃɂ������ԍ����ݒ肳��Ă��邩�m�F�B
		}
		else {
			if (nb6bushou[iTsumaBushouID].spouse == iBushouIDSpouse) {
				return iTsumaBushouID;
				// �Ȃ����ݒ肳��Ă��Ȃ��c�B�������Ńf�[�^���Ă���B
			}
			else {
				return 0xFFFF;
			}
		}
	}
	else {
		return 0xFFFF;
	}
}

// �P(���̕����̍Ȋ܂�)���A�w��̕����ƌ���������A�����֌W���͈�ؑ��삳��Ȃ��B
bool setHimeMarriage(int iHimeID, int iOttoID, BOOL withKodokuDeath) {

	// ����l���B�A�E�g�B
	if (iHimeID == iOttoID) { return false; }

	// �v�ƕP���K��͈̔͂ɓ����Ă��Ȃ���΃A�E�g
	if (0 <= iOttoID && iOttoID < GAMEDATASTRUCT_BUSHOU_NUM &&
		500 <= iHimeID && iHimeID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// �����P���̂h�c�̕������A�P�łȂ��Ȃ�΁A�A�E�g
		if (nb6bushouname[iHimeID].State != 5) { // 
			return false;
		}

		int _new_spouse = iHimeID - 500; // �Ȃɓ���ׂ��l�́A�P�����ԍ��y�z��p�z-500

										 // ���łɗ��҂͕v�w�ł���A��������K�v�������B
		if (nb6bushou[iOttoID].spouse == _new_spouse &&  nb6bushou[iHimeID].spouse == _new_spouse) {
			return true;
		}

		// �v�������łɌ������Ă��邩�A�������Ă����痣��
		int _otto_old_spouse = nb6bushou[iOttoID].spouse; //
														  // ����
		setHimeDivorce(_otto_old_spouse + 500, withKodokuDeath);

		nb6bushouname[iHimeID].State = 5; // �V�W�ǓƏ����Ŏ��S������������Ȃ��̂ŕP�ɖ߂��B

		int _tuma_old_spouse = nb6bushou[iHimeID].spouse; //
		setHimeDivorce(_tuma_old_spouse + 500, withKodokuDeath);

		nb6bushouname[iHimeID].State = 5; // �V�W�ǓƏ����Ŏ��S������������Ȃ��̂ŕP�ɖ߂��B

										  // �g���Y��ɂȂ����̂ŉ��߂Č���
		nb6bushou[iOttoID].spouse = _new_spouse;
		nb6bushou[iHimeID].spouse = _new_spouse;

		// ���喼�Ƃ��o���Ă�����
		int OldDaimyoID = nb6bushou[iHimeID].attach;

		// �v���̑喼�̕��ɐg���񂹂�
		nb6bushou[iHimeID].attach = nb6bushou[iOttoID].attach;

		// ������v�̂��̂ŏ㏑������B
		strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iOttoID].familyname);

		// ���ʁA�喼�Ƃ��ω������̂ł���΁A�m���N�������Z�b�g
		if (OldDaimyoID != nb6bushou[iHimeID].attach) {
			nb6bushou[iHimeID].work = 0;
		}

		return true;
	}

	return false;
}


// �w��̕P�𗣍�������B
bool setHimeDivorce(int iHimeID, BOOL withKodokuDeath) {

	// �v�ƕP���K��͈̔͂ɓ����Ă��Ȃ���΃A�E�g
	if (500 <= iHimeID && iHimeID < GAMEDATASTRUCT_BUSHOU_NUM) {


		// �����P���̂h�c�̕������A�P�łȂ��Ȃ�΁A�A�E�g
		if (nb6bushouname[iHimeID].State != 5) {
			return false;
		}

		int _tuma_spouse = nb6bushou[iHimeID].spouse; //

													  // ���X�������Ă��Ȃ��B
		if (_tuma_spouse == 0xFF) {
			return false;
		}

		// ���҂̌��������N���A
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
			// �v�������͍Ȃł���
			if (nb6bushou[iBushouID].spouse == _tuma_spouse) {
				// ����
				nb6bushou[iBushouID].spouse = 0xFF;
				// �v�ƍ�2�l�����Ƃ��l��0xFF�ɂ���K�v������̂ŁAbreak���Ȃ����ƁB
				// ���łɃf�[�^�ɃS�~�������Ă���ꍇ�ł��N���A
			}
		}


		// ���喼�Ƃ��o���Ă�����
		int OldDaimyoID = nb6bushou[iHimeID].attach;

		// �ȉ��̐g������l�n�̏����́A�v���O�������ŏo���邾������Ă������Ƃ�����|�B
		// ���ɂ����œK�؂ȑ喼�ɋA���]�ڂł��Ȃ������Ƃ��Ă��A�V�ċL�̃v���O�����{�̂����G�ߎ��ɂ́A�K�؂ȑ喼�ɋA�������鏈�����s���B

		// ���������̂ŏ����喼��ύX����K�v��������B�܂��A�e���喼�����Ă��邩�ǂ����B
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// �喼�̂����c
			if (nb6bushouname[iBushouID].State == 0) { // �喼

													   // �����̐e���喼����Ă�B
				if (nb6bushou[iHimeID].parent < 5000) {
					// ���̑喼�͕P�̐e
					if (nb6bushouname[iBushouID].number == nb6bushou[iHimeID].parent) {

						// �����ɐg���񂹂�
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}


		// �e���喼������Ă��Ȃ��Ƃ��A�e�������l(�����Z��o��)���喼������Ă��邩�ǂ����B
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// �喼�̂����c
			if (nb6bushouname[iBushouID].State == 0) { // �喼

													   // �e���������B
				if (nb6bushou[iHimeID].parent < 5000) {
					if (nb6bushou[iBushouID].parent == nb6bushou[iHimeID].parent) {

						// �����ɐg���񂹂�
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}

		// �e�Z�킪�喼����Ă��Ȃ��Ă��A��傪�喼������Ă���̂ł͂Ȃ����B
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// �喼�̂����c
			if (nb6bushouname[iBushouID].State == 0) { // �喼

													   // �e���������B
				if (nb6bushou[iHimeID].blood != 0xFF) {
					if (nb6bushou[iBushouID].blood == nb6bushou[iHimeID].blood) {

						// �����ɐg���񂹂�
						nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

						strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);
						break;
					}
				}
			}
		}

		bool isTengaiKodoku = true;
		// �喼�łȂ��Ƃ��A�e���ǂ����ɂ���̂ł͂Ȃ����H
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// �����̐e
			if (nb6bushou[iHimeID].parent < 5000) {
				if (nb6bushouname[iBushouID].number == nb6bushou[iHimeID].parent) {

					// �����ɐg���񂹂�
					nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

					strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);

					// �g��肪�����̂œV�W�ǓƂł͂Ȃ�
					isTengaiKodoku = false;
					break;
				}
			}
		}

		// �喼�łȂ��Ƃ��A�e�������l(�����Z��o��)���ǂ����ɂ���̂ł͂Ȃ����H
		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {

			// �e���������B
			if (nb6bushou[iHimeID].parent < 5000) {
				if (nb6bushou[iBushouID].parent == nb6bushou[iHimeID].parent) {

					// �����ɐg���񂹂�
					nb6bushou[iHimeID].attach = nb6bushou[iBushouID].attach;

					strcpy(nb6bushouname[iHimeID].familyname, nb6bushouname[iBushouID].familyname);

					// �g��肪�����̂œV�W�ǓƂł͂Ȃ�
					isTengaiKodoku = false;
					break;
				}
			}
		}


		// ���ʁA�喼�Ƃ��ω������̂ł���΁A�m���N�������Z�b�g
		if (OldDaimyoID != nb6bushou[iHimeID].attach) {
			nb6bushou[iHimeID].work = 0;
		}

		if (withKodokuDeath) {
			if (isTengaiKodoku) {
				nb6bushouname[iHimeID].State = 7; // �V�W�ǓƂɂȂ����玀�S�Ƃ���B
			}
		}

		return true;
	}

	return false;
}




// State ���� �� State �Q�l��
bool setGenekiToRounin(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		if (nb6bushouname[iBushouID].State == 2) { // ���𕐏��̏ꍇ��������������B

												   // �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = nb6bushou[iBushouID].castle - 1;
			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
				if (nb6castle[iCastleID].master == 0xFFFF) { return false; } // �����N���X�g�����Ă���̂���ɒN���������Ă��Ȃ��B�������Ȃ��Breturn;

																			 // ��������̒l�ύX
				{
					nb6bushouname[iBushouID].State = 4; // ��Ԃ�Q�l�Ƃ���B

					nb6bushouname[iBushouID].position = 6; // �g���𑫌y�Ƃ���B

					nb6bushou[iBushouID].attach = 0xFFFF; // �喼�ɏ������Ȃ��B
					nb6bushou[iBushouID].gundan = 0xFFFF; // �R�c�ɏ������Ȃ��B
					nb6bushou[iBushouID].loyal = 50; // ������50�Ƃ���B
					nb6bushou[iBushouID].work = 0; // �d���N����0�Ƃ���B

					nb6bushou[iBushouID].rise = 0xFFFF; // ��������Ȃ��Ƃ���B
					nb6bushou[iBushouID].bRise = 0; // �����Ȃ��B

					nb6bushou[iBushouID].soldier = 0; // ������0�Ƃ���B
					nb6bushou[iBushouID].training = 0; // �P����0�Ƃ���B
					nb6bushou[iBushouID].solloyal = 0; // ������0�Ƃ���B
					nb6bushou[iBushouID].form = 0; // ���y���Ƃ���B

					nb6bushou[iBushouID].merits = 0; // �M����0�Ƃ���B
				}

				/* �@����
				��
				��-��-��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/


				// �Q�l�ɂ����������́A���܏�傾
				if (nb6castle[iCastleID].master - 1 == iBushouID) {
					nb6castle[iCastleID].master = nb6bushou[iBushouID].next; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// ���������ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// ������next�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}


				/* �@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// �Q�l�Ƃ��Ă݂Ȃ������A������next�́A���ݘQ�l���X�g�̐擪�̐l
				nb6bushou[iBushouID].next = nb6castle[iCastleID].ronin; // ���݂̐擪�̐l�������̎��̐l��

																		// next���L���ȕ����Ȃ�΁c
				if (0 < nb6castle[iCastleID].ronin && nb6castle[iCastleID].ronin <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// ���̐l��prev��������
					nb6bushou[nb6castle[iCastleID].ronin - 1].prev = iBushouID + 1;

				}
				nb6bushou[iBushouID].prev = 0xFFFF; // prev�͋��Ȃ�

				nb6castle[iCastleID].ronin = iBushouID + 1; // ��̘Q�l�̐擪�������ɂ���B

				return true;

			}
		}
	}

	return false;
}


// State �Q�l �� State ������
bool setRouninToGeneki(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		if (nb6bushouname[iBushouID].State == 4) { // �Q�l�����̏ꍇ��������������B
												   // �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = nb6bushou[iBushouID].castle - 1;
			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].ronin == 0xFFFF) { return false; } // �����N���X�g�����Ă���̂��Q�l���N�����Ȃ����ƂɂȂ�������Ă�B�������Ȃ��Breturn;
				if (nb6castle[iCastleID].attach == 0xFFFF) { return false; } // �Y���̏邪�ǂ��̌R�c�ɂ��������Ă��Ȃ��ꍇ�A�Q�l�������Ƃ͏o���Ȃ��B
																			 // �Ȃ��Ȃ�A����͑喼�����邱�Ƃ��Ӗ����邩��B
				int iAttachGundanID = nb6castle[iCastleID].attach - 1;
				int iAttachDaimyoID = -1;
				if (0 <= iAttachGundanID && iAttachGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
					iAttachDaimyoID = nb6gundan[iAttachGundanID].attach - 1;
				}
				else {
					return false;
				}
				if (!(0 <= iAttachDaimyoID && iAttachDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM)) {
					return false;
				}

				// ���݂̏�̏�傩��A�����N���X�g��H���Ă���
				int iLinkEndBusyouID = nb6castle[iCastleID].master;
				int iSafetyCnt = 0;
				while (true) {
					// �Z�[�t�e�B�J�E���g���\�����Ă���B
					if (iSafetyCnt > GAMEDATASTRUCT_BUSHOU_NUM) {
						return false;
					}

					// ��傪���Ȃ��Ȃ�΁A�I���
					if (iLinkEndBusyouID == 0xFFFF) {
						break;
					}

					// ���݂̕����́Anext���L���ł͂Ȃ���΁A���݂̕������Ō�̐l�B�I���B
					if (nb6bushou[iLinkEndBusyouID - 1].next == 0xFFFF) {
						break;

						// ���݂̐l���L���ł���B
					}
					else {
						// �����N���X�g�����̐l�Ƃ���B
						if (0 < iLinkEndBusyouID && iLinkEndBusyouID <= GAMEDATASTRUCT_BUSHOU_NUM) {
							iLinkEndBusyouID = nb6bushou[iLinkEndBusyouID - 1].next;
						}
					}
				}

				// ��������̒l�ύX
				{
					nb6bushouname[iBushouID].State = 2; // ��Ԃ������Ƃ���B

					nb6bushou[iBushouID].attach = iAttachDaimyoID + 1; // �喼�ɏ�������B
					nb6bushou[iBushouID].gundan = iAttachGundanID + 1; // �R�c�ɏ�������B
					nb6bushou[iBushouID].loyal = 50; // ������50�Ƃ���B

					nb6bushou[iBushouID].rise = 0xFFFF; // ��������Ȃ��Ƃ���B
					nb6bushou[iBushouID].bRise = 0; // �����Ȃ��B

					nb6bushou[iBushouID].soldier = 0; // ������0�Ƃ���B
					nb6bushou[iBushouID].training = 0; // �P����0�Ƃ���B
					nb6bushou[iBushouID].solloyal = 0; // ������0�Ƃ���B
					nb6bushou[iBushouID].form = 0; // ���y���Ƃ���B

					nb6bushouname[iBushouID].position = 6; // �g���𑫌y�Ƃ���B
					//------------------------------------------------------
				}

				/* �@����
				��
				��-��-��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/


				// �����ɂ����������́A���ܐ擪��
				if (nb6castle[iCastleID].ronin - 1 == iBushouID) {
					nb6castle[iCastleID].ronin = nb6bushou[iBushouID].next; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// �������擪�ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// ������next�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}


				/* �@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/


				// �����͌����Ƃ��Ĉ�ԍŌ�ɂ������B������next�͋��Ȃ�
				nb6bushou[iBushouID].next = 0xFFFF;

				// ���������́A�����ɂȂ�ƂƂ��ɁA���ɂ��Ȃ�ׂ��Ȃ�΁c
				if (iLinkEndBusyouID == 0xFFFF) {
					nb6bushou[iBushouID].prev = 0xFFFF; // �����̑O�̐l�͋��Ȃ�

					nb6castle[iCastleID].master = iBushouID + 1; // ���͎���

																 // ���������N���X�g�̈�ԍŌ�ɂԂ牺����ׂ��B
				}
				else {

					nb6bushou[iLinkEndBusyouID - 1].next = iBushouID + 1; // �����N���X�g�̍Ō��next��������

					nb6bushou[iBushouID].prev = iLinkEndBusyouID; // �����̑O�̐l�́A��̃����N���X�g�̍Ō�̐l��
				}
				return true;

			}
		}
	}

	return false;
}


bool _setBushouTransportRonin(int iBushouID, int iNewCastleID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		if (nb6bushouname[iBushouID].State == 4) { // �Q�l�����̏ꍇ��������������B
												   // �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = nb6bushou[iBushouID].castle - 1;

			if (iCastleID == iNewCastleID) { return true; } // �����z���悪�����������牽������K�v�͂Ȃ����������Ƃ݂Ȃ��B

			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].ronin == 0xFFFF) { return false; } // �����N���X�g�����Ă���̂��Q�l���N�����Ȃ����ƂɂȂ�������Ă�B�������Ȃ��Breturn;

																			// ��������̒l�ύX
				{
					// ���������]����ɕύX����B
					nb6bushou[iBushouID].castle = iNewCastleID + 1;
				}

				/* �@����
				��
				��-��-��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/


				// �]�������������́A���ܐ擪��
				if (nb6castle[iCastleID].ronin - 1 == iBushouID) {
					nb6castle[iCastleID].ronin = nb6bushou[iBushouID].next; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// �������擪�ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// ������next�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}

				/* �@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// �Q�l�Ƃ��Ă݂Ȃ������A������next�́A���ݘQ�l���X�g�̐擪�̐l
				nb6bushou[iBushouID].next = nb6castle[iNewCastleID].ronin; // �]����̌��݂̐擪�̐l�������̎��̐l��

																		   // next���L���ȕ����Ȃ�΁c
				if (0 < nb6castle[iNewCastleID].ronin && nb6castle[iNewCastleID].ronin <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// ���̐l��prev��������
					nb6bushou[nb6castle[iNewCastleID].ronin - 1].prev = iBushouID + 1;
				}
				nb6bushou[iBushouID].prev = 0xFFFF; // prev�͋��Ȃ�

				nb6castle[iNewCastleID].ronin = iBushouID + 1; // ��̘Q�l�̐擪�������ɂ���B

				return true;
			}
		}
	}

	return false;
}


bool setBushouTransport(int iBushouID, int iNewCastleID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		// ���̋���ƐV��������
		int iCastleID = nb6bushou[iBushouID].castle - 1;
		if (iCastleID == iNewCastleID) { return true; } // ������ꏊ�ƁA�]���悪�����Ȃ牽������K�v�͂Ȃ��B

														// �Q�l�̏ꍇ�͈ړ]���邾��
		if (nb6bushouname[iBushouID].State == 4) { // �Q�l�����̏ꍇ��������������B
			return _setBushouTransportRonin(iBushouID, iNewCastleID);

			// �����̏ꍇ�́A�Q�l�����Ă���A�ړ]���āA�܂�(�\�ł����)�����ɖ߂��B
			// �������邾�ƘQ�l�̂܂܈ړ]���邱�ƂƂȂ�B
		}
		else if (nb6bushouname[iBushouID].State == 2) { // ���𕐏��ł���
			int _merits = nb6bushou[iBushouID].merits;
			int _work = nb6bushou[iBushouID].work;
			int _position = nb6bushouname[iBushouID].position;
			int _loyal = nb6bushou[iBushouID].loyal;
			int _soldier = nb6bushou[iBushouID].soldier;
			int _training = nb6bushou[iBushouID].training;
			int _solloyal = nb6bushou[iBushouID].solloyal;
			int _form = nb6bushou[iBushouID].form;
			int _attach = nb6bushou[iBushouID].attach;
			int _rise = nb6bushou[iBushouID].rise;
			int _bRise = nb6bushou[iBushouID].bRise;

			// ��[�A�Q�l�ɂ���
			bool isRouninka = setGenekiToRounin(iBushouID);
			if (!isRouninka) { return false; }

			// �ʒu�ړ�
			bool isTranska = _setBushouTransportRonin(iBushouID, iNewCastleID);
			if (!isTranska) { return false; }

			bool isGenekika = setRouninToGeneki(iBushouID);
			// �����ɂł��Ȃ������炻�̂܂ܘQ�l�Ƃ��ďI���B(���x�z��Ƃ����ƁA���̂܂ܘQ�l�̂܂܂ƂȂ�B)
			if (!isGenekika) { return false; }

			// ���X�����Ȃ̂ŁA�Q�l������O�̒l�ŕ���������̂�߂��B
			nb6bushou[iBushouID].merits = _merits; // �M��
			nb6bushouname[iBushouID].position = _position; // �g��
			nb6bushou[iBushouID].loyal = _loyal; // ����
			nb6bushou[iBushouID].soldier = _soldier; // ����
			nb6bushou[iBushouID].training = _training; // �P��
			nb6bushou[iBushouID].solloyal = _solloyal; // �m�C
			nb6bushou[iBushouID].form = _form; // ����

											   // �]���O�Ɠ]����ő喼���ω����Ă��Ȃ��ꍇ�̂݁A�m���N��������n�����̒l�𕜌�
			if (_attach == nb6bushou[iBushouID].attach) {
				nb6bushou[iBushouID].work = _work; // �d���N��
				nb6bushou[iBushouID].rise = _rise; // ������
				nb6bushou[iBushouID].bRise = _bRise; // �������
			}
			else {
				nb6bushou[iBushouID].grudge = 0; // �喼���ς�����ꍇ�A���݂͏���
			}

		}
	}
	return false;
}


// ���������̏�̏��Ƃ���B
// ����́u�����v�̕������A���̏�̏��ɂ���B
// ���̏�傪�u�R�c���v��u�喼�v���ƁA���̐l���̗���ƂȂ�B
bool setGenekiToJyosyu(int iBushouID) {

	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {

		//0�喼,1�R��,2����
		if (nb6bushouname[iBushouID].State == 2) { // ���𕐏��̏ꍇ��������������B

												   // �Y�������̋��邪�����Ƃ�����񂪊i�[����Ă���B(���[�U�[�������ɂ���ĉ��Ă��Ȃ�)
			int iCastleID = nb6bushou[iBushouID].castle - 1;

			if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {

				if (nb6castle[iCastleID].master == 0xFFFF) { return false; } // �����N���X�g�����Ă���̂���ɒN���������Ă��Ȃ��B�������Ȃ��Breturn;

																			 // �����܂ŗ������傪����̂Łc
				int iJyosyuBushouID = nb6castle[iCastleID].master - 1;

				// �w�蕐�������łɏ��Ȃ牽�����Ȃ��Ă����ł���B
				if (iBushouID == iJyosyuBushouID) { return true; }

				// ���͋��邪(��������)�������Ȕj����f�[�^�ɂȂ��Ă�����A�������Ȃ��B
				if (!(0 <= iJyosyuBushouID && iJyosyuBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
					return false;
				}

				//0�喼,1�R��,2����

				// ��傪�����ł��R�c���ł��Ȃ��Ȃ��(�喼)�A�������Ȃ��B����ւ���ƕςȂ��ƂɂȂ�B
				// �����Ȃ��
				if (nb6bushouname[iJyosyuBushouID].State == 2) {

					; // ���ɉ������Ȃ�
					  // �R�c���Ȃ��
				}
				else if (nb6bushouname[iJyosyuBushouID].State == 1) {
					// ���̌R�c���������Ƃ���
					nb6bushouname[iJyosyuBushouID].State = 2; // �����Ƃ���

															  // �t�Ɏw�蕐�����R�c��������
					nb6bushouname[iBushouID].State = 1; // �R�c��
					int iGundanID = nb6bushou[iJyosyuBushouID].gundan - 1;
					// �����ėv��ʔ���̂͂��ł��邪�ꉞ
					if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
						// �R�c���̌R�c���̔ԍ����A�w��̕����ɂ���B
						nb6gundan[iGundanID].leader = iBushouID + 1;
					}
					// �喼�Ȃ�΁c
				}
				else if (nb6bushouname[iJyosyuBushouID].State == 0) {
					// ���̑喼�������Ƃ���
					nb6bushouname[iJyosyuBushouID].State = 2;
					// �喼�������l�̐g�����h�V�Ƃ���B
					nb6bushouname[iJyosyuBushouID].position = 2; //(�B��=0, �喼=1, �h�V=2, �ƘV=3, ����=4, ���叫=5, ���y��=6)
																 // �t�Ɏw�蕐����喼�Ƃ���
					nb6bushouname[iBushouID].State = 0;
					nb6bushouname[iBushouID].position = 1;

					int iGundanID = nb6bushou[iJyosyuBushouID].gundan - 1;
					int iDaimyoID = nb6bushou[iJyosyuBushouID].attach - 1;
					// �����ėv��ʔ���̂͂��ł��邪�ꉞ
					if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
						// �R�c���̌R�c���̔ԍ����A�w��̕����ɂ���B
						nb6gundan[iGundanID].leader = iBushouID + 1;
					}
					if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
						// nb6daimyo�̑喼�̔ԍ����A�w��̕����ɂ���B
						nb6daimyo[iDaimyoID].attach = iBushouID + 1;
					}

				}
				else {
					return false;
				}




				/*����̕������X�g

				�@ �@����
				   ��
				   ��-��-��-��

				   �Ƃ����̂�

				   ��-��-��

				   �Ƃ���B
				   */


				   // �p�[�W�����������́A���܏�傾
				if (nb6castle[iCastleID].master - 1 == iBushouID) {
					nb6castle[iCastleID].master = nb6bushou[iBushouID].next; // ������next�����ɂ���B
				}

				// ������prev�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].prev && nb6bushou[iBushouID].prev <= GAMEDATASTRUCT_BUSHOU_NUM) {

					// ���������ł͂Ȃ������ŁA
					// �P�O�̐l�̎��̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].prev != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].prev - 1)].next == iBushouID + 1) {
						// �����ł͂Ȃ��A���̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].prev - 1)].next = nb6bushou[iBushouID].next;
					}
				}

				// ������next�͗L���ȕ������B
				if (0 < nb6bushou[iBushouID].next && nb6bushou[iBushouID].next <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// �P��̐l�̑O�̃����N�悪�������g�̏ꍇ
					if (nb6bushou[iBushouID].next != 0xFFFF && nb6bushou[(nb6bushou[iBushouID].next - 1)].prev == iBushouID + 1) {
						// �����ł͂Ȃ��A�O�̐l�ւƌq��������B
						nb6bushou[(nb6bushou[iBushouID].next - 1)].prev = nb6bushou[iBushouID].prev;
					}
				}



				/* ����̏�僊�X�g�@

				��-��

				�Ƃ����̂�

				��-��-��

				�Ƃ���B
				*/

				// ���������ƂȂ�̂ŁA�����̎��̐l���A���̏��̐l�Ƃ���B
				int iJosyu = nb6castle[iCastleID].master;
				nb6bushou[iBushouID].next = iJosyu; // ���݂̐擪�̐l�������̎��̐l��

													// next���L���ȕ����Ȃ�΁c
				if (0 < iJosyu && iJosyu <= GAMEDATASTRUCT_BUSHOU_NUM) {
					// ���̐l��prev��������
					nb6bushou[iJosyu - 1].prev = iBushouID + 1;
				}

				nb6bushou[iBushouID].prev = 0xFFFF; // �{�l���擪�ɂȂ�̂ŁAprev�͋��Ȃ�

													// �����čŌ�Ɏ���������
				nb6castle[iCastleID].master = iBushouID + 1; // ��̏��������ɂ���B

				return true;
			}
		}
	}

	return false;
}



// �����̗֔z��B(�v�Z�p)
static int arrayAisho[32] = { 8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0,1,2,3,4,5,6,7 };

// A������B�����̑����̍����𓾂�
// �ŏ�0(�����ō�) �ő�8(�����ň�)
static int getAishoDiff(int iAishoA, int iAishoB) {

	// �܂��AA�����̑����ʒu�𒆉�������
	int iAAishoIXInArray = 0;
	for (int iAishoID = 8; iAishoID<8 + GAMEDATASTRUCT_AISHOU_NUM; iAishoID++) {
		// A�̑����l����������A������A�̈ʒu
		if (arrayAisho[iAishoID] == iAishoA) {
			iAAishoIXInArray = iAishoID;
		}
	}

	// �s���Ȑ����̏ꍇ�́A�������͍ł��������̂Ƃ���B
	if (iAAishoIXInArray == 0) { return 8; }

	// B�����̑����ʒu��A������-8����X�^�[�g
	int iBAishoIXInArray = 0;
	for (int iAishoID = iAAishoIXInArray - 8; iAishoID<iAAishoIXInArray + 8; iAishoID++) {
		// A�̑����l����������A������A�̈ʒu
		if (arrayAisho[iAishoID] == iAishoB) {
			iBAishoIXInArray = iAishoID;
		}
	}

	// �s���Ȑ����̏ꍇ�́A�������͍ł��������̂Ƃ���B
	if (iBAishoIXInArray == 0) { return 8; }

	// �Q�̑����̈ʒu�̍�����������
	return abs(iBAishoIXInArray - iAAishoIXInArray);
}


/*
* 2�l�̕���ID���瑊���̈Ⴂ�𓾂�B
* �ŏ�0(�����ō�) �ő�8(�����ň�)
*/
int getBushouAishoDiff(int iBushouAID, int iBushouBID) {
	// ����A������B���͈͓��Ɏ��܂��Ă���
	if (0 <= iBushouAID && iBushouAID < GAMEDATASTRUCT_BUSHOU_NUM && 0 <= iBushouBID && iBushouBID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// �����̑����̍���Ԃ�
		return getAishoDiff(nb6bushou[iBushouAID].affinity, nb6bushou[iBushouBID].affinity);
	}
	// ��Ԉ����l��Ԃ��Ă���
	else {
		return 8;
	}
}






