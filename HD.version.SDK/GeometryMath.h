#pragma once

#pragma pack(1)

#include "3DPosition.h"
#include "2DPosition.h"


/*-----------------------------------------------------------------
// ����A1x, A1y �� A2x, A2y  ��  ����B1x, B1y �� B2x, B2y  �Ƃ� �Փ˂��邩�ǂ����B
/*-----------------------------------------------------------------*/
bool LineAndLine( double A1x, double A1y, double A2x, double A2y, double B1x, double B1y, double B2x, double B2y );


/*-----------------------------------------------------------------
// �l�p�`�Ɛ����Ƃ̏Փ˂̔���
/-----------------------------------------------------------------*/
bool RectAndLine( double left, double top, double right, double bottom, double x1, double y1, double x2, double y2 );


/*-----------------------------------------------------------------
	���Wpos �ɍł��߂� ����ab��̍��W ���v�Z
  -----------------------------------------------------------------*/
D3D_POSITION GetClosePosToLine( D3D_POSITION pos, D3D_POSITION a, D3D_POSITION b);


/*-----------------------------------------------------------------
	���Wpos �� ����ab �Ƃ̋������v�Z
  -----------------------------------------------------------------*/
double GetDistanceToLine( D3D_POSITION pos, D3D_POSITION a, D3D_POSITION b);


