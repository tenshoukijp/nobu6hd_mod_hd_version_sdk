#pragma once

#include "�ƕ��.h"

public ref class �ƕ���^ {
protected:
	int iKahouID;
public:

	�ƕ���^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iKahouID; }
	}

	property String^ ���� {
		String^ get();
		void set(String^ value);
	}

	/// <summary>��</summary>
	property int ��� {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int �摜 {
		int get();
		void set(int value);
	}

	property int ���L�����ԍ� {
		int get();
		void set(int value);
	}

	property bool �o�� {
		bool get();
		void set(bool value);
	}

	property bool ���� {
		bool get();
		void set(bool value);
	}

	property int ���� {
		int get();
		void set(int value);
	}

	property int ���� {
		int get();
		void set(int value);
	}
};


public ref class �ƕ󃊃X�g���^
{
public:
	�ƕ󃊃X�g���^();

	List<�ƕ���^^>^ �z��;

	int Find_�ƕ�ԍ�(String^ ����);
};

