#pragma once

#pragma pack(1)

#include <cmath>

// ���ʂ̂R�������W�^�B
struct D3D_POSITION {
	D3D_POSITION(double _x, double _y, double _z) : x(_x),y(_y),z(_z) {}
	D3D_POSITION() : x(0),y(0),z(0) {}
	double x;
	double y;
	double z;

	D3D_POSITION& operator=(const D3D_POSITION& v);
    //��r���Z�q
	bool operator==(const D3D_POSITION& v) const;
	bool operator!=(const D3D_POSITION& v) const;
};

// ���ʂ̂R�����x�N�g���^�B
struct D3D_VECTOR {
	//�����o�ϐ�
	double x;
	double y;
	double z;

	//�R���X�g���N�^
	D3D_VECTOR();
	D3D_VECTOR(double x,double y,double z);
	D3D_VECTOR(D3D_POSITION pos);

	//������Z�q
	D3D_VECTOR& D3D_VECTOR::operator=(const D3D_VECTOR& v);
	//�P�����Z�q
	D3D_VECTOR& operator+=(const D3D_VECTOR& v);
	D3D_VECTOR& operator-=(const D3D_VECTOR& v);
	D3D_VECTOR& operator*=(double k);
	D3D_VECTOR& operator/=(double k);
	D3D_VECTOR operator+()const;
	D3D_VECTOR operator-()const;
	//�Y�������Z�q
	double& operator[](int i);
    //��r���Z�q
	bool operator==(const D3D_VECTOR& v) const;
	bool operator!=(const D3D_VECTOR& v) const;
	//�׃N�g���̒���
	double length()const;
	//���K��
	void normalize();
};
//�x�N�g�����Z
//D3D_VECTOR+D3D_VECTOR
D3D_VECTOR operator+(const D3D_VECTOR& u,const D3D_VECTOR& v);
//D3D_VECTOR-D3D_VECTOR
D3D_VECTOR operator-(const D3D_VECTOR& u,const D3D_VECTOR& v);
//double*D3D_VECTOR
D3D_VECTOR operator*(double k,const  D3D_VECTOR& v);
//D3D_VECTOR*double
D3D_VECTOR operator*(const D3D_VECTOR& v,double k);
//D3D_VECTOR/double
D3D_VECTOR operator/(const D3D_VECTOR& v,double k);
//���� D3D_VECTOR*D3D_VECTOR
double operator*(const D3D_VECTOR& u,const D3D_VECTOR& v);
//�O�� D3D_VECTOR%D3D_VECTOR
D3D_VECTOR operator%(const D3D_VECTOR& u,const D3D_VECTOR& v);
//2�̃x�N�g���̂Ȃ��p�x
double angle(const D3D_VECTOR& u,const D3D_VECTOR& v);
// �Q�_�ԍ��W�̍�
D3D_VECTOR operator-(D3D_POSITION &p1, D3D_POSITION &p2);