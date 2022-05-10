#pragma once

#include <windows.h>

namespace warstatus { 
	enum { ���\���˓��O = 1, ���^�[���� = 2, ��\���˓��O = 3 };
};
bool Is_FieldWar();          // ���݉�ʂɏo�Ă���́A���
bool Is_CastleWar();        // ���݉�ʂɏo�Ă���́A�U���

// ���݃t�B�[���h�ł̎c��^�[����
int getFieldTurnInBattle();


/*
�x�[�X
00811000   56               PUSH ESI


���ł̌o�߃^�[����
References in NOBU6HD_ : .text to 00B767EA..00B767EA
Address    Disassembly                               Comment
00912FE0   MOV DWORD PTR DS : [B767EA], 0               DS : [00B767EA] = 00000017		�� �����Ƀ^�[�����̒l���N���A���Ă���B
00913030   MOV EAX, DWORD PTR DS : [B767EA]             [00B767EA] = 00000017
00913116   MOV DWORD PTR DS : [B767EA], EAX												�� �����Ƀ^�[�����̒l���������Ă���B
*/

/*
�x�[�X
00811000   56               PUSH ESI

00B767EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  ........  [17]=�o�߃^�[������[02]=�V�C  0x29=41�Ƃ͖��̉���HEX���̂���  0x12�̎��͍U�Đ��HEX���̉��̃}�X���ł���18�̂��ƁB
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ........
*/

/*
�x�[�X
00811000   56               PUSH ESI

��� or �U���@�̐؂�ւ�莞�ɒl�̑�������Ă���ӏ�

References in NOBU6HD_ : .text to 00B767F8..00B767F8
Address    Disassembly                               Comment
008FDC86   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FF0DA   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FFC18   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FFC53   MOV DWORD PTR DS : [B767F8], 12              DS : [00B767F8] = 00000029
*/

/*
00B767EA  17 00 00 00 02 00 00 00 00 00 00 00 00 00 [29] 00  ...........     0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ........          (�U���̎��́A����0x12=18,  �c��0x10=16)
*/



/*
�x�[�X
00811000   56               PUSH ESI

�V�C�̒l���Q�Ƃ������Ă��鏊


References in NOBU6HD_:.text to 00B767EE..00B767EE
Address    Disassembly                               Comment
00912FD0   MOV DWORD PTR DS:[B767EE],0               DS:[00B767EE]=00000001
00913020   MOV EAX,DWORD PTR DS:[B767EE]             [00B767EE]=00000001
009130A0   CMP DWORD PTR DS:[B767EE],ESI
009130BC   MOV DWORD PTR DS:[B767EE],ESI
009130D5   MOV DWORD PTR DS:[B767EE],ESI
009130EE   MOV DWORD PTR DS:[B767EE],ESI
009130FA   MOV DWORD PTR DS:[B767EE],EAX
*/

/*
00B767EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00    [17]=�o�߃^�[������[02]=�V�C  0x29=41�Ƃ͖��̉���HEX���̂���  0x12�̎��͍U�Đ��HEX���̉��̃}�X���ł���18�̂��ƁB
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ......		   
*/

// �V�C���𓾂� 0:���� 1:�܂� 2:�J 3:��
int GetWeather();






/*
00811000   56               PUSH ESI

References in NOBU6HD_:.text to 00B767E0..00B767E0
Address    Disassembly                               Comment
00912FC5   MOV WORD PTR DS:[B767E0],AX
00913010   MOV AX,WORD PTR DS:[B767E0]               [00B767E0]=FFFF
00913073   MOV WORD PTR DS:[B767E0],CX

00B767DA  8F 00 40 4F 8F 00 [FF FF] 14 00 00 00 05 00 00 00  .. FF FF ���Ɛ푈���Ă��Ȃ��AFFFF�ȊO���ƁA���̒��S�ƂȂ��Ă���u��ԍ��v�������Ă���B
00B767EA  02 00 00 00 02 00 00 00 00 00 00 00 00 00 [29] 00     0x29=41�͖��̃}�b�v�̉��`�b�v���A 0x18=24 �͖��̃}�b�v�̏c�`�b�v��
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..   (�U���̎��́A����0x12=18,  �c��0x10=16)
*/

// �푈�������������̒����̏�ԍ�(�z��p)�B�푈���������Ă��Ȃ�����0xFFFF��Ԃ��B
// -1:�s���B�l�����������ȂǁB
// 0xFFFF: ���C����ʁB�푈�ł͂Ȃ��B
// 0�`213: ��ID
int GetWarCenterCastle();

// �푈�����ǂ���
bool IsDoingWar();


extern int isFieldWarOrCastleWar;
