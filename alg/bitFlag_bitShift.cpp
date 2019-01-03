/* 35_00.c ビット・フラグとビット・シフト演算 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* マクロ定義 */
#define Mac_MaskLever 0x03 /* レバー・ビット抽出用マスク     */
#define Mac_MaskPower 0x0c /* レバーの強さ  抽出用マスク     */
#define Mac_ShiftPower 2   /* レバーの強さ  抽出用のシフト値 */

#define Mac_LeverRight 0 /* レバー → */
#define Mac_LeverLeft 1  /*        ← */
#define Mac_LeverUp 2    /*        ↑ */
#define Mac_LeverDown 3  /*        ↓ */
#define Mac_MaxLever (Mac_LeverDown + 1)
#define Mac_Power0 0 /* 強さ   微 */
#define Mac_Power1 1 /*        弱 */
#define Mac_Power2 2 /*        中 */
#define Mac_Power3 3 /*        強 */
#define Mac_MaxPower (Mac_Power3 + 1)

/* プロトタイプ宣言 */
unsigned char get_pwlv(void);
void std_out(unsigned char pl, const char *s_p[], const char *s_l[]);

/* main 関数 */
#define Mac_MaxLoop 5

int main(void)
{
    const char *str_pw[] = {"微", "弱", "中", "強"};
    const char *str_lv[] = {"→", "←", "↑", "↓"};
    unsigned char pw_lv; /* レバーの強さと方向 */
    int i;

    srand((unsigned int)time(NULL));
    for (i = 0; i < Mac_MaxLoop; i++)
    {
        pw_lv = get_pwlv();
        std_out(pw_lv, str_pw, str_lv);
    }

    // unsigned char lv; /* レバーの方向 */
    // unsigned char pw; /* レバーの強さ */
    // unsigned char pl; /* レバーの強さと方向の合成値 */

    // lv = (unsigned char)(rand() % Mac_MaxLever);
    // pw = (unsigned char)(rand() % Mac_MaxPower);
    // pl = (unsigned char)((pw << Mac_ShiftPower) | lv);

    // printf("%02X\n",lv);
    // printf("%02X\n",pw);
    // printf("%02X\n",pl);




    return (0);
}
#undef Mac_MaxLoop

/* 力の強さとレバーの方向の値を、乱数を元に生成 */
unsigned char get_pwlv(void)
{
    unsigned char lv; /* レバーの方向 */
    unsigned char pw; /* レバーの強さ */
    unsigned char pl; /* レバーの強さと方向の合成値 */

    lv = (unsigned char)(rand() % Mac_MaxLever);
    pw = (unsigned char)(rand() % Mac_MaxPower);
    pl = (unsigned char)((pw << Mac_ShiftPower) | lv);
    return (pl);
}

/* フラグを元に文字列表示 */
#define Mac_Fmt "値 : %02X\nレバーの方向 : %s\nレバーの強さ : %s\n"

void std_out(unsigned char pl, const char *s_p[], const char *s_l[])
{
    int pw = (pl & Mac_MaskPower) >> Mac_ShiftPower; /* 強さ */
    int lv = pl & Mac_MaskLever;                     /* 方向 */

    printf(Mac_Fmt, pl, s_l[lv], s_p[pw]);
    return;
}
#undef Mac_Fmt