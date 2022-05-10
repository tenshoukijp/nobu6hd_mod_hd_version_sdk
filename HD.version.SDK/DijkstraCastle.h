#pragma once

#include "GameDataStruct.h"
#include "dijkstra.h"


#define N6PCASTLE_EDGE_NUM	306


struct N6PCASTLE_EDGE {
	WORD e1;
	WORD e2;
};

// iCastleID���m�̘A�����B
extern N6PCASTLE_EDGE nb6castle_edges[N6PCASTLE_EDGE_NUM];


// �ŏ��̃m�[�h��G�b�W�̏������B�o�H�֌W���g���O�Ɏ��s���Ă����K�v������B
void InitCastleNodeAndEdge();

// �X�^�[�g�m�[�h�̐ݒ�
void SetStartCastleNode(int iCastleID );

// �S�[���m�[�h�̐ݒ�
void SetGoalCastleNode(int iCastleID );

// ����̏�m�[�h�̍폜(���̏�ɂ������Ă���G�b�W���폜�����)
void RemoveCastleNode(int iCastleID );

// �X�^�[�g���S�[���ւ̃��[�g���v�Z���A�o�H�ƂȂ�����ID�̃��X�g��Ԃ��B
vector<int> SearchCastleWayRoot();

