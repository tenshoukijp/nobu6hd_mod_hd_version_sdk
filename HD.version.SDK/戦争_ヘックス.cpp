#include "GameDataStruct.h"

�w�b�N�X�x�N�g���^^ operator-(�w�b�N�X�ʒu�^^ p1, �w�b�N�X�ʒu�^^ p2) {
	�w�b�N�X�x�N�g���^^ v = gcnew �w�b�N�X�x�N�g���^();
	v->�w = p1->�w - p2->�w;
	v->�x = p1->�x - p2->�x;
	return v;
}


int �w�b�N�X�ʒu�^::����::get() {
	HEX_POSITION p;
	p.x = this->�w;
	p.y = this->�x;

	if (Is_FieldWar()) {
		return GetFieldHexRole(p);
	}
	else if (Is_CastleWar()) {
		return GetCastleHexRole(p);
	}
	else {
		return 0;
	}
}

int �w�b�N�X�ʒu�^::����::get() {
	HEX_POSITION p;
	p.x = this->�w;
	p.y = this->�x;

	if (Is_FieldWar()) {
		return GetFieldHexHigh(p);
	}
	else if (Is_CastleWar()) {
		return GetCastleHexHigh(p);
	}
	else {
		return 0;
	}
}

int �w�b�N�X�ʒu�^::����::get() {
	HEX_POSITION p;
	p.x = this->�w;
	p.y = this->�x;

	if (Is_FieldWar()) {
		return 0;
	}
	else if (Is_CastleWar()) {
		return GetFireHexRole(p);
	}
	else {
		return 0;
	}
}


int �w�b�N�X�x�N�g���^::�Ԋu::get() {
	HEX_POSITION p1(0, 0);
	HEX_POSITION p2(this->�w, this->�x);
	int distance = getHexDistance(p1, p2);
	return distance;
}