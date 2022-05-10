#include "GameDataStruct.h"

/*
ダイアログメッセージの一般的な格納場所
ベース
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


016F1E78  8E 9E 82 CD 31 35 36 30 94 4E 82 54 8C 8E 81 63  時は1560年５月…
016F1E88  0A 8D A1 90 EC 8B 60 8C B3 82 CD 96 F1 82 53 96.今川義元は約４・
016F1E98  9C 82 CC 8C 52 90 A8 82 F0 97 A6 82 A2 81 41 8F  怩ﾌ軍勢を率い、・
016F1EA8  78 95 7B 8F E9 82 F0 8F 6F 94 AD 82 B5 82 BD 81  x府城を出発した・
016F1EB8  42 0A 92 B7 94 4E 82 CC 8F 68 8A E8 82 C5 82 A0  B.長年の宿願であ
016F1EC8  82 C1 82 BD 0A 81 75 8F E3 97 8C 82 F0 89 CA 82  った.「上洛を果・
016F1ED8  BD 82 B5 93 56 89 BA 82 C9 8D 86 97 DF 82 B7 82  ｽし天下に号令す・
016F1EE8  E9 81 76 82 C6 82 A2 82 A4 8E A9 82 E7 82 CC 96  驕vという自らの・
016F1EF8  EC 96 5D 82 F0 89 CA 82 BD 82 B7                 ・]を果たすため・

01484858   83C4 08          ADD ESP,8
0148485B   B9 68676F01      MOV ECX,NOBU6HD_.016F6768
01484860   E8 1BC00700      CALL NOBU6HD_.01500880
01484865   E8 F68B0000      CALL NOBU6HD_.0148D460				← フェイドアウト
0148486A   6A 01            PUSH 1
0148486C   6A 01            PUSH 1
0148486E   68 BD000000      PUSH 0BD
01484873   B9 50436F01      MOV ECX,NOBU6HD_.016F4350
01484878   E8 C3AC0500      CALL NOBU6HD_.014DF540				← カメラ
0148487D   E8 BE8B0000      CALL NOBU6HD_.0148D440				← フェイドイン
01484882   6A 00            PUSH 0
01484884   6A 00            PUSH 0
01484886   6A 00            PUSH 0
01484888   6A 00            PUSH 0
0148488A   6A 00            PUSH 0
0148488C   6A 00            PUSH 0
0148488E   6A 00            PUSH 0
01484890   68 641C6F01      PUSH NOBU6HD_.016F1C64
01484895   68 EA360000      PUSH 36EA
0148489A   E8 C1CC0000      CALL NOBU6HD_.01491560		← 文字列の読み込み
0148489F   83C4 20          ADD ESP,20
014848A2   50               PUSH EAX					← 文字列へのポインタ
014848A3   E8 489CFFFF      CALL NOBU6HD_.0147E4F0		← ダイアログの関数
014848A8   0FB705 641C6F01  MOVZX EAX,WORD PTR DS:[16F1C64]
014848AF   50               PUSH EAX
014848B0   E8 CB460000      CALL NOBU6HD_.01488F80
014848B5   6A 03            PUSH 3
014848B7   E8 F49BFFFF      CALL NOBU6HD_.0147E4B0
014848BC   68 A81E0000      PUSH 1EA8
014848C1   E8 5A9CFFFF      CALL NOBU6HD_.0147E520
014848C6   0FB705 681C6F01  MOVZX EAX,WORD PTR DS:[16F1C68]

*/


