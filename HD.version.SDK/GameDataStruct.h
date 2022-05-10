#pragma once
#pragma warning ( 3 : 4706 )

#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include "�f�o�b�O�o��.h"
#include "WriteAdmJumperAndReturn.h"
#include "type_limits.h"

using namespace std;


#define GAMEDATASTRUCT_REGISTED_BUSHOU_NUM		1300		// [�o�^�ςݕ�����]
#define GAMEDATASTRUCT_RETSUDEN_NUM				1332		// [��`�̌�]

#define GAMEDATASTRUCT_TENSHOUKI_GANNEN			1454

#define GAMEDATASTRUCT_PLAYERS8_NUM				8			// [��L�̍ő吔�i��������v���C���[�ő吔�j���W]

#define	GAMEDATASTRUCT_BUSHOU_NUM				532

#define	GAMEDATASTRUCT_CASTLE_NUM				214

#define	GAMEDATASTRUCT_CASTLETYPE_NUM			7			// [��̃^�C�v(�䏊�Ƃ��قƂ�)]�̐�

#define	GAMEDATASTRUCT_CHIMEI_NUM				74

#define	GAMEDATASTRUCT_KANI_NUM					250
#define	GAMEDATASTRUCT_KANITYPE_NUM				23			// [���ʎ�ނ̐�] ����ʁ`�]���ʉ� �܂�

#define	GAMEDATASTRUCT_KAHOU_NUM				120
#define	GAMEDATASTRUCT_KAHOUTYPE_NUM			24

#define	GAMEDATASTRUCT_GUNDAN_NUM				214

#define	GAMEDATASTRUCT_DAIMYO_NUM				72

#define GAMEDATASTRUCT_AISHOU_NUM				16			// �����̌� 0�`15

#define	GAMEDATASTRUCT_POSITIONTYPE_NUM			8

#define GAMEDATASTRUCT_SOLDIERMAX_NUM			7			// ���m�������g���� [0:�B��,1:�喼,2:�h�V�`6:���y]

#define GAMEDATASTRUCT_WAR_HEX_UNIT_INFO_NUM	72			// HEX�}�b�v�ɂ����郆�j�b�g�̍ő吔�B1�邩��o�Ă���W�l �~ �P��킠����X��

#define GAMEDATASTRUCT_WAR_JOINT_DAIMYO_HEX_GROUP_INFO_NUM		9			//  �푈�Ɋ֌W����喼�͍ő�X�喼�܂ŁB



#include "GlobalVariable.h"
#include "GameDataStructYear.h"
#include "GameDataStructTurn.h"
#include "GameDataStructPlayer.h"
#include "GameDataStructBushou.h"
#include "GameDataStructGundan.h"
#include "GameDataStructDaimyo.h"
#include "GameDataStructDoumei.h"
#include "GameDataStructCastle.h"
#include "GameDataStructChimei.h"
#include "GameDataStructKahou.h"
#include "GameDataStructKani.h"
#include "GameDataStructYakusyoku.h"
#include "GameDataStructSoba.h"
#include "GameDataStructScenario.h"
#include "GameDataStructSettings.h"

#include "tmath.h"
#include "2DPosition.h"
#include "3DPosition.h"
#include "GameDataStructBattle.h"
#include "GameDataStructBattleHex.h"
#include "GameDataStructBattleTurn.h"

#include "GameDataStructParamMax.h"

#include "GameDataStructHukidashi.h"

#include "GameDataStructBgm.h"
#include "GameDataStructMovie.h"

#include "OnChangeFieldWarTurn.h"

#include "DoBGMPlay.h"
#include "DoCameraMove.h"
#include "DoFade.h"
#include "DoMessageDialog.h"
#include "DoImageDialog.h"
#include "DoSoundPlay.h"








extern NB6YEAR			    *_nb6year;
#define						nb6year					_nb6year[0]

extern NB6TURN			    *_nb6turn;
#define						nb6turn					_nb6turn[0]

extern int					nb6turn_gundan_ptr;		// ����nb6turn.gundan �̃A�h���X���i�[���邽�߂����B(�A�Z���u�����猩�邽��)

extern NB6PLAYERS8		    *nb6players8;

