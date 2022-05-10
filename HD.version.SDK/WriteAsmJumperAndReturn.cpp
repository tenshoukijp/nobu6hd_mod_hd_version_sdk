#include "GameDataStruct.h"

void WriteAsmJumperAndFunc(int&CallFunc) {
	CallFunc = CallFunc + GlobalVariable::pCurrentProcessBaseAddress;
}

void WriteAsmJumperAndReturn(int NakedFunctionAddress, int &FromJump, int &GoToJump, int iCopyByte) {

	char cmdOnTenshouExeJumpFrom[10] = "\xE9\x90\x90\x90\x90\x90\x90\x90\x90"; // 多めにとっておく

	FromJump = FromJump + GlobalVariable::pCurrentProcessBaseAddress;
	GoToJump = GoToJump + GlobalVariable::pCurrentProcessBaseAddress;

	// まずアドレスを数字として扱う
	int iAddress = (int)NakedFunctionAddress;
	int SubAddress = iAddress - (FromJump + 5);

	// ５というのは、0046C194  -E9 ????????  JMP TSMod.OnTSExeCreateFileA01  の命令に必要なバイト数。要するに５バイト足すと次のニーモニック命令群に移動するのだ。そしてそこからの差分がジャンプする際の目的格として利用される。
	memcpy(cmdOnTenshouExeJumpFrom + 1, &SubAddress, 4); // +1 はE9の次から4バイト分書き換えるから。

														 // 構築したニーモニック命令をTENSHOU.EXEのメモリに書き換える
	WriteProcessMemory(GetCurrentProcess(), (LPVOID)(FromJump), cmdOnTenshouExeJumpFrom, iCopyByte, NULL); //5バイトのみ書き込む
}

