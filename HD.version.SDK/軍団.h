#pragma once

#include "��E��.h"
#include "�R�c��.h"

public ref class �R�c���^ {
protected:
	int iGundanID;
public:
	�R�c���^() {}
	�R�c���^(int i�ԍ�);

	property int �ԍ� {
		int get() { return iGundanID; }
	}

	/// <summary>ix or ��</summary>
	property int ������ԍ� {
		int get();
	}

	property int �R�c��_�����ԍ� {
		int get();
	}

	property int �����喼�ԍ� {
		int get();
	}

	property int �s���� {
		int get();
		void set(int value);
	}

	property int �� {
		int get();
		void set(int value);
	}

	property int �� {
		int get();
		void set(int value);
	}

	property int �n {
		int get();
		void set(int value);
	}

	property int �S�C {
		int get();
		void set(int value);
	}

	property int ���m {
		int get();
	}

	/// <summary>�P�`�W�̔ԍ��̂���</summary>
	property int �C���ԍ� {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int ��E {
		int get();
		void set(int value);
	}

	property List<int>^ ���������ԍ����X�g {
		List<int>^ get();
	}

	property List<int>^ ������ԍ����X�g {
		List<int>^ get();
	}

	/// <summary>�v���C���̎x�z���ɂ���R�c</summary>
	property bool Is_�v���C�������R�c {
		bool get();
	}

	/// <summary>�v���C�������ڑ��삵�Ă���R�c</summary>
	property bool Is_�v���C���S���R�c {
		bool get();
	}

	bool Do_�����喼�ύX(int �喼�ԍ�);


	ref class �푈�R�c���^ {
	protected:
		int iGundanID;
	public:
		�푈�R�c���^(int i�ԍ�) { iGundanID = i�ԍ�; }

		property int ���叫_�����ԍ� {
			int get();
		}

		/// <summary>��</summary>
		property int �Q�헧�� {
			int get();
		}

	};
	
	�푈�R�c���^^ �푈;
};


public ref class �R�c���X�g���^
{
public:
	�R�c���X�g���^();

	List<�R�c���^^>^ �z��;

	property List<int>^ �L���R�c�ԍ����X�g{
		List<int>^ get();
	}

	ref class �푈�R�c���X�g���^ {
	public:
		property List<int>^ �Q��R�c�ԍ����X�g {
			List<int>^ get();
		}
	};
	
	�푈�R�c���X�g���^ ^�푈;

};

