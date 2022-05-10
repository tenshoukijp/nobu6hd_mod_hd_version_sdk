#include "GameDataStruct.h"


// �S�L���喼�̃��X�g��Ԃ��B�^�[���喼���g�������Ă�̂Œ��ӁB
vector<int> getDaimyoList(BOOL isIncludeTurnDaimyo) {
	vector<int> list;
	for (int iDaimyoID = 0; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		// �^�[���喼�͊܂܂Ȃ�
		if (!isIncludeTurnDaimyo) {
			// �^�[���喼�Ȃ�p�X
			if (iDaimyoID == nb6turn.daimyo - 1) {
				continue;
			}
		}
		// �����ƕ������[�߂Ă���喼�Ƃ̂�
		if (nb6daimyo[iDaimyoID].attach != 0xFFFF) {
			list.push_back(iDaimyoID);
		}
	}
	return list;
}




int DaimyoHasCastleArray[GAMEDATASTRUCT_DAIMYO_NUM] = { 0 }; // �e�X�̑喼�����鐔

															 //�ő吨��(�ł������鐔������)�喼�𓾂�
int GetMaximumInfluenceDaimyo() {
	// �܂��A�ꉞ�Ă΂��x�Ƀ��Z�b�g
	for (int iDaimyoID = 0; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		DaimyoHasCastleArray[iDaimyoID] = 0;
	}

	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		// �����喼�ԍ��ɏ]���āA�J�E���g�𑝂₵�Ă䂭�B
		int iGundanID = nb6castle[iCastleID].attach - 1;
		if (iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) { // �N�ɂ��������ĂȂ���͂��̏����Œe�����
			int iDaimyoID = nb6gundan[iGundanID].attach - 1;
			DaimyoHasCastleArray[iDaimyoID]++;
		}
	}

	// �ő�̏鎝���̑喼ID��T��
	int iMaximumInfluenceDaimyoID = 0;

	// ��r����Ȃ̂�1�X�^�[�g�ŗǂ�
	for (int iDaimyoID = 1; iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM; iDaimyoID++) {
		if (DaimyoHasCastleArray[iDaimyoID] > DaimyoHasCastleArray[iMaximumInfluenceDaimyoID]) {
			iMaximumInfluenceDaimyoID = iDaimyoID;
		}
	}

	return iMaximumInfluenceDaimyoID;
}

