#pragma once

/*
* ���o���Ȃǂɂ�����A���́E�q�́E��R�ҁv��ID
*/
struct NB6FUKIDASHIRELATEPERSONS {
	WORD i1stPersonID;	// ������ID(�ʏ핐��ID)
	WORD i2ndPersonID;	// �����ID(�ʏ핐��ID�B�C�x���g��⏤�l���531,�_�����532�ƂȂ�)
	WORD i3rdPersonID;	// ��R�҂�ID(�ʏ�1stPerson��2ndPerson�̉�b�̒��ŏo�Ă���l��ID);
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};


/*
�Q�l�̘b��
���������Q�Ƃ��Ă���ꏊ�i�Q�����j�̓t�b�N���邱��!!
���ꂪ�����ƁA��b�_�C�A���O�n�̃t�b�N�^�C�~���O�ɂȂ�͂��B

�x�[�X�A�h���X
00D61000   56               PUSH ESI

References in NOBU6HD_:.text to 010C72C0..010C72C0
Address    Disassembly                               Comment
00E8146C   PUSH NOBU6HD_.010C72C0
00E81AD8   MOVZX ESI,WORD PTR DS:[EAX*2+10C72C0]

010C72C0  59 00 BD 00 BD 00 00                             Y.�.�..
*/