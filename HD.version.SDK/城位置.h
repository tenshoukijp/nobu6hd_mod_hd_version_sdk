#pragma once

public ref class ��ʒu�^ {
public:
	int �w;
	int �x;
	��ʒu�^(int _x, int _y);
	��ʒu�^() : �w(0), �x(0) {}
};

public ref class ��O���b�h�ʒu�^ {
public:
	int �w;
	int �x;
	��O���b�h�ʒu�^(int _x, int _y);
	��O���b�h�ʒu�^() : �w(0), �x(0) {}
};


public ref class ��O���b�h�x�N�g���^ {
public:
	int �w;
	int �x;
	��O���b�h�x�N�g���^(int �w����, int �x����) : �w(�w����), �x(�x����) {}
	��O���b�h�x�N�g���^() : �w(0), �x(0) {}
};

��O���b�h�x�N�g���^^ operator-(��O���b�h�ʒu�^^ p1, ��O���b�h�ʒu�^^ p2);
