#pragma once

#include <windows.h>

namespace warstatus { 
	enum { 野戦表示突入前 = 1, 野戦ターン時 = 2, 城表示突入前 = 3 };
};
bool Is_FieldWar();          // 現在画面に出てる戦場は、野戦
bool Is_CastleWar();        // 現在画面に出てる戦場は、攻城戦

// 現在フィールドでの残りターン数
int getFieldTurnInBattle();


/*
ベース
00811000   56               PUSH ESI


戦場での経過ターン数
References in NOBU6HD_ : .text to 00B767EA..00B767EA
Address    Disassembly                               Comment
00912FE0   MOV DWORD PTR DS : [B767EA], 0               DS : [00B767EA] = 00000017		← ここにターン数の値をクリアしている。
00913030   MOV EAX, DWORD PTR DS : [B767EA]             [00B767EA] = 00000017
00913116   MOV DWORD PTR DS : [B767EA], EAX												← ここにターン数の値が代入されている。
*/

/*
ベース
00811000   56               PUSH ESI

00B767EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  ........  [17]=経過ターン数と[02]=天気  0x29=41とは野戦の横のHEX数のこと  0x12の時は攻籠戦のHEX数の横のマス数である18のこと。
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ........
*/

/*
ベース
00811000   56               PUSH ESI

野戦 or 攻城戦　の切り替わり時に値の代入をしている箇所

References in NOBU6HD_ : .text to 00B767F8..00B767F8
Address    Disassembly                               Comment
008FDC86   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FF0DA   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FFC18   MOV DWORD PTR DS : [B767F8], 29              DS : [00B767F8] = 00000029
008FFC53   MOV DWORD PTR DS : [B767F8], 12              DS : [00B767F8] = 00000029
*/

/*
00B767EA  17 00 00 00 02 00 00 00 00 00 00 00 00 00 [29] 00  ...........     0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ........          (攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/



/*
ベース
00811000   56               PUSH ESI

天気の値を参照や代入している所


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
00B767EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00    [17]=経過ターン数と[02]=天気  0x29=41とは野戦の横のHEX数のこと  0x12の時は攻籠戦のHEX数の横のマス数である18のこと。
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ......		   
*/

// 天気情報を得る 0:晴れ 1:曇り 2:雨 3:雪
int GetWeather();






/*
00811000   56               PUSH ESI

References in NOBU6HD_:.text to 00B767E0..00B767E0
Address    Disassembly                               Comment
00912FC5   MOV WORD PTR DS:[B767E0],AX
00913010   MOV AX,WORD PTR DS:[B767E0]               [00B767E0]=FFFF
00913073   MOV WORD PTR DS:[B767E0],CX

00B767DA  8F 00 40 4F 8F 00 [FF FF] 14 00 00 00 05 00 00 00  .. FF FF だと戦争していない、FFFF以外だと、戦場の中心となっている「城番号」が入っている。
00B767EA  02 00 00 00 02 00 00 00 00 00 00 00 00 00 [29] 00     0x29=41は野戦のマップの横チップ数、 0x18=24 は野戦のマップの縦チップ数
00B767FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ..   (攻城戦の時は、横が0x12=18,  縦が0x10=16)
*/

// 戦争が発生した時の中央の城番号(配列用)。戦争が発生していない時は0xFFFFを返す。
// -1:不明。値が未初期化など。
// 0xFFFF: メイン画面。戦争ではない。
// 0～213: 城ID
int GetWarCenterCastle();

// 戦争中かどうか
bool IsDoingWar();


extern int isFieldWarOrCastleWar;
