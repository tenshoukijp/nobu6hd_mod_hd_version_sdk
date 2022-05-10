// ���C���}�b�v�̏�̌o�H���_�C�N�X�g���@�v�Z�ŋ��߂邽�߂̃N���X


#pragma once
#include <list>
#include <math.h>
#include <windows.h>

#define Circle_r 1	//�`��A�����̊

struct Node;
struct NodeConnect;

//�m�[�h
struct Node
{
	int iCastleID;
	int GetCastleID() {
		return iCastleID;
	}

	int x;//�m�[�h�̍��W
	int y;

	std::list<NodeConnect> m_connectNode;	//�ڑ����Ă���m�[�h

	//�v�Z�ŕێ�����l-------------------
	int		cost;	//�T���ɗv�����R�X�g�B-1�̎��͂��̃m�[�h�𖢒T���Ƃ��Ă��܂��B
	Node*	toGoal;	//�S�[���ւ̍ŒZ���[�g�ɂȂ���m�[�h
	//-----------------------------------


	Node(int iCastleID, int ix, int iy);

	//�v�Z���ʂ��N���A����
	void Reset();

	//����m�[�h�ւ̐ڑ����폜
	void RemoveConnect(Node* n);
};

//�m�[�h�Ԃ̃R�X�g�v�Z(�����ł͋������R�X�g�Ƃ��܂�)
double QueryCost(Node* n1, Node* n2 );

//���̃m�[�h�ւ̐ڑ����
struct NodeConnect
{
	Node*		node;//�ړ���m�[�h
	int			cost;//�ړ��ɂ�����R�X�g(�����ł͋���)

	NodeConnect( Node*	_node, int _cost )
	{
		node = _node;
		cost = _cost;
	}
};

struct NodePair
{
	Node* n1;
	Node* n2;
};

//�_�C�N�X�g���@�ōŒZ�o�H�����߂�N���X
class Dijkstra
{
	Node* m_start;
	Node* m_goal;
	std::list<Node*> m_node;

	//�m�[�h�����X�g�̉��Ԗڂ� 0����X�^�[�g �����Ƃ�-1
	int QueryIdx( Node* node );
	//�C���f�b�N�X�w��Ń��X�g����m�[�h�擾
	Node* QueryFromIdx(int idx);

public:
	Dijkstra();
	virtual ~Dijkstra();

	//�S�m�[�h���폜
	void Clear();

	void AddNode(int iCastleID, int x, int y)
	{
		m_node.push_back( new Node(iCastleID, x,y) );
	}
	
	//�w��m�[�h���폜
	void Remove( Node* n1 );
	//�w��m�[�h�ڑ����폜
	void RemoveConnect( Node* n1, Node* n2 );

	//�Q�_�Ԃ̃��[�g���쐬
	void ConnectNode( Node* n1, Node* n2 );

	//�N���b�N�ʒu�̃m�[�h���擾
	Node* Query(int x, int y);

	// ��ԍ�����m�[�h���擾
	Node* Query(int iCastleID);

	//�N���b�N�ʒu�̐��ɏ�������m�[�h�g���擾
	bool QueryLineOnNodePair(NodePair* rslt, int x, int y);

	//�e�m�[�h�����Z�b�g
	void ResetNode();

	//���[�g�����J�n
	void SearchRoot();

	//�����X�^�[�g�_
	void SelctStart(Node* node) {
		m_start	= node;
	}
	void SelctGoal(Node* node) {
		m_goal	= node;
	}

	Node* GetStartNode() {
		return m_start;
	}

	Node* GetGoalNode() {
		return m_goal;
	}

	//�`��
	void Draw(HDC hdc);

	//�t�@�C���ǂݍ��݁A��������
	bool Inport();

};
