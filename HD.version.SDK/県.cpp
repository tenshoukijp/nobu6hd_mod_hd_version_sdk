#include "GameDataStruct.h"

Œ§î•ñŒ^::Œ§î•ñŒ^(int i”Ô†) {
	iTodouhukenID = i”Ô†;
}

String^ Œ§î•ñŒ^::Œ§–¼::get() {
	return gcnew String(getTodouhukenName(iTodouhukenID));
}



List<int>^ Œ§î•ñŒ^::Š‘®é”Ô†ƒŠƒXƒg::get() {
	List<int>^ m_list = gcnew List<int>();

	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		int iKenID = getCastleTodouhukenNum(iCastleID);
		if (iKenID == iTodouhukenID) {
			m_list->Add(iCastleID);
		}
	}

	return m_list;
}



Œ§ƒŠƒXƒgî•ñŒ^::Œ§ƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<Œ§î•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i <= —ñ‹“::Œ§::Œ§”Ô†::‰«“êŒ§; i++)
	{
		”z—ñ->Add(gcnew Œ§î•ñŒ^(i));
	}

}
