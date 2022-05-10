#include "GameDataStruct.h"
#include "tmath.h"
#include "GeometryMath.h"
#include <algorithm>
#include <functional>


static D2D_POSITION _StartPosForRoleArrayOfBetweenPosToPos;
static bool _CompareLengthForRoleArrayOfBetweenPosToPos(const HEX_POSITION pos1, const HEX_POSITION pos2 ) {
	// �������v�Z�\�Ȍ`��
	D2D_POSITION p1( pos1.x, pos1.y );
	D2D_POSITION p2( pos2.x, pos2.y );

	// �J�n�_����e�X�̓_�ւ̃x�N�g��
	D2D_VECTOR v1 = p1 - _StartPosForRoleArrayOfBetweenPosToPos;
	D2D_VECTOR v2 = p2 - _StartPosForRoleArrayOfBetweenPosToPos;

	// ����
	return v1.length() < v2.length();
}

// �w�b�N�X�̂`�_�Ƃa�_�̊Ԃɂ���`�b�v�̃A���C��Ԃ��B
vector<int> RoleArrayOfBetweenPosToPos( HEX_POSITION pos1, HEX_POSITION pos2 ) {

	// �l���O���[�o���ϐ��ɃR�s�[�B��Ŕ�r�֐��悤�ɗ��p���邽�߁B
	_StartPosForRoleArrayOfBetweenPosToPos.x = pos1.x;
	_StartPosForRoleArrayOfBetweenPosToPos.y = pos1.y;

	vector<int> arrRoleArray;

	vector< HEX_POSITION > pos_array;

	// �Q�̍��W����傫�ȋ�`���o���B
	double posy_min = pos1.y <= pos2.y ? pos1.y : pos2.y;
	double posy_max = pos1.y >  pos2.y ? pos1.y : pos2.y;
	double posx_min = pos1.x <= pos2.x ? pos1.x : pos2.x;
	posx_min = posx_min - 2; // ���S�̂��߁A�P������`�ɓ����B
	double posx_max = pos1.x >  pos2.x ? pos1.x : pos2.x;
	posx_max = posx_max + 2; // ���S�̂��߁A1�E����`�ɓ����B

	for ( double y = posy_min; y <= posy_max; y++ ) {
		for ( double x = posx_min;  x <= posx_max; x++ ) {
			// Y�������s�ł���
			y = round�s�������t(y);
			x = round�s�񕪂̈�z�����t(x); // 0.5�z����

			if ( (int)y % 2 == 0 ) {
				// x��3.5�Ƃ��Ȃ�3.0�ւƐ�����
				x = (int)x;
				pos_array.push_back( HEX_POSITION( x, y ) );

			// Y����ł���B
			} else {
				// Y����Ȃ�X��2.5�ȂǂłȂ��ƃ_���Ȃ̂ɐ�����������0.5�����B

				// 0.5�Ŋ���Ƌ����ɂȂ�Ƃ������Ƃ́A�����ł���B0.5�𑫂��B
				if ( int(x / 0.5) % 2 == 0 ) {
					x = x + 0.5;
				}

				pos_array.push_back( HEX_POSITION( x, y ) );
			}
		}
	}

	// �|�W�V������pos1����̋����Ń\�[�g
	std::sort(pos_array.begin(),pos_array.end(),_CompareLengthForRoleArrayOfBetweenPosToPos);//��r�֐����w�肵�ă\�[�g

	// �\�[�g���ꂽ�z��𑖍�
	for ( vector<HEX_POSITION>::iterator it = pos_array.begin(); it != pos_array.end(); it++ ) {

		// pos1�Ɠ����Ȃ玟
		if ( it->x == pos1.x && it->y == pos1.y ) {
			continue;
		}

		// pos2�Ɠ����Ȃ玟
		if ( it->x == pos2.x && it->y == pos2.y ) {
			continue;
		}

		// �Y�����W�͂����Ɩ��������邩�ǂ����B
		int role = -1;
		if ( Is_FieldWar() ) {
			role = GetFieldHexRole( it->x, it->y );
		} else if ( Is_CastleWar() ) {
			role = GetCastleHexRole( it->x, it->y );
		}

		// ���̍��W�͖����������Ƃ������Ȃ�΁c
		if ( role != -1 ) {
			// �����ƊY���`�b�v����������Ȃ�΁c
			if ( RectAndLine( it->x-0.6, it->y-0.6, it->x+0.6, it->y+0.6,  pos1.x, pos1.y, pos2.x, pos2.y) ) {
				arrRoleArray.push_back( role );
			}
		}
	}

	// �����s����s���ŁA�킯�Ȃ���A
	// �R���W�����Ƃ��Ă����B
	// �����s�͂w���W�͐����ɂ܂Ƃ߂�B
	// ��s��0.5���܂��Ă�B

	return arrRoleArray;
}