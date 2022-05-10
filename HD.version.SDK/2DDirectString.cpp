#pragma pack(1)

#include "2DDirectString.h"

// �x�N�g���𕶎��񉻂��邪�A������k�n�i�W���ʁj�ŕ����񉻁B
string get�W���ʕ�����(D2D_VECTOR v) {

	if ( v.length() == 0 ) {
		return "������";
	}

	double inner = -1; // �^�t����̃X�^�[�g
	string dir = "";

	//�@�W�̕����́u�P�ʃx�N�g���v��p�ӂ��āA�u�Ŋ��邩��̃x�N�g���v�Ƃ̓��ς��ő�̂��̂����̗p����B
	// �P�ʃx�N�g�����u�̓��ς��P�ɋ߂��قǁi���Ȃ킿�傫���قǁj�Ƃ������Ƃ́A�Q�̃x�N�g���̕����͓��������ł���B
	// �t�Ɍ����ΐ^�t�ł���قǍŏ��i���Ȃ킿-1)�ɋ߂Â��B
	D2D_VECTOR i(0,-1); // �k�Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "�k";
	}

	i = D2D_VECTOR(0,1); // ��Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	i = D2D_VECTOR(1,0); // ���Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	i = D2D_VECTOR(-1,0); // ���Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	i = D2D_VECTOR(1,-1); // ���k�Ɣ�r
	i.normalize(); // �P�ʃx�N�g����
	if ( i * v > inner) {
		inner = i * v;
		dir = "�k��";
	}

	i = D2D_VECTOR(-1,-1); // ���k�Ɣ�r
	i.normalize(); // �P�ʃx�N�g����
	if ( i * v > inner) {
		inner = i * v;
		dir = "�k��";
	}

	i = D2D_VECTOR(1,1); // ����Ɣ�r
	i.normalize(); // �P�ʃx�N�g����
	if ( i * v > inner) {
		inner = i * v;
		dir = "�쓌";
	}

	i = D2D_VECTOR(-1,1); // ����Ɣ�r
	i.normalize(); // �P�ʃx�N�g����
	if ( i * v > inner) {
		inner = i * v;
		dir = "�쐼";
	}

	return dir;
}



// �x�N�g���𕶎��񉻂��邪�A������k�n�i�S���ʁj�ŕ����񉻁B
string get�S���ʕ�����(D2D_VECTOR v) {

	if ( v.length() == 0 ) {
		return "������";
	}

	double inner = -1; // ���ρB��ԑ傫�����̂�T���B�^�t����̃X�^�[�g
	string dir = "";

	//�@�S�̕����́u�P�ʃx�N�g���v��p�ӂ��āA�u�Ŋ��邩��̃x�N�g���v�Ƃ̓��ς��ő�̂��̂����̗p����B
	// �P�ʃx�N�g�����u�̓��ς��P�ɋ߂��قǁi���Ȃ킿�傫���قǁj�Ƃ������Ƃ́A�Q�̃x�N�g���̕����͓��������ł���B
	// �t�Ɍ����ΐ^�t�ł���قǍŏ��i���Ȃ킿-1)�ɋ߂Â��B
	D2D_VECTOR i(0,-1); // �k�Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "�k";
	}

	i = D2D_VECTOR(0,1); // ��Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	i = D2D_VECTOR(1,0); // ���Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	i = D2D_VECTOR(-1,0); // ���Ɣ�r
	if ( i * v > inner) {
		inner = i * v;
		dir = "��";
	}

	return dir;
}
