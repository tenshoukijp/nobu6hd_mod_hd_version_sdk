#pragma once

#include "�喼��.h"
#include "��E��.h"

public ref class �喼���^ {
protected:
	int iDaimyoID;
public:
	�喼���^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iDaimyoID; }
	}

	property int �喼_�����ԍ� {
		int get();
	}

	/// <summary>ix or ��</summary>
	property int ����ԍ� {
		int get();
	}

	property int �Ɩ�ԍ� {
		int get();
		void set(int value);
	}

	property int �G�Α喼�ԍ� {
		int get();
		void set(int value);
	}

	property int �F�D�喼�ԍ� {
		int get();
		void set(int value);
	}

	property int ����F�D�x {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int ��p���l {
		int get();
		void set(int value);
	}

	property int ���l�F�D�x {
		int get();
		void set(int value);
	}

	property bool ���l�s�� {
		bool get();
		void set(bool value);
	}

	property bool �z���� {
		bool get();
		void set(bool value);
	}

	property bool �]��� {
		bool get();
		void set(bool value);
	}

	int Get_�F�D�֌W(int �喼�ԍ�);
	void Set_�F�D�֌W(int �喼�ԍ�, int �F�D�l);
	void Set_�����֌W(int �喼�ԍ�);
	void Set_�����֌W(int �喼�ԍ�);
	bool Is_�����֌W(int �喼�ԍ�);
	bool Is_�����֌W(int �喼�ԍ�);

	property List<int>^ �����R�c�ԍ����X�g {
		List<int>^ get();
	}
	property List<int>^ ������ԍ����X�g {
		List<int>^ get();
	}
	property List<int>^ �����όR�c�C���ԍ����X�g {
		List<int>^ get();
	}
	property List<int>^ �������R�c�C���ԍ����X�g {
		List<int>^ get();
	}

	/// <summary>��</summary>
	property int ��E {
		int get();
		void set(int value);
	}

	property bool Is_�v���C���S���喼 {
		bool get();
	}

};


public ref class �喼���X�g���^
{
public:
	�喼���X�g���^();

	List<�喼���^^>^ �z��;

	property List<int>^ �L���喼�ԍ����X�g {
		List<int>^ get();
	}

	ref class �푈�喼���X�g���^ {
	public:
		property List<int>^ �Q��喼�ԍ����X�g {
			List<int>^ get();
		}
	};
	
	�푈�喼���X�g���^ ^�푈;

};

