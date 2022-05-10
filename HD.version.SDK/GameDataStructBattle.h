#pragma once

#include <windows.h>





struct NB6BUSHOU_HEX_UNIT_INFO {
	WORD bushou;					// �����ԍ��B1�傫�����̕��B�����ԍ��Ɏ����ɂ�-1���邱�ƁB
	WORD junban;					// ���̒l�̓^�[�����ԁB�푈�ɂ����āA���̐��l���Ⴂ�R�c���珇�Ԃ����Ƃ������ƁB
	int	 pos_x;						// �s���ɂ�����pos_x�B�߂܂�����A�ދp�����肵�āA��ꂩ�狏�Ȃ��Ȃ�ƁA0xFFFF
	int	 pos_y;						// �s���ɂ�����pos_y�B�߂܂�����A�ދp�����肵�āA��ꂩ�狏�Ȃ��Ȃ�ƁA0xFFFF
	BYTE movepower;					// �ړ��͎c�ʁB0x1�`0xF���炢�̐��l�������Ă���B
	WORD _undef2;					// �s��2 ���j�b�g���݂��Ă�̂�FFFF�A���Ă��Ȃ��̂�
	BYTE _undef3;					// �s��1
	BYTE _undef4;					// �s��1
	BYTE _undef5;					// �s��1
	WORD _what1;					// �����Ӗ������肻���B1�`8���炢�̐��l�������Ă���B
	WORD _undef6;					// �ق�0x0000
	WORD _undef7;					// �ق�0xFFFF
	BYTE konran : 4;					// 1=�ʏ퍬�� 2=�卬�� 3=����
	BYTE bEnd : 4;					// �s���σt���O�B0x2=�s���ς�, 0x0=���s��
	BYTE _what4;					// �����Ӗ������肻���B���݂��Ă镐���́A�0x2�������
	WORD _what5;					// �����Ӗ������肻���B���݂��Ă镐���́A�0x70�������
	int	 _undef8;					// �s��
};

// �w�蕐�������ɂ����āA�s���ς݂��ǂ���
BOOL IsActionEndInBattle(int iBushouID);


namespace KONRAN_STATUS {
	enum { ���� = 0, ���� = 1, �卬�� = 2, ���� = 3 };
}
// �Ώۂ̕������������Ă��邩�B
int GetKonranStatus(int iBushouID);
// �Ώۂ̕���������������B(�`�悪����Ȃ�)


// �ړ��͎c�ʂ𓾂�
int GetBushouMovePower(int iBushouID);

// �ړ��͎c�ʂ�ݒ肷��
int SetBushouMovePower(int iBushouID, int iMovePower);


// �푈���Ɋւ���Ă���u�喼�E�R�c�E���叫�E[�U�ߎ�E�󂯎�E����]�v���
struct NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO {
	WORD daimyo;		// �喼�ԍ�
	WORD gundan;		// �R�c�ԍ�
	WORD soudaisho;		// ���叫�̕����ԍ�
	WORD group;			// ���Ԃ��U�����A�󑤂��A�Ȃǂ́A�s��B�����܂ł��A�퓬�J�n���̍U�ߑ��喼�Ɠ����O���[�v���U�ߑ��̉��R�A�󑤂̑喼�Ɠ����O���[�v���󑤁A����ȊO�������ł���B
	WORD _undef;		// ���ɂȂɂ��Ȃ��Bmust 0000
};

// ���ǐ���Ă���̂͂ǂ��̑喼�Ȃ̂��H
struct NB6WAR_BATTLE_DAIMYO_INFO {
	int defend_gundan;	// ���ڎ�����̌R�c�ԍ�
	int attack_gundan;	// ���ڍU�����̌R�c�ԍ�
	int defend_daimyo;  // ���ڎ�����̑喼�ԍ�
	int attack_daimyo;  // ���ڍU�����̑喼�ԍ�
};


// �푈�ɏo�w���Ă���iBushouID�̈ꗗ�𓾂�B
vector<int> GetSyutujinBushouArray();

// ���ݕ\������Ă���}�b�v����ŁA�o�w���Ă���iBushouID�̈ꗗ�𓾂�B
vector<int> GetCurMapSyutujinBushouArray();





// ���ݐi�s���̐푈�Ɋւ���Ă���iDaimyoID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
vector<int> GetCurWarJointDaimyoIDList();

// ���ݐi�s���̐푈�Ɋւ���Ă���iGundanID�̃��X�g�B(�o�w���Ă��邩�ǂ����͊֌W�Ȃ�)
vector<int> GetCurWarJointGundanIDList();



namespace WarStandPoint {
	//	   �s��          ���ڍU����   ���ڎ����   �U�����̉��R�@      ������̉��R�@�@�����R 
	enum { unknown = 0, attack = 1, defend = 2, attack_enngun = 3, defend_enngun = 4, chuuritsu = 5 };
};

// �Y���̌R�c�̐��ɂ����闧���Ԃ�(�s��=0, ���ڍU�߂鑤=1, ���ڎ�鑤=2, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
int GetWarStandPointTheGundan(int iGundanID);

// �Y���̕����̐��ɂ����闧���Ԃ�(�s��=0, ���ڍU�߂鑤=1, ���ڎ�鑤=2, �U�߂鑤�̉��R=3, ��鑤�̉��R=4, �����R=5)
int GetWarStandPointTheBushou(int iBushouID);

// ���݂̐�ɂ����āA�w��R�c�̑��叫(�R�c����喼�̂��Ƃł͂Ȃ��A���ɂ����Ă̊Y���R�c�̑��叫�B
int GetWarSoudaishoTheGundan(int iGundanID);


