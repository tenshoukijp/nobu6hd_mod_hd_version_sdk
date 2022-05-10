
#include "GameDataStruct.h"
#include "dijkstra.h"
#include "DijkstraCastle.h"



//�t�@�C���ǂݍ���
bool Dijkstra::Inport()
{
	Clear();

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iCastleID=0; iCastleID<GAMEDATASTRUCT_CASTLE_NUM; iCastleID++ ) {
		// ��̍��W�����̂܂܃m�[�h�̍��W�Ƃ��Ċi�[�B
		AddNode( iCastleID, nb6castlemax[iCastleID].x, nb6castlemax[iCastleID].y );
	}

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iEdgeID=0; iEdgeID<N6PCASTLE_EDGE_NUM; iEdgeID++ ) {
		Node* n1 = QueryFromIdx(nb6castle_edges[iEdgeID].e1);
		Node* n2 = QueryFromIdx(nb6castle_edges[iEdgeID].e2);
			
		ConnectNode( n1, n2 );
	}

	return true;

}

