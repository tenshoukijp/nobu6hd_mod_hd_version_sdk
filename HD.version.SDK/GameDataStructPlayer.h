#pragma once


/*
�v���C���[�̒S���R�c(�喼�ԍ��ł͂Ȃ��R�c�ԍ�)
*/
struct NB6PLAYERS8
{
	WORD gundan;
};



// �Ώۂ̌R�cID�������ꂩ�̃v���C���[���͉��̌R�c�ł���(�ő�W�l)
bool isPlayerGundan( WORD iTargetGundanID );

// �Ώۂ̕���ID�������ꂩ�̃v���C���[���͉��̕����ł���
bool isPlayerBushou( WORD iTargetBushouID );

// �Ώۂ̑喼ID�������ꂩ�̃v���C���[�S���̑喼�ł���
bool isPlayerDaimyo( WORD iTargetDaimyoID );


