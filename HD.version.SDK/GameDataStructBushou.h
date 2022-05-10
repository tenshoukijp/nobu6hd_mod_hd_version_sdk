#pragma once

/*
�������O�e�[�u��(18*500�ƕP���p��18*32)

[24�o�C�g]
*/
struct NB6BUSHOUNAME
{
	char familyname[9];	//����
	char fastname[9];	//���O
	WORD number;		//�����i���o�[(����12bit�͗�`�H)
	WORD face;
	byte State : 4;		//0�喼,1�R��,2����,3�B��,4�Q�l,5�P,6,�ҋ@,7���S
	byte position : 4;	//�g��		(�B��=0, �喼=1, �h�V=2, �ƘV=3, ����=4, ���叫=5, ���y��=6)
	byte sex : 1;			//�� 0-�j 1-��
	byte battleRetreat : 1;	//1:���őދp�����B0:�ʏ�ʂ�
	byte battleDeath : 1;	//1:���Ő펀�����B0:�ʏ�ʂ�
	byte _undef : 5;
};


/*
�y�����̃A���S���Y���z:
0�c�����ƌĂ΂ꂽ�l���B�L�������ɑ����B�M���G�g�ƍN�ق��A�֓����O�⏼�i�v�G���B
�����I�ȃo�����X�̗ǂ��^�C�v�����Acom�̏ꍇ���͂΂��葝�₵�A���܂�푈���Ȃ��B
1�c�ҏ��ɑ����B�ēc���Ƃ�`��i�Ƃ�암������B
2�c�퓬�ɋ��������������B�����ȂǁB
3�c�퓬�����B���쎁�^��B�����D���H
4�c�����]�ᓙ�A�V��E���l���̕����l�n�����B�����D���H
5�c�E�ҕ�����A�v���e���E���n�@���`�ȂǁB�����D���B
6�c�ڗ����Ȃ��U�R�����B���\�^�C�v�H
7�c�I���W�i���P�B���i�͕s���B
255�c�����_���P�B���i�͕s���B
*/

/*
�y�����z:
0 ����			 217 �^�c�K���E���@�䕔���e�E���Ë`�v�E�E�ґS��
1 ��V������	 152 �O�c���ƁE���q���G�E���ԏ@�΁E�������
2 �e�\			 119 �ēc���ƁE���������M�E���ˑ��E���X�؏����Y
3 ���M			 30 �㐙�����E����`���E�����`���E�������
4 ���ӋC		 180 �ɒB���@�E�O�D���c�E��؏d�G�E�R�䐳��
5 �Ќ�			 143 �D�c�M���E����ƍN�E���c�M���E�㐙���M
6 �`��			 145 �L�b�G�g�E�֓����O�E���i�v�G�E�����`��
7 ���			 314 �{�������E�g�쌳�t�E�R�����V���E�j���P�S��
*/

/*
[�����f�[�^(47*532)]

0-1	�O�̕���
2-3 ���̕���
4-5	�H
6	����
7	���
8	�q��
9-10	���n   ( min 500 �` max 2000 )
11-12	��n   ( min 500 �` max 2000 )
13-14	�q�n   ( min 500 �` max 2000 )
15	����
16	��]
17	����
18-19	�M��
20	���� 0xFF�͖���
21-22	�喼(�喼�ԍ�)  �����喼�y�喼�ԍ��z;	//�喼
23-24	�R�c(�R�c�ԍ�)  �����R�c�y�R�c�ԍ��z;	//�R�c
25-26	����		    ��������y��ԍ��z;	//����
27-28	������ FFFF ����
29	����
30	�P��
31	����
32	����(0=���y,1=�R�n,2=�S�C,3=�R�n�S�C,18�܂�)
33	�d��
34	�� ���Ɍ����ς݃t���O����H
35	���N
36-37	�e��NO
38	�v�l
39	aaaabbbb a-���� b-�`��
40	00aabbcc a-�q�K b-��K c-���K
41	�Z�\
42	�E�� 0x00�� 0x10 �E�� 0x20 ���l 0x30 ���� 0x40 �m�� 0x50 �C�� 0x60 ���� 0x70 ���l 0x80 ���� 0x90 �؎x�O 0xA0 �R�m 0xB0 ���p�m 0xC0 ����
43-44	���ȁE�R�n�S�C�E��C�E�S�b�D
0123 4445 5566 6777
0=���֌W�H,1=�S�b�D,2=�R�n�S�C,3=��C
4,5,6,7=���R,�S�C,�R�n,���y�̕��ȁAMAX5
45	aabbbccc a-�Ɨ� b-�E�� c-����
46	1234aaa5 1=� 2-�⍦ 3 ���� 4-�s�� 5�Ɨ��̃r�b�g�̑���
a-����
*/