extern NB6BUSHOU			*nb6bushou;
extern NB6BUSHOUNAME		*nb6bushouname;
extern NB6GUNDAN			*nb6gundan;
extern NB6DAIMYO			*nb6daimyo;

extern byte					*nb6doumei;

extern NB6CASTLE			*nb6castle;
extern NB6CASTLEMAX			*nb6castlemax;

extern NB6CHIMEI			*nb6chimei;

extern NB6KAHOU				*nb6kahou;
extern NB6KANI				*nb6kani;

extern NB6SOBA			    *_nb6soba;
#define						 nb6soba				_nb6soba[0]

extern HEX_XY				*_nb6hex_xy;
#define						 nb6hex_xy				_nb6hex_xy[0]

extern NB6FIELD_HEX_ROLE    *_nb6field_hex_role;
#define						 nb6field_hex_role		_nb6field_hex_role[0]
extern NB6FIELD_HEX_UNIT_POS *_nb6field_hex_unit_pos;
#define						 nb6field_hex_unit_pos	_nb6field_hex_unit_pos[0]

extern NB6CASTLE_HEX_ROLE   *_nb6castle_hex_role;
#define						 nb6castle_hex_role		_nb6castle_hex_role[0]
extern NB6CASTLE_HEX_HIGH   *_nb6castle_hex_high;
#define						 nb6castle_hex_high		_nb6castle_hex_high[0]

extern NB6CASTLE_HEX_UNIT_POS *_nb6castle_hex_unit_pos;
#define						 nb6castle_hex_unit_pos	_nb6castle_hex_unit_pos[0]

extern NB6CASTLE_HEX_ROLE   *_nb6fire_hex_role;
#define						 nb6fire_hex_role		_nb6fire_hex_role[0]

extern NB6BUSHOU_HEX_UNIT_INFO *nb6bushou_hex_unit_info;

extern NB6WAR_JOINT_DAIMYO_HEX_GROUP_INFO *nb6war_joint_daimyo_hex_group_info;

extern NB6WAR_BATTLE_DAIMYO_INFO *_nb6war_battle_daimyo_info;
#define						      nb6war_battle_daimyo_info		_nb6war_battle_daimyo_info[0]


extern NB6PARAMMAX			*_nb6parammax;
#define						 nb6parammax			_nb6parammax[0]
extern NB6PARAMMAX_MAIN		*_nb6parammax_main;
#define						 nb6parammax_main		_nb6parammax_main[0]
extern NB6SOLDIERMAX		*nb6soldier_max;


extern NB6FUKIDASHIRELATEPERSONS *_nb6fukidashi_relate_persons;
#define							 nb6fukidashi_relate_persons   _nb6fukidashi_relate_persons[0]

extern int						nb6fukidashi_msg_ptr; // �����o���n�̃��b�Z�[�W���������񃁃����ɒ~������|�C���^

extern BYTE					*_nb6weather;
#define						nb6weather   _nb6weather[0]

extern BYTE					*_nb6battle_field_turn;
#define						nb6battle_field_turn	_nb6battle_field_turn[0]

extern int					*nb6bgmdirptr;
extern int					*nb6moviedirptr;

extern NB6BGMTABLE			*nb6bgmtable;
extern NB6BGMTABLE			 nb6bgmdefault[GAMEDATASTRUCT_BGM_FILE_NUM];

extern NB6MOVIETABLE		*nb6movietable;
extern NB6MOVIETABLE		 nb6moviedefault[GAMEDATASTRUCT_MOVIE_FILE_NUM];


extern WORD					*_nb6battle_center_castle;		// �푈�����������ۂɁA�U�߂�ꂽ��(=���̒����̏�)
#define						 nb6battle_center_castle		_nb6battle_center_castle[0]

extern int					nb6textlabel_base_ptr; // ���낢��ȃe�L�X�g���x��������x�[�X�ƂȂ�|�C���^
extern NB6SCENARIOTITLE	    nb6scenariotitle;	   // �U�̃V�i���I�^�C�g���ł���A�V�i���I�^�C�g���̏ꏊ�ł�����B

extern int					nb6dialog_message_ptr;

extern NB6SETTINGS_INGAME	*_nb6settings_ingame;
#define						 nb6settings_ingame		_nb6settings_ingame[0]

extern void SetGameDataStructPointer();



#include "�V�ċL�N���X.h"

