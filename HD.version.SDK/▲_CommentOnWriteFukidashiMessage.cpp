#include "GameDataStruct.h"

/*
１人の会話 / 人物同士の会話
会話主たちは、nb6fukidasi_relate_persons が担う


ベースアドレス
00871000   56               PUSH ESI

00BF1E78  89 BD 82 F0 82 B7 82 E9 82 A9 82 CD 0A 8C 5A 8F  何をするかは.兄・
00BF1E88  E3 82 CC 0A 90 53 8E 9F 91 E6 00 82 E7 82 AD 82  繧ﾌ.心次第.らく・
00BF1E98  A8 91 D2 82 BF 82 AD 82 BE 82 B3 82 A2 00 00 00  ｨ待ちください...
00BF1EA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00BF1EB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
00BF1EC8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................



References in NOBU6HD_:.text to 00BF1E78..00BF1E78
Address    Disassembly                               Comment
00953758   PUSH NOBU6HD_.00BF1E78
0095378E   PUSH NOBU6HD_.00BF1E78
009537C4   PUSH NOBU6HD_.00BF1E78
009537FA   PUSH NOBU6HD_.00BF1E78
00953830   PUSH NOBU6HD_.00BF1E78
00953866   PUSH NOBU6HD_.00BF1E78
0095389C   PUSH NOBU6HD_.00BF1E78
009538D2   PUSH NOBU6HD_.00BF1E78
00953908   PUSH NOBU6HD_.00BF1E78
0095393E   PUSH NOBU6HD_.00BF1E78
00953981   PUSH NOBU6HD_.00BF1E78
009539B7   PUSH NOBU6HD_.00BF1E78
00953A89   PUSH NOBU6HD_.00BF1E78
00953ABF   PUSH NOBU6HD_.00BF1E78
00953AF5   PUSH NOBU6HD_.00BF1E78
00954C34   PUSH NOBU6HD_.00BF1E78
00955730   PUSH NOBU6HD_.00BF1E78
0095573F   PUSH NOBU6HD_.00BF1E78
00955878   PUSH NOBU6HD_.00BF1E78
00956CD4   PUSH NOBU6HD_.00BF1E78
00956EA8   PUSH NOBU6HD_.00BF1E78
009588CA   PUSH NOBU6HD_.00BF1E78
0095B0F2   PUSH NOBU6HD_.00BF1E78
0095B2A0   PUSH NOBU6HD_.00BF1E78
0095B2F9   PUSH NOBU6HD_.00BF1E78
0095B894   PUSH NOBU6HD_.00BF1E78
0095FD9C   PUSH NOBU6HD_.00BF1E78
009614AF   PUSH NOBU6HD_.00BF1E78
0097A4F8   PUSH NOBU6HD_.00BF1E78
0097A502   PUSH NOBU6HD_.00BF1E78
0099161A   MOV DWORD PTR DS:[BF7454],NOBU6HD_.00BF1  DS:[00BF7454]=00BF1E93 (NOBU6HD_.00BF1E9	← 　書き換えている所
00991784   MOV EAX,NOBU6HD_.00BF1E78                 00BF1E78=NOBU6HD_.00BF1E78                 ← 　← ここが噴き出しメッセージでもっともよくつかわれている!!
0099250A   MOV DWORD PTR DS:[BF7454],NOBU6HD_.00BF1  DS:[00BF7454]=00BF1E93 (NOBU6HD_.00BF1E9  	← 　書き換えている所
00994BD4   PUSH NOBU6HD_.00BF1E78
00994C17   PUSH NOBU6HD_.00BF1E78
00994D26   PUSH NOBU6HD_.00BF1E78
00994DD7   PUSH NOBU6HD_.00BF1E78
00994ED8   PUSH NOBU6HD_.00BF1E78
00994F89   PUSH NOBU6HD_.00BF1E78
00995038   PUSH NOBU6HD_.00BF1E78
009950E9   PUSH NOBU6HD_.00BF1E78
009C9D35   PUSH NOBU6HD_.00BF1E78
009C9D45   PUSH NOBU6HD_.00BF1E78
009C9D65   PUSH NOBU6HD_.00BF1E78
009C9D6F   PUSH NOBU6HD_.00BF1E78
009EF5C8   PUSH NOBU6HD_.00BF1E78
009EF5D2   PUSH NOBU6HD_.00BF1E78
009F4B9E   PUSH NOBU6HD_.00BF1E78
009F4BA8   PUSH NOBU6HD_.00BF1E78
00A0806C   PUSH NOBU6HD_.00BF1E78
00A080A6   MOV DL,BYTE PTR DS:[EAX+BF1E78]

*/