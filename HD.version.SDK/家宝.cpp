#include "GameDataStruct.h"


家宝情報型::家宝情報型(int i番号)
{
	iKahouID = i番号;
}

String^ 家宝情報型::名称::get() {
	return gcnew String(nb6kahou[iKahouID].name);
}

void 家宝情報型::名称::set(String^ value) {
	string native_value = to_native_string(value);
	if (native_value.size() <= 12) {
		strcpy(nb6kahou[iKahouID].name, native_value.c_str());
	}
}

int 家宝情報型::種類::get() {
	return nb6kahou[iKahouID].type;
}

void 家宝情報型::種類::set(int value) {
	if (列挙::家宝::種類::茶碗 <= value && value <= 列挙::家宝::種類::日葡辞書) {
		// 種類を変更するので一度家宝を外す
		int iBushouID = nb6kahou[iKahouID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].type = value;
											   // 元の人物に付け直す
		ReAttachKahou(iKahouID, iBushouID);
	}
}

int 家宝情報型::画像::get() {
	return nb6kahou[iKahouID].face;
}

void 家宝情報型::画像::set(int value) {
	if (列挙::家宝::画像::茶碗 <= value && value <= 列挙::家宝::画像::香木) {
		nb6kahou[iKahouID].face = value;
	}
}

// 名前が反転してるので、反対の値。
bool 家宝情報型::登場::get() {
	// 未登場なら、false
	if (nb6kahou[iKahouID].bMitojo) {
		return false;
	}
	else {
		return true;
	}
}

void 家宝情報型::登場::set(bool value) {
	// 登場の設定なら
	if (value) {
		nb6kahou[iKahouID].bMitojo = false;
	}
	else {
		nb6kahou[iKahouID].bMitojo = true;
	}
}


bool 家宝情報型::消失::get() {
	return nb6kahou[iKahouID].bLost;
}

void 家宝情報型::消失::set(bool value) {
	nb6kahou[iKahouID].bLost = value;
}

int 家宝情報型::所有武将番号::get()
{
	int attr = nb6kahou[iKahouID].attach;
	if (attr >= 0xFFFF) { return 0xFFFF; }

	attr = attr - 1;
	if (0 <= attr && attr < GAMEDATASTRUCT_BUSHOU_NUM) {
		return attr;
	}

	return 0xFFFF;
}

void 家宝情報型::所有武将番号::set(int value)
{
	int iNewBushouID = value;
	ReAttachKahou(iKahouID, value);
}

int 家宝情報型::等級::get() {
	int value = nb6kahou[iKahouID].param;
	if (1 <= value && value < 10) {
		return 11 - value; // 上昇値が大きいほど、等級の数値は小さい。
	}
	return 0xFFFF; // 未セッティング
}

void 家宝情報型::等級::set(int value) {
	if (1 <= value && value < 10) {
		// 等級を変更するので一度家宝を外す
		int iBushouID = nb6kahou[iKahouID].attach-1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].param = 11 - value; // 等級が小さいほど、上昇値は大きい

		// 元の人物に付け直す
		ReAttachKahou(iKahouID, iBushouID);
	}
}

int 家宝情報型::効果::get() {
	return nb6kahou[iKahouID].param;
}

void 家宝情報型::効果::set(int value) {
	if (1 <= value && value < 10) {

		// 等級を変更するので一度家宝を外す
		int iBushouID = nb6kahou[iKahouID].attach - 1;
		if (iBushouID >= 0xFFFE) { iBushouID = 0xFFFF; }
		ReAttachKahou(iKahouID, 0xFFFF);

		nb6kahou[iKahouID].param = value;

		// 元の人物に付け直す
		ReAttachKahou(iKahouID, iBushouID);
	}
}



家宝リスト情報型::家宝リスト情報型() {
	配列 = gcnew List<家宝情報型^>();
	配列->Clear();
	for (int i = 0; i < GAMEDATASTRUCT_KAHOU_NUM; i++)
	{
		配列->Add(gcnew 家宝情報型(i));
	}
}


int 家宝リスト情報型::Find_家宝番号(String^ 名称) {

	for (int i = 0; i < GAMEDATASTRUCT_KAHOU_NUM; i++) {
		if (名称 == gcnew String(nb6kahou[i].name)) {
			return i;
		}
	}

	return 0xFFFF;
}


