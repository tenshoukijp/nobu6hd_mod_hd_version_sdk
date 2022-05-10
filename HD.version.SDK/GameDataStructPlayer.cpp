#include "GameDataStruct.h"


// �Ώۂ̌R�cID�������ꂩ�̃v���C���[���͉��̌R�c�ł���(�ő�W�l)
// iTargetGundanID�ɂ͔z���̔ԍ�(attach-1�̐�)��n������
bool isPlayerGundan(WORD iTargetGundanID) {

	if (iTargetGundanID >= GAMEDATASTRUCT_GUNDAN_NUM) {
		return false;
	}

	WORD iGundanID = 0;
	for (int iPG = 0; iPG<GAMEDATASTRUCT_PLAYERS8_NUM; iPG++) {
		// �v���C���[���S�����Ă���R�c�̂h�c���m��
		iGundanID = nb6players8[iPG].gundan;

		// 0xFFFF�Ȃ�΃v���C���[�ł͂Ȃ�
		if (iGundanID == 0xFFFF) {
			continue;
		}

		// �v���C���[�S���̌R�c�̑喼���A�^�[�Q�b�g�Ƃ��Ă���Ώۂ̌R�c�̑喼�ƈ�v����Ȃ�΁A
		// ����̓v���C���[�̐��͉��̌R�c�ł���B
		// �ǂ���nb6player8��gundan�̒l�́A�����Ǘ���gundan�̒l����+1����Ă���悤�ł���B
		// ����Ă����ł�-1����B
		if (iGundanID >= 1 && nb6gundan[iGundanID - 1].attach == nb6gundan[iTargetGundanID].attach) {
			return true;
		}
	}

	return false;
}

// �Ώۂ̕���ID�������ꂩ�̃v���C���[���͉��̕����ł���
bool isPlayerBushou(WORD iTargetBushouID) {
	// ����ID�͈̔͂Ɏ��܂��Ă��邱��
	if (0 <= iTargetBushouID && iTargetBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
		return isPlayerGundan(nb6bushou[iTargetBushouID].gundan - 1);
	}
	else {
		return false;
	}
}

// �Ώۂ̑喼ID�������ꂩ�̃v���C���[�S���̑喼�ł���
bool isPlayerDaimyo(WORD iTargetDaimyoID) {
	// ����ID�͈̔͂Ɏ��܂��Ă��邱��
	if (0 <= iTargetDaimyoID && iTargetDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		// �^�[�Q�b�g�̕����̌R�cID���v���C���[�̌R�c�ł��邩��Ԃ�
		return isPlayerGundan(nb6daimyo[iTargetDaimyoID].gundan - 1);
	}
	else {
		return false;
	}
}


