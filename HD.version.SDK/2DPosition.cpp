#include "GameDataStruct.h"

//��r���Z�q
bool D2D_POSITION::operator==(const D2D_POSITION& v ) const{
    return (x == v.x) && (y == v.y);
}
bool D2D_POSITION::operator!=(const D2D_POSITION& v ) const{
    return !(*this == v);
}
//������Z�q
D2D_POSITION& D2D_POSITION::operator=(const D2D_POSITION& v){
	this->x=v.x;
	this->y=v.y;
	return *this;
}


//�R���X�g���N�^
D2D_VECTOR::D2D_VECTOR() { x = y = 0; }

D2D_VECTOR::D2D_VECTOR(double x,double y){
	this->x=x;
	this->y=y;
}

D2D_VECTOR::D2D_VECTOR(D2D_POSITION pos) {
	this->x=pos.x;
	this->y=pos.y;
}

//������Z�q
D2D_VECTOR& D2D_VECTOR::operator=(const D2D_VECTOR& v){
	this->x=v.x;
	this->y=v.y;
	return *this;
}
//�P�����Z�q
D2D_VECTOR& D2D_VECTOR::operator+=(const D2D_VECTOR& v){
	this->x += v.x;
	this->y += v.y;
	return *this;
}
D2D_VECTOR& D2D_VECTOR::operator-=(const D2D_VECTOR& v){
	this->x -= v.x;
	this->y -= v.y;
	return *this;
}
D2D_VECTOR& D2D_VECTOR::operator*=(double k){
	this->x *= k;
	this->y *= k;
	return *this;
}
D2D_VECTOR& D2D_VECTOR::operator/=(double k){
	this->x /= k;
	this->y /= k;
	return *this;
}
D2D_VECTOR D2D_VECTOR::operator+()const{		//+D2D_VECTOR
	return *this;
}
D2D_VECTOR D2D_VECTOR::operator-()const{		//-D2D_VECTOR
	return D2D_VECTOR(-x,-y);
}
//�Y�������Z�q
double& D2D_VECTOR::operator[](int i){
	if(i == 0){
		return x;
	}
	else if(i == 1){
		return y;
	}
	else{
		return x;
	}
}
//��r���Z�q
bool D2D_VECTOR::operator==(const D2D_VECTOR& v ) const{
    return (x == v.x) && (y == v.y);
}
bool D2D_VECTOR::operator!=(const D2D_VECTOR& v ) const{
    return !(*this == v);
}
//�׃N�g���̒���
double D2D_VECTOR::length()const{
	return pow(x*x+y*y,(double)0.5);
}
//���K��
void D2D_VECTOR::normalize(){

	if ( length() == 0 ) {
		MessageBox(NULL, "�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B","�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B", NULL);
	}

	*this /= length();
}
//*----------------------�O���[�o���֐��̎���--------------------------*//
//�񍀉��Z�q�̒�`
//D2D_VECTOR+D2D_VECTOR
D2D_VECTOR operator+(const D2D_VECTOR& u,const D2D_VECTOR& v){
	D2D_VECTOR w;
	w.x=u.x+v.x;
	w.y=u.y+v.y;
	return w;
}
//D2D_VECTOR-D2D_VECTOR
D2D_VECTOR operator-(const D2D_VECTOR& u,const D2D_VECTOR& v){
	D2D_VECTOR w;
	w.x=u.x-v.x;
	w.y=u.y-v.y;
	return w;
}
//double*D2D_VECTOR
D2D_VECTOR operator*(double k,const  D2D_VECTOR& v){
	return D2D_VECTOR(k*v.x,k*v.y);
}
//D2D_VECTOR*double
D2D_VECTOR operator*(const D2D_VECTOR& v,double k){
	return D2D_VECTOR(v.x*k,v.y*k);
}
//D2D_VECTOR/double
D2D_VECTOR operator/(const D2D_VECTOR& v,double k){
	return D2D_VECTOR(v.x/k,v.y/k);
}
//���� D2D_VECTOR*D2D_VECTOR
double operator*(const D2D_VECTOR& u,const D2D_VECTOR& v){
	return u.x*v.x+u.y*v.y;
}
//�O�� D2D_VECTOR%D2D_VECTOR
double operator%(const D2D_VECTOR& u,const D2D_VECTOR& v){
	D2D_VECTOR w;
	return u.x*v.y - u.y*v.x;
}

//�Q�̃x�N�g���̂Ȃ��p
double angle(const D2D_VECTOR& u,const D2D_VECTOR& v){
	double cos =u*v/(u.length()*v.length());
	return double(acos(cos)/M_PI*180);
}

//�Q�_�ԍ��W�̍�
D2D_VECTOR operator-(D2D_POSITION &p1, D2D_POSITION &p2) {
	D2D_VECTOR v;
	v.x = p1.x - p2.x;
	v.y = p1.y - p2.y;
	return v;
}