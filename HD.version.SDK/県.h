#pragma once

#include "����.h"

public ref class �����^ {
protected:
	int iTodouhukenID;
public:
	�����^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iTodouhukenID; }
	}

	property String^ ���� {
		String^ get();
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

