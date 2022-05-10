#include "GameDataStruct.h"


Š¯ˆÊî•ñŒ^::Š¯ˆÊî•ñŒ^(int i”Ô†)
{
	iKaniID = i”Ô†;
}


String^ Š¯ˆÊî•ñŒ^::Š¯ˆÊ–¼::get() {
	return gcnew String(nb6kani[iKaniID].name);
}
void Š¯ˆÊî•ñŒ^::Š¯ˆÊ–¼::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 12) {
		strcpy(nb6kani[iKaniID].name, native_value.c_str());
	}
}

int Š¯ˆÊî•ñŒ^::Š—L•«”Ô†::get()
{
	int attr = nb6kani[iKaniID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void Š¯ˆÊî•ñŒ^::Š—L•«”Ô†::set(int value)
{
	int iNewBushouID = value;
	ReAttachKani(iKaniID, value);
}



int Š¯ˆÊî•ñŒ^::ˆÊŠK::get() {
	return nb6kani[iKaniID].rank;
}

void Š¯ˆÊî•ñŒ^::ˆÊŠK::set(int value) {
	if (—ñ‹“::Š¯ˆÊ::ˆÊŠK::³ˆêˆÊ <= value && value < —ñ‹“::Š¯ˆÊ::ˆÊŠK::³”ªˆÊã) {

		// “™‹‰‚ğ•ÏX‚·‚é‚Ì‚Åˆê“x‰Æ•ó‚ğŠO‚·
		int iBushouID = nb6kani[iKaniID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		// ’©’ì‚Éˆê’U–ß‚·
		ReAttachKani(iKaniID, 0xFFFF);

		nb6kani[iKaniID].rank = value;

		// Œ³‚Ìl•¨‚É•t‚¯’¼‚·
		ReAttachKani(iKaniID, iBushouID);

	}
}

String^ Š¯ˆÊî•ñŒ^::ˆÊŠK–¼::get() {
	int rank = nb6kani[iKaniID].rank;
	return gcnew String(getKaniTypeName(rank));
}

int Š¯ˆÊî•ñŒ^::Œø‰Ê::get() {
	return nb6kani[iKaniID].param;
}

void Š¯ˆÊî•ñŒ^::Œø‰Ê::set(int value) {
	if (0 <= value && value < LIMIT_CHAR_MAX) {

		int iBushouID = nb6kani[iKaniID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		// ’©’ì‚Éˆê’U–ß‚·
		ReAttachKani(iKaniID, 0xFFFF);

		nb6kani[iKaniID].param = value;

		// Œ³‚Ìl•¨‚É•t‚¯’¼‚·
		ReAttachKani(iKaniID, iBushouID);
	}
}



Š¯ˆÊƒŠƒXƒgî•ñŒ^::Š¯ˆÊƒŠƒXƒgî•ñŒ^() {
	”z—ñ = gcnew List<Š¯ˆÊî•ñŒ^^>();
	”z—ñ->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_KANI_NUM; i++)
	{
		”z—ñ->Add(gcnew Š¯ˆÊî•ñŒ^(i));
	}

}


int Š¯ˆÊƒŠƒXƒgî•ñŒ^::Find_Š¯ˆÊ”Ô†(String^ Š¯ˆÊ–¼) {

	for (int i = 0; i < GAMEDATASTRUCT_KANI_NUM; i++) {
		if (Š¯ˆÊ–¼ == gcnew String(nb6kani[i].name)) {
			return i;
		}
	}

	return 0xFFFF;
}

