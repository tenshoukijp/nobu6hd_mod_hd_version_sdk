#include "GameDataStruct.h"

�����^::�����^(int i�ԍ�) {
	iTodouhukenID = i�ԍ�;
}

String^ �����^::����::get() {
	return gcnew String(getTodouhukenName(iTodouhukenID));
}



List<int>^ �����^::������ԍ����X�g::get() {
	List<int>^ m_list = gcnew List<int>();

	for (int iCastleID = 0; iCastleID < GAMEDATASTRUCT_CASTLE_NUM; iCastleID++) {
		int iKenID = getCastleTodouhukenNum(iCastleID);
		if (iKenID == iTodouhukenID) {
			m_list->Add(iCastleID);
		}
	}

	return m_list;
}



�����X�g���^::�����X�g���^() {
	�z�� = gcnew List<�����^^>();
	�z��->Clear();
	for (int i = 0; i <= ��::��::���ԍ�::���ꌧ; i++)
	{
		�z��->Add(gcnew �����^(i));
	}

}