struct NB6BUSHOU
{
	WORD prev;
	WORD next;
	WORD _undef2;		//must 0xFFFF
	byte maxgov;		//����
	byte maxbat;		//���
	byte maxint;		//�q��
	WORD expgov;		//���n
	WORD expbat;		//��n
	WORD expint;		//�q�n
	char charm;			//����
	char ambition;		//��]
	char loyal;			//����
	WORD merits;		//�M��
	byte blood;			//���� 0xFF�͖���
	WORD attach;		//�喼  �����喼�y�喼�ԍ��z;	//�喼
	WORD gundan;		//�R�c  �����R�c�y�R�c�ԍ��z;	//�R�c
	WORD castle;		//����  ��������y��ԍ��z;	//����
	WORD rise;			//������ 0xFFFF ������̑喼�ԍ�
	byte soldier;		//����
	byte training;		//�P��
	byte solloyal;		//����
	byte form;			//����(0=���y,1=�R�n,2=�S�C,3=�R�n�S�C,18�܂�)
	byte work;			//�d���N��
	byte spouse;		//�� (�����ԍ���500�Ԉȏオ�Ȃ�P�ƂȂ�����ł���B���肪500�Ԃ̎��ɁA������0�Ƃ������l������B0��0+500�ˋA�� �Ƃ�������B
						//�� ���̔ԍ���255�Ȃ�Ȃ͂��Ȃ��B255�ȊO�̎�(�Ⴆ��3)�́A���̔ԍ���500�������y�����ԍ��z(�Ⴆ��503)�̏������ȂƂ�������)
						// �����ĊY���̕���(�ȕP����)��_�Ȃ�����(�Ⴆ��3)�̒l�ɂȂ��Ă��邱�ƁB
	byte birth;			//���N - 1454
	WORD parent;		//�e��NO
	byte algo;			//�v�l
	byte duty : 4;		//�`��
	byte affinity : 4;	//����
						//00aa bbcc a-�q�K b-��K c-���K
	byte aptitudegov : 2;	//c-���K (2=A,1=B,0=C)
	byte aptitudebat : 2;	//b-��K (2=A,1=B,0=C)
	byte aptitudeint : 2;	//a-�q�K (2=A,1=B,0=C)
	byte undef_5 : 2;		//
	byte tech_ikkatsu : 1;	//�Z�\�E�ꊅ
	byte tech_ansatsu : 1;	//�Z�\�E�ÎE
	byte tech_ryusyutsu : 1;	//�Z�\�E���o
	byte tech_sendou : 1;		//�Z�\�E����
	byte tech_ryugen : 1;		//�Z�\�E����
	byte tech_benzetsu : 1;	//�Z�\�E�ِ�
	byte tech_yakiuchi : 1;	//�Z�\�E�ē�
	byte tech_chohatsu : 1;	//�Z�\�E����
	byte job;			//�E�� 0x00 �� 0x10 �E�� 0x20 ���l 0x30 ���� 0x40 �m�� 0x50 �C�� 0x60 ���� 0x70 ���l 0x80 ���� 0x90 �؎x�O 0xA0 �R�m 0xB0 ���p�m 0xC0 ����

	byte aptitudeasi : 3;		//���y�K��
	byte aptitudekib : 3;		//�R�n�K��
	byte _aptitudegun_hi : 2; //�S�C�K����ʃr�b�g
	byte _aptitudegun_lo : 1; //�S�C�K�����ʃr�b�g
	byte aptitudesui : 3;		//���R�K��

	byte biggun : 1;		//��C
	byte horsegun : 1;	//�R�n�S�C
	byte steelship : 1;	//�S�b�D
	byte _undef : 1;		//0
	byte life : 3;		//����
	byte brave : 3;		//�E��
	byte _independence_hi : 2; //�Ɨ���ʃr�b�g
	byte _independence_lo : 1; //�Ɨ����ʃr�b�g
	byte tone : 3;		//����
	byte bEnd : 1;		//�s��
	byte bRise : 1;		//����
	byte grudge : 1;		//�⍦
	byte kaiken : 1;		//�
};



