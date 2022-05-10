#include "GameDataStruct.h"


//��r���Z�q
bool �c�R�c�ʒu�^::operator==(�c�R�c�ʒu�^^ v) {
	return (�w == v->�w) && (�x == v->�x) && (�y == v->�y);
}
bool �c�R�c�ʒu�^::operator!=(�c�R�c�ʒu�^^ v) {
	return (�w != v->�w) || (�x != v->�x) || (�y != v->�y);
}
//������Z�q
�c�R�c�ʒu�^^ �c�R�c�ʒu�^::operator=(�c�R�c�ʒu�^^ v) {
	this->�w = v->�w;
	this->�x = v->�x;
	this->�y = v->�y;
	return this;
}



//*----------------------�����o�֐��̎���--------------------------*//
�c�R�c�x�N�g���^::�c�R�c�x�N�g���^() { �w = �x = �y = 0; }
�c�R�c�x�N�g���^::�c�R�c�x�N�g���^(double �w����, double �x����, double �y����) {
	this->�w = �w����;
	this->�x = �x����;
	this->�y = �y����;
}
�c�R�c�x�N�g���^::�c�R�c�x�N�g���^(�c�R�c�ʒu�^^ pos) {
	this->�w = pos->�w;
	this->�x = pos->�x;
	this->�y = pos->�y;
}
//������Z�q
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator=(�c�R�c�x�N�g���^^ v) {
	this->�w = v->�w;
	this->�x = v->�x;
	this->�y = v->�y;
	return this;
}
//�P�����Z�q
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator+=(�c�R�c�x�N�g���^^ v) {
	this->�w += v->�w;
	this->�x += v->�x;
	this->�y += v->�y;
	return this;
}
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator-=(�c�R�c�x�N�g���^^ v) {
	this->�w -= v->�w;
	this->�x -= v->�x;
	this->�y -= v->�y;
	return this;
}
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator*=(double k) {
	this->�w *= k;
	this->�x *= k;
	this->�y *= k;
	return this;
}
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator/=(double k) {
	this->�w /= k;
	this->�x /= k;
	this->�y /= k;
	return this;
}
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator+() {		//+�c�R�c�x�N�g���^
	return this;
}
�c�R�c�x�N�g���^^ �c�R�c�x�N�g���^::operator-() {		//-�c�R�c�x�N�g���^
	return gcnew �c�R�c�x�N�g���^(-�w, -�x, -�y);
}
//�Y�������Z�q
double �c�R�c�x�N�g���^::operator[](int i) {
	if (i == 0) {
		return �w;
	}
	else if (i == 1) {
		return �x;
	}
	else if (i == 2) {
		return �y;
	}
	else {
		return �w;
	}
}
//��r���Z�q
bool �c�R�c�x�N�g���^::operator==(�c�R�c�x�N�g���^^ v) {
	return (�w == v->�w) && (�x == v->�x) && (�y == v->�y);
}
bool �c�R�c�x�N�g���^::operator!=(�c�R�c�x�N�g���^^ v) {
	return (�w != v->�w) || (�x != v->�x) || (�y != v->�y);
}
//�׃N�g���̒���
double �c�R�c�x�N�g���^::����::get() {
	return System::Math::Pow((double)(�w*�w + �x*�x + �y*�y), (double)0.5f);
}
//���K��(�P�ʃx�N�g����)
void �c�R�c�x�N�g���^::���K��() {
	if (���� == 0) {
		�f�o�b�O�o�� << "�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B" << endl;
		this->�w = 0;
		this->�x = 0;
		this->�y = 0;
	}
	else {
		this->�w /= ����;
		this->�x /= ����;
		this->�y /= ����;
	}
}
//*----------------------�O���[�o���֐��̎���--------------------------*//
//�񍀉��Z�q�̒�`
//�c�R�c�x�N�g���^+�c�R�c�x�N�g���^
�c�R�c�x�N�g���^^ operator+(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v) {
	�c�R�c�x�N�g���^^ w = gcnew �c�R�c�x�N�g���^();
	w->�w = u->�w + v->�w;
	w->�x = u->�x + v->�x;
	w->�y = u->�y + v->�y;
	return w;
}
//�c�R�c�x�N�g���^-�c�R�c�x�N�g���^
�c�R�c�x�N�g���^^ operator-(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v) {
	�c�R�c�x�N�g���^^ w = gcnew �c�R�c�x�N�g���^();
	w->�w = u->�w - v->�w;
	w->�x = u->�x - v->�x;
	w->�y = u->�y - v->�y;
	return w;
}
//double*�c�R�c�x�N�g���^
�c�R�c�x�N�g���^^ operator*(double k, �c�R�c�x�N�g���^^ v) {
	return gcnew �c�R�c�x�N�g���^(k*v->�w, k*v->�x, k*v->�y);
}
//�c�R�c�x�N�g���^*double
�c�R�c�x�N�g���^^ operator*(�c�R�c�x�N�g���^^ v, double k) {
	return gcnew �c�R�c�x�N�g���^(v->�w*k, v->�x*k, v->�y*k);
}
//�c�R�c�x�N�g���^/double
�c�R�c�x�N�g���^^ operator/(�c�R�c�x�N�g���^^ v, double k) {
	return gcnew �c�R�c�x�N�g���^(v->�w / k, v->�x / k, v->�y / k);
}
//���� �c�R�c�x�N�g���^*�c�R�c�x�N�g���^
double operator*(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v) {
	return u->�w*v->�w + u->�x*v->�x + u->�y*v->�y;
}
//�O�� �c�R�c�x�N�g���^%�c�R�c�x�N�g���^
�c�R�c�x�N�g���^^ operator%(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v) {
	�c�R�c�x�N�g���^^ w = gcnew �c�R�c�x�N�g���^();
	w->�w = u->�x*v->�y - u->�y*v->�x;
	w->�x = u->�y*v->�w - u->�w*v->�y;
	w->�y = u->�w*v->�x - u->�x*v->�w;
	return w;
}

//�Q�̃x�N�g���̂Ȃ��p
double �p�x(�c�R�c�x�N�g���^^ u, �c�R�c�x�N�g���^^ v) {
	double cos = u*v / (u->����*v->����);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//�Q�_�ԍ��W�̍�
�c�R�c�x�N�g���^^ operator-(�c�R�c�ʒu�^^ p1, �c�R�c�ʒu�^^ p2) {
	�c�R�c�x�N�g���^^ v = gcnew �c�R�c�x�N�g���^();
	v->�w = p1->�w - p2->�w;
	v->�x = p1->�x - p2->�x;
	v->�y = p1->�y - p2->�y;
	return v;
}
