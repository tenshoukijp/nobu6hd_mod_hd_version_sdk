#pragma once

/*			�R�c���(21*214)

[21�o�C�g]

0-1	�O�̌R�c
2-3 ���̌R�c
4-5	���閼�i���o�[
6-7	�R�c���i���o�[(�������O�e�[�u���̏���)
8-9	�喼
10	�s����
11-12	��
13-14	��
15-16	�R�n
17-18	�S�C
19	�H
20	aaaabbbb A ��E B �R�c�ԍ�
0 ���� 1 ���Α叫�R 2 �Ǘ� 3 �֓��Ǘ� 4 ���B�T�� 5 �����T�� 6 ��B�T�� 7 �H�B�T�� �� getNormalizedGundanPosition

*/
struct NB6GUNDAN
{
	WORD prev;		//�O�̌R�c
	WORD next;		//���̌R�c
	WORD residence;	//���閼�i���o�[
	WORD leader;	//�R�c���i���o�[(�������O�e�[�u���̏���)
	WORD attach;	//����(�喼) (�喼�ԍ��e�[�u���̏���)
	byte act;		//�s����
	WORD money;		//��
	WORD rise;		//��
	WORD horse;		//�n
	WORD gun;		//�S�C
	byte _undef;	//must 0?
	byte number : 4;	//1-8 �� �R�c�ԍ�
	byte position : 4;//��E  (0 ���� 1 ���Α叫�R 2 �Ǘ� 3 �֓��Ǘ� 4 ���B�T�� 5 �����T�� 6 ��B�T�� 7 �H�B�T��) �� getNormalizedGundanPosition
};


/// ����(���̏u��)�A�V�ċL�ɑ��݂���R�c�́u�R�c�ԍ��y�z��p�z�v�����X�g�œ���B
vector<int> getValidGundanList();

// �����喼�ɑ�����R�c�ԍ��y�z��p�z�̃��X�g�𓾂�
vector<int> getGovernedGundanList(int iDaimyoID);

// �R�c�ɏ������镐�����X�g�𓾂�
vector<int> getGundanBushouList(int iGundanID);

// �R�c�ɏ������镺���𓾂�
int getGundanHeisuCnt(int iGundanID);

// �Ƃ���喼���͂̓����R�c���肠�Ĕԍ����X�g�𓾂�B
vector<int> getGovernedGundanWariateNumList(int iDaimyoID);

// �Ƃ���喼�z���̌R�c���ɂ���R�c�u���v�����ԍ��̃��X�g�𓾂�B
vector<int> getNotGovernedGundanWariateNumList(int iDaimyoID);

// �R�c�C���ԍ��̕ύX(����)�����݂�B���s�����false
bool tryChangeGundanWariateNum(int iGundanID, int iNewWariateNum);

// �w��̌R�c�̏�������喼�𐨗͂��z���āA�ύX����B
bool setGundanReAttachDaimyo(int iGundanID, int iNewDaimyoID);

