#include "GameDataStruct.h"

//��r���Z�q
bool �c�Q�c�ʒu�^::operator==(const �c�Q�c�ʒu�^^ v) {
	return (�w == v->�w) && (�x == v->�x);
}
bool �c�Q�c�ʒu�^::operator!=(const �c�Q�c�ʒu�^^ v) {
	return (�w != v->�w) || (�x != v->�x);
}
//������Z�q
�c�Q�c�ʒu�^^ �c�Q�c�ʒu�^::operator=(const �c�Q�c�ʒu�^^ v) {
	this->�w = v->�w;
	this->�x = v->�x;
	return this;
}



//*----------------------�����o�֐��̎���--------------------------*//
�c�Q�c�x�N�g���^::�c�Q�c�x�N�g���^() { �w = �x = 0; }
�c�Q�c�x�N�g���^::�c�Q�c�x�N�g���^(double �w����, double �x����) {
	this->�w = �w����;
	this->�x = �x����;
}
�c�Q�c�x�N�g���^::�c�Q�c�x�N�g���^(�c�Q�c�ʒu�^^ pos) {
	this->�w = pos->�w;
	this->�x = pos->�x;
}

//������Z�q
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator=(�c�Q�c�x�N�g���^^ v) {
	this->�w = v->�w;
	this->�x = v->�x;
	return this;
}
//�P�����Z�q
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator+=(�c�Q�c�x�N�g���^^ v) {
	this->�w += v->�w;
	this->�x += v->�x;
	return this;
}
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator-=(�c�Q�c�x�N�g���^^ v) {
	this->�w -= v->�w;
	this->�x -= v->�x;
	return this;
}
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator*=(double k) {
	this->�w *= k;
	this->�x *= k;
	return this;
}
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator/=(double k) {
	this->�w /= k;
	this->�x /= k;
	return this;
}
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator+() {		//+�c�Q�c�x�N�g���^
	return this;
}
�c�Q�c�x�N�g���^^ �c�Q�c�x�N�g���^::operator-() {		//-�c�Q�c�x�N�g���^
	return gcnew �c�Q�c�x�N�g���^(-�w, -�x);
}
//�Y�������Z�q
double �c�Q�c�x�N�g���^::operator[](int i) {
	if (i == 0) {
		return �w;
	}
	else if (i == 1) {
		return �x;
	}
	else {
		return �w;
	}
}
//��r���Z�q
bool �c�Q�c�x�N�g���^::operator==(�c�Q�c�x�N�g���^^ v) {
	return (�w == v->�w) && (�x == v->�x);
}
bool �c�Q�c�x�N�g���^::operator!=(�c�Q�c�x�N�g���^^ v) {
	return (�w != v->�w) || (�x != v->�x);
}
//�׃N�g���̒���
double �c�Q�c�x�N�g���^::����::get() {
	return System::Math::Pow((double)(�w*�w + �x*�x), (double)0.5f);
}
//���K��(�P�ʃx�N�g����)
void �c�Q�c�x�N�g���^::���K��() {
	if (���� == 0) {
		�f�o�b�O�o�� << "�������O�̃x�N�g��(=�����������x�N�g��)��P�ʃx�N�g�������悤�Ƃ��܂����B�����O���Z�ŃG���[�ƂȂ�܂��B" << endl;
		this->�w = 0;
		this->�x = 0;
	}
	else {
		this->�w /= ����;
		this->�x /= ����;
	}
}
//*----------------------�O���[�o���֐��̎���--------------------------*//
//�񍀉��Z�q�̒�`
//�c�Q�c�x�N�g���^+�c�Q�c�x�N�g���^
�c�Q�c�x�N�g���^^ operator+(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v) {
	�c�Q�c�x�N�g���^^ w = gcnew �c�Q�c�x�N�g���^();
	w->�w = u->�w + v->�w;
	w->�x = u->�x + v->�x;
	return w;
}
//�c�Q�c�x�N�g���^-�c�Q�c�x�N�g���^
�c�Q�c�x�N�g���^^ operator-(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v) {
	�c�Q�c�x�N�g���^^ w = gcnew �c�Q�c�x�N�g���^();
	w->�w = u->�w - v->�w;
	w->�x = u->�x - v->�x;
	return w;
}
//double*�c�Q�c�x�N�g���^
�c�Q�c�x�N�g���^^ operator*(double k, �c�Q�c�x�N�g���^^ v) {
	return gcnew �c�Q�c�x�N�g���^(k*v->�w, k*v->�x);
}
//�c�Q�c�x�N�g���^*double
�c�Q�c�x�N�g���^^ operator*(�c�Q�c�x�N�g���^^ v, double k) {
	return gcnew �c�Q�c�x�N�g���^(v->�w*k, v->�x*k);
}
//�c�Q�c�x�N�g���^/double
�c�Q�c�x�N�g���^^ operator/(�c�Q�c�x�N�g���^^ v, double k) {
	return gcnew �c�Q�c�x�N�g���^(v->�w / k, v->�x / k);
}
//���� �c�Q�c�x�N�g���^*�c�Q�c�x�N�g���^
double operator*(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v) {
	return u->�w*v->�w + u->�x*v->�x;
}

//�O�� �c�Q�c�x�N�g���^%�c�Q�c�x�N�g���^
double operator%(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v) {
	�c�Q�c�x�N�g���^^ w = gcnew �c�Q�c�x�N�g���^();
	return u->�w*v->�x - u->�x*v->�w;
}

//�Q�̃x�N�g���̂Ȃ��p
double �p�x(�c�Q�c�x�N�g���^^ u, �c�Q�c�x�N�g���^^ v) {
	double cos = u*v / (u->����*v->����);
	return double(System::Math::Acos(cos) / System::Math::PI * 180);
}

//�Q�_�ԍ��W�̍�
�c�Q�c�x�N�g���^^ operator-(�c�Q�c�ʒu�^^ p1, �c�Q�c�ʒu�^^ p2) {
	�c�Q�c�x�N�g���^^ v = gcnew �c�Q�c�x�N�g���^();
	v->�w = p1->�w - p2->�w;
	v->�x = p1->�x - p2->�x;
	return v;
}

