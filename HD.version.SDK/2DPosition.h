#pragma once

#pragma pack(1)

#include <cmath>

// ���ʂ̂Q�������W�^�B
struct D2D_POSITION {
	D2D_POSITION(double _x, double _y) : x(_x),y(_y) {}
	D2D_POSITION() : x(0),y(0) {}
	double x;
	double y;


	D2D_POSITION& operator=(const D2D_POSITION& v);
    //��r���Z�q
	bool operator==(const D2D_POSITION& v) const;
	bool operator!=(const D2D_POSITION& v) const;
};

// ���ʂ̂Q�����x�N�g���^�B
struct D2D_VECTOR {
	//�����o�ϐ�
	double x;
	double y;
	//�R���X�g���N�^
	D2D_VECTOR();
	D2D_VECTOR(double x,double y);
	D2D_VECTOR(D2D_POSITION pos);

	//������Z�q
	D2D_VECTOR& D2D_VECTOR::operator=(const D2D_VECTOR& v);
	//�P�����Z�q
	D2D_VECTOR& operator+=(const D2D_VECTOR& v);
	D2D_VECTOR& operator-=(const D2D_VECTOR& v);
	D2D_VECTOR& operator*=(double k);
	D2D_VECTOR& operator/=(double k);
	D2D_VECTOR operator+()const;
	D2D_VECTOR operator-()const;
	//�Y�������Z�q
	double& operator[](int i);
    //��r���Z�q
	bool operator==(const D2D_VECTOR& v) const;
	bool operator!=(const D2D_VECTOR& v) const;
	//�׃N�g���̒���
	double length()const;
	//���K��
	void normalize();
};
//�x�N�g�����Z
//D2D_VECTOR+D2D_VECTOR
D2D_VECTOR operator+(const D2D_VECTOR& u,const D2D_VECTOR& v);
//D2D_VECTOR-D2D_VECTOR
D2D_VECTOR operator-(const D2D_VECTOR& u,const D2D_VECTOR& v);
//double*D2D_VECTOR
D2D_VECTOR operator*(double k,const  D2D_VECTOR& v);
//D2D_VECTOR*double
D2D_VECTOR operator*(const D2D_VECTOR& v,double k);
//D2D_VECTOR/double
D2D_VECTOR operator/(const D2D_VECTOR& v,double k);
//���� D2D_VECTOR*D2D_VECTOR
double operator*(const D2D_VECTOR& u,const D2D_VECTOR& v);
//�O�� D2D_VECTOR%D2D_VECTOR
double operator%(const D2D_VECTOR& u,const D2D_VECTOR& v);
//2�̃x�N�g���̂Ȃ��p�x
double angle(const D2D_VECTOR& u,const D2D_VECTOR& v);
// �Q�_�ԍ��W�̍�
D2D_VECTOR operator-(D2D_POSITION &p1, D2D_POSITION &p2);