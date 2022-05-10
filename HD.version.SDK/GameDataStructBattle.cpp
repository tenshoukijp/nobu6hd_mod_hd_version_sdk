#include "GameDataStruct.h"


HEX_VECTOR operator-(HEX_POSITION &p1, HEX_POSITION &p2) {
	HEX_VECTOR p;
	p.x = p1.x - p2.x;
	p.y = p1.y - p2.y;
	return p;
}


// ����w�b�N�X�ꏊ�̃`�b�v�̖���(FIELD_HEX_ROLE)�𓾂�
int GetFieldHexRole(double x, double y) {
	// ���W�l�͑Ó��Ȕ͈͂��H
	if (0 <= x && x <= GAMEDATASTRUCT_FIELD_HEX_COLS && 0 <= y && y <= GAMEDATASTRUCT_FIELD_HEX_ROWS) {
		// y�����W���l�ɂ��āA������
		int _y = round�s�������t(y);
		// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// x���ł��߂��l�̐�����
		int _x = round�s�������t(x);
		// �O��菬�����Ȃ邱�Ƃ�����̂łO��
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_FIELD_HEX_COLS) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_FIELD_HEX_ROWS) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS - 1; }
		// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(FIELD_HEX_ROLE)��Ԃ�
		return nb6field_hex_role.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}

int GetFieldHexRole(HEX_POSITION p) {
	return GetFieldHexRole(p.x, p.y);
}




// �t�ɐݒ肷��B(�Ƃ����Ă��A�ݒ肵���Ƃ��Ă��A�G���ς��Ȃ��̂ŏ�肭�����Ȃ���)
void SetFieldHexRole(double x, double y, int eHexRole) {
	// ���W�l�͑Ó��Ȕ͈͂��H
	if (0 <= x && x< GAMEDATASTRUCT_FIELD_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_FIELD_HEX_ROWS) {
		// y�����W���l�ɂ��āA������
		int _y = round�s�������t(y);
		// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// x���ł��߂��l�̐�����
		int _x = round�s�������t(x);
		// �O��菬�����Ȃ邱�Ƃ�����̂łO��
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_FIELD_HEX_COLS) { _x = GAMEDATASTRUCT_FIELD_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_FIELD_HEX_ROWS) { _y = GAMEDATASTRUCT_FIELD_HEX_ROWS - 1; }
		// �Y���̏ꏊ�̃`�b�v�̖����ԍ�(FIELD_HEX_ROLE)��ݒ肷��B
		nb6field_hex_role.pos_y[_y].pos_x[_x] = eHexRole;
	}
}

void SetFieldHexRole(HEX_POSITION p, int eHexRole) {
	SetFieldHexRole(p.x, p.y, eHexRole);
}




// ����w�b�N�X�ꏊ�̃`�b�v�̍����𓾂�
int GetFieldHexHigh(double x, double y) {
	int role = GetFieldHexRole(x, y);
	if (role == FIELD_HEX_ROLE::�� || FIELD_HEX_ROLE::�� || FIELD_HEX_ROLE::�C) {
		return 0;
	}
	else if (role == FIELD_HEX_ROLE::��R) {
		return 2;
	}
	else if (role == FIELD_HEX_ROLE::���R) {
		return 3;
	}
	else if (role == FIELD_HEX_ROLE::���R) {
		return 4;
	}
	else {
		return 1;
	}
}

int GetFieldHexHigh(HEX_POSITION p) {
	return GetFieldHexHigh(p.x, p.y);
}






// ����w�b�N�X�ꏊ�̃`�b�v�̖���(CASTLE_HEX_ROLE)�𓾂�
int GetCastleHexRole(double x, double y) {
	// ���W�l�͑Ó��Ȕ͈͂��H
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// y�����W���l�ɂ��āA������
		int _y = round�s�������t(y);
		// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// x���ł��߂��l�̐�����
		int _x = round�s�������t(x);
		// �O��菬�����Ȃ邱�Ƃ�����̂łO��
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(CASTLE_HEX_ROLE)��Ԃ�
		return nb6castle_hex_role.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}


int GetCastleHexRole(HEX_POSITION p) {
	return GetCastleHexRole(p.x, p.y);
}



