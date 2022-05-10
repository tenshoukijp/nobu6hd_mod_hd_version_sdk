#include <algorithm>
#include "GameDataStruct.h"

using namespace std;


// �Ƃ���喼���͂̓����R�c�ԍ����X�g�𓾂�B
vector<int> getGovernedGundanList(int iDaimyoID) {
	// ����ȊO�͉������ꂸ�ɕԂ��B
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(iGundanID);
			}
		}
	}

	return list;
}

// �R�c�ɏ������镐�����X�g�𓾂�
vector<int> getGundanBushouList(int iGundanID) {
	// ����ȊO�͉������ꂸ�ɕԂ��B
	vector<int> list;

	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // �喼, �R�c��, ���� �ŃJ�E���g
				list.push_back(i);
			}
		}
	}
	return list;
}

/// ����(���̏u��)�A�V�ċL�ɑ��݂���R�c�́u�R�c�ԍ��y�z��p�z�v�����X�g�œ���B
vector<int> getValidGundanList() {
	vector<int> list;

	// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
	for (int iGundanID = 0; iGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
		if (nb6gundan[iGundanID].leader != 0xFFFF) {
			list.push_back(iGundanID);
		}
	}

	return list;
}


// �R�c�ɏ������镺���𓾂�
int getGundanHeisuCnt(int iGundanID) {
	int iSoldierCnt = 0;
	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].gundan - 1 == iGundanID) {
			if (nb6bushouname[i].State <= 2) { // �喼, �R�c��, ���� �ŃJ�E���g
				iSoldierCnt += nb6bushou[i].soldier;
			}
		}
	}
	return iSoldierCnt;
}

// �Ƃ���喼���͂̓����R�c���肠�Ĕԍ����X�g�𓾂�B
vector<int> getGovernedGundanWariateNumList(int iDaimyoID) {
	// ����ȊO�͉������ꂸ�ɕԂ��B
	vector<int> list;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				list.push_back(nb6gundan[iGundanID].number);
			}
		}
	}

	std::sort(list.begin(), list.end());//�����\�[�g

	return list;
}



// �Ƃ���喼�z���̌R�c���ɂ���R�c�u���v�����ԍ��̃��X�g�𓾂�B
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID) {

	// ���蓖�Ă��Ă���̂ɁA�P������
	int wariate_array[8] = { 0,0,0,0,0,0,0,0 };

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {

		// �Y���̑喼�h�c�ɑ�����R�c�����X�g�ɉ�����
		for (int iGundanID = 0; iGundanID<GAMEDATASTRUCT_GUNDAN_NUM; iGundanID++) {
			if (nb6gundan[iGundanID].attach - 1 == iDaimyoID) {
				int g = nb6gundan[iGundanID].number;
				if (1 <= g && g <= 8) {
					// ���蓖�Ă��Ă���̂ɁA�P������
					wariate_array[g - 1] = 1;
				}
			}
		}
	}

	vector<int> list;
	for (int ix = 0; ix<8; ix++) {
		if (wariate_array[ix] == 0) { // �R�c�������Ȃ����
			list.push_back(ix + 1);
		}
	}

	std::sort(list.begin(), list.end());//�����\�[�g

	return list;
}

// �R�c�C���ԍ��̕ύX(����)�����݂�B���s�����false
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum) {

	// ��P�R�c�͑喼���g�B�ύX�͖����B
	if (nb6gundan[iGundanID].number == 1) {
		return false;
	}

	if (!(1 <= iNewWariateNum && iNewWariateNum <= 8) ) {
		return false;
	}

	// �����̌R�c�̑喼��ID
	int iDaimyoID = nb6gundan[iGundanID].attach - 1;

	// �喼�����ŋ󂫃X���b�g�ƂȂ��Ă���C���ԍ��ꗗ
	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		vector<int> sameDaimyoGundanList = getGovernedGundanList(iDaimyoID);
		int iOldNinmeiNum = nb6gundan[iGundanID].number; // ���܂ł̔C���ԍ�

														 // �ʌR�c���w��̌R�c�𗘗p���Ă���Ȃ�΁A�����̌R�c�ԍ������̌R�c�ɍ����グ��B
		for each (int iGID in sameDaimyoGundanList) {
			// ���łɕʌR�c�ŗ��p����Ă���Ȃ��
			if (nb6gundan[iGID].number == iNewWariateNum) {
				nb6gundan[iGID].number = iOldNinmeiNum;
				break;
			}
		}

		// �����͎w��̌R�c�ԍ��ƂȂ�B
		nb6gundan[iGundanID].number = iNewWariateNum;

		return true;
	}

	return false;

}


