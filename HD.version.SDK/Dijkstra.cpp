#include "GameDataStruct.h"
#include "dijkstra.h"

double DistPoints(double lx, double ly, double rx, double ry )
{
	double len = ( rx - lx )*( rx - lx ) + ( ry - ly )*( ry - ly );
	
	return pow( len , 0.5 );
}

//�O�ρ@�����Ɠ_�̋������o���Ƃ��Ɏg��
double CrossProduct(double lx, double ly, double rx, double ry ) { return (lx * ry) - (ly * rx); }

//���ρ@�x�N�g�������̃`�F�b�N�ɂ���
double DotProduct(double lx, double ly, double rx, double ry ) { return (lx * rx) + (ly * ry); }

//������ɓ_�����邩
bool IntersectPointLine(
	int x, int y,		//�_
	int lx1, int ly1,	//�����n�_
	int lx2, int ly2,	//�����I�_
	double limit )		//�덷
{
	double dist;
	
	do {

		double lineLen = DistPoints(lx1, ly1, lx2, ly2);
		if ( lineLen == 0.0 ) {
			dist = DistPoints( x, y, lx1, ly1 );
			break;
		}
		
		if (DotProduct(lx2 - lx1, ly2 - ly1, x - lx1, y- ly1) <= 0) {
			dist = DistPoints( x, y, lx1, ly1 );
			break;
        }

		if (DotProduct(lx1 - lx2, ly1 - ly2, x - lx2, y- ly2) <= 0) {
			dist = DistPoints( x, y, lx2, ly2 );
            break;
        }
		
		dist = CrossProduct(lx2 - lx1, ly2 - ly1, x - lx1, y- ly1) / lineLen;
		dist = abs(dist);

	} while(0);
	
	if ( dist < limit) {
		return true;
	}
	return false;
}


//�m�[�h�Ԃ̃R�X�g(����)�v�Z
double QueryCost(Node* n1, Node* n2 )
{
	return DistPoints(n1->x,n1->y, n2->x, n2->y);
}

Dijkstra::Dijkstra()
{
	m_start = NULL;
	m_goal = NULL;
}
Dijkstra::~Dijkstra()
{
	Clear();
}

//�w��m�[�h���폜
void Dijkstra::Remove( Node* n1 )
{
	std::list<NodeConnect>::iterator it = n1->m_connectNode.begin();
	for ( ; it != n1->m_connectNode.end(); it++ ) {
		//�ڑ���̃m�[�h���玩�g�̏������O
		it->node->RemoveConnect(n1);
	}

	//���X�g���玩�M�����O���ĉ���B
	m_node.remove(n1);
	delete n1;
}

//�m�[�h�ڑ����폜
void Dijkstra::RemoveConnect( Node* n1, Node* n2 )
{
	//n1�̃m�[�h����n2�����O
	n1->RemoveConnect(n2);
	n2->RemoveConnect(n1);
}

//�S�m�[�h���폜
void Dijkstra::Clear()
{
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++ ) {
		delete (*it);
	}
	
	m_node.clear();
	m_start = NULL;
	m_goal  = NULL;
}

//�m�[�h�����X�g�̉��Ԗڂ� 0����X�^�[�g �����Ƃ�-1
int Dijkstra::QueryIdx( Node* node )
{
	int ret = 0;
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++, ret++ ) {
		if ( *it == node ) {
			return ret;
		}
	}
	return -1;
}

//�C���f�b�N�X�w��Ń��X�g����m�[�h�擾
Node* Dijkstra::QueryFromIdx(int idx)
{
	int ret = 0;
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++, ret++ ) {
		if ( ret == idx ) {
			return (*it);
		}
	}
	return NULL;
}

//�Q�_�Ԃ̃��[�g���쐬
void Dijkstra::ConnectNode( Node* n1, Node* n2 )
{
	//�o�^�ς݂łȂ���
	std::list<NodeConnect>::iterator it = n1->m_connectNode.begin();
	for ( ; it != n1->m_connectNode.end(); it++ ) {

		if ( it->node == n2 ) {
			return;
		}
	}
	
	//�R�X�g=�����v�Z
	double cost = QueryCost(n1, n2);

	//�ڑ�
	n1->m_connectNode.push_back( NodeConnect(n2,(int)cost) );
	n2->m_connectNode.push_back( NodeConnect(n1,(int)cost) );
}