// ����w�b�N�X�ꏊ�̃`�b�v�̍����𓾂�
int GetCastleHexHigh(double x, double y) {
	// ���W�l�͑Ó��Ȕ͈͂��H
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// y�����W���l�ɂ��āA������
		int _y = round�s�������t(y);
		// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// x���ł��߂��l�̐�����
		int _x = round�s�������t(x);
		// �O��菬�����Ȃ邱�Ƃ�����̂łO��
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(CASTLE_HEX_ROLE)��Ԃ�
		return nb6castle_hex_high.pos_y[_y].pos_x[_x];
	}
	else {
		return -1;
	}
}

int GetCastleHexHigh(HEX_POSITION p) {
	return GetCastleHexHigh(p.x, p.y);
}



/* ���ŉE�P�o�C�g���P�̏��͉����t���Ă���
004D4DAA                          10 10 10 10 10 10 10 10          
004D4DBA  10 00 00 00 00 00 00 00 00 10 10 10 11 98 90 10  ........�E
004D4DCA  10 10 10 00 00 00 00 00 00 00 00 10 10 10 10 90  ........�E
004D4DDA  90 90 10 10 10 10 00 00 00 00 00 00 00 10 10 10  ��.......
004D4DEA  10 91 90 10 10 10 10 00 00 00 00 00 00 00 00 00  ��.........
004D4DFA  10 10 10 11 10 10 10 10 10 00 00 00 00 00 00 00  .......
004D4E0A  00 00 10 10 11 11 11 10 10 10 00 00 00 00 00 00  ........
004D4E1A  00 00 00 00 00 10 10 10 11 10 10 10 00 00 00 00  .........
004D4E2A  00 00 00 00 00 00 00 10 10 10 10 10 10 00 00 00  ..........
*/
// ����w�b�N�X�ꏊ�̃`�b�v�̉��̖���(CASTLE_HEX_ROLE)�𓾂�
// �����t���Ă��鏊�́A�E�̂P�o�C�g��1�ɂȂ�B
int GetFireHexRole(double x, double y) {
	// ���W�l�͑Ó��Ȕ͈͂��H
	if (0 <= x && x< GAMEDATASTRUCT_CASTLE_HEX_COLS && 0 <= y && y< GAMEDATASTRUCT_CASTLE_HEX_ROWS) {
		// y�����W���l�ɂ��āA������
		int _y = round�s�������t(y);
		// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"��HEX"�����l��x�ɓ����Ă��邽�߁B
		if (_y % 2 == 1) {
			x = x - 0.5;
		}
		// x���ł��߂��l�̐�����
		int _x = round�s�������t(x);
		// �O��菬�����Ȃ邱�Ƃ�����̂łO��
		if (_x < 0) { _x = 0; }
		if (_x >= GAMEDATASTRUCT_CASTLE_HEX_COLS) { _x = GAMEDATASTRUCT_CASTLE_HEX_COLS - 1; }
		if (_y >= GAMEDATASTRUCT_CASTLE_HEX_ROWS) { _y = GAMEDATASTRUCT_CASTLE_HEX_ROWS - 1; }
		// �Y���̏ꏊ�ɂ���`�b�v�̖����ԍ�(CASTLE_HEX_ROLE)��Ԃ�
		return (nb6fire_hex_role.pos_y[_y].pos_x[_x] & 0xF) == 1;
	}
	else {
		return -1;
	}
}


int GetFireHexRole(HEX_POSITION p) {
	return GetFireHexRole(p.x, p.y);
}


// �t�B�[���h�w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
D3D_POSITION FieldHexPos_To_WorldPos(HEX_POSITION p) {
	D3D_POSITION p_real;
	p_real.x = p.x - GAMEDATASTRUCT_FIELD_HEX_CENTER_X;
	p_real.z = (p.y - GAMEDATASTRUCT_FIELD_HEX_CENTER_Y) * (sqrt(3.0f) / 2.0f) * -1; // sin60��
	if (p_real.z == 0) { p_real.z = 0; } // �A�z�݂��������A"-0"�ƂȂ�Ȃ��悤�ɂ���B

										 // y�̍��������߂�ɂ������āA��R�Ȃ�1, ���R�Ȃ�2, ���R�Ȃ�3�Ƃ���B
	int iHexRole = GetFieldHexRole(p.x, p.y);

	if (iHexRole == FIELD_HEX_ROLE::���R) {
		p_real.y = 3;
	}
	else if (iHexRole == FIELD_HEX_ROLE::���R) {
		p_real.y = 2;
	}
	else if (iHexRole == FIELD_HEX_ROLE::��R) {
		p_real.y = 1;
	}
	else {
		p_real.y = 0;
	}
	return p_real;
}

