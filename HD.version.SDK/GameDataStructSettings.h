#pragma once

/*
設定系のアドレス
01381000   56               PUSH ESI

01388446   A1 30506F01      MOV EAX,DWORD PTR DS:[16F5030] ← ここを基点
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
	byte screen : 1;	// ウィンドウモードなら1 フルスクリーンなら0
	byte _undef2 : 2;

	byte _undef6 : 4;
	byte r_clk_cancel : 1; // 右クリックのキャンセル 有効:1 無効:0
	byte _undef11 : 3;

	byte seikan_key : 1; // 静終のキー。Space:0 Tab:1
	byte _undef7 : 7;

	byte _undef8 : 2;
	byte auto_save : 1;  // 有効 : 1 無効 : 0
	byte _undef9 : 5;

	byte _undef10;
	byte _undef3[3];     // 0が３つ
	int width;
	int height;
	int undef4;			// 	0が１つ
	int message_speed; // 自動メッセージ送り 無効:0 低速:2～最速:5  １が無いので注意
	int undef5;
	int others_war;	   // 他国の戦争 　見る:0 任意:1 見ない:2
	int myself_war;	   // 自国の戦争 　見る:0 任意:1 見ない:2
	int undef11;
	int undef12;
	int gengo;			// 元号:0 西暦:1
	int bgm_volume;		// 音楽音量		消音:0 １メモリあたり10で、最大で100。消音＋10段階。
	int se_volume;		// 効果音音量	消音:0 １メモリあたり10で、最大で100。消音＋10段階。
};