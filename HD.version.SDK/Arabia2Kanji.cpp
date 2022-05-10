
#include <stdlib.h>
#include <string.h>

const char *suuji[] = {
    "�Z", "��", "��", "�O", "�l",
    "��", "�Z", "��", "��", "��",
};

const char *keta[] = {
    "�Z",
    "��", "�\", "�S", "��",
    "��", "�\", "�S", "��",
    "��", "�\", "�S", "��",
    "��", "�\", "�S", "��",
};

char *arabia2kanji(const char *arb, char *knj)
{
    unsigned i, kt1, kt2, num, len, flag;
    char *sav = knj;
    *knj = '\0';
    flag = 0;
    len = strlen(arb);
    if (len < sizeof(keta)/sizeof(keta[0])) {
        for (i=0; i<len; i++) {
            num = *(arb+i) - '0'; /* ���l */
            kt1 = len - i; /* ���ʒu */
            kt2 = kt1 % 4;
            if (num && (num > 1 || kt2 == 1 )) {
                strcat(knj, suuji[num]);
                flag = 1;
            }
            if (kt1 > 1 && (num || kt2 == 1)) {
                if (flag || num == 1) {
                    strcat(knj, keta[kt1]);
                    flag = 1;
                }
            }
            if (kt2 == 1) flag = 0;
        }
    }
    return sav;
}