// ���ʂ̂R�������W(����f�J���g)���t�B�[���h�w�b�N�X�̍��W��
HEX_POSITION WorldPos_To_FieldHexPos(D3D_POSITION p) {
	HEX_POSITION p_hex;
	p_hex.x = round�s�������t(p.x + GAMEDATASTRUCT_FIELD_HEX_CENTER_X);
	p_hex.y = round�s�񕪂̈�z�����t((2.0f / sqrt(3.0f)) * (p.z) * -1 + GAMEDATASTRUCT_FIELD_HEX_CENTER_Y);
	return p_hex;
}

// ��w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
D3D_POSITION CastleHexPos_To_WorldPos(HEX_POSITION p) {
	D3D_POSITION p_real;
	p_real.x = p.x - GAMEDATASTRUCT_CASTLE_HEX_CENTER_X;
	p_real.z = (p.y - GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y) * (sqrt(3.0f) / 2.0f) * -1; // sin60��
	if (p_real.z == 0) { p_real.z = 0; } // �A�z�݂��������A"-0"�ƂȂ�Ȃ��悤�ɂ���B

										 // y�̍��������߂�ɂ������ď�̍������𓖂Ă͂߂�B
	int iHexHigh = GetCastleHexHigh(p.x, p.y);
	p_real.y = iHexHigh;
	return p_real;
}

// ���ʂ̂R�������W(����f�J���g)����w�b�N�X�̍��W��
HEX_POSITION WorldPos_To_CastleHexPos(D3D_POSITION p) {
	HEX_POSITION p_hex;
	p_hex.x = round�s�������t(p.x + GAMEDATASTRUCT_CASTLE_HEX_CENTER_X);
	p_hex.y = round�s�񕪂̈�z�����t((2.0f / sqrt(3.0f)) * (p.z) * -1 + GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y);
	return p_hex;
}


// �w�b�N�X�Ԋu�̎擾�Bp1��p2�܂ŉ��e�ړ�����K�v������̂�(�S�Ă̞e�͍s������̂Ɖ��肷��)
int getHexDistance(HEX_POSITION p1, HEX_POSITION p2) {
	double ax = double(abs(p1.x - p2.x));
	double ay = double(abs(p1.y - p2.y));
	if (p1.y == p2.y) { // �����s�ɋ���Ȃ�΁c
		return round�s�������t(ax);
	}
	else if (ax * 2 <= ay) { // 2�_�Ԃ�X���W�̍���2�_�Ԃ�Y���W�̍��̔����ȉ��̏ꍇ�AY���W�̈ړ������ŊY���|�C���g�܂œ��B�ł���B
		return round�s�������t(ay);
	}
	else {
		// X�̍� + Y�̍� - Y�̍��̔���
		return round�s�������t(ax + ay - 0.5*ay);
	}
}




// ���ݏo�w���Ă���iBushouID�̈ꗗ�𓾂�B
vector<int> GetSyutujinBushouArray() {
	vector<int> bArray;

	// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } // �����Ŕ͈͕ۏႵ�Ă����Ă�����B���̐l

		int iBushouID = nb6bushou_hex_unit_info[i].bushou - 1;

		if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
			// �펀��ދp���Ă��Ȃ�
			if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
				bArray.push_back(iBushouID);
			}
		}
	}

	return bArray;
}

