#pragma once


/*
[����(18*250)]

0-12	���O
13		�ʊK
14-15	���L�����ԍ�
16		�㏸�l
17		_undef
*/
struct NB6KANI
{
	char name[13];	//���O
	byte rank;		//���ʂ̃����N(����ʁ`�]���ʏ�܂ł𐔒l�ɂ������� ��ԍ����̂�0�A���ʂ��Ⴂ�قǁA�t�ɐ��l�͑傫��)
	WORD attach;	//���L��
	byte param;		//�㏸�l(���͂̏㏸�l)
	byte _undef0;	//
};


// ���ʂ̎�ނ�ID���當����𓾂�
char* getKaniTypeName(byte type);



// ���ʂ𕐏��ɃA�^�b�`����B���X�ʕ����������Ă����ꍇ�́A���̕�������w�肵�������ւƃA�^�b�`���ς��B
// �\�͒l�̕ύX�𔺂��B����ɕԏシ��ꍇ��0xFFFF�Ƃ���B
bool ReAttachKani(int iKaniID, int iNewBushouID);