enum APTITUDE { APTITUDE_ASIGARU = 1, APTITUDE_KIBA = 2, APTITUDE_TEPPOU = 3, APTITUDE_SUIGUN = 4, APTITUDE_YUMI = 5, APTITUDE_YARI = 6 };

// �����̔N��𓾂�
int getYearsOld(int iBushouID);


// ���y�E�R�n�E�S�C�E���R�̓K���𐔒l�œ���B(0=E,1=D,2=C,3=B,4=A,5=S)
int getBushouAptitude(int iBushouID, APTITUDE eAptitude);

// ���y�E�R�n�E�S�C�E���R�̓K���𐔒l�œ���B(0=E,1=D,2=C,3=B,4=A,5=S)
void setBushouAptitude(int iBushouID, APTITUDE eAptitude, int iTekisei);


// �����̐퓬�l
int getBushouBat(int iBushouID);
// �����̒q�d�l
int getBushouInt(int iBushouID);
// �����̐����l
int getBushouGov(int iBushouID);

// �ƕ�Ȃǂ��܂߂Ȃ��f�̐����˔\
int getBushouPureGovMax(int iBushouID);

// �ƕ�Ȃǂ��܂߂Ȃ��f�̐퓬�˔\
int getBushouPureBatMax(int iBushouID);

// �ƕ�Ȃǂ��܂߂Ȃ��f�̒q�d�˔\
int getBushouPureIntMax(int iBushouID);

// �ƕ�Ȃǂ��܂߂Ȃ��f�̖�]
int getBushouPureAmbition(int iBushouID);

// ���ʂȂǂ��܂߂Ȃ��f�̖���
int getBushouPureCharm(int iBushouID);

// �ƕ�ɂ�鐭���̏グ��
int getBushouGovMaxUpByKahou(int iBushouID);

// �ƕ�ɂ��퓬�̏グ��
int getBushouBatMaxUpByKahou(int iBushouID);

// �ƕ�ɂ��q�d�̏グ��
int getBushouIntMaxUpByKahou(int iBushouID);

// �ƕ�ɂ���]�̏グ��
int getBushouAmbitionUpByKahou(int iBushouID);

// ���ʂɂ�閣�͂̏グ��
int getBushouCharmUpByKani(int iBushouID);


// �����̓Ɨ��l�𓾂�
int getBushouIndependence(int iBushouID);

// �����̓Ɨ��l��ݒ肷��
void setBushouIndependence(int iBushouID, int iIndependence);


// ��ID���畐��ID�����߂�B(�z��p�ł͂Ȃ���+1���ꂽ�l���Ԃ��Ă���)
int getBushouIDFromFaceID(int iFaceID);


// State ���� �� State �Q�l��
bool setGenekiToRounin(int iBushouID);

// State �Q�l �� State ������
bool setRouninToGeneki(int iBushouID);

// ���������̏�̏��Ƃ���B
// ����́u�����v�̕������A���̏�̏��ɂ���B
// ���̏�傪�u�R�c���v��u�喼�v���ƁA���̐l���̗���ƂȂ�B
bool setGenekiToJyosyu(int iBushouID);

// �������w���Ɉړ�����B
bool setBushouTransport(int iBushouID, int iNewCastleID);

// �w�蕐���̔�����iBushouID�𓾂�B���������Ȃ��ꍇ�ɂ́A0xFFFF���Ԃ��Ă���B
int getHanryoBushouID(int iBushouID);

// �P(���̕����̍Ȋ܂�)���A�w��̕����ƌ���������A�����֌W���͈�ؑ��삳��Ȃ��B
// withKodokuDeath�́A�N�����������ēV�W�ǓƂɂȂ����玀�S�������s������
bool setHimeMarriage(int iHimeID, int iOttoID, BOOL withKodokuDeath = true);

// �w��̕P�𗣍�������B
// withKodokuDeath�́A�N�����������ēV�W�ǓƂɂȂ����玀�S�������s������
bool setHimeDivorce(int iHimeID, BOOL withKodokuDeath = true);



// 2�l�̕����̑����̍��𓾂�
int getBushouAishoDiff(int iBushouAID, int iBushouBID);
