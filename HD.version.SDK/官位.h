#pragma once

#include "Š¯ˆÊ—ñ‹“.h"

public ref class Š¯ˆÊî•ñŒ^ {
protected:
	int iKaniID;
public:
	Š¯ˆÊî•ñŒ^(int i”Ô†);

	property int ”Ô† {
		int get() { return iKaniID; }
	}

	property String^ Š¯ˆÊ–¼ {
		String^ get();
		void set(String^ value);
	}

	/// <summary>—ñ‹“</summary>
	property int ˆÊŠK {
		int get();
		void set(int value);
	}

	property String^ ˆÊŠK–¼ {
		String^ get();
	}

	property int Š—L•«”Ô† {
		int get();
		void set(int value);
	}

	property int Œø‰Ê {
		int get();
		void set(int value);
	}
};


public ref class Š¯ˆÊƒŠƒXƒgî•ñŒ^
{
public:
	Š¯ˆÊƒŠƒXƒgî•ñŒ^();

	List<Š¯ˆÊî•ñŒ^^>^ ”z—ñ;

	int Find_Š¯ˆÊ”Ô†(String^ Š¯ˆÊ–¼);
};

