#pragma once


/*
����(33*214)

[33�o�C�g]

0-1		�R�c�������X�g�̑O
2-3		���X�g�̌��
4-5		���(�擪) // ����ԂȂǂɕύX�����ꍇ�̓��X�g�𐮓ڂ��Ȃ����K�v������B
6-7		�Q�l(�擪) // �Q�l��ԂȂǂɕύX�����ꍇ�̓��X�g�𐮓ڂ��Ȃ����K�v������B
8-16	�閼
17-18	���� (�����R�c�ԍ�)
19		��s
20-21	�΍�
22		����
23-24	�l��-������
25		����
26-27	������
28		���� 0-2 (0=��,1=��,2=��)
29		ABC0 EFGH
A �Ꝅ B ���ۍ` C �` E �n�Y�n F �b�� G �{�� H ����
30		ABCD EFGH
C �Ꝅ� G ���R H ��R
31		AAAAAA BB
A:���	0x00 �� 0x01 ��V 0x02 �� 0x04 �䏊 0x08 �� 0x10 �� 0x20 ��A����ȊO�̒l=�����t���Ȃ�
B:��G���\���������́A�w�i�̎��(0=�R) (1=��) (2=�C) (3=����)
32		000A000B A-���� B ���O�ύX
*/
struct NB6CASTLE
{
	WORD prev;		//�R�c�����郊�X�g �O�̏�
	WORD next;		//�R�c�����郊�X�g ��̏�
	WORD master;	//���(�擪)
	WORD ronin;		//�Q�l(�擪)
	char name[9];	//�閼
	WORD attach;	//���� (�����R�c�ԍ�)
	byte build;		//��s
	WORD grain;		//�΍�
	byte town;		//����
	WORD population;//�l��
	byte loyal;		//����
	WORD soldier;	//������
	byte quality;	//���� 0-2  (0=��,1=��,2=��)
	byte honjo : 2;	//�{�� ���� (�喼�̖{��=1, �R�c���̖{��=2);
	byte bSmith : 1;	//�b��
	byte bHorse : 1;	//�n�Y�n
	byte _undef3 : 1;	//0
	byte bPort : 1;	//�`
	byte blPort : 1;	//���ۍ`
	byte _undef4 : 1;	//

	byte bSilver : 1;	//��R
	byte bGold : 1;	//���R
	byte _undef5 : 2;	//
	byte bRevolt : 1;	//�Ꝅ�
	byte _undef6 : 3;	//

	byte bgback : 2;	//��G���\���������́A�w�i�̎�� ���(0=�R) (1=��) (2=�C) (3=����)
	byte title : 6;	//���

	byte _undef7 : 3;	//
	byte bLarge : 1;	//����
	byte bCngName : 4;//���O�ύX
};


/*
��̈ʒu���Ȃ�(8*214)

[8�o�C�g]

0	�n�於
1	0
2	�΍��ő�l/10
3	���ƍő�l
4	X�Z�����W(�}�b�v�Ō����Ă�̂Ƃ͈قȂ��؂�� 50�ŋ�؂��Ă���)
5	Y�Z�����W(��Ɠ����ŁA�}�b�v�Ō����Ă���̂Ƃ͈قȂ��؂��12���x�ŋ�؂��Ă���)
6	X_offset
7	Y_offset
*/
struct NB6CASTLEMAX
{
	byte chiiki;	//�����n��ԍ�)
	byte _undef1;	//must 0
	byte maxgrain;	//�Ő΍�/10
	byte maxtown;	//�ŏ���
	byte _x_undef;	//�Z������X�̂���
	byte _y_undef;	//�Z������Y�̂���
	byte x;			//�Z��X���W    �O���b�h�B
	byte y;			//�Z��Y���W	   �O���b�h�B
};




// ��̃^�C�vID�����̓I�ȕ�����𓾂�
char *getCastleTypeName(int iCastleType);

// �w��̌R�c���������Ă����̐��B
int getGundanHasCastleNum(int iGundanID);

// �w��̑喼���������Ă����̐��B
int getDaimyoHasCastleNum(int iDaimyoID);

// ��ɏ������镺���𓾂�
int getCastleHeisuCnt(int iCastleID);



// ���C���}�b�v�̃O���b�h�p�̍\���́B�B�w�� �x���@�Œl���������Ă����B
struct GRID_POSITION {
	int x;
	int y;
	GRID_POSITION(int _x, int _y);

	WORD nw; // �k���y��ԍ��z; iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD no; // �k�y��ԍ��z;   iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD ne; // �k���y��ԍ��z; iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD we; // ���y��ԍ��z;   iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD ea; // ���y��ԍ��z;   iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD sw; // �쐼�y��ԍ��z; iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD so; // ��y��ԍ��z;   iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
	WORD se; // �쓌�y��ԍ��z; iCaslteID���1�����B ���݂��Ȃ����́A0xFFFF;
};

// �O���b�h�̕����x�N�g���B�w�� �x���@�Œl���������Ă����B
struct GRID_VECTOR {
	int x;
	int y;
	GRID_VECTOR(int _x, int _y) : x(_x), y(_y) {}
	GRID_VECTOR() : x(0), y(0) {}
};

// �O���b�h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
GRID_VECTOR operator-(GRID_POSITION &p1, GRID_POSITION &p2);


// ��h�c����A���C���O���b�h��̃|�W�V�����𓾂�B����O���b�h��0,0�Bmapdataobgk�̃O���b�h������΂킩��₷���B
// �P�̃O���b�h�ɂ́A�P�̏邵���Ȃ��B
// �S���}�b�v�ƃG���A�̃��[�� 
// �e�O���b�h4x3�}�X�ɕ�������Ă��āA��̈ʒu�͈ړ��\�����A����6�}�X�̂ǂꂩ���g�p�����B 
// �O���b�h�̍��E�[�ł́u�G���A���̕����v�̂݃N���b�N����������B 
// �܂��A�O���b�h�̏㕔�ł́A�͂ݏo������̉��������̓N���b�N�������Ȃ��B 
GRID_POSITION getCastlePosInMainGrid(int iCastleID);

// �w��̏�ɑ΂��ėאڂ��Ă����̃��X�g�𓾂�
vector<int> getRinsetsuCastles(int iCastleID);

// �w��̏邩�瓹���q�����Ă���אڏ�̃��X�g�𓾂�B
vector<int> getWayConnectCastles(int iCastleID);

