#pragma once

#include "����.h"

public ref class �����^ {
protected:
	int iChimeiID;
public:
	�����^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iChimeiID; }
	}

	property String^ ���� {
		String^ get();
		void set(String^ value);
	}

	property List<int>^ ������ԍ����X�g {
		List<int>^ get();
	}

};


public ref class �����X�g���^
{
public:
	�����X�g���^();

	List<�����^^>^ �z��;
};

