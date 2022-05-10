#include "GameDataStruct.h"

NB6YEAR				*_nb6year      = NULL;
NB6TURN				*_nb6turn      = NULL;
int			          nb6turn_gundan_ptr;			// ‚±‚ênb6turn.gundan ‚ÌƒAƒhƒŒƒX‚ğŠi”[‚·‚é‚½‚ß‚¾‚¯B(ƒAƒZƒ“ƒuƒ‰‚©‚çŒ©‚é‚½‚ß)

NB6PLAYERS8			*nb6players8   = NULL;

NB6BUSHOU			*nb6bushou	   = NULL;
NB6BUSHOUNAME		*nb6bushouname = NULL;
NB6CASTLE			*nb6castle	   = NULL;
NB6CASTLEMAX		*nb6castlemax  = NULL;
NB6CHIMEI			*nb6chimei     = NULL;
NB6KANI				*nb6kani       = NULL;
NB6KAHOU			*nb6kahou      = NULL;
NB6GUNDAN			*nb6gundan	   = NULL;
NB6DAIMYO			*nb6daimyo     = NULL;
byte				*nb6doumei     = NULL;

byte				*_nb6battle_field_turn = NULL;

HEX_XY				*_nb6hex_xy    = NULL;

NB6FIELD_HEX_ROLE		 *_nb6field_hex_role     = NULL;
NB6FIELD_HEX_UNIT_POS	 *_nb6field_hex_unit_pos = NULL;

NB6CASTLE_HEX_ROLE	     *_nb6castle_hex_role    = NULL;
NB6CASTLE_HEX_HIGH	     *_nb6castle_hex_high    = NULL;
NB6CASTLE_HEX_UNIT_POS   *_nb6castle_hex_unit_pos = NULL;

NB6CASTLE_HEX_ROLE       *_nb6fire_hex_role       = NULL;

NB6BUSHOU_HEX_UNIT_INFO  *nb6bushou_hex_unit_info = NULL;

NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *nb6war_joint_daimyo_hex_group_info = NULL;

NB6WAR_BATTLE_DAIMYO_INFO *_nb6war_battle_daimyo_info = NULL;


NB6SOBA				*_nb6soba      = NULL;

NB6PARAMMAX			*_nb6parammax	   = NULL;
NB6PARAMMAX_MAIN	*_nb6parammax_main = NULL;
NB6SOLDIERMAX		*nb6soldier_max   = NULL;

NB6FUKIDASHIRELATEPERSONS  *_nb6fukidashi_relate_persons = NULL;

int					nb6fukidashi_msg_ptr = NULL;

BYTE				*_nb6weather = NULL;

WORD				*_nb6battle_center_castle;		// í‘ˆ‚ª”­¶‚µ‚½Û‚ÉAU‚ß‚ç‚ê‚½é(=–ìí‚Ì’†‰›‚Ìé)

int				    *nb6bgmdirptr   = NULL;
int				    *nb6moviedirptr = NULL;

NB6BGMTABLE			*nb6bgmtable  = NULL;
NB6BGMTABLE			nb6bgmdefault[GAMEDATASTRUCT_BGM_FILE_NUM]; // Å‰‚ÌƒfƒtƒHƒ‹ƒg’l‚ğŠo‚¦‚Ä‚¨‚­BŒ³‚Ö‚Æ–ß‚¹‚é‚æ‚¤‚É‚·‚é‚½‚ßB

NB6MOVIETABLE		*nb6movietable = NULL;
NB6MOVIETABLE		nb6moviedefault[GAMEDATASTRUCT_MOVIE_FILE_NUM]; // Å‰‚ÌƒfƒtƒHƒ‹ƒg’l‚ğŠo‚¦‚Ä‚¨‚­BŒ³‚Ö‚Æ–ß‚¹‚é‚æ‚¤‚É‚·‚é‚½‚ßB


int					nb6textlabel_base_ptr = NULL; // —lX‚ÈƒeƒLƒXƒgƒ‰ƒxƒ‹‚Ìƒx[ƒX
NB6SCENARIOTITLE	nb6scenariotitle;

int					nb6dialog_message_ptr = NULL;

NB6SETTINGS_INGAME	*_nb6settings_ingame = NULL;

