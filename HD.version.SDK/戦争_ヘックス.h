#pragma once

#include "�푈_�w�b�N�X��.h"

public ref class �w�b�N�X���^ {
public:
};


public ref class �w�b�N�X�ʒu�^ : public �c�Q�c�ʒu�^ {
public:
	�w�b�N�X�ʒu�^(double �w�ʒu, double �x�ʒu) {
		this->�w = �w�ʒu;
		this->�x = �x�ʒu;
	}
	�w�b�N�X�ʒu�^() {
		this->�w = 0;
		this->�x = 0;
	}

	property int ���� {
		int get();
	}

	property int ���� {
		int get();
	}

	property int ���� {
		int get();
	}
};

public ref class �w�b�N�X�x�N�g���^ : public �c�Q�c�x�N�g���^ {
public:
	�w�b�N�X�x�N�g���^(double �w����, double �x����) {
		this->�w = �w����;
		this->�x = �x����;
	}
	�w�b�N�X�x�N�g���^() {
		this->�w = 0;
		this->�x = 0;
	}

	property int �Ԋu {
		int get();
	}
};

�w�b�N�X�x�N�g���^^ operator-(�w�b�N�X�ʒu�^^ p1, �w�b�N�X�ʒu�^^ p2);
