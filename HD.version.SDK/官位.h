#pragma once

#include "���ʗ�.h"

public ref class ���ʏ��^ {
protected:
	int iKaniID;
public:
	���ʏ��^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iKaniID; }
	}

	property String^ ���ʖ� {
		String^ get();
		void set(String^ value);
	}

	/// <summary>��</summary>
	property int �ʊK {
		int get();
		void set(int value);
	}

	property String^ �ʊK�� {
		String^ get();
	}

	property int ���L�����ԍ� {
		int get();
		void set(int value);
	}

	property int ���� {
		int get();
		void set(int value);
	}
};


public ref class ���ʃ��X�g���^
{
public:
	���ʃ��X�g���^();

	List<���ʏ��^^>^ �z��;

	int Find_���ʔԍ�(String^ ���ʖ�);
};