void SetGameDataStructPointer() {

	int *iTargetAddress = NULL;



	/*
	0099BF87   56               PUSH ESI
	0099BF88   0FB735 6055BD00  MOVZX ESI,WORD PTR DS:[BD5560] © ”N‚Æ‹Gß‚Ö‚ÌQÆB
	0099BF8F   6A 0F            PUSH 0F
	0099BF91   50               PUSH EAX
	*/

	/*
	00BD5553                                         6A 00 00               ..@© ”N‚Æ‹Gß
	00BD5563  05 55 55 55 65 55 55 55 55 55 55 55 55 55 55 75  UUUeUUUUUUUUUUu  © “¯–¿î•ñ
	00BD5573  57 57 55 55 55 55 55 55 55 55 55 55 59 55 55 55  WWUUUUUUUUUUYUUU
	*/

	iTargetAddress = (int *)(0x99BF8B - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6year = (NB6YEAR *)(*iTargetAddress);




	/*
	00871000   56               PUSH ESI

	ƒ^[ƒ“î•ñŠÖ˜A‚Ìƒƒ‚ƒŠB
	// ‘å–¼ƒ^[ƒ“‚ÆŒR’cƒ^[ƒ“
	References in NOBU6HD_:.text to 00BCF8DD..00BCF8DD
	Address    Disassembly                               Comment
	0099BCF5   MOV WORD PTR DS:[BCF8DD],AX
	0099BD90   MOV AX,WORD PTR DS:[BCF8DD]               [00BCF8DD]=0019
	0099C226   MOVZX EDX,WORD PTR DS:[BCF8DD]            DS:[00BCF8DD]=0019
	0099C23A   MOV WORD PTR DS:[BCF8DD],DX

	0099BCF0   B8 FFFF0000      MOV EAX,0FFFF
	0099BCF5   66:A3 DDF8BC00   MOV WORD PTR DS:[BCF8DD],AX
	0099BCFB   C3               RETN

	00BCF8DD  19 00 23 00 FF FF 1D 00 01 00 39                 .#.ÿÿ..9
	*/

	iTargetAddress = (int *)(0x099BCF7 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6turn = (NB6TURN *)(*iTargetAddress);
	nb6turn_gundan_ptr = (int)(&nb6turn.gundan);




	/*
	011AF975  20 00 21 00 2C 00 32 00 FF FF FF FF FF FF FF FF   .!.,.2.ÿÿÿÿÿÿÿÿ 1560‚ÅD“cEÖ“¡EóˆäE–{Šè›
	*/
	/*
	0099BBCF   53               PUSH EBX
	0099BBD0   56               PUSH ESI
	0099BBD1   57               PUSH EDI
	0099BBD2   B9 FFFF0000      MOV ECX,0FFFF
	0099BBD7   33FF             XOR EDI,EDI
	0099BBD9   66:890C45 75F9BC>MOV WORD PTR DS:[EAX*2+BCF975],CX  ©ƒvƒŒƒCƒ„‚Wl‚ÌŒR’c”Ô†‚Ö‚ÌƒAƒhƒŒƒX
	0099BBE1   BB FF000000      MOV EBX,0FF
	0099BBE6   33F6             XOR ESI,ESI



	*/
	iTargetAddress = (int *)(0x99BBDD - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6players8 = (NB6PLAYERS8 *)(*iTargetAddress);


	/*
	0xF30000   BASE

	00FCEC42   83C4 08          ADD ESP,8
	00FCEC45   B8 48652801      MOV EAX,NOBU6HD_.01286548
	00FCEC4A   0FB740 15        MOVZX EAX,WORD PTR DS:[EAX+15]
	00FCEC4E   B9 FFFF0000      MOV ECX,0FFFF
	00FCEC53   66:3BC1          CMP AX,CX
	*/
	iTargetAddress = (int *)(0xFCEC46 - 0xF30000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6bushou = (NB6BUSHOU *)(*iTargetAddress);


	/*
	nb6bushouname ‚ÌˆÊ’u
	00220000   BASE

	002BECE7   83C4 08          ADD ESP,8
	002BECEA   B8 F8C65700      MOV EAX,NOBU6HD_.00[57C6F8]  ©  ‚±‚±‚ªnb6bushouname ‚ğw‚µ‚Ä‚¢‚éƒAƒhƒŒƒX
	002BECEF   0FB740 16        MOVZX EAX,WORD PTR DS:[EAX+16]
	002BECF3   6A 0F            PUSH 0F
	002BECF5   50               PUSH EAX
	*/
	iTargetAddress = (int *)(0x2BECEB - 0x220000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6bushouname = (NB6BUSHOUNAME *)(*iTargetAddress);







	/*
	00BD3318  [21] 00 16 00 FF FF FF FF 8B E0 90 CE 00 00 00 00 ‹àÎ....@@© [8BE090CE]‚Íu‹àÎv‚Ì‚±‚ÆB
	00BD3328  00 47 00 38 3D 00 51 9D 05 41 0F 00 01 60 00 02
	00BD3338  00 00 00 FF FF EB 00 EF 00 8E B5 94 F6 00 00 00
	00BD3348  00 00 29 00 8F 22 03 47 64 09 34 00 00 01 81 00
	00BD3358  00 08 39 00 04 00 7D 01 FF FF 8E 77 8C 8E 00 00
	00BD3368  00 00 00 41 00 24 30 01 1A 5E 03 35 23 00 00 00
	00BD3378  00 02 00 03 00 0D 00


	ƒx[ƒX
	00871000   56               PUSH ESI

	009976DF   83C4 08          ADD ESP,8
	009976E2   B8 1833BD00      MOV EAX,NOBU6HD_.00BD3318    ©@‚±‚±‚ªéƒŠƒXƒg‚Ö‚ÌQÆ
	009976E7   0FB770 02        MOVZX ESI,WORD PTR DS:[EAX+2]
	009976EB   66:3BF3          CMP SI,BX
	009976EE  ^75 B6            JNZ SHORT NOBU6HD_.009976A6
	009976F0   5F               POP EDI
	009976F1   5E               POP ESI
	009976F2   5B               POP EBX
	009976F3   5D               POP EBP
	009976F4   C3               RETN
	*/

	iTargetAddress = (int *)(0x9976E3 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6castle = (NB6CASTLE *)(*iTargetAddress);


	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00997FDA   83C4 08          ADD ESP,8
	00997FDD   B9 B04EBD00      MOV ECX,NOBU6HD_.00BD4EB0  © ‚±‚±‚ªé‚Ì•t‰Áî•ñƒŠƒXƒg‚Ö‚ÌQÆ
	00997FE2   8B45 14          MOV EAX,DWORD PTR SS:[EBP+14]
	00997FE5   C1E0 03          SHL EAX,3
	00997FE8   50               PUSH EAX
	00997FE9   8B45 0C          MOV EAX,DWORD PTR SS:[EBP+C]
	00997FEC   51               PUSH ECX
	00997FED   8B4D 08          MOV ECX,DWORD PTR SS:[EBP+8]
	00997FF0   03C3             ADD EAX,EBX
	00997FF2   50               PUSH EAX
	*/
	iTargetAddress = (int *)(0x997FDE - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6castlemax = (NB6CASTLEMAX *)(*iTargetAddress);


	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	009265EB   B8 D82BBD00      MOV EAX,NOBU6HD_.00BD2BD8  © ’n–¼‚Ö‚ÌƒŠƒXƒg‚Ö‚ÌQÆ
	009265F0   83C4 08          ADD ESP,8
	009265F3   0FB740 17        MOVZX EAX,WORD PTR DS:[EAX+17]
	009265F7   2345 0C          AND EAX,DWORD PTR SS:[EBP+C]
	009265FA   F7D8             NEG EAX
	009265FC   1BC0             SBB EAX,EAX
	009265FE   F7D8             NEG EAX
	00926600   5D               POP EBP
	00926601   C3               RETN
	00926602   CC               INT3
	*/
	iTargetAddress = (int *)(0x9265EC - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6chimei = (NB6CHIMEI *)(*iTargetAddress);

	/*
	00925E38   83C4 08          ADD ESP,8
	00925E3B   B9 401ABD00      MOV ECX,NOBU6HD_.00BD1A40  © Š¯ˆÊ‚ÌƒŠƒXƒg‚Ö‚ÌQÆ
	00925E40   8B45 14          MOV EAX,DWORD PTR SS:[EBP+14]
	00925E43   8D04C0           LEA EAX,DWORD PTR DS:[EAX+EAX*8]
	00925E46   03C0             ADD EAX,EAX
	00925E48   50               PUSH EAX
	00925E49   51               PUSH ECX
	00925E4A   FF75 0C          PUSH DWORD PTR SS:[EBP+C]
	00925E4D   8B4D 08          MOV ECX,DWORD PTR SS:[EBP+8]
	00925E50   E8 7BAA0600      CALL NOBU6HD_.009908D0
	00925E55   5D               POP EBP
	00925E56   C3               RETN
	00925E57   CC               INT3
	*/
	iTargetAddress = (int *)(0x925E3C - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6kani = (NB6KANI *)(*iTargetAddress);


	/*
	0092501C   E8 CF7A0700      CALL NOBU6HD_.0099CAF0
	00925021   B8 5811BD00      MOV EAX,NOBU6HD_.00BD1158		© ‰Æ•ó‚Ìƒƒ‚ƒŠ‚Ö‚ÌQÆ
	00925026   B9 FFBF0000      MOV ECX,0BFFF
	0092502B   83C4 08          ADD ESP,8
	0092502E   66:2148 11       AND WORD PTR DS:[EAX+11],CX
	00925032   5D               POP EBP
	00925033   C3               RETN
	00925034   CC               INT3
	*/
	iTargetAddress = (int *)(0x925022 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6kahou = (NB6KAHOU *)(*iTargetAddress);


	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00953756   6A 00            PUSH 0
	00953758   68 781EBF00      PUSH NOBU6HD_.00BF1E78
	0095375D   E8 DECC0A00      CALL NOBU6HD_.00A00440
	*/
	/*
	00BF1E78  89 BD 82 F0 82 B7 82 E9 82 A9 82 CD 0A 8C 5A 8F  ‰½‚ğ‚·‚é‚©‚Í.ŒZE
	00BF1E88  E3 82 CC 0A 90 53 8E 9F 91 E6 00 82 E7 82 AD 82  ã‚Ì.SŸ‘æ.‚ç‚­E
	00BF1E98  A8 91 D2 82 BF 82 AD 82 BE 82 B3 82 A2 00 00 00  ¨‘Ò‚¿‚­‚¾‚³‚¢...
	00BF1EA8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
	*/

	iTargetAddress = (int *)(0x953759 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6fukidashi_msg_ptr = (int)(*iTargetAddress); // int ‚Æ‚µ‚Ä•Û‘¶‚µ‚Ä‚¨‚­B


	/*
	00BCFFC8  [00 00 FF FF 0A 00 01 00 01] 00 00 E8 03 E8 03 0A  ..ÿÿ.....EE. © ŒR’c‚Ìƒƒ‚ƒŠB1560”N‚Å‚±‚Ì‚ ‚½‚è‚ÅŒŸõ‚·‚ê‚Îo‚é
	00BCFFD8  00 00 00 00 01 00 00 03 00 36 00 03 00 02 00 00  .......6....
	00BCFFE8  84 03 84 03 1E 00 00 00 00 01 02 00 FF FF        EE.....ÿÿ.
	*/

	/*
	00920542   57               PUSH EDI
	00920543   E8 A8C50700      CALL NOBU6HD_.0099CAF0
	00920548   83C4 08          ADD ESP,8
	0092054B   B8 C8FFBC00      MOV EAX,NOBU6HD_.00BCFFC8    © ŒR’cî•ñƒŠƒXƒg‚Ö‚ÌQÆ
	00920550   B9 FFFF0000      MOV ECX,0FFFF
	00920555   66:3948 06       CMP WORD PTR DS:[EAX+6],CX
	00920559   74 0A            JE SHORT NOBU6HD_.00920565
	*/
	iTargetAddress = (int *)(0x92054C - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6gundan = (NB6GUNDAN *)(*iTargetAddress);


	/*

	00BCF998  01 00 01 00 0A 00 FF FF 38 00 FF FF 00 00 00 00    ©‘å–¼‚Ìƒƒ‚ƒŠB
	00BCF9A8  00 00 FF FF 00 00 03 00 02 00 36 00 FF FF 14 14  

	..ÿ
	*/
	/*
	0091E42A   83C4 08          ADD ESP,8
	0091E42D   B8 98F9BC00      MOV EAX,NOBU6HD_.00BCF998	© ‘å–¼‚Ìƒƒ‚ƒŠ‚Ö‚ÌQÆ
	0091E432   66:3918          CMP WORD PTR DS:[EAX],BX
	0091E435   74 0A            JE SHORT NOBU6HD_.0091E441
	0091E437   56               PUSH ESI
	0091E438   FFD7             CALL EDI
	0091E43A   83C4 04          ADD ESP,4
	0091E43D   85C0             TEST EAX,EAX
	*/
	iTargetAddress = (int *)(0x91E42E - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6daimyo = (NB6DAIMYO *)(*iTargetAddress);


	/*
	004CF213  05 55 55 55 65 55 55 55 55 55 55 55 55 55 55 75  UUUeUUUUUUUUUUu
	004CF223  57 57 55 55 55 55 55 55 55 55 55 55 56 55 55 55  WWUUUUUUUUUUVUUU
	004CF233  55 55 55 55 00 55 55 53 25 55                    UUUU.UUS%U
	*/
	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0099C669   4A               DEC EDX
	0099C66A   83CA FE          OR EDX,FFFFFFFE
	0099C66D   42               INC EDX
	0099C66E   F7DA             NEG EDX
	0099C670   1AD2             SBB DL,DL
	0099C672   0FB7C6           MOVZX EAX,SI
	0099C675   D1E9             SHR ECX,1
	0099C677   8D04C0           LEA EAX,DWORD PTR DS:[EAX+EAX*8]
	0099C67A   8DB1 6355BD00    LEA ESI,DWORD PTR DS:[ECX+BD5563] © “¯–¿î•ñ‚Ö‚ÌƒŠƒtƒ@ƒŒƒ“ƒX
	*/

	iTargetAddress = (int *)(0x99C67C - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6doumei = (byte *)(*iTargetAddress);


	/*
	‚Ql‚Ì˜bÒ

	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	References in NOBU6HD_:.text to 00BD72C0..00BD72C0
	Address    Disassembly                               
	0099156C   PUSH NOBU6HD_.00BD72C0                     © ˜bÒ‚Pl‚ğƒvƒbƒVƒ…‚©B
	00991BD8   MOVZX ESI,WORD PTR DS:[EAX*2+BD72C0]       © ˜bÒ•¡”l‚ğƒRƒs[‚©B


	00BD72C0  BF 00 BD 00 BD 00 00 00 00 00 00 00 19           ¿.½.½.......
	*/
	
	iTargetAddress = (int *)(0x99156D - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6fukidashi_relate_persons = (NB6FUKIDASHIRELATEPERSONS *)(*iTargetAddress);




	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00950325   0FAFC2                  IMUL EAX,EDX
	00950328   0FB68C08 BAE0BE00       MOVZX ECX,BYTE PTR DS:[EAX+ECX+BEE0BA]		© –ìí–ğŠ„‚ÌêŠ‚Ö‚Ìƒ|ƒCƒ“ƒ^
	00950330   3BF7                    CMP ESI,EDI
	00950332   73 11                   JNB SHORT NOBU6HD_.00950345
	*/
	/*
	00BEE0BA  00 07 07 07 06 06 07 07 06 06 01 06 06 01 06 07  .          •“c¨ã™‚ÉU‚ß‚½‚Ì‚¢‚Â‚à‚Ì‚Æ‚±‚ë‚Å‚ÌA–ìí–ğŠ„
	00BEE0CA  07 07 02 07 07 06 01 01 01 02 02 05 01 01 01 01  
	00BEE0DA  01 01 02 01 01 09 09 09 00 00 07 07 07 07 07 07  .....

	*/
	iTargetAddress = (int *)(0x95032C - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6field_hex_role = (NB6FIELD_HEX_ROLE *)(*iTargetAddress);


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0095F388   68 FF000000             PUSH 0FF
	0095F38D   68 D8030000             PUSH 3D8
	0095F392   68 6AE8BE00             PUSH NOBU6HD_.00BEE86A ©–ìíƒ†ƒjƒbƒgˆÊ’u
	0095F397   E8 94F30200             CALL NOBU6HD_.0098E730
	*/
	/*
	00BEE86A  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF  ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ     •“c¨ã™‚ÉU‚ß‚½‚Ìƒ†ƒjƒbƒg‚ÌˆÊ’u‚È‚Ç
	00BEE87A  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF  ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ
	00BEE88A  FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF FF  ÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿÿ
	00BEE89A  FF FF FF FF FF FF FF FF FF FF FF FF FF           ÿÿÿÿÿÿÿÿÿÿÿÿÿ

	*/
	// ‚±‚Ì“–‚½‚èAu‰Švu–ğŠ„vu‚‚³vuƒ†ƒjƒbƒgˆÊ’uv‚Ì‡”Ô‚ÅA0x3d8ƒoƒCƒg‚¸‚ÂƒAƒhƒŒƒX‚ªi‚ñ‚Å‚¢‚­

	iTargetAddress = (int *)(0x95F393 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6field_hex_unit_pos = (NB6FIELD_HEX_UNIT_POS *)(*iTargetAddress);


	// é‚Ì–ğŠ„‚ÍƒAƒhƒŒƒX‚ª–ìí‚Æ“¯‚¶
	iTargetAddress = (int *)(0x95032C - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6castle_hex_role = (NB6CASTLE_HEX_ROLE *)(*iTargetAddress);

	// é‚Å‚Ìƒ|ƒWƒVƒ‡ƒ“‚ÌƒAƒhƒŒƒX‚Í–ìí‚Æ“¯‚¶
	iTargetAddress = (int *)(0x95F393 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6castle_hex_unit_pos = (NB6CASTLE_HEX_UNIT_POS *)(*iTargetAddress);


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	009502E7   8BC1                    MOV EAX,ECX
	009502E9   0FAFC7                  IMUL EAX,EDI
	009502EC   0FAF4D FC               IMUL ECX,DWORD PTR SS:[EBP-4]
	009502F0   0FB6B430 92E4BE00       MOVZX ESI,BYTE PTR DS:[EAX+ESI+BEE492]@Uéí‚Ì‚‚³‚ÌŠT”O
	009502F8   0FB6BC11 92E4BE00       MOVZX EDI,BYTE PTR DS:[ECX+EDX+BEE492]
	*/
	/*
	00BEE0BA  00 07 07 07 06 06 07 07 06 06 01 06 06 01 06 07  .    –ìí‚Ì–ğŠ„‚ÌÅŒã‚É‘±‚¢‚ÄUéí‚Ì‚‚³
	00BEE0CA  07 07 02 07 07 06 01 01 01 02 02 05 01 01 01 01  
	00BEE0DA  01 01 02 01 01 09 09 09 00 00 07 07 07 07 07 07  .....
	*/
	/*
	00BEE492  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................ âÄéí‚Ì‚‚³
	00BEE4A2  00 00 00 00 00 01 01 01 01 01 01 01 01 01 01 01  .....
	00BEE4B2  01 01 00 00 00 00 00 01 01 01 01 01 01 01 01 01  .....
	00BEE4C2  01 01 01 01 00 00 00 00 00 02 02 02 02           .....
	*/
	// Uéí“¬‚Ìu‚‚³v
	iTargetAddress = (int *)(0x9502F4 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6castle_hex_high = (NB6CASTLE_HEX_HIGH *)(*iTargetAddress);


	/*
	0095F368   5F               POP EDI
	0095F369   5E               POP ESI
	0095F36A   5B               POP EBX
	0095F36B   8BE5             MOV ESP,EBP
	0095F36D   5D               POP EBP
	0095F36E   C3               RETN
	0095F36F   CC               INT3
	0095F370   33C0             XOR EAX,EAX
	0095F372   50               PUSH EAX
	0095F373   68 D8030000      PUSH 3D8
	0095F378   68 E2DCBE00      PUSH NOBU6HD_.00BEDCE2		@@@©âÄéí‚Ì‰Š‚Ìî•ñ
	0095F37D   66:A3 E0DCBE00   MOV WORD PTR DS:[BEDCE0],AX


	00B3F322   50               PUSH EAX
	00B3F323   68 D8030000      PUSH 3D8
	00B3F328   68 DADCDC00      PUSH NOBU6HD_.00DCDCDA
	00B3F32D   66:A3 D8DCDC00   MOV WORD PTR DS : [DCDCD8], AX
	*/
	// ‰Š
	iTargetAddress = (int *)(0x95F379 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6fire_hex_role = (NB6CASTLE_HEX_ROLE *)(*iTargetAddress);



	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00A120ED   C1E7 04                 SHL EDI,4
	00A120F0   68 14BFB400             PUSH NOBU6HD_.00B4BF14                   ; ASCII "BGM\" © BGM\‚Æ‚¢‚¤•¶š—ñ‚ÌêŠ
	00A120F5   8BCE                    MOV ECX,ESI
	00A120F7   81C7 98ECBD00           ADD EDI,NOBU6HD_.00BDEC98
	*/
	iTargetAddress = (int *)(0xA120F1 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6bgmdirptr = (int *)(iTargetAddress); // ‚±‚±‚Í’†g‚Å‚Í‚È‚­A‚±‚Ìƒ|ƒCƒ“ƒ^©‘Ì‚ğ‚Á‚Ä‚¨‚­•K—v‚ª‚ ‚éB

	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00A11489   8B7D 08                 MOV EDI,DWORD PTR SS:[EBP+8]
	00A1148C   1BC9                    SBB ECX,ECX
	00A1148E   41                      INC ECX
	00A1148F   6A 06                   PUSH 6
	00A11491   8D3488                  LEA ESI,DWORD PTR DS:[EAX+ECX*4]
	00A11494   03F1                    ADD ESI,ECX
	00A11496   68 0CBFB400             PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"    © ƒ€[ƒr[‚Æ‚¢‚¤•¶š—ñ‚Ö‚ÌƒAƒhƒŒƒX;  ASCII "MOVIE\"
	00A1149B   8BCF                    MOV ECX,EDI
	*/

	iTargetAddress = (int *)(0xA11497 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6moviedirptr = (int *)(iTargetAddress); // ‚±‚±‚Í’†g‚Å‚Í‚È‚­A‚±‚Ìƒ|ƒCƒ“ƒ^©‘Ì‚ğ‚Á‚Ä‚¨‚­•K—v‚ª‚ ‚éB



	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00923BA2   E8 498F0700      CALL NOBU6HD_.0099CAF0
	00923BA7   B8 30D1BE00      MOV EAX,NOBU6HD_.00BED130		© íê‚ÉQ‰Á‚µ‚Ä‚¢‚é‘S•«î•ñ
	00923BAC   83C4 08          ADD ESP,8
	00923BAF   8B40 18          MOV EAX,DWORD PTR DS:[EAX+18]
	00923BB2   2345 0C          AND EAX,DWORD PTR SS:[EBP+C]
	00923BB5   5D               POP EBP
	00923BB6   C3               RETN
	00923BB7   CC               INT3
	*/

	/*
	00BED130  BC 00 02 00 03 00 00 00 11 00 00 00 0F FF FF 00  ¼........ÿÿ.
	00BED140  00 00 07 00 00 00 FF FF 20 02 00 00 00 00        .....ÿÿ ....
	*/
	iTargetAddress = (int *)(0x923BA8 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6bushou_hex_unit_info = (NB6BUSHOU_HEX_UNIT_INFO *)(*iTargetAddress);



	/*

	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00973A09   83C4 08          ADD ESP,8
	00973A0C   B8 50DABE00      MOV EAX,NOBU6HD_.00BEDA50    © í‘ˆ‚ÉQ‰Á‚µ‚Ä‚¢‚é‘å–¼¨—ÍEŒR’c¨—ÍE‘ã•\ÒE—§ê
	00973A11   83C0 04          ADD EAX,4
	00973A14   8945 08          MOV DWORD PTR SS:[EBP+8],EAX
	00973A17   5D               POP EBP
	00973A18  ^E9 43B8F9FF      JMP NOBU6HD_.0090F260


	*/
	/*
	00BEDA50  1B 00 25 00 CA 00 00 00 00 00 19 00 23 00 BC 00  
	00BEDA60  01 00 00 00 FF FF FF FF FF FF 00 00 00 00 FF FF  
	00BEDA70  FF FF FF FF 00 00 00 00 FF FF FF FF FF FF 00 00
	00BEDA80  00 00 FF FF FF FF FF FF 00 00
	*/
	iTargetAddress = (int *)(0x973A0D - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6war_joint_daimyo_hex_group_info = (NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *)(*iTargetAddress);


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0095F23D   56               PUSH ESI
	0095F23E   66:A3 B0DBBE00   MOV WORD PTR DS:[BEDBB0],AX			©@‘Îíî•ñ
	0095F244   E8 D7950300      CALL NOBU6HD_.00998820
	0095F249   66:A3 B8DBBE00   MOV WORD PTR DS:[BEDBB8],AX
	0095F24F   8D45 E8          LEA EAX,DWORD PTR SS:[EBP-18]
	0095F252   56               PUSH ESI
	0095F253   50               PUSH EAX
	*/
	/*
	00BEDBB0  25 00 00 00 23 00 00 00 1B 00 00 00 19 00 00 00  %...#.........  ‘½•ªQí‚µ‚Ä‚¢‚éŒR’c”Ô†ƒŠƒXƒg‚Q‚ÂA‘å–¼”Ô†ƒŠƒXƒg‚Q‚ÂB
	00BEDBC0  01 00 00 00 25 00 00 00 00 00 00 00 1B 00 00 00  ...%..........
	00BEDBD0  FF FF 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ÿÿ..............
	*/
	iTargetAddress = (int *)(0x95F240 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6war_battle_daimyo_info = (NB6WAR_BATTLE_DAIMYO_INFO *)(*iTargetAddress);
	// ƒfƒoƒbƒOo—Í << "‘Îí‘å–¼" << nb6war_battle_daimyo_info << endl;


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00910DE5   C3               RETN
	00910DE6   33C0             XOR EAX,EAX
	00910DE8   5D               POP EBP
	00910DE9   C3               RETN
	00910DEA   CC               INT3
	00910DEB   CC               INT3
	00910DEC   CC               INT3
	00910DED   CC               INT3
	00910DEE   CC               INT3
	00910DEF   CC               INT3
	00910DF0   55               PUSH EBP
	00910DF1   8BEC             MOV EBP,ESP
	00910DF3   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
	00910DF6   8B0485 203FBC00  MOV EAX,DWORD PTR DS:[EAX*4+BC3F20]	© Maxƒpƒ‰ƒƒ^‚Ö‚ÌQÆ
	00910DFD   5D               POP EBP
	00910DFE   C3               RETN
	*/
	/*
	00BC3F20  6E 00 00 00 6E 00 00 00 6E 00 00 00 D0 07 00 00
	00BC3F30  D0 07 00 00 D0 07 00 00 6E 00 00 00 6E 00 00 00
	00BC3F40  64 00 00 00 E7 03 00 00 FF 00 00 00 48 00 00 00
	00BC3F50  D6 00 00 00 D6 00 00 00 64 00 00 00 C8 00 00 00
	00BC3F60  64 00 00 00 03 00 00 00 FF 00 00 00 FF 00 00 00
	00BC3F70  06 00 00 00 FF 00 00 00 FF FF 00 00 FF FF 00 00  
	*/
	iTargetAddress = (int *)(0x910DF9 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6parammax = (NB6PARAMMAX *)(*iTargetAddress);


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0099894A   C3               RETN
	0099894B   33C0             XOR EAX,EAX
	0099894D   5D               POP EBP
	0099894E   C3               RETN
	0099894F   CC               INT3
	00998950   55               PUSH EBP
	00998951   8BEC             MOV EBP,ESP
	00998953   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
	00998956   83F8 0B          CMP EAX,0B
	00998959   77 09            JA SHORT NOBU6HD_.00998964
	0099895B   8B0485 0876BD00  MOV EAX,DWORD PTR DS:[EAX*4+BD7608]	 ©Maxƒpƒ‰ƒƒ^ƒƒCƒ“‚Ö‚ÌQÆ
	00998962   5D               POP EBP
	00998963   C3               RETN
	00998964   B8 01000000      MOV EAX,1
	00998969   5D               POP EBP
	0099896A   C3               RETN

	*/
	/*
	00BD7608  D6 00 00 00 FA 00 00 00 C4 09 00 00 C8 00 00 00
	00BD7618  0F 27 00 00 64 00 00 00 E7 03 00 00 02 00 00 00  
	00BD7628  4A 00 00 00 FA 00 00 00 C8 00 00 00 03 00 00 00

	*/

	iTargetAddress = (int *)(0x99895E - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6parammax_main = (NB6PARAMMAX_MAIN *)(*iTargetAddress);



	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0091122A   0FB7C0                 MOVZX EAX,AX
	0091122D   83C4 08                ADD ESP,8
	00911230   0FB70445 DC3FBC00      MOVZX EAX,WORD PTR DS:[EAX*2+BC3FDC]
	00911238   5D                     POP EBP
	00911239   C3                     RETN
	*/
	/*
	00BC3FDC  00 00 64 00 64 00 4B 00 37 00 28 00 1E 00 00 00
	*/
	iTargetAddress = (int *)(0x911234 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6soldier_max = (NB6SOLDIERMAX *)(*iTargetAddress);



	/*
	BGMƒe[ƒuƒ‹
	*/
	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	00A120F0   68 14BFB400      PUSH NOBU6HD_.00B4BF14                   ; ASCII "BGM\"
	00A120F5   8BCE             MOV ECX,ESI
	00A120F7   81C7 98ECBD00    ADD EDI,NOBU6HD_.00BDEC98				© ŠeBGMƒtƒ@ƒCƒ‹–¼Œn‚Ì\‘¢‘Ì‚Ö‚Ìƒ|ƒCƒ“ƒ^
	00A120FD   E8 0E30E6FF      CALL NOBU6HD_.00875110
	00A12102   FF77 04          PUSH DWORD PTR DS:[EDI+4]
	00A12105   8BCE             MOV ECX,ESI


	009B1FC5   8BCE             MOV ECX,ESI
	009B1FC7   81C7 98ECB700    ADD EDI,NOBU6HD_.00B7EC98
	009B1FCD   E8 3E31E6FF      CALL NOBU6HD_.00815110
	*/
	/*
	00BDEC98  00 00 00 00 1C BF B4 00 00 00 00 00 00 00 00 00  ....© BGM”Ô†‚ÆBGM•¶š—ñ‚Ö‚Ìƒ|ƒCƒ“ƒ^‚ÆAg—pƒtƒ‰ƒO
	00BDECA8  01 00 00 00 28 BF B4 00 01 00 00 00 00 00 00 00
	00BDECB8  02 00 00 00 34 BF B4 00 01 00 00 00 00 00 00 00
	00BDECC8  03 00 00 00 40 BF B4 00 01 00 00 00 00 00 00 00
	00BDECD8  04 00 00 00 4C BF B4 00 01 00 00 00 00 00 00 00
	00BDECE8  05 00 00 00 58 BF B4 00 01 00 00 00 00 00 00 00
	00BDECF8  06 00 00 00 64 BF B4 00 01 00 00 00 00 00 00 00
	00BDED08  07 00 00 00 70 BF B4 00 01 00 00 00 00 00 00 00
	00BDED18  08 00 00 00 7C BF B4 00 01 00 00 00 00 00 00 00
	00BDED28  09 00 00 00 88 BF B4 00 01 00 00 00 00 00 00 00
	00BDED38  0A 00 00 00 94 BF B4 00 01 00 00 00 00 00 00 00
	00BDED48  0B 00 00 00 A0 BF B4 00 00 00 00 00 00 00 00 00

	*/
	iTargetAddress = (int *)(0xA120F9 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6bgmtable = (NB6BGMTABLE *)(*iTargetAddress);

	// ƒfƒtƒHƒ‹ƒg’l‚ğƒRƒs[‚µ‚Ä‚¨‚­B
	memcpy(nb6bgmdefault, nb6bgmtable, sizeof(nb6bgmdefault));



	/*
	ƒx[ƒX
	00871000   56               PUSH ESI

	00A11496   68 0CBFB400      PUSH NOBU6HD_.00B4BF0C                   ; ASCII "MOVIE\"
	00A1149B   8BCF             MOV ECX,EDI
	00A1149D   E8 3E49E6FF      CALL NOBU6HD_.00875DE0
	00A114A2   8B14F5 18ECBD00  MOV EDX,DWORD PTR DS:[ESI*8+BDEC18]
	00A114A9   803A 00          CMP BYTE PTR DS:[EDX],0


	00BDEC18  7C BE B4 00 00 00 00 00 88 BE B4 00 00 00 00 00
	00BDEC28  98 BE B4 00 00 00 00 00 B0 BE B4 00 01 00 00 00
	00BDEC38  B8 BE B4 00 01 00 00 00 C0 BE B4 00 00 00 00 00
	00BDEC48  D0 BE B4 00 00 00 00 00 E0 BE B4 00 00 00 00 00
	00BDEC58  FC BE B4 00 01 00 00 00 04 BF B4 00 01 00 00 00

	*/
	iTargetAddress = (int *)(0xA114A5 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6movietable = (NB6MOVIETABLE *)(*iTargetAddress);

	// ƒfƒtƒHƒ‹ƒg’l‚ğƒRƒs[‚µ‚Ä‚¨‚­B
	memcpy(nb6moviedefault, nb6movietable, sizeof(nb6moviedefault));



	/*
	‚±‚Ì‚Ìƒx[ƒXƒAƒhƒŒƒX
	00871000   56               PUSH ESI

	0095DCCC   C705 D8DBBE00 00000000           MOV DWORD PTR DS:[BEDBD8],0
	0095DCD6   C705 F867BD00 29000000           MOV DWORD PTR DS:[BD67F8],29     © –ìí‚Ì‰¡ƒ}ƒX
	0095DCE0   C705 FC67BD00 18000000           MOV DWORD PTR DS:[BD67FC],18     © –ìí‚Ìcƒ}ƒX
	0095DCEA   C705 0068BD00 03000000           MOV DWORD PTR DS:[BD6800],3
	0095DCF4   C705 0468BD00 D8030000           MOV DWORD PTR DS:[BD6804],3D8    © c~‰¡
	0095DCFE   C705 D0DBBE00 FFFF0000           MOV DWORD PTR DS:[BEDBD0],0FFFF
	0095DD08   E8 B32A0300                      CALL NOBU6HD_.009907C0
	*/

	/*
	00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29] 00  0x29=41‚Í–ìí‚Ìƒ}ƒbƒv‚Ì‰¡ƒ`ƒbƒv”A 0x18=24 ‚Í–ìí‚Ìƒ}ƒbƒv‚Ìcƒ`ƒbƒv”
	00BD67FA  00 00 [18] 00 00 00 03 00 00 00 D8 03 00 00 FF FF  (Uéí‚Ì‚ÍA‰¡‚ª0x12=18,  c‚ª0x10=16)
	00BD680A  00 00 00 00 00 00 FF 03 02 05 04 04 05 07 09 09
	*/
	iTargetAddress = (int *)(0x95DCD8 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6hex_xy = (HEX_XY *)(*iTargetAddress);



	/*
	00871000   56               PUSH ESI

	References in NOBU6HD_:.text to 00BD67E0..00BD67E0
	Address    Disassembly                               Comment
	00973025   MOV WORD PTR DS:[BD67E0],AX				© ‚±‚±‚ÍƒNƒŠƒA‚Ìê
	00973070   MOV AX,WORD PTR DS:[BD67E0]               [00BD67E0]=005A
	009730D3   MOV WORD PTR DS:[BD67E0],CX				© ‚±‚±‚Íí‘ˆŠJn‚É’†S“_‚Ìé”Ô†‚ª“ü‚éêŠ

	00BD67DA  95 00 A0 4F 95 00 [FF FF] 14 00 00 00 05 00 00 00                  FF FF ‚¾‚Æí‘ˆ‚µ‚Ä‚¢‚È‚¢AFFFFˆÈŠO‚¾‚ÆAíê‚Ì’†S‚Æ‚È‚Á‚Ä‚¢‚éué”Ô†v‚ª“ü‚Á‚Ä‚¢‚éB
	00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 29 00  .                 0x29=41‚Í–ìí‚Ìƒ}ƒbƒv‚Ì‰¡ƒ`ƒbƒv”A 0x18=24 ‚Í–ìí‚Ìƒ}ƒbƒv‚Ìcƒ`ƒbƒv”
	00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .                 (Uéí‚Ì‚ÍA‰¡‚ª0x12=18,  c‚ª0x10=16)

	00BD67DA  95 00 A0 4F 95 00 [5A 00] 14 00 00 00 05 00 00 00
	00BD67EA  0D 00 00 00 02 00 00 00 00 00 00 00 00 00 [29: 00
	00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .
	*/

	/*
	0097301D   CC                               INT3
	0097301E   CC                               INT3
	0097301F   CC                               INT3
	00973020   B8 FFFF0000                      MOV EAX,0FFFF
	00973025   66:A3 E067BD00                   MOV WORD PTR DS:[BD67E0],AX			© í‘ˆ‚Ì’†S‚Æ‚È‚Á‚Ä‚¢‚éé(í‘ˆ‚µ‚Ä‚¢‚È‚¢‚Í0xFFFF)
	0097302B   C3                               RETN
	0097302C   CC                               INT3

	*/
	iTargetAddress = (int *)(0x973027 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6battle_center_castle = (WORD *)(*iTargetAddress);  // ƒoƒCƒgƒ|ƒCƒ“ƒ^‚Æ‚µ‚Ä•Û




	/*
	ƒx[ƒX
	00871000   56               PUSH ESI

	íê‚Å‚ÌŒo‰ßƒ^[ƒ“”
	References in NOBU6HD_:.text to 00BD67EA..00BD67EA
	Address    Disassembly                               Comment
	00973040   MOV DWORD PTR DS:[BD67EA],0               DS:[00BD67EA]=0000000D  © ‚±‚±‚Éƒ^[ƒ“”‚Ì’l‚ğƒNƒŠƒA‚µ‚Ä‚¢‚éB
	00973090   MOV EAX,DWORD PTR DS:[BD67EA]             [00BD67EA]=0000000D
	00973176   MOV DWORD PTR DS:[BD67EA],EAX                                     © ‚±‚±‚Éƒ^[ƒ“”‚Ì’l‚ª‘ã“ü‚³‚ê‚Ä‚¢‚éB


	0097303D   CC                               INT3
	0097303E   CC                               INT3
	0097303F   CC                               INT3
	00973040   C705 EA67BD00 00000000           MOV DWORD PTR DS:[BD67EA],0
	0097304A   C3                               RETN
	0097304B   CC                               INT3
	0097304C   CC                               INT3
	* /

	/*
	ƒx[ƒX
	00871000   56               PUSH ESI

	00BD67DA  95 00 A0 4F 95 00 5A 00 14 00 00 00 05 00 00 00  E OE
	00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 [29] 00  . [17]=Œo‰ßƒ^[ƒ“”‚Æ[02]=“V‹C  0x29=41‚Æ‚Í–ìí‚Ì‰¡‚ÌHEX”‚Ì‚±‚Æ  0x12‚Ì‚ÍUâÄí‚ÌHEX”‚Ì‰¡‚Ìƒ}ƒX”‚Å‚ ‚é18‚Ì‚±‚ÆB
	00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  .......
	*/

	iTargetAddress = (int *)(0x973042 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6battle_field_turn = (byte *)(*iTargetAddress);


	/*
	ƒx[ƒX
	00871000   56               PUSH ESI

	“V‹C‚Ì’l‚ğQÆ‚â‘ã“ü‚µ‚Ä‚¢‚éŠ


	References in NOBU6HD_:.text to 00BD67EE..00BD67EE
	Address    Disassembly                               Comment
	00973030   MOV DWORD PTR DS:[BD67EE],0               DS:[00BD67EE]=00000002
	00973080   MOV EAX,DWORD PTR DS:[BD67EE]             [00BD67EE]=00000002
	00973100   CMP DWORD PTR DS:[BD67EE],ESI
	0097311C   MOV DWORD PTR DS:[BD67EE],ESI
	00973135   MOV DWORD PTR DS:[BD67EE],ESI
	0097314E   MOV DWORD PTR DS:[BD67EE],ESI
	0097315A   MOV DWORD PTR DS:[BD67EE],EAX


	0097302F   CC                        INT3
	00973030   C705 EE67BD00 00000000    MOV DWORD PTR DS:[BD67EE],0
	0097303A   C3                        RETN
	0097303B   CC                        INT3

	*/


	/*
	00BD67EA  [17] 00 00 00 [02] 00 00 00 00 00 00 00 00 00 29 00 .[02]=“V‹C
	00BD67FA  00 00 18 00 00 00 03 00 00 00 D8 03 00 00 FF FF  ...
	00BD680A  00 00 00 00 00 00 FF 03 02 05 04 04 05 07 09 09  ...


	*/

	iTargetAddress = (int *)(0x973032 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6weather = (BYTE *)(*iTargetAddress);  // ƒoƒCƒgƒ|ƒCƒ“ƒ^‚Æ‚µ‚Ä•Û



	/*
	•Ä “S–C ”n •º‚Ì‡”ÔB‚»‚ê‚¼‚êBYTE

	00871000   56               PUSH ESI

	References in NOBU6HD_:.text to 00BCF985..00BCF985
	Address    Disassembly                               Comment
	0099BED0   MOVZX EAX,BYTE PTR DS:[BCF985]            DS:[00BCF985]=0F
	0099C3F6   MOV BYTE PTR DS:[BCF985],AL


	0099BECB   CC                        INT3
	0099BECC   CC                        INT3
	0099BECD   CC                        INT3
	0099BECE   CC                        INT3
	0099BECF   CC                        INT3
	0099BED0   0FB605 85F9BC00           MOVZX EAX,BYTE PTR DS:[BCF985]  	© ‘Šê‚Ö‚ÌƒŠƒtƒ@ƒŒƒ“ƒXB‚±‚±‚©‚ç’T‚é‚Ì‚Í—Ç‚¢‚©‚à
	0099BED7   C3                        RETN
	0099BED8   CC                        INT3
	*/
	iTargetAddress = (int *)(0x99BED3 - 0x870000 + GlobalVariable::pCurrentProcessBaseAddress);
	_nb6soba = (NB6SOBA *)(*iTargetAddress);


	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00FD1000   56               PUSH ESI


	01193BFC   CC               INT3
	01193BFD   CC               INT3
	01193BFE   CC               INT3
	01193BFF   CC               INT3
	01193C00   55               PUSH EBP
	01193C01   8BEC             MOV EBP, ESP
	01193C03   8B45 08          MOV EAX, DWORD PTR SS : [EBP + 8]
	01193C06   8B0485 D0173401  MOV EAX, DWORD PTR DS : [EAX * 4 + 13417D0]@© ‚±‚±‚àg‚¦‚é‚©‚ÈH
	01193C0D   5D               POP EBP
	01193C0E   C3               RETN
	01193C0F   CC               INT3
	01193C10   55               PUSH EBP
	01193C11   8BEC             MOV EBP, ESP
	01193C13   8B55 08          MOV EDX, DWORD PTR SS : [EBP + 8]
	01193C16   83FA 23          CMP EDX, 23
	01193C19   77 10            JA SHORT NOBU6HD_.01193C2B
	01193C1B   8B04D5 70062B01  MOV EAX, DWORD PTR DS : [EDX * 8 + 12B0670]@© ‚±‚ÌƒAƒhƒŒƒX‚ª‘å‹N“_
	01193C22   8B14D5 74062B01  MOV EDX, DWORD PTR DS : [EDX * 8 + 12B0674]
	01193C29   5D               POP EBP
	01193C2A   C3               RETN
	01193C2B   B8 46C12A01      MOV EAX, NOBU6HD_.012AC146
	01193C30   8BD0             MOV EDX, EAX
	01193C32   5D               POP EBP
	01193C33   C3               RETN
	01193C34   CC               INT3
	01193C35   CC               INT3
	01193C36   CC               INT3
	01193C37   CC               INT3
	01193C38   CC               INT3
	*/
	iTargetAddress = (int *)(0x1193C1E - 0xFD0000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6textlabel_base_ptr = (int)(*iTargetAddress);

	/*
	ƒx[ƒXƒAƒhƒŒƒX
	00FD1000   56               PUSH ESI

	¦0x12B0670‚©‚ç‚Ì·•ª

	+ 0x24d0
	012B2B40  20 20 90 4D 92 B7 82 CC 92 61 90 B6 20 20 81 69    M’·‚Ì’a¶  i
	012B2B50  82 50 82 54 82 52 82 53 94 4E 81 6A 20 00 00 00  ‚P‚T‚R‚S”Nj ...

	+ 0x24fc
	012B2B6C  20 20 20 90 4D 92 B7 8C B3 95 9E 20 20 20 81 69     M’·Œ³•   i
	012B2B7C  82 50 82 54 82 53 82 55 94 4E 81 6A 20 00 00 00  ‚P‚T‚S‚U”Nj ...

	+ 0x2528
	012B2B98  20 89 B1 8B B7 8A D4 82 CC 8D 87 90 ED 20 81 69   ‰±‹·ŠÔ‚Ì‡í i
	012B2BA8  82 50 82 54 82 55 82 4F 94 4E 81 6A 20 00 00 00  ‚P‚T‚U‚O”Nj ...

	+ 0x254c
	012B2BBC  20 20 90 4D 92 B7 95 EF 88 CD 96 D4 20 20 81 69    M’·•ïˆÍ–Ô  i
	012B2BCC  82 50 82 54 82 56 82 50 94 4E 81 6A 20 00 00 00  ‚P‚T‚V‚P”Nj ...

	+ 0x2588
	012B2BF8  20 20 96 7B 94 5C 8E 9B 82 CC 95 CF 20 20 81 69    –{”\›‚Ì•Ï  i
	012B2C08  82 50 82 54 82 57 82 51 94 4E 81 6A 20 00 00 00  ‚P‚T‚W‚Q”Nj ...

	+ 0x25a8
	012B2C18  20 20 8A D6 83 96 8C B4 91 4F 96 E9 20 20 81 69    ŠÖƒ–Œ´‘O–é  i
	012B2C28  82 50 82 54 82 58 82 58 94 4E 81 6A 20 00 00 00  ‚P‚T‚X‚X”Nj ...
	*/
	nb6scenariotitle.szTitle1 = (char *)(nb6textlabel_base_ptr + 0x24d0);
	nb6scenariotitle.szTitle5 = (char *)(nb6textlabel_base_ptr + 0x24fc);
	nb6scenariotitle.szTitle2 = (char *)(nb6textlabel_base_ptr + 0x2528);
	nb6scenariotitle.szTitle3 = (char *)(nb6textlabel_base_ptr + 0x254c);
	nb6scenariotitle.szTitle4 = (char *)(nb6textlabel_base_ptr + 0x2588);
	nb6scenariotitle.szTitle6 = (char *)(nb6textlabel_base_ptr + 0x25a8);


	/*
	ƒ_ƒCƒAƒƒOƒƒbƒZ[ƒW‚Ìˆê”Ê“I‚ÈŠi”[êŠ
	01371000   56               PUSH ESI

	References in NOBU6HD_:.text to 016F1E78..016F1E78
	Address    Disassembly                               Comment
	01453758   PUSH NOBU6HD_.016F1E78
	0149161A   MOV DWORD PTR DS:[16F7454],NOBU6HD_.016F  DS:[016F7454]=016F1F0A (NOBU6HD_.016F1F0
	0149250A   MOV DWORD PTR DS:[16F7454],NOBU6HD_.016F  DS:[016F7454]=016F1F0A (NOBU6HD_.016F1F0
	015080A6   MOV DL,BYTE PTR DS:[EAX+16F1E78]

	01453756   6A 00            PUSH 0
	01453758   68 781E6F01      PUSH NOBU6HD_.016F1E78
	0145375D   E8 DECC0A00      CALL NOBU6HD_.01500440
	01453762   6A 03            PUSH 3


	016F1E78  8E 9E 82 CD 31 35 36 30 94 4E 82 54 8C 8E 81 63  ‚Í1560”N‚TŒc
	016F1E88  0A 8D A1 90 EC 8B 60 8C B3 82 CD 96 F1 82 53 96.¡ì‹`Œ³‚Í–ñ‚SE
	016F1E98  9C 82 CC 8C 52 90 A8 82 F0 97 A6 82 A2 81 41 8F  œ‚ÌŒR¨‚ğ—¦‚¢AE
	016F1EA8  78 95 7B 8F E9 82 F0 8F 6F 94 AD 82 B5 82 BD 81  x•{é‚ğo”­‚µ‚½E
	016F1EB8  42 0A 92 B7 94 4E 82 CC 8F 68 8A E8 82 C5 82 A0  B.’·”N‚ÌhŠè‚Å‚ 
	016F1EC8  82 C1 82 BD 0A 81 75 8F E3 97 8C 82 F0 89 CA 82  ‚Á‚½.uã—Œ‚ğ‰ÊE
	016F1ED8  BD 82 B5 93 56 89 BA 82 C9 8D 86 97 DF 82 B7 82  ½‚µ“V‰º‚É†—ß‚·E
	016F1EE8  E9 81 76 82 C6 82 A2 82 A4 8E A9 82 E7 82 CC 96  év‚Æ‚¢‚¤©‚ç‚ÌE
	016F1EF8  EC 96 5D 82 F0 89 CA 82 BD 82 B7                 E]‚ğ‰Ê‚½‚·‚½‚ßE
	*/
	iTargetAddress = (int *)(0x1453759 - 0x1370000 + GlobalVariable::pCurrentProcessBaseAddress);
	nb6dialog_message_ptr = (int)(*iTargetAddress);

	/*
	İ’èŒn‚ÌƒAƒhƒŒƒX
	01381000   56               PUSH ESI

	01388446   A1 30506F01      MOV EAX,DWORD PTR DS:[16F5030] © ‚±‚±‚ğŠî“_
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

	016F6B78  3F FC 0E 8C 05 00 00 00 00 05 00 00 D0 02 00 00  ?EE......Ğ..
	016F6B88  00 00 00 00 03 00 00 00 01 00 00 00 02 00 00 00  .............
	016F6B98  01 00 00 00 03 00 00 00 01 00 00 00 00 00 00 00  .............
	016F6BA8  64 00 00 00 1E 00 00 00 00 00 00 00 01 00 00 00  d.............
	016F6BB8  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00  ................
	*/

	iTargetAddress = (int *)(0x1388447 - 0x1380000 + GlobalVariable::pCurrentProcessBaseAddress);
	int iAddress = (*iTargetAddress) + 0x1b48;
	_nb6settings_ingame = (NB6SETTINGS_INGAME *)iAddress;
}