//�N���b�N�ʒu�̃m�[�h���擾
Node* Dijkstra::Query(int x, int y)
{
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++ ) {
		
		if ( (*it)->x == x && (*it)->y == y ) {
			return (*it);	
		}
	
	}
	return NULL;
}

// ��ԍ�����m�[�h���擾
Node* Dijkstra::Query(int iCastleID)
{
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++ ) {
		
		if ( (*it)->GetCastleID() == iCastleID ) {
			return (*it);	
		}
	
	}
	return NULL;
}

//�N���b�N�ʒu�̐��ɏ�������m�[�h�g���擾
bool Dijkstra::QueryLineOnNodePair( NodePair* rslt, int x, int y )
{
	int search_leng = Circle_r * 1;

	std::list<Node*>::iterator it = m_node.begin();
	Node *node, *sideNode;
	for ( ; it != m_node.end(); it++ ) {
		node = *it;
		
		std::list<NodeConnect>::iterator it_cnct = (*it)->m_connectNode.begin();
		for ( ; it_cnct != (*it)->m_connectNode.end(); it_cnct++ ) {
			
			sideNode = it_cnct->node;
		
			//�_�Ɛ��̌����`�F�b�N
			if ( IntersectPointLine( x, y, node->x, node->y, sideNode->x, sideNode->y, search_leng ) ) {
				rslt->n1 = node;
				rslt->n2 = sideNode;
				return true;
			}
		}
	}

	return false;
}

//�e�m�[�h�����Z�b�g
void Dijkstra::ResetNode() {
	
	std::list<Node*>::iterator it = m_node.begin();
	for ( ; it != m_node.end(); it++ ) {
		(*it)->Reset();
	}
}

//���[�g�����J�n
void Dijkstra::SearchRoot() {

	//�S�m�[�h�̌v�Z���ʂ����Z�b�g
	ResetNode();

	if ( !m_start || !m_goal ) { return; }

	std::list<Node*> work1;
	std::list<Node*> work2;

	std::list<Node*>* currLevel = &work1;
	std::list<Node*>* nextLevel = &work2;
	std::list<Node*>* for_swap;//currLevel��nextLevel����ւ��Ɏg��

    //�S�[������v�Z���܂��B
	m_goal->cost = 0;//�S�[���ɃR�X�g0���Z�b�g���Čv�Z�ς݂Ƃ���
	currLevel->push_back(m_goal);//�������K�w�̃m�[�h�Z�b�g(�S�[���m�[�h���Z�b�g����)

	std::list<Node*>::iterator it;
	int nodeCost;
	while ( currLevel->size() ) {

		for( it = currLevel->begin(); it != currLevel->end(); it++ ) {
			
			//���̃m�[�h�K�w�֐i�߂�Ȃ�Anext���x���Ɋi�[
			std::list<NodeConnect>::iterator it_cnct = (*it)->m_connectNode.begin();
			for( ; it_cnct != (*it)->m_connectNode.end(); it_cnct++ ) {
				
				nodeCost = (*it)->cost + it_cnct->cost;

				if ( ( it_cnct->node->cost == -1 ) || ( nodeCost < it_cnct->node->cost ) ) {
					//���T���m�[�h���邢�͍ŒZ���[�g���X�V�ł���ꍇ

					//�o�H�R�X�g�ƃS�[���֌��������߂̃m�[�h���Z�b�g
					it_cnct->node->cost = nodeCost;
					it_cnct->node->toGoal = (*it);

				} else {
					continue;
				}
				
				//���Ɍ�������K�w�̃��X�g�ɓo�^
				nextLevel->push_back( it_cnct->node );
			}
		
		}
		
		//���X�g�����ւ��Ď��̊K�w����������
		for_swap = currLevel;
		currLevel = nextLevel;
		nextLevel = for_swap;
		nextLevel->clear();//�N���A����
	}
		
}