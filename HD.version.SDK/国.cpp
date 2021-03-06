#include "GameDataStruct.h"

国情報型::国情報型(int i番号) {
	iChimeiID = i番号;
}

String^ 国情報型::国名::get() {
	return gcnew String(nb6chimei[iChimeiID].name);
}

void 国情報型::国名::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 6) {
		strcpy(nb6chimei[iChimeiID].name, native_value.c_str());
	}
}

List<int>^ 国情報型::所属城番号リスト::get() {
	List<int>^ m_list = gcnew List<int>();
	if (nb6chimei[iChimeiID].castle1 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle1 - 1);
	}
	if (nb6chimei[iChimeiID].castle2 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle2 - 1);
	}
	if (nb6chimei[iChimeiID].castle3 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle3 - 1);
	}
	if (nb6chimei[iChimeiID].castle4 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle4 - 1);
	}
	if (nb6chimei[iChimeiID].castle5 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle5 - 1);
	}
	if (nb6chimei[iChimeiID].castle6 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle6 - 1);
	}
	if (nb6chimei[iChimeiID].castle7 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle7 - 1);
	}
	if (nb6chimei[iChimeiID].castle8 != 0xFFFF) {
		m_list->Add(nb6chimei[iChimeiID].castle8 - 1);
	}

	return m_list;
}




国リスト情報型::国リスト情報型() {
	配列 = gcnew List<国情報型^>();
	配列->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_CHIMEI_NUM; i++)
	{
		配列->Add(gcnew 国情報型(i));
	}

}
