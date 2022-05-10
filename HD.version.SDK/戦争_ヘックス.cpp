#include "GameDataStruct.h"

ƒwƒbƒNƒXƒxƒNƒgƒ‹Œ^^ operator-(ƒwƒbƒNƒXˆÊ’uŒ^^ p1, ƒwƒbƒNƒXˆÊ’uŒ^^ p2) {
	ƒwƒbƒNƒXƒxƒNƒgƒ‹Œ^^ v = gcnew ƒwƒbƒNƒXƒxƒNƒgƒ‹Œ^();
	v->‚w = p1->‚w - p2->‚w;
	v->‚x = p1->‚x - p2->‚x;
	return v;
}


int ƒwƒbƒNƒXˆÊ’uŒ^::–ðŠ„::get() {
	HEX_POSITION p;
	p.x = this->‚w;
	p.y = this->‚x;

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

int ƒwƒbƒNƒXˆÊ’uŒ^::‚‚³::get() {
	HEX_POSITION p;
	p.x = this->‚w;
	p.y = this->‚x;

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

int ƒwƒbƒNƒXˆÊ’uŒ^::‰Šã::get() {
	HEX_POSITION p;
	p.x = this->‚w;
	p.y = this->‚x;

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


int ƒwƒbƒNƒXƒxƒNƒgƒ‹Œ^::ŠÔŠu::get() {
	HEX_POSITION p1(0, 0);
	HEX_POSITION p2(this->‚w, this->‚x);
	int distance = getHexDistance(p1, p2);
	return distance;
}