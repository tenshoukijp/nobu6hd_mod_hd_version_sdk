#pragma once



/*
[ ���݂̃^�[���̏��]

W �喼
W �R�c
W ��
*/
struct NB6TURN
{
	WORD daimyo;			// ���݂̃^�[���̑喼�ԍ�
	WORD gundan;			// ���݂̃^�[���̌R�c�ԍ�
	// WORD castle;			// ���݂̃^�[���̏�ԍ� HD�łł͕ʏꏊ�̖͗l
};



/*
�x�[�X
0xD60000

�^�[�����֘A�̃������B
// �喼�^�[���ƌR�c�^�[��
References in NOBU6HD_:.text to 010BF8DD..010BF8DD
Address    Disassembly                               Comment
00E8BBD5   MOV WORD PTR DS:[10BF8DD],AX
00E8BC70   MOV AX,WORD PTR DS:[10BF8DD]              [010BF8DD]=001B
00E8C106   MOVZX EDX,WORD PTR DS:[10BF8DD]           DS:[010BF8DD]=001B
00E8C11A   MOV WORD PTR DS:[10BF8DD],DX


010BF8DD  1B 00 25 00 FF FF                               
*/



/*
�R�c�^�[���؂�ւ��̃��t�@�����X

�x�[�X
00811000   56               PUSH ESI

References in NOBU6HD_:.text to 00B6F8DD..00B6F8DD
Address    Disassembly                               Comment
0093BBD5   MOV WORD PTR DS:[B6F8DD],AX
0093BC70   MOV AX,WORD PTR DS:[B6F8DD]               [00B6F8DD]=0019
0093C106   MOVZX EDX,WORD PTR DS:[B6F8DD]            DS:[00B6F8DD]=0019
0093C11A   MOV WORD PTR DS:[B6F8DD],DX

00B6F8DD  19 00 23 00 FF FF 1D 00 01 00 39 00 25 00 31 00 
00B6F8ED  34 00 02 00 08 00 23 00 30 00 12 00 14 00 28 00  
00B6F8FD  0A 00 1B 00 0D 00                                
*/