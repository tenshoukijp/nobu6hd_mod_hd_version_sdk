#pragma once

#include "���.h"

#include "��ʒu.h"

public ref class ����^ {
protected:
	int iCastleID;
public:
	����^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iCastleID; }
	}

	property String^ �閼 {
		String^ get();
		void set(String^);
	}

	property String^ ��� {
		String^ get();
	}

	// �閼+���
	property String^ �閼�� {
		String^ get();
	}

	property int ���_�����ԍ� {
		int get();
	}

	property int �����R�c�ԍ� {
		int get();
	}

	property List<int>^ ���������ԍ����X�g {
		List<int>^ get();
	}

	// �R�c���̖{��������͑喼�̖{��
	property bool Is_�R�c���{�� {
		bool get();
	}

	// �喼�̖{��
	property bool Is_�喼�{�� {
		bool get();
	}

	property int ��s {
		int get();
		void set(int value);
	}

	property int �΍� {
		int get();
		void set(int value);
	}

	property int �ő�΍� {
		int get();
		void set(int value);
	}

	property int ���� {
		int get();
		void set(int value);
	}

	property int �ő古�� {
		int get();
		void set(int value);
	}

	property int �l�� {
		int get();
		void set(int value);
	}

	property int ���� {
		int get();
		void set(int value);
	}


	property int ������ {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int ���� {
		int get();
		void set(int value);
	}

	property int ���m {
		int get();
	}

	property bool �b�� {
		bool get();
		void set(bool value);
	}

	property bool �n�Y�n {
		bool get();
		void set(bool value);
	}

	property bool �` {
		bool get();
		void set(bool value);
	}

	property bool ���ۍ` {
		bool get();
		void set(bool value);
	}

	property bool ��R {
		bool get();
		void set(bool value);
	}

	property bool ���R {
		bool get();
		void set(bool value);
	}

	property bool ���� {
		bool get();
		void set(bool value);
	}

	property bool �Ꝅ� {
		bool get();
		void set(bool value);
	}

	/// <summary>��</summary>
	property int ��G�w�i {
		int get();
		void set(int value);
	}

	/// <summary>ix or ��</summary>
	property int �������ԍ� {
		int get();
	}

	/// <summary>ix or ��</summary>
	property int �������ԍ� {
		int get();
	}

	property ��ʒu�^^ �ʒu {
		��ʒu�^^ get();
		void set(��ʒu�^^ value);
	}

	property ��O���b�h�ʒu�^^ �O���b�h�ʒu {
		��O���b�h�ʒu�^^ get();
	}

	bool Is_�א�(int ��a�ԍ�);

	property List<int>^ �אڏ�ԍ����X�g {
		List<int>^ get();
	};
	property List<int>^ �o�H�אڏ�ԍ����X�g {
		List<int>^ get();
	}

};




public ref class �郊�X�g���^
{
public:
	�郊�X�g���^();

	List<����^^>^ �z��;

	List<int>^ Get_�o�H��̏�ԍ����X�g(int �J�n��ԍ�, int �ړI��ԍ�);
	List<int>^ Get_�o�H��̏�ԍ����X�g(int �J�n��ԍ�, int �ړI��ԍ�, List<int>^ �o�H�\�z������ԍ����X�g);
};

