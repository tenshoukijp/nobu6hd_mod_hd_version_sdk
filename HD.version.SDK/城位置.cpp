#include "GameDataStruct.h"

// �O���b�h���W���u�̌��Z�B���W�`�����W�a�̃x�N�g�������߂�̂ɁA�ʏ�A�a�|�`�����邾�낤����B
��O���b�h�x�N�g���^^ operator-(��O���b�h�ʒu�^^ �ʒu�P, ��O���b�h�ʒu�^^ �ʒu�Q) {
	��O���b�h�x�N�g���^^ �u = gcnew ��O���b�h�x�N�g���^();
	�u->�w = �ʒu�P->�w - �ʒu�Q->�w;
	�u->�x = �ʒu�P->�x - �ʒu�Q->�x;
	return �u;
}

