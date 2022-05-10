#pragma once

#include "‰Æ•ó—ñ‹“.h"

public ref class ‰Æ•óî•ñŒ^ {
protected:
	int iKahouID;
public:

	‰Æ•óî•ñŒ^(int i”Ô†);

	property int ”Ô† {
		int get() { return iKahouID; }
	}

	property String^ –¼Ì {
		String^ get();
		void set(String^ value);
	}

	/// <summary>—ñ‹“</summary>
	property int í—Ş {
		int get();
		void set(int value);
	}

	/// <summary>—ñ‹“</summary>
	property int ‰æ‘œ {
		int get();
		void set(int value);
	}

	property int Š—L•«”Ô† {
		int get();
		void set(int value);
	}

	property bool “oê {
		bool get();
		void set(bool value);
	}

	property bool Á¸ {
		bool get();
		void set(bool value);
	}

	property int “™‹‰ {
		int get();
		void set(int value);
	}

	property int Œø‰Ê {
		int get();
		void set(int value);
	}
};


public ref class ‰Æ•óƒŠƒXƒgî•ñŒ^
{
public:
	‰Æ•óƒŠƒXƒgî•ñŒ^();

	List<‰Æ•óî•ñŒ^^>^ ”z—ñ;

	int Find_‰Æ•ó”Ô†(String^ –¼Ì);
};