//---------------------下部のダイアログ-------------------------
/*
下部ダイアログ
ベース
01371000   56               PUSH ESI

0147E4F0   55               PUSH EBP
0147E4F1   8BEC             MOV EBP,ESP
0147E4F3   A1 58A46E01      MOV EAX,DWORD PTR DS:[16EA458]
0147E4F8   8B40 04          MOV EAX,DWORD PTR DS:[EAX+4]
0147E4FB   99               CDQ
0147E4FC   2BC2             SUB EAX,EDX
0147E4FE   D1F8             SAR EAX,1
0147E500   05 84000000      ADD EAX,84
0147E505   50               PUSH EAX
0147E506   68 FFFF0000      PUSH 0FFFF
0147E50B   FF75 0C          PUSH DWORD PTR SS:[EBP+C]
0147E50E   FF75 08          PUSH DWORD PTR SS:[EBP+8]
0147E511   E8 8A830800      CALL NOBU6HD_.015068A0
0147E516   83C4 10          ADD ESP,10
0147E519   5D               POP EBP
0147E51A   C3               RETN

*/
int pCallFromFuncConfirmDialogBottomAsm = 0x147E4F0 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncConfirmDialogBottomAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
		// 引数なし
		call pCallFromFuncConfirmDialogBottomAsm
			// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncConfirmDialogBottom(char *szMessage) {
	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し
	FuncConfirmDialogBottomAsm();
}






//-------------------------------------




//---------------------中央部のダイアログ-------------------------
/*
中央ダイアログ
ベース
01371000   56               PUSH ESI

0148483C   6A 00            PUSH 0
0148483E   6A 00            PUSH 0
01484840   68 641C6F01      PUSH NOBU6HD_.016F1C64
01484845   68 E9360000      PUSH 36E9
0148484A   E8 11CD0000      CALL NOBU6HD_.01491560			確認中央ダイアログ表示のための読込
0148484F   83C4 20          ADD ESP,20
01484852   50               PUSH EAX							← 文字列ポインタ
01484853   E8 389CFFFF      CALL NOBU6HD_.0147E490				← 中央ダイアログ表示
01484858   83C4 08          ADD ESP,8
0148485B   B9 68676F01      MOV ECX,NOBU6HD_.016F6768
01484860   E8 1BC00700      CALL NOBU6HD_.01500880
01484865   E8 F68B0000      CALL NOBU6HD_.0148D460				← フェイドアウト
0148486A   6A 01            PUSH 1
0148486C   6A 01            PUSH 1
0148486E   68 BD000000      PUSH 0BD
01484873   B9 50436F01      MOV ECX,NOBU6HD_.016F4350
01484878   E8 C3AC0500      CALL NOBU6HD_.014DF540				← カメラ
0148487D   E8 BE8B0000      CALL NOBU6HD_.0148D440				← フェイドイン
01484882   6A 00            PUSH 0

*/
int pCallFromFuncConfirmDialogCenterAsm = 0x147E490 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncConfirmDialogCenterAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
								   // 引数なし
		call pCallFromFuncConfirmDialogCenterAsm
		// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncConfirmDialogCenter(char *szMessage) {
	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し
	FuncConfirmDialogCenterAsm();
}



//-------------------------------------

//---------------------警告のダイアログ-------------------------
/*
警告ダイアログ
ベース
01371000   56               PUSH ESI

015069E0   55               PUSH EBP
015069E1   8BEC             MOV EBP,ESP
015069E3   81EC 08020000    SUB ESP,208
015069E9   A1 30506E01      MOV EAX,DWORD PTR DS:[16E5030]
015069EE   33C5             XOR EAX,EBP
015069F0   8945 FC          MOV DWORD PTR SS:[EBP-4],EAX
015069F3   8B45 08          MOV EAX,DWORD PTR SS:[EBP+8]
015069F6   57               PUSH EDI
015069F7   8B3D CCFF6D01    MOV EDI,DWORD PTR DS:[16DFFCC]           ; NOBU6HD_.016530E0
015069FD   50               PUSH EAX
015069FE   8D85 F8FDFFFF    LEA EAX,DWORD PTR SS:[EBP-208]
01506A04   68 03020000      PUSH 203
01506A09   50               PUSH EAX
01506A0A   E8 8B090C00      CALL NOBU6HD_.015C739A
01506A0F   83C4 0C          ADD ESP,0C
01506A12   F605 F8706F01 02 TEST BYTE PTR DS:[16F70F8],2
01506A19   74 25            JE SHORT NOBU6HD_.01506A40
01506A1B   A1 58A46E01      MOV EAX,DWORD PTR DS:[16EA458]
01506A20   8B40 04          MOV EAX,DWORD PTR DS:[EAX+4]
01506A23   99               CDQ
01506A24   2BC2             SUB EAX,EDX
01506A26   D1F8             SAR EAX,1
01506A28   05 84000000      ADD EAX,84
01506A2D   3945 14          CMP DWORD PTR SS:[EBP+14],EAX
01506A30   74 0E            JE SHORT NOBU6HD_.01506A40
01506A32   FF35 58F06D01    PUSH DWORD PTR DS:[16DF058]
01506A38   E8 B36DF8FF      CALL NOBU6HD_.0148D7F0
01506A3D   83C4 04          ADD ESP,4
01506A40   8B45 0C          MOV EAX,DWORD PTR SS:[EBP+C]
01506A43   3D FFFF0000      CMP EAX,0FFFF
01506A48   74 0F            JE SHORT NOBU6HD_.01506A59
01506A4A   6A 00            PUSH 0
01506A4C   6A 00            PUSH 0
01506A4E   6A 00            PUSH 0
01506A50   50               PUSH EAX
01506A51   E8 7A9C0000      CALL NOBU6HD_.015106D0


*/
int pCallFromFuncWarningDialogCenterAsm = 0x15069E0 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncWarningDialogCenterAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
								// 引数なし
		call pCallFromFuncWarningDialogCenterAsm
		// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncWarningDialogCenter(char *szMessage) {
	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し
	FuncWarningDialogCenterAsm();
}





