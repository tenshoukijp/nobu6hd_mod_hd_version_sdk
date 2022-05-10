#pragma once

inline bool Is_Contains(System::Collections::ICollection^ list, int ”Ô†) {
	if (0 <= ”Ô† && ”Ô† < list->Count) {
		return true;
	}
	return false;
}
inline bool Is_Contains(int ”Ô†, System::Collections::ICollection^ list) {
	if (0 <= ”Ô† && ”Ô† < list->Count) {
		return true;
	}
	return false;
}
