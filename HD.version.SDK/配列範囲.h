#pragma once

inline bool Is_Contains(System::Collections::ICollection^ list, int 番号) {
	if (0 <= 番号 && 番号 < list->Count) {
		return true;
	}
	return false;
}
inline bool Is_Contains(int 番号, System::Collections::ICollection^ list) {
	if (0 <= 番号 && 番号 < list->Count) {
		return true;
	}
	return false;
}