//-------------------------------------
/*
ベース
01371000   56               PUSH ESI

015071F0   55               PUSH EBP
015071F1   8BEC             MOV EBP, ESP
015071F3   FF75 14          PUSH DWORD PTR SS : [EBP + 14]
015071F6   FF75 10          PUSH DWORD PTR SS : [EBP + 10]
015071F9   FF75 0C          PUSH DWORD PTR SS : [EBP + C]
015071FC   6A 00            PUSH 0
015071FE   6A 0F            PUSH 0F
01507200   6A 00            PUSH 0
01507202   FF35 D0FF6D01    PUSH DWORD PTR DS : [16DFFD0]; NOBU6HD_.016530E8
01507208   FF75 08          PUSH DWORD PTR SS : [EBP + 8]
0150720B   E8 10000000      CALL NOBU6HD_.01507220
01507210   83C4 20          ADD ESP, 20
01507213   5D               POP EBP
01507214   C3               RETN
*/


int pCallFromFuncInfoDialogCenterAsm = 0x15071F0 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncInfoDialogCenterAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
								// 引数なし
		call pCallFromFuncInfoDialogCenterAsm
		// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncInfoDialogCenter(char *szMessage) {
	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し
	FuncInfoDialogCenterAsm();
}





/*
ベース
01371000   56               PUSH ESI

// 以下はよくわからない。結局中央に表示されてしまうようだ。
015068A0   55               PUSH EBP
015068A1   8BEC             MOV EBP,ESP
015068A3   E8 887AF2FF      CALL NOBU6HD_.0142E330
015068A8   FF75 14          PUSH DWORD PTR SS:[EBP+14]
015068AB   FF75 10          PUSH DWORD PTR SS:[EBP+10]
015068AE   FF75 0C          PUSH DWORD PTR SS:[EBP+C]
015068B1   85C0             TEST EAX,EAX
015068B3   74 19            JE SHORT NOBU6HD_.015068CE
015068B5   6A 00            PUSH 0
015068B7   6A 0F            PUSH 0F
015068B9   6A 00            PUSH 0
015068BB   FF35 D0FF6D01    PUSH DWORD PTR DS:[16DFFD0]              ; NOBU6HD_.016530E8
015068C1   FF75 08          PUSH DWORD PTR SS:[EBP+8]
015068C4   E8 57090000      CALL NOBU6HD_.01507220
015068C9   83C4 20          ADD ESP,20
015068CC   5D               POP EBP
015068CD   C3               RETN
015068CE   6A 11            PUSH 11
015068D0   6A 0F            PUSH 0F
015068D2   6A 00            PUSH 0
015068D4   FF35 C8FF6D01    PUSH DWORD PTR DS:[16DFFC8]              ; NOBU6HD_.01653DB0
015068DA   FF75 08          PUSH DWORD PTR SS:[EBP+8]
015068DD   E8 3E090000      CALL NOBU6HD_.01507220
015068E2   83C4 20          ADD ESP,20
015068E5   5D               POP EBP
015068E6   C3               RETN
015068E7   CC               INT3

*/



