#pragma once

/*
�x�[�X�A�h���X
00FD1000   56               PUSH ESI


01193BFC   CC               INT3
01193BFD   CC               INT3
01193BFE   CC               INT3
01193BFF   CC               INT3
01193C00   55               PUSH EBP
01193C01   8BEC             MOV EBP, ESP
01193C03   8B45 08          MOV EAX, DWORD PTR SS : [EBP + 8]
01193C06   8B0485 D0173401  MOV EAX, DWORD PTR DS : [EAX * 4 + 13417D0]�@�� �������g���邩�ȁH
01193C0D   5D               POP EBP
01193C0E   C3               RETN
01193C0F   CC               INT3
01193C10   55               PUSH EBP
01193C11   8BEC             MOV EBP, ESP
01193C13   8B55 08          MOV EDX, DWORD PTR SS : [EBP + 8]
01193C16   83FA 23          CMP EDX, 23
01193C19   77 10            JA SHORT NOBU6HD_.01193C2B
01193C1B   8B04D5 70062B01  MOV EAX, DWORD PTR DS : [EDX * 8 + 12B0670]�@�� ���̃A�h���X����N�_
01193C22   8B14D5 74062B01  MOV EDX, DWORD PTR DS : [EDX * 8 + 12B0674]
01193C29   5D               POP EBP
01193C2A   C3               RETN
01193C2B   B8 46C12A01      MOV EAX, NOBU6HD_.012AC146
01193C30   8BD0             MOV EDX, EAX
01193C32   5D               POP EBP
01193C33   C3               RETN
01193C34   CC               INT3
01193C35   CC               INT3
01193C36   CC               INT3
01193C37   CC               INT3
01193C38   CC               INT3


��0x12B0670����̍���

+0x24d0
012B2B40  20 20 90 4D 92 B7 82 CC 92 61 90 B6 20 20 81 69    �M���̒a��  �i
012B2B50  82 50 82 54 82 52 82 53 94 4E 81 6A 20 00 00 00  �P�T�R�S�N�j

+0x24fc
012B2B6C  20 20 20 90 4D 92 B7 8C B3 95 9E 20 20 20 81 69     �M������   �i
012B2B7C  82 50 82 54 82 53 82 55 94 4E 81 6A 20 00 00 00  �P�T�S�U�N�j

+0x2528
012B2B98  20 89 B1 8B B7 8A D4 82 CC 8D 87 90 ED 20 81 69   �����Ԃ̍��� �i
012B2BA8  82 50 82 54 82 55 82 4F 94 4E 81 6A 20 00 00 00  �P�T�U�O�N�j

+0x254c
012B2BBC  20 20 90 4D 92 B7 95 EF 88 CD 96 D4 20 20 81 69    �M����͖�  �i
012B2BCC  82 50 82 54 82 56 82 50 94 4E 81 6A 20 00 00 00  �P�T�V�P�N�j

+0x2588
012B2BF8  20 20 96 7B 94 5C 8E 9B 82 CC 95 CF 20 20 81 69    �{�\���̕�  �i
012B2C08  82 50 82 54 82 57 82 51 94 4E 81 6A 20 00 00 00  �P�T�W�Q�N�j

+0x25a8
012B2C18  20 20 8A D6 83 96 8C B4 91 4F 96 E9 20 20 81 69    �փ����O��  �i
012B2C28  82 50 82 54 82 58 82 58 94 4E 81 6A 20 00 00 00  �P�T�X�X�N�j


*/
struct NB6SCENARIOTITLE {
	char *szTitle1; // �M���̒a��
	char *szTitle5; // �M������
	char *szTitle2; // �����Ԃ̍���
	char *szTitle3; // �M����͖�
	char *szTitle4; // �{�\���̕�
	char *szTitle6; // �փ����O��
};

void SetScenatioTitle(char *pszTitle, char *szNewString);

