#pragma once

/*
�ݒ�n�̃A�h���X
01381000   56               PUSH ESI

01388446   A1 30506F01      MOV EAX,DWORD PTR DS:[16F5030] �� ��������_
0138844B   33C5             XOR EAX,EBP
0138844D   50               PUSH EAX
0138844E   8D45 F4          LEA EAX,DWORD PTR SS:[EBP-C]
01388451   64:A3 00000000   MOV DWORD PTR FS:[0],EAX
01388457   8BF1             MOV ESI,ECX
01388459   E8 22581A00      CALL NOBU6HD_.0152DC80
0138845E   8BC8             MOV ECX,EAX
01388460   E8 BB2C0000      CALL NOBU6HD_.0138B120
01388465   8BF8             MOV EDI,EAX
01388467   C745 F0 0F000000 MOV DWORD PTR SS:[EBP-10],0F
0138846E   C745 EC 00000000 MOV DWORD PTR SS:[EBP-14],0
01388475   C645 DC 00       MOV BYTE PTR SS:[EBP-24],0
01388479   8D45 DC          LEA EAX,DWORD PTR SS:[EBP-24]
0138847C   50               PUSH EAX
0138847D   8BCE             MOV ECX,ESI
0138847F   C745 FC 00000000 MOV DWORD PTR SS:[EBP-4],0
01388486   E8 55010000      CALL NOBU6HD_.013885E0
0138848B   8D45 DC          LEA EAX,DWORD PTR SS:[EBP-24]
0138848E   50               PUSH EAX
0138848F   E8 7CE61900      CALL NOBU6HD_.01526B10
01388494   8D45 DC          LEA EAX,DWORD PTR SS:[EBP-24]
01388497   50               PUSH EAX
01388498   E8 43EA1900      CALL NOBU6HD_.01526EE0
0138849D   83C4 08          ADD ESP,8
013884A0   8D4D DC          LEA ECX,DWORD PTR SS:[EBP-24]
013884A3   6A 0F            PUSH 0F
013884A5   68 5CC86401      PUSH NOBU6HD_.0164C85C                   ; ASCII "systemcfgPK.n6p"
013884AA   E8 91D6FFFF      CALL NOBU6HD_.01385B40
013884AF   837D F0 10       CMP DWORD PTR SS:[EBP-10],10
013884B3   8D45 DC          LEA EAX,DWORD PTR SS:[EBP-24]
*/

/*
01381000   56               PUSH ESI

016F6B78  3F FC 0E 8C 05 00 00 00 40 06 00 00 98 03 00 00 
016F6B88  00 00 00 00 03 00 00 00 01 00 00 00 02 00 00 00 
016F6B98  01 00 00 00 03 00 00 00 01 00 00 00 00 00 00 00 
016F6BA8  64 00 00 00 1E 00 00 00 00 00 00 00 01 00 00 00 
016F6BB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 
*/

struct NB6SETTINGS_INGAME {
	byte _undef1 : 5;
	byte screen : 1;	// �E�B���h�E���[�h�Ȃ�1 �t���X�N���[���Ȃ�0
	byte _undef2 : 2;

	byte _undef6 : 4;
	byte r_clk_cancel : 1; // �E�N���b�N�̃L�����Z�� �L��:1 ����:0
	byte _undef11 : 3;

	byte seikan_key : 1; // �ÏI�̃L�[�BSpace:0 Tab:1
	byte _undef7 : 7;

	byte _undef8 : 2;
	byte auto_save : 1;  // �L�� : 1 ���� : 0
	byte _undef9 : 5;

	byte _undef10;
	byte _undef3[3];     // 0���R��
	int width;
	int height;
	int undef4;			// 	0���P��
	int message_speed; // �������b�Z�[�W���� ����:0 �ᑬ:2�`�ő�:5  �P�������̂Œ���
	int undef5;
	int others_war;	   // �����̐푈 �@����:0 �C��:1 ���Ȃ�:2
	int myself_war;	   // �����̐푈 �@����:0 �C��:1 ���Ȃ�:2
	int undef11;
	int undef12;
	int gengo;			// ����:0 ����:1
	int bgm_volume;		// ���y����		����:0 �P������������10�ŁA�ő��100�B�����{10�i�K�B
	int se_volume;		// ���ʉ�����	����:0 �P������������10�ŁA�ő��100�B�����{10�i�K�B
};