int pCallFromFuncInfoDialogBottomAsm = 0x15068A0 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先

void FuncInfoDialogBottomAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
								   // 引数なし
		call pCallFromFuncInfoDialogBottomAsm
		// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
	}

	_asm {
		POPFD
		POPAD
	}
}

void FuncInfoDialogBottom(char *szMessage) {
	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し
	FuncInfoDialogBottomAsm();
}






/*
実行・取り消しダイアログ
ベース
01371000   56               PUSH ESI


01506C70   55               PUSH EBP
01506C71   8BEC             MOV EBP, ESP
01506C73   56               PUSH ESI
01506C74   6A 00            PUSH 0
01506C76   68 FFFF0000      PUSH 0FFFF
01506C7B   68 FFFF0000      PUSH 0FFFF
01506C80   68 FFFF0000      PUSH 0FFFF
01506C85   6A 0F            PUSH 0F
01506C87   6A 00            PUSH 0
01506C89   6A 03            PUSH 3
01506C8B   FF35 D4FF6D01    PUSH DWORD PTR DS : [16DFFD4]; NOBU6HD_.016530F0
01506C91   B9 006B6F01      MOV ECX, NOBU6HD_.016F6B00
01506C96   FF75 08          PUSH DWORD PTR SS : [EBP + 8]
01506C99   E8 12BFFFFF      CALL NOBU6HD_.01502BB0
01506C9E   6A 02            PUSH 2
01506CA0   E8 DBCEF2FF      CALL NOBU6HD_.01433B80
01506CA5   83C4 04          ADD ESP, 4
01506CA8   E8 D33EFEFF      CALL NOBU6HD_.014EAB80
01506CAD   B9 006B6F01      MOV ECX, NOBU6HD_.016F6B00
01506CB2   8BF0             MOV ESI, EAX
01506CB4   E8 779AFFFF      CALL NOBU6HD_.01500730
01506CB9   33C0             XOR EAX, EAX
01506CBB   85F6             TEST ESI, ESI
01506CBD   0F95C0           SETNE AL
01506CC0   5E               POP ESI
01506CC1   5D               POP EBP
01506CC2   C3               RETN
*/

int pCallFromFuncOkCancelDialogAsm = 0x1506C70 - 0x1370000; // 元々TENSHOU.EXE内にあったCALL先
int iResultOfFuncOkCancelDialog = 0;
void FuncOkCancelDialogAsm() {

	__asm {

		PUSHAD
		PUSHFD

	}
	__asm {
		push nb6dialog_message_ptr // ダイアログメッセージ系で使われる場所。無難
		call pCallFromFuncOkCancelDialogAsm
		// 引数なしなのでスタックのずれ込みは無し
		add esp, 0x4
		mov iResultOfFuncOkCancelDialog, eax // 解答の値。
	}

	_asm {
		POPFD
		POPAD
	}
}

// iImageIDとしては0x1ea3など
int FuncOkCancelDialog(char *szMessage) {

	strcpy((char *)nb6dialog_message_ptr, szMessage);
	// TENSHOU.EXE内の関数呼び出し

	// TENSHOU.EXE内の関数呼び出し
	FuncOkCancelDialogAsm();

	return iResultOfFuncOkCancelDialog;
}
















// ニーモニック書き換え用
void WriteAsmJumperOnTenshouExFuncMessageDialog() {
	WriteAsmJumperAndFunc(pCallFromFuncConfirmDialogBottomAsm);
	WriteAsmJumperAndFunc(pCallFromFuncConfirmDialogCenterAsm);
	WriteAsmJumperAndFunc(pCallFromFuncWarningDialogCenterAsm);
	WriteAsmJumperAndFunc(pCallFromFuncInfoDialogCenterAsm);
	WriteAsmJumperAndFunc(pCallFromFuncInfoDialogBottomAsm);
	WriteAsmJumperAndFunc(pCallFromFuncOkCancelDialogAsm);
}
