#include "GameDataStruct.h"

// ����ɕ���������߂��������ɁATENSHOU.EXE���̃|�C���^�z�񂩂��������悤�ɂ��������A���҂̉����ւ̑ϋv�͂����������B
static char nb6CastleTypeName[GAMEDATASTRUCT_CASTLETYPE_NUM][5] = {
	"��",
	"��V",
	"��",
	"�䏊",
	"��",
	"",
	"��"
};

// ��̃^�C�vID�����̓I�ȕ�����𓾂�
char *getCastleTypeName(int iCastleType) {
	if (iCastleType == 0x00) {
		return nb6CastleTypeName[0];
	}
	else if (iCastleType == 0x01) {
		return nb6CastleTypeName[1];
	}
	else if (iCastleType == 0x02) {
		return nb6CastleTypeName[2];
	}
	else if (iCastleType == 0x04) {
		return nb6CastleTypeName[3];
	}
	else if (iCastleType == 0x08) {
		return nb6CastleTypeName[4];
	}
	else if (iCastleType == 0x10) {
		return nb6CastleTypeName[5];
	}
	else if (iCastleType == 0x20) {
		return nb6CastleTypeName[6];
	}
	return "";
}


// �w��̌R�c���������Ă����̐��B
int getGundanHasCastleNum(int iGundanID) {
	int iHasCastleCnt = 0;
	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			// �R�c�ԍ�����v������̂��J�E���g
			if (iGundanID == nb6castle[iCastleID].attach - 1) {
				iHasCastleCnt++;
			}
		}
	}
	return iHasCastleCnt;
}

// �w��̑喼���������Ă����̐��B
int getDaimyoHasCastleNum(int iDaimyoID) {
	int iHasCastleCnt = 0;

	if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			int iGundanID = nb6castle[iCastleID].attach - 1;

			if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
				// �喼�ԍ�����v������̂��J�E���g
				if (iDaimyoID == nb6gundan[iGundanID].attach - 1) {
					iHasCastleCnt++;
				}
			}
		}
	}
	return iHasCastleCnt;
}


// ��ɏ������镺���𓾂�
int getCastleHeisuCnt(int iCastleID) {
	int iSoldierCnt = 0;
	for (int i = 0; i<GAMEDATASTRUCT_BUSHOU_NUM; i++) {
		if (nb6bushou[i].castle - 1 == iCastleID) {
			if (nb6bushouname[i].State <= 2) { // �喼, �R�c��, ���� �ŃJ�E���g
				iSoldierCnt += nb6bushou[i].soldier;
			}
		}
	}
	return iSoldierCnt;
}





//--------------MAIN�̃O���b�h�n

// �O���b�h�|�W�V�����N���X
GRID_POSITION::GRID_POSITION(int _x, int _y) {
	x = _x,
		y = _y;

	// �e�אڏ�͖�����Ԃŏ�����
	nw = 0xFFFF;
	no = 0xFFFF;
	ne = 0xFFFF;
	we = 0xFFFF;
	ea = 0xFFFF;
	sw = 0xFFFF;
	so = 0xFFFF;
	se = 0xFFFF;

}

// �O���b�h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
GRID_VECTOR operator-(GRID_POSITION &p1, GRID_POSITION &p2) {
	GRID_VECTOR p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}

// ��h�c����A���C���O���b�h��̃|�W�V�����𓾂�B����O���b�h��0,0�Bmapdataobgk�̃O���b�h������΂킩��₷���B
// �P�̃O���b�h�ɂ́A�P�̏邵���Ȃ��B
GRID_POSITION getCastlePosInMainGrid(int iCastleID) {
	GRID_POSITION pos(0, 0);
	if (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) {
		int iGridX = (nb6castlemax[iCastleID].x + 1) / 5; // �O�I���W���Ȃ̂Ł{�P���ĂT�Ŋ���B�w�����͂P�̃O���b�h�̒��ɂT�̏ꏊ������B
		int iGridY = (nb6castlemax[iCastleID].y + 1) / 3; // �O�I���W���Ȃ̂Ł{�P���ĂR�Ŋ���B�x�����͂P�̃O���b�h�̒��ɂR�̏ꏊ������B

		pos.x = iGridX;
		pos.y = iGridY;

		// �אڂ����̂h�c������Ă����B
		for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
			int iFX = (nb6castlemax[iCastleID].x + 1) / 5; // �O�I���W���Ȃ̂Ł{�P���ĂT�Ŋ���B�w�����͂P�̃O���b�h�̒��ɂT�̏ꏊ������B
			int iFY = (nb6castlemax[iCastleID].y + 1) / 3; // �O�I���W���Ȃ̂Ł{�P���ĂR�Ŋ���B�x�����͂P�̃O���b�h�̒��ɂR�̏ꏊ������B

			if (iFX - pos.x == -1 && iFY - pos.y == -1) { // �k��
				pos.nw = iCastleID + 1;
			}
			else if (iFX - pos.x == 0 && iFY - pos.y == -1) { // �k
				pos.no = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == -1) { // �k��
				pos.ne = iCastleID + 1;
			}
			else if (iFX - pos.x == -1 && iFY - pos.y == 0) { // ��
				pos.we = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == 0) { // ��
				pos.ea = iCastleID + 1;
			}
			else if (iFX - pos.x == -1 && iFY - pos.y == 1) { // �쐼
				pos.sw = iCastleID + 1;
			}
			else if (iFX - pos.x == 0 && iFY - pos.y == 1) { // ��
				pos.so = iCastleID + 1;
			}
			else if (iFX - pos.x == 1 && iFY - pos.y == 1) { // �쓌
				pos.se = iCastleID + 1;
			}
		}

		return pos;
	}
	return pos;
}

// �w��̏�ɑ΂��ėאڂ��Ă����̃��X�g�𓾂�
vector<int> getRinsetsuCastles(int iCastleID) {
	// �܂��́A�w���̃O���b�h�̏ꏊ�𓾂�
	GRID_POSITION CenterPos = getCastlePosInMainGrid(iCastleID);

	vector<int> RinsetsuCastles;

	// �אڂ��Ă������x�N�g���ɒǉ����Ă䂭
	for (int iTargetID = 0; iTargetID < GAMEDATASTRUCT_CASTLE_NUM; iTargetID++) {
		// �������g�̓p�X
		if (iCastleID == iTargetID) {
			continue;
		}

		GRID_POSITION TargetPos = getCastlePosInMainGrid(iTargetID);
		// �אڂ��Ă���B
		if (abs(CenterPos.x - TargetPos.x) <= 1 && abs(CenterPos.y - TargetPos.y) <= 1) {
			RinsetsuCastles.push_back(iTargetID);
		}
	}
	return RinsetsuCastles;
}

