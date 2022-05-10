#pragma once

#include <string>

using namespace std;

/*
 * �s���{���̒�`
 */
// http://www.mhlw.go.jp/topics/2007/07/dl/tp0727-1d.pdf


namespace �s���{�� {
	enum {
		�k�C�� = 1,
		�X�� = 2,
		��茧 = 3,
		�{�錧 = 4,
		�H�c�� = 5,
		�R�`�� = 6,
		������ = 7,
		��錧 = 8,
		�Ȗ،� = 9,
		�Q�n�� = 10,
		��ʌ� = 11,
		��t�� = 12,
		�����s = 13,
		�_�ސ쌧 = 14,
		�V���� = 15,
		�x�R�� = 16,
		�ΐ쌧 = 17,
		���䌧 = 18,
		�R���� = 19,
		���쌧 = 20,
		�򕌌� = 21,
		�É��� = 22,
		���m�� = 23,
		�O�d�� = 24,
		���ꌧ = 25,
		���s�{ = 26,
		���{ = 27,
		���Ɍ� = 28,
		�ޗǌ� = 29,
		�a�̎R�� = 30,
		���挧 = 31,
		������ = 32,
		���R�� = 33,
		�L���� = 34,
		�R���� = 35,
		������ = 36,
		���쌧 = 37,
		���Q�� = 38,
		���m�� = 39,
		������ = 40,
		���ꌧ = 41,
		���茧 = 42,
		�F�{�� = 43,
		�啪�� = 44,
		�{�茧 = 45,
		�������� = 46,
		���ꌧ = 47,
	};
}

// ��̓s���{���ԍ��𓾂�
// �s���Ȉ����̏ꍇ�A0xFFFF���Ԃ��Ă���B
int getCastleTodouhukenNum(int iCastleID );

// �s���{���ԍ����s���{�����𓾂�
// �s���Ȉ����̏ꍇ�A""���Ԃ��Ă���B
char* getTodouhukenName(int iTodouhukenNum);