// ���ݕ\������Ă���}�b�v����ŁA�o�w���Ă���iBushouID�̈ꗗ�𓾂�B
vector<int> GetCurMapSyutujinBushouArray() {
	vector<int> bArray;

	if (Is_CastleWar()) {
		for (int i = 0; i<GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS; i++) {
			int iBango = nb6castle_hex_unit_pos.index[i];
			if (1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM) {
				if (nb6bushou_hex_unit_info[iBango - 1].bushou != 0xFFFF) {
					int iBushouID = nb6bushou_hex_unit_info[iBango - 1].bushou - 1;

					if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
						// �펀��ދp���Ă��Ȃ�
						if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
							bArray.push_back(iBushouID);
						}
					}
				}
			}
		}
	}
	if (Is_FieldWar()) {
		for (int i = 0; i<GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS; i++) {
			int iBango = nb6field_hex_unit_pos.index[i];
			if (1 <= iBango && iBango <= GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM) {
				if (nb6bushou_hex_unit_info[iBango - 1].bushou != 0xFFFF) {
					int iBushouID = nb6bushou_hex_unit_info[iBango - 1].bushou - 1;

					if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
						// �펀��ދp���Ă��Ȃ�
						if (nb6bushouname[iBushouID].battleDeath == 0 && nb6bushouname[iBushouID].battleRetreat == 0) {
							bArray.push_back(iBushouID);
						}
					}
				}
			}
		}
	}
	return bArray;
}


// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B
HEX_POSITION GetFieldHexUnitPos(int iBushouID) {

	HEX_POSITION pos(0xFFFF, 0xFFFF);

	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return pos;
	}
	if (!Is_FieldWar()) {
		return pos;
	}

	// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } //

																						 // �T���Ă镐�����A�\�����̖��ɋ���!!
		if (iBushouID == nb6bushou_hex_unit_info[i].bushou - 1) {
			int x = nb6bushou_hex_unit_info[i].pos_x;
			int y = nb6bushou_hex_unit_info[i].pos_y;

			if (x == 0xFFFF) {
				return pos;
			}

			// y�����W���l�ɂ��āA������
			pos.y = y;

			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"���W��0.5���E�ɂ��炷�B
			if (y % 2 == 1) {
				pos.x = x + 0.5;
			}
			else {
				pos.x = x;
			}

			return pos;
		}
	}

	return pos;
}




// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFFFF, y=0xFFFF) ���Ԃ��Ă���B
HEX_POSITION GetCastleHexUnitPos(int iBushouID) {


	HEX_POSITION pos(0xFFFF, 0xFFFF);

	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return pos;
	}
	if (!Is_CastleWar()) {
		return pos;
	}

	// ���ɂ��镐����������𖞂������̂̈ړ��c�ʂ𑝂₷�B
	for (int i = 0; i<GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == 0xFFFF) { continue; } // 0xFFFF���Ƃ��̃X���b�g�ɕ����͋��Ȃ��B���̐l
		if (nb6bushou_hex_unit_info[i].bushou > GAMEDATASTRUCT_BUSHOU_NUM) { continue; } //

																						 // �T���Ă镐�����A�\�����̍U��퓬�ɋ���!!
		if (iBushouID == nb6bushou_hex_unit_info[i].bushou - 1) {
			int x = nb6bushou_hex_unit_info[i].pos_x;
			int y = nb6bushou_hex_unit_info[i].pos_y;

			if (x == 0xFFFF) {
				return pos;
			}

			// y�����W���l�ɂ��āA������
			pos.y = y;

			// ���̋����s�ڂ���s�ڂ��ŁA���g���炷�B�����s�Ȃ�A"���W��0.5���E�ɂ��炷�B
			if (y % 2 == 1) {
				pos.x = x + 0.5;
			}
			else {
				pos.x = x;
			}

			return pos;
		}
	}

	return pos;
}


// ���ݐi�s���̐푈�Ɋւ���Ă���iDaimyoID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
vector<int> GetCurWarJointDaimyoIDList() {
	vector<int> list;
	if (Is_FieldWar() || Is_CastleWar()) {
		// �Q���喼�ԍ����������āA
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1;
			// �͈͓��ł���΁A���X�g�ɒǉ�
			if (0 <= iDaimyoID && iDaimyoID < GAMEDATASTRUCT_DAIMYO_NUM) {
				// �Y���̒l�����ł�list���ɂ��邩
				vector<int>::iterator  iter = std::find(list.begin(), list.end(), iDaimyoID);
				// ���݂��Ȃ���΁c
				if (iter == list.end()) {
					// �ǉ�
					list.push_back(iDaimyoID);
				}
			}
		}
	}


	return list;
}

