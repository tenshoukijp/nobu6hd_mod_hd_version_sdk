#include "GameDataStruct.h"

‘î•ñŒ^::‘î•ñŒ^(int i”Ô†) {
	iChimeiID = i”Ô†;
}

String^ ‘î•ñŒ^::‘–¼::get() {
	return gcnew String(nb6chimei[iChimeiID].name);
}

void ‘î•ñŒ^::‘–¼::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 6) {
		strcpy(nb6chimei[iChimeiID].name, native_value.c_str());
	}
}

List<int>^ ‘î•ñŒ^::Š‘®é”Ô†ƒŠƒXƒg::get() {
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




‘ƒŠƒXƒgî•ñŒ^::‘ƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<‘î•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_CHIMEI_NUM; i++)
	{
		”z—ñ->Add(gcnew ‘î•ñŒ^(i));
	}

}