void RegisterFunctionsOfWriteAsmJumperAndReturn() {

	// CreateFile01の１つ目
	extern void WriteAsmJumperOnTenshouExeCreateFileA01();
	extern void WriteAsmJumperOnTenshouExeCreateFileA02();
	extern void WriteAsmJumperOnTenshouExeCreateFileA03();
	extern void WriteAsmJumperOnTenshouExeCreateFileA04();
	extern void WriteAsmJumperOnTenshouExeCreateFileA05();
	extern void WriteAsmJumperOnTenshouExeCreateFileA06();
	extern void WriteAsmJumperOnTenshouExeCreateFileA07();
	extern void WriteAsmJumperOnTenshouExeCreateFileA08();
	extern void WriteAsmJumperOnTenshouExeCreateFileA09();
	extern void WriteAsmJumperOnTenshouExeCreateFileA10();
	extern void WriteAsmJumperOnTenshouExeCreateFileA11();
	extern void WriteAsmJumperOnTenshouExeCreateFileA12();

	extern void WriteAsmJumperOnTenshouExeWriteFukidashiMessage01();

	extern void WriteAsmJumperOnTenshouExeBattleStart();
	extern void WriteAsmJumperOnTenshouExeBattleClear();
	extern void WriteAsmJumperOnTenshouExeChangeGundanTurnUndef();
	extern void WriteAsmJumperOnTenshouExeChangeGundanTurn();

	extern void WriteAsmJumperOnTenshouExeFieldWarStart01();
	extern void WriteAsmJumperOnTenshouExeFieldWarStart02();
	extern void WriteAsmJumperOnTenshouExeFieldWarStart03();

	extern void WriteAsmJumperOnTenshouExeChangeFieldWarTurnInit();
	extern void WriteAsmJumperOnTenshouExeChangeFieldWarTurn();

	extern void WriteAsmJumperOnTenshouExeCastleWarStart01();

	extern void WriteAsmJumperOnTenshouExeWarScreenEnd();
	extern void WriteAsmJumperOnTenshouExeHoryoSyogu();

	extern void WriteAsmJumperOnTenshouExeBGMPlayingNumberDecide();
	extern void WriteAsmJumperOnTenshouExeMOVIEPlayingNumberDecide();

	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_01();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_02();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_03();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_04();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_05();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_06();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_07();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_08();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_09();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_10();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_11();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_12();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_13();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_14();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_15();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_16();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_17();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_18();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_19();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_20();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_21();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_22();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_23();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_24();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_25();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_26();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_27();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_28();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_29();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_30();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_31();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_32();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_33();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_34();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_35();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_36();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_37();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_38();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_39();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_40();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_41();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_42();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_43();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_44();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_45();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_46();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_47();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_48();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_49();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_50();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_51();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_52();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_53();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_54();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_55();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_56();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_57();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_58();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_59();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_60();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_61();
	extern void WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_62();

	WriteAsmJumperOnTenshouExeCreateFileA01();
	WriteAsmJumperOnTenshouExeCreateFileA02();
	WriteAsmJumperOnTenshouExeCreateFileA03();
	WriteAsmJumperOnTenshouExeCreateFileA04();
	WriteAsmJumperOnTenshouExeCreateFileA05();
	WriteAsmJumperOnTenshouExeCreateFileA06();
	WriteAsmJumperOnTenshouExeCreateFileA07();
	WriteAsmJumperOnTenshouExeCreateFileA08();
	WriteAsmJumperOnTenshouExeCreateFileA09();
	WriteAsmJumperOnTenshouExeCreateFileA10();
	WriteAsmJumperOnTenshouExeCreateFileA11();
	WriteAsmJumperOnTenshouExeCreateFileA12();

	WriteAsmJumperOnTenshouExeWriteFukidashiMessage01();

	WriteAsmJumperOnTenshouExeBattleStart();
	WriteAsmJumperOnTenshouExeBattleClear();

	WriteAsmJumperOnTenshouExeChangeGundanTurnUndef();
	WriteAsmJumperOnTenshouExeChangeGundanTurn();

	WriteAsmJumperOnTenshouExeFieldWarStart01();
	WriteAsmJumperOnTenshouExeFieldWarStart02();
	WriteAsmJumperOnTenshouExeFieldWarStart03();

	WriteAsmJumperOnTenshouExeChangeFieldWarTurnInit();
	WriteAsmJumperOnTenshouExeChangeFieldWarTurn();

	WriteAsmJumperOnTenshouExeCastleWarStart01();

	WriteAsmJumperOnTenshouExeWarScreenEnd();
	WriteAsmJumperOnTenshouExeHoryoSyogu();

	WriteAsmJumperOnTenshouExeBGMPlayingNumberDecide();
	WriteAsmJumperOnTenshouExeMOVIEPlayingNumberDecide();

	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_01();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_02();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_03();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_04();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_05();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_06();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_07();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_08();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_09();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_10();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_11();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_12();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_13();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_14();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_15();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_16();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_17();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_18();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_19();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_20();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_21();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_22();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_23();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_24();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_25();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_26();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_27();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_28();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_29();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_30();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_31();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_32();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_33();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_34();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_35();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_36();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_37();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_38();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_39();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_40();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_41();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_42();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_43();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_44();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_45();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_46();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_47();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_48();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_49();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_50();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_51();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_52();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_53();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_54();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_55();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_56();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_57();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_58();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_59();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_60();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_61();
	WriteAsmJumperOnTenshouExeCallFuncBGM_LOCATION_62();
}

void ReplaceWrapperCallFunctions() {

	extern void WriteAsmJumperOnTenshouExFuncPlayBGM();
	extern void WriteAsmJumperOnTenshouExFuncMoveCamera();
	extern void WriteAsmJumperOnTenshouExFuncFade();
	extern void WriteAsmJumperOnTenshouExFuncMessageDialog();
	extern void WriteAsmJumperOnTenshouExFuncPlaySound();
	extern void WriteAsmJumperOnTenshouExFuncImageDialog();

	WriteAsmJumperOnTenshouExFuncPlayBGM();
	WriteAsmJumperOnTenshouExFuncMoveCamera();
	WriteAsmJumperOnTenshouExFuncFade();
	WriteAsmJumperOnTenshouExFuncMessageDialog();
	WriteAsmJumperOnTenshouExFuncImageDialog();
	WriteAsmJumperOnTenshouExFuncPlaySound();
}