// ���ݐi�s���̐푈�Ɋւ���Ă���iGundanID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
vector<int> GetCurWarJointGundanIDList() {
	vector<int> list;
	if (Is_FieldWar() || Is_CastleWar()) {
		// �Q���喼�ԍ����������āA
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;
			// �͈͓��ł���΁A���X�g�ɒǉ�
			if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
				list.push_back(iGundanID);
			}
		}
	}

	return list;
}




// �Y���̌R�c�̐��ɂ����闧���Ԃ�(���ڎ�鑤=0, ���ڍU�߂鑤=1, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
int GetWarStandPointTheGundan(int iGundanID) {

	if (!(0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM)) {
		return WarStandPoint::unknown;
	}

	// enum { unknown = -1,  �U���e�R = 1,  �U���q�R = 5,  ����e�R=0, ����q�R = 4, �����e�R=2, �����q�R=6, �U�����R�e�R=1, �U�����R�q�R=5, ������R�e�R=0, ������R�q�R=4 };

	if (Is_FieldWar() || Is_CastleWar()) {

		//--------------------------------- ���ڍU�����A�������́A���ږh�䑤�ł���΁A�푈�J�n�p�����^����͂����o����
		// �w��̌R�c�̑喼ID
		int iDaimyoID = nb6gundan[iGundanID].attach - 1;

		// �U�����̌R�c�̑喼ID
		int iAttackDaimyoID = -1;
		int iAttackGundanID = -1;
		if (0 <= nb6war_battle_daimyo_info.attack_gundan - 1 && nb6war_battle_daimyo_info.attack_gundan - 1 < GAMEDATASTRUCT_GUNDAN_NUM) {
			iAttackDaimyoID = nb6war_battle_daimyo_info.attack_daimyo - 1;
			iAttackGundanID = nb6war_battle_daimyo_info.attack_gundan - 1;
		}

		// ������̌R�c�̑喼ID
		int iDefendDaimyoID = -1;
		int iDefendGundanID = -1;
		if (0 <= nb6war_battle_daimyo_info.defend_gundan - 1 && nb6war_battle_daimyo_info.defend_gundan - 1 < GAMEDATASTRUCT_GUNDAN_NUM) {
			iDefendDaimyoID = nb6war_battle_daimyo_info.defend_daimyo - 1;
			iDefendGundanID = nb6war_battle_daimyo_info.defend_gundan - 1;
		}

		// �w��̌R�c�̑喼�͒��ڍU���̑喼
		if (iDaimyoID == iAttackDaimyoID) {
			return WarStandPoint::attack; // ���ڍU����
		}
		// �w��̌R�c�̑喼�͒��ڎ���̑喼
		else if (iDaimyoID == iDefendDaimyoID) {
			return WarStandPoint::defend; // ���ږh�䑤
		}

		//--------------------------------- ����ȊO�̏ꍇ�́AWAR_JOINT_DAIMYO_HEX_GROUP_INFO �n�̏�񂩂�H���Ă���

		// �Q���喼�ԍ����������āA�U�����̃O���[�vID�A������̃O���[�vID���o���B
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {
			// ���R�⒆���R���`�F�b�N
			int JoinGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1; // �Q���R�cID
			int JoinDaimyoID = (int)nb6war_joint_daimyo_hex_group_info[ix].daimyo - 1; // �Q���喼ID
																					   // �w��̌R�c�Ɠ����R�cID�ł���ꍇ�̂ݒl��Ԃ��B
			if (iGundanID == JoinGundanID) {

				// �w��̌R�c�̑喼�͒��ڍU���̑喼
				if (JoinDaimyoID == iAttackDaimyoID) {
					return WarStandPoint::attack; // ���ڍU����
				}
				// �w��̌R�c�̑喼�͒��ڎ���̑喼
				else if (JoinDaimyoID == iDefendDaimyoID) {
					return WarStandPoint::defend; // ���ږh�䑤
				}

				// 2��6�Ȃ璆���R�B2�������̐e�R�ŁA6�������̎q�R
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 2 || nb6war_joint_daimyo_hex_group_info[ix].group == 6) {
					// �����R
					return WarStandPoint::chuuritsu;
				}
				// 1��5�Ȃ片�R�̍U���R�B1�����R�̐e�R�ŁA5�����R�̎q�R
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 1 || nb6war_joint_daimyo_hex_group_info[ix].group == 5) {
					// ���R�̍U���R
					return WarStandPoint::attack_enngun;
				}
				// 0��4�Ȃ片�R�̎���R�B0�����R�̐e�R�ŁA4�����R�̎q�R
				else if (nb6war_joint_daimyo_hex_group_info[ix].group == 0 || nb6war_joint_daimyo_hex_group_info[ix].group == 4) {
					// ���R�̎���R
					return WarStandPoint::defend_enngun;
				}
			}
		}
	}

	return WarStandPoint::unknown; // �s��
}