// �w��̌R�c�̏�������喼�𐨗͂��z���āA�ύX����B
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID) {

	// �V�喼�������ł͂Ȃ��B
	if (!(0 <= iNewDaimyoID && iNewDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM)) {
		return false;
	}

	// �R�c���S�����܂��Ă���Ȃ�΁A
	vector<int> glist = getGovernedGundanWariateNumList(iNewDaimyoID);
	if (glist.size() == 8) { // �R�c�͑S�����܂��Ă���
							 // �����ł��Ȃ�
		return false;
	}

	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {

		// �w��̌R�c�����ݏ������Ă���喼�ԍ������߂�
		int iDaimyoID = nb6gundan[iGundanID].attach - 1;
		// �V������̑喼���A���������Ă���喼�ł���΁A�������邱�Ƃ͂Ȃ��B
		if (iDaimyoID == iNewDaimyoID) {
			return true;
		}

		// �R�c���蓖�Ĕԍ����P�Ԃ͑喼���g�B����͌Œ�B���̏ꍇ�A�����������s�Ƃ���B
		if (nb6gundan[iGundanID].number == 1) {
			return false;
		}

		// ���݁A�V�喼�ɏ������Ă��āAnext��0xFFFF�ɂȂ��Ă���R�c���A�Ԃ牺����ׂ������N���X�g�̍Ōゾ�B
		// �Ԃ牺���邱�Ƃ��o���邩�A���O�Ƀ`�F�b�N���Ă����B
		int iLinkEndGundanID = -1;
		for (int iCurGundanID = 0; iCurGundanID < GAMEDATASTRUCT_GUNDAN_NUM; iCurGundanID++) {
			// 
			int iCurDaimyoID = nb6gundan[iCurGundanID].attach - 1;

			// �w��̐V�喼�ɏ������Ă���Ȃ�΁A
			if (iCurDaimyoID == iNewDaimyoID) {
				// ���̌R�c�������̂ł���΁A�������ŏI�R�c�ԍ�
				if (nb6gundan[iCurGundanID].next == 0xFFFF) {
					iLinkEndGundanID = iCurGundanID + 1;
				}

			}

		}

		// ���ꂪ�͈͂ɓ����Ă��Ȃ��Ȃ�΁A�V�喼�̌R�c�����N���X�g�́A��������������Ȃ�����񂪉��Ă���B
		// �����I��
		if (!(0 < iLinkEndGundanID && iLinkEndGundanID <= GAMEDATASTRUCT_GUNDAN_NUM)) {
			return false;
		}

		/* �@���R�c
		��
		��-��-��-��

		�Ƃ����̂�

		��-��-��

		�Ƃ���B
		*/

		int iPrevID = nb6gundan[iGundanID].prev;
		int iNextID = nb6gundan[iGundanID].next;

		// ������prev�͗L���ȌR�c���B
		if (0 < iPrevID && iPrevID <= GAMEDATASTRUCT_GUNDAN_NUM) {

			// �������擪�ł͂Ȃ��R�c�ŁA
			// �P�O�̌R�c�̎��̃����N�悪���R�c�̏ꍇ
			if (iPrevID != 0xFFFF && nb6gundan[(iPrevID - 1)].next == iGundanID + 1) {
				// ���R�c�ł͂Ȃ��A���̌R�c�ւƌq��������B
				nb6gundan[(iPrevID - 1)].next = iNextID;
			}
		}

		// ������next�͗L���ȌR�c���B
		if (0 < iNextID && iNextID <= GAMEDATASTRUCT_GUNDAN_NUM) {
			// �P��̌R�c�̑O�̃����N�悪���R�c�̏ꍇ
			if (iNextID != 0xFFFF && nb6gundan[(iNextID - 1)].prev == iGundanID + 1) {
				// ���R�c�ł͂Ȃ��A�O�̌R�c�ւƌq��������B
				nb6gundan[(iNextID - 1)].prev = iPrevID;
			}
		}


		/* �@

		��-��

		�Ƃ����̂�

		��-��-��

		�Ƃ���B
		*/



		nb6gundan[iLinkEndGundanID - 1].next = iGundanID + 1; // �����N���X�g�̍Ō�̌R�c��next�����R�c��

		nb6gundan[iGundanID].prev = iLinkEndGundanID; // ���R�c�̑O�̌R�c�́A�R�c�̃����N���X�g�̍Ō�̌R�c

													  // ���R�c�́A�R�c���X�g�̈�ԍŌ�ɂ������B���R�c��next�͋��Ȃ�
		nb6gundan[iGundanID].next = 0xFFFF; // 

											// ��������������
		{
			nb6gundan[iGundanID].number = 8; // ���̔ԍ��Ƃ����킯�ɂ͂����Ȃ��̂ŁA������̂��߂ɁA�Ƃ肠�����A�ł������m���ŋ󂢂Ă�Z�[�t�Ȃ��̂����

			vector<int> milist = getNotGovernedGundanWariateNumList(iNewDaimyoID);
			if (milist.size() > 0) {
				nb6gundan[iGundanID].number = milist[0]; // ��ԍ��̍ŏ��̂��̂���荞��
			}

			nb6gundan[iGundanID].attach = iNewDaimyoID + 1;
		}

		for (int iBushouID = 0; iBushouID < GAMEDATASTRUCT_BUSHOU_NUM; iBushouID++) {
			// �w��̌R�c�ɏ������Ă��镐���́A�S�āA�V�喼�ɏ�����ύX����B
			if (nb6bushou[iBushouID].gundan == iGundanID + 1) {
				nb6bushou[iBushouID].attach = iNewDaimyoID + 1;
				nb6bushou[iBushouID].work = 0; // �m���N�����Z�b�g
				nb6bushou[iBushouID].rise = 0xFFFF; // �����惊�Z�b�g
				nb6bushou[iBushouID].bRise = 0; // ������ԂȂ�
				nb6bushou[iBushouID].grudge = 0; // �⍦�Ȃ�
			}
		}

		return true;

	}

	return false;
}
