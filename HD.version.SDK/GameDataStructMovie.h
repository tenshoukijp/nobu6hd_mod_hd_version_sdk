#pragma once


namespace Native {
	void On_lnuhdtH_v();
}


/*
x[X
00811000   56               PUSH ESI


009B136D   E8 6E4AE6FF      CALL NOBU6HD_.00815DE0
009B1372   8B14F5 18ECB700  MOV EDX, DWORD PTR DS : [ESI * 8 + B7EC18]
009B1379   803A 00          CMP BYTE PTR DS : [EDX], 0

00B7EC18  64 BE AE 00 00 00 00 00 70 BE AE 00 00 00 00 00  
00B7EC28  80 BE AE 00 00 00 00 00 98 BE AE 00 01 00 00 00  
00B7EC38  A0 BE AE 00 01 00 00 00 A8 BE AE 00 00 00 00 00  
00B7EC48  B8 BE AE 00 00 00 00 00 C8 BE AE 00 00 00 00 00  
00B7EC58  E4 BE AE 00 01 00 00 00 EC BE AE 00 01 00 00 00  
*/

#define GAMEDATASTRUCT_MOVIE_FILE_NUM		10  // MOVIEÌ

// aflÌÔÌt@C|C^ÖÌAhXÈÇB
struct NB6MOVIETABLE {
	int iMOVIEFileNameAddress;
	BYTE isUsed;
	BYTE undef[3]; // ¢gp
};

