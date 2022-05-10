#pragma once

#include <windows.h>


struct HEX_XY {
	int cols;
	int rows;
};


// �w�b�N�X�̍��W���n�B�w�� �x���@�Œl���������Ă����B
struct HEX_POSITION {
	HEX_POSITION(double _x, double _y) : x(_x), y(_y) {}
	HEX_POSITION() : x(0), y(0) {}
	double x;
	double y;
};

// �t�B�[���h�̕����x�N�g���B�w�� �x���@�Œl���������Ă����B
struct HEX_VECTOR {
	HEX_VECTOR(double _x, double _y) : x(_x), y(_y) {}
	HEX_VECTOR() : x(0), y(0) {}
	double x;
	double y;
};

// �t�B�[���h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
HEX_VECTOR operator-(HEX_POSITION &p1, HEX_POSITION &p2);




#define GAMEDATASTRUCT_FIELD_HEX_COLS			41	// ����HEX�̉��̐�
#define GAMEDATASTRUCT_FIELD_HEX_ROWS			24	// ����HEX�̏c�̐�

const int GAMEDATASTRUCT_FIELD_HEX_CENTER_X = 20;
const int GAMEDATASTRUCT_FIELD_HEX_CENTER_Y = 12;

namespace FIELD_HEX_ROLE {
	enum { �g�O = 0x00, ���n = 0x1, �� = 0x2, ���n = 0x3, �r��n = 0x4, �X = 0x5, ��R = 0x6, ���R = 0x7, ���R = 0x8, �� = 0x9, �� = 0xA, �C = 0xB, �� = 0xB, �� = 0xC /*�Q�A��*/ };
}

// ��펞�̃w�b�N�X�̖����̃o�C�g��
union NB6FIELD_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41���A24�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};

// ��펞�̃��j�b�g�̃}�b�v���̃|�W�V����
union NB6FIELD_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_FIELD_HEX_COLS * GAMEDATASTRUCT_FIELD_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_FIELD_HEX_COLS];				// 41���A24�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_FIELD_HEX_ROWS];
};


// ����w�b�N�X�ꏊ�̃`�b�v�̖���(FIELD_HEX_ROLE)�𓾂�
int GetFieldHexRole(double x, double y);
int GetFieldHexRole(HEX_POSITION p);

// �t�ɐݒ肷��B(�Ƃ����Ă��A�ݒ肵���Ƃ��Ă��A�G���ς��Ȃ��̂ŏ�肭�����Ȃ���)
void SetFieldHexRole(double x, double y, int eHexRole);
void SetFieldHexRole(HEX_POSITION p, int eHexRole);



// ����w�b�N�X�ꏊ�̍���
int GetCastleHexHigh(double x, double y);
int GetCastleHexHigh(HEX_POSITION p);


// ����w�b�N�X�ꏊ�̍���
int GetFieldHexHigh(double x, double y);
int GetFieldHexHigh(HEX_POSITION p);


#define GAMEDATASTRUCT_CASTLE_HEX_COLS			18	// �U����HEX�̉��̐�
#define GAMEDATASTRUCT_CASTLE_HEX_ROWS			16	// �U����HEX�̏c�̐�

const int GAMEDATASTRUCT_CASTLE_HEX_CENTER_X = 9;
const int GAMEDATASTRUCT_CASTLE_HEX_CENTER_Y = 8;

namespace CASTLE_HEX_ROLE {
	enum { �g�O = 0x00, ������n = 0x10, ������n = 0x11, ��O���n = 0x12, �X = 0x13, �x = 0x14, �C = 0x14, �� = 0x14, �x�� = 0x15, ��� = 0x16, �� = 0x17, �J�� = 0x18, �E = 0x19, �� = 0x1A, �{�� = 0x1B };
}

// �퓬��ʂ̏���w�b�N�X�̖����̃o�C�g��
union NB6CASTLE_HEX_ROLE {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// �퓬��ʂ̏���w�b�N�X�̍����̃o�C�g��
union NB6CASTLE_HEX_HIGH {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};

// ��U���̃��j�b�g�̃}�b�v���̃|�W�V����
union NB6CASTLE_HEX_UNIT_POS {
	BYTE index[GAMEDATASTRUCT_CASTLE_HEX_COLS * GAMEDATASTRUCT_CASTLE_HEX_ROWS];				// �o�C�g��̃C���f�b�N�X�Ƃ��Ă݂��ꍇ
	struct {
		BYTE pos_x[GAMEDATASTRUCT_CASTLE_HEX_COLS];				// 18���A16�s�Ƃ��Č����ꍇ;
	} pos_y[GAMEDATASTRUCT_CASTLE_HEX_ROWS];
};


// ����w�b�N�X�ꏊ�̃`�b�v�̖���(CASTLE_HEX_ROLE)�𓾂�
int GetCastleHexRole(double x, double y);
int GetCastleHexRole(HEX_POSITION p);



// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFF, y=0xFF) ���Ԃ��Ă���B
HEX_POSITION GetFieldHexUnitPos(int iBushouID);

// �w��̕����h�c�̕������ǂ��ɂ���̂��H ���Ȃ��ꍇ�Ap(x=0xFF, y=0xFF) ���Ԃ��Ă���B
HEX_POSITION GetCastleHexUnitPos(int iBushouID);



// �w�b�N�X�Ԋu�̎擾�Bp1��p2�܂ŉ��e�ړ�����K�v������̂�(�S�Ă̞e�͍s������̂Ɖ��肷��)
int getHexDistance(HEX_POSITION p1, HEX_POSITION p2);


// �t�B�[���h�w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
D3D_POSITION FieldHexPos_To_WorldPos(HEX_POSITION p);

// ���ʂ̂R�������W(����f�J���g)���t�B�[���h�w�b�N�X�̍��W��
HEX_POSITION WorldPos_To_FieldHexPos(D3D_POSITION p);

// ��w�b�N�X�̍��W�����ʂ̂R�������W(����f�J���g�E���Ɠ�����)
D3D_POSITION CastleHexPos_To_WorldPos(HEX_POSITION p);

// ���ʂ̂R�������W(����f�J���g)����w�b�N�X�̍��W��
HEX_POSITION WorldPos_To_CastleHexPos(D3D_POSITION p);






namespace FIRE_HEX_ROLE {
	enum { ���� = 0x00, ���� = 0x01 };
}

// ����w�b�N�X�ꏊ�̃`�b�v�̉����
int GetFireHexRole(double x, double y);
int GetFireHexRole(HEX_POSITION p);





// �w�b�N�X�̂`�_�Ƃa�_�̊Ԃɂ���`�b�v�̃A���C��Ԃ��B
vector<int> RoleArrayOfBetweenPosToPos(HEX_POSITION pos1, HEX_POSITION pos2);


