#pragma once

/*
�l�X�ȃp�����[�^�̍ő�l
*/
struct NB6PARAMMAX
{
	DWORD maxgov;		//����		110
	DWORD maxbat;		//���		110
	DWORD maxint;		//�q��		110
	DWORD expgov;		//���n		2000
	DWORD expbat;		//��n		2000
	DWORD expint;		//�q�n		2000
	DWORD charm;		//����		110
	DWORD ambition;		//��]		110
	DWORD loyal;		//����		100
	DWORD merits;		//�M��		999
	DWORD blood;		//����		255
	DWORD attach;		//�喼�ԍ�	72
	DWORD gundan;		//�R�c		214
	DWORD castle;		//����		214
	DWORD soldier;		//����		100
	DWORD training;		//�P��		200
	DWORD solloyal;		//����		100
};

struct NB6PARAMMAX_MAIN
{
	DWORD castle;		//�鐔		214
	DWORD build;		//���s(�h��x)	250
	DWORD grain;		//�΍�		2500
	DWORD town;			//����		200
	DWORD population;	//�l��		9999
	DWORD loyal;		//����		100
	DWORD soldier;		//������	999
	DWORD quality;		//����		2
	DWORD chimei;		//�n��		74
	DWORD _kani;		//���ʁH(�s��)	250
	DWORD _undef2;		//�H�H			200
	DWORD _form;		//���ԁH(�s��)    3
};


/*
�ő啺�� [0:�B��,1:�喼,2:�h�V�`6:���y]�܂łƂ��Ċi�[���Ă䂭
*/
struct NB6SOLDIERMAX
{
	WORD soldiermax;
};


