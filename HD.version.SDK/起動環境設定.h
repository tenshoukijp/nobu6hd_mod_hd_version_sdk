#pragma once

#include "�N�����ݒ��.h"

public ref class �N�����ݒ���^ {
protected:
	Microsoft::Win32::RegistryKey^ regkey;
public:
	�N�����ݒ���^();
	~�N�����ݒ���^();
	!�N�����ݒ���^();

	/// <summary>��</summary>
	property int �E�B���h�E���[�h {
		int get();
		void set(int value);
	}

	property ���𑜓x�^^ ��ʃT�C�Y {
		���𑜓x�^^ get();
		void set(���𑜓x�^^ value);
	}

	property int �N�����j�^�[ {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int ���[�r�[ {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int �a�f�l {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int ���ʉ� {
		int get();
		void set(int value);
	}

	/// <summary>��</summary>
	property int �J�[�\�����[�h {
		int get();
		void set(int value);
	}

};