// �Y���̕����̐��ɂ����闧���Ԃ�(�s��=0, ���ڍU�߂鑤=1, ���ڎ�鑤=2, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
int GetWarStandPointTheBushou(int iBushouID) {

	// �͈̓`�F�b�N
	if (!(0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM)) {
		return WarStandPoint::unknown;
	}

	// �Y�������̌R�cID����
	int iGundanID = nb6bushou[iBushouID].gundan - 1;
	if (0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM) {
		return GetWarStandPointTheGundan(iGundanID);
	}

	return WarStandPoint::unknown;
}

// ���݂̐�ɂ����āA�w��R�c�̑��叫(�R�c����喼�̂��Ƃł͂Ȃ��A���ɂ����Ă̊Y���R�c�̑��叫�B
int GetWarSoudaishoTheGundan(int iGundanID) {
	if (!(0 <= iGundanID && iGundanID < GAMEDATASTRUCT_GUNDAN_NUM)) {
		return 0xFFFF;
	}

	if (Is_FieldWar() || Is_CastleWar()) {
		// �Q���喼�ԍ����������āA�U�����̃O���[�vID�A������̃O���[�vID���o���B
		for (int ix = 0; ix < GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM; ix++) {

			int iJointGundanID = (int)nb6war_joint_daimyo_hex_group_info[ix].gundan - 1;

			// �w��̌R�c���������B
			if (iGundanID == iJointGundanID) {
				// �����ԍ�(+1�̕�)�͈̔͂Ɏ��܂��Ă���B
				if (0 < nb6war_joint_daimyo_hex_group_info[ix].soudaisho && nb6war_joint_daimyo_hex_group_info[ix].soudaisho <= GAMEDATASTRUCT_BUSHOU_NUM) {
					return nb6war_joint_daimyo_hex_group_info[ix].soudaisho - 1;
					// �����ԍ��͈̔͂Ɏ��܂��Ă��Ȃ��Ƃ������Ƃ́A�喼��R�c�͌��܂��Ă��邪�A���叫�����܂��Ă��Ȃ��B���j�b�g�z�u�O���Ƒ��叫�����܂�Ȃ��̂ŁA���̂悤�Ȓl�ƂȂ�B
				}
				else {
					return 0xFFFF;
				}
			}
		}
	}

	return 0xFFFF;
}



// �w�蕐�������ɂ����āA�s���ς݂��ǂ���
BOOL IsActionEndInBattle(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
			if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
				if (nb6bushou_hex_unit_info[i].bEnd == 0x2) { // �s���ςł���B
					return TRUE;
				}
				else {
					return FALSE;
				}
				break;
			}
		}
	}
	return FALSE;
}


// �Ώۂ̕������������Ă��邩�B
int GetKonranStatus(int iBushouID) {
	if (0 <= iBushouID && iBushouID < GAMEDATASTRUCT_BUSHOU_NUM) {
		for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
			if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
				return nb6bushou_hex_unit_info[i].konran;
			}
		}
	}
	return KONRAN_STATUS::����;
}


int GetBushouMovePower(int iBushouID) {

	// �ړ��͂��኱��
	for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
			return nb6bushou_hex_unit_info[i].movepower;
		}
	}
	return 0xFFFF;
}


int SetBushouMovePower(int iBushouID, int iMovePower) {

	// �ړ��͂��኱��
	for (int i = 0; i < GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM; i++) {
		if (nb6bushou_hex_unit_info[i].bushou == iBushouID + 1) {
			nb6bushou_hex_unit_info[i].movepower = iMovePower;
			break;
		}
	}
	return 0xFFFF;
}
