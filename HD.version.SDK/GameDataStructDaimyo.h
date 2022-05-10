#pragma once


/*
�喼(22*72)

0-1	����INDEX
2-3	�R�c�ԍ�
4-5	����
6-7	�B�����X�g�擪
8	�Ɩ�
9	����
A	�G�Α喼
B	�F�D�喼
C
D	���l
E	000A 000B  A�]�� B�z��
F	��E 0x01 ���R 0x02 �Ǘ� 0x04 �֓��Ǘ� 0x08 ���B�T�� 0x10 �����T�� 0x20 ��B�T�� 0x40 �H�B�T��@��getNormalizedDaimyoPosition
�������E�ɂ͂Ȃ�Ȃ��悤��
*/
struct NB6DAIMYO
{
	WORD attach;		//�喼 ����INDEX
	WORD gundan;		//�R�c �R�c�ԍ�
	WORD castle;		//����
	WORD retire;		//�B�����X�g�擪 // �B����ԂȂǂɕύX�����ꍇ�̓��X�g�𐮓ڂ��Ȃ����K�v������B
	byte symbol;		//�Ɩ�
	byte tyotei;		//����
	byte hostile;		//�G�Α喼
	byte friendship;	//�F�D�喼
	byte merchantHuman : 4;	//�ǂ��̏��l�� 0:�_�� �@�X 1:���� �@�� 2:�Óc �@�y 3:���� �@�v 4:�C�v �����q�� 5:���� ���� 6:���g �����q�� 7:���� �l�Y���Y 8:�p�q ���� 9:�D�� �ЗR
	byte undef : 4;	//
	byte merchant;		//���l�F�D�x
	byte bPropagate : 1;	//�z�� :�z���ς݂��ۂ�
	byte bMerchantAngry : 1; // ���l���{���Ă���B
	byte _undef1 : 2;		//must 0 �z���̎c���r�b�g�ɉ߂��Ȃ��B����ɐ��l����Ȃ�����
	byte hyotei : 1;		//�]�� :�]��ς݂��ǂ���
	byte _undef2 : 3;		//must 0 �]��̎c���r�b�g�ɉ߂��Ȃ��B����ɐ��l����Ȃ�����
	byte position;		//��E 0x01 ���R 0x02 �Ǘ� 0x04 �֓��Ǘ� 0x08 ���B�T�� 0x10 �����T�� 0x20 ��B�T�� 0x40 �H�B�T��@��getNormalizedDaimyoPosition
	byte _undef3;
	byte _undef4;
	byte _undef5;
	WORD _undef6;
	byte _undef7;
};


// �S�L���喼�̃��X�g��Ԃ��B�^�[���喼���g�������Ă�̂Œ��ӁB
vector<int> getDaimyoList(BOOL isIncludeTurnDaimyo = TRUE);


//�ő吨��(�ł������鐔������)�喼�𓾂�
int GetMaximumInfluenceDaimyo();
