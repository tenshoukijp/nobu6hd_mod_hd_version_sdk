#pragma once

inline bool Is_Contains(System::Collections::ICollection^ list, int �ԍ�) {
	if (0 <= �ԍ� && �ԍ� < list->Count) {
		return true;
	}
	return false;
}
inline bool Is_Contains(int �ԍ�, System::Collections::ICollection^ list) {
	if (0 <= �ԍ� && �ԍ� < list->Count) {
		return true;
	}
	return false;
}
