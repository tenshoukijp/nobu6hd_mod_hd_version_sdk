#pragma once

/*
* 噴出しなどにおける、｢主体・客体・第３者」のID
*/
struct NB6FUKIDASHIRELATEPERSONS {
	WORD i1stPersonID;	// 自分のID(通常武将ID)
	WORD i2ndPersonID;	// 相手のID(通常武将ID。イベント顔や商人顔は531,農民顔は532となる)
	WORD i3rdPersonID;	// 第３者のID(通常1stPersonと2ndPersonの会話の中で出てくる人のID);
	DWORD _undef1;
	DWORD _undef2;
	DWORD _undef3;
	DWORD _undef4;
	DWORD _undef5;
};


/*
２人の話者
★ここを参照している場所（２か所）はフックすること!!
それがきっと、会話ダイアログ系のフックタイミングになるはず。

ベースアドレス
00D61000   56               PUSH ESI

References in NOBU6HD_:.text to 010C72C0..010C72C0
Address    Disassembly                               Comment
00E8146C   PUSH NOBU6HD_.010C72C0
00E81AD8   MOVZX ESI,WORD PTR DS:[EAX*2+10C72C0]

010C72C0  59 00 BD 00 BD 00 00                             Y.ｽ.ｽ..
*/