#include "GameDataStruct.h"
#include "dijkstra.h"
#include "DijkstraCastle.h"


static Dijkstra  m_dijkstra;  //�_�C�N�X�g���@�v�Z�N���X
static Node*     m_select;    //�I���m�[�h�i�ڑ��Ŏg���j



void InitCastleNodeAndEdge() {
	m_select = NULL;

	// �m�[�h�ʒu����ڑ������C���|�[�g
	m_dijkstra.Inport();
}


void SetStartCastleNode(int iCastleID ) {

	// ��ID�͈̓`�F�b�N
	if (! (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) ) {
		return;
	}

	Node* n = m_dijkstra.Query(iCastleID);

	if ( n != NULL ) {
		m_dijkstra.SelctStart(n);
	}
}

void SetGoalCastleNode(int iCastleID ) {

	// ��ID�͈̓`�F�b�N
	if (! (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) ) {
		return;
	}

	Node* n = m_dijkstra.Query(iCastleID);

	if ( n != NULL ) {
		m_dijkstra.SelctGoal(n);
	}
}


void RemoveCastleNode(int iCastleID) {
	// ��ID�͈̓`�F�b�N
	if (! (0 <= iCastleID && iCastleID < GAMEDATASTRUCT_CASTLE_NUM) ) {
		return;
	}

	//�m�[�h��m�[�h�ڑ����폜
	Node* n = m_dijkstra.Query(iCastleID);

	if ( n != NULL ) {
		m_dijkstra.Remove(n);
	}

	NodePair pair;
	if ( m_dijkstra.QueryLineOnNodePair( &pair, n->x, n->y) ) {
		m_dijkstra.RemoveConnect( pair.n1, pair.n2 );
	}
}


vector<int> SearchCastleWayRoot() {
	vector<int> iWayCastleIDList; // �o�H��̏�ID

	// �o�H�f�[�^�ݒ�
	m_dijkstra.SearchRoot();

	Node* curr = m_dijkstra.GetStartNode();
	iWayCastleIDList.push_back( curr->GetCastleID() ); // �X�^�[�g�̂�͕K��������

	// �S�[���ւƌq���鎟�̃m�[�h������Ȃ�΁c
	while ( curr->toGoal ) {
		// ���̃m�[�h�����̃m�[�h�Ƃ���B
		curr = curr->toGoal;
		iWayCastleIDList.push_back( curr->GetCastleID() ); // ���̔ԍ���������
	}

	return iWayCastleIDList;
	
}


// �w��̏邩�瓹���q�����Ă���אڏ�̃��X�g�𓾂�B
vector<int> getWayConnectCastles(int iCastleID) {
	vector<int> connect_castle_list;

	// �G�b�W�̃X�^�[�g�n�_�������́A�S�[���n�_�Ɏ��g��iCastleID������B
	for ( int iEdgeID=0; iEdgeID<N6PCASTLE_EDGE_NUM; iEdgeID++ ) {
		// ��ԍ���e1�ƈ�v������Ae2���A����
		if ( iCastleID == nb6castle_edges[iEdgeID].e1 ) {
			connect_castle_list.push_back( nb6castle_edges[iEdgeID].e2 );
		}
		// �t��e2�ƈ�v������Ae1���A����
		else if ( iCastleID == nb6castle_edges[iEdgeID].e2 ) {
			connect_castle_list.push_back( nb6castle_edges[iEdgeID].e1 );
		}
	}

	return connect_castle_list;
}





