/* 31_02.c 文字列の配列の配列 百人一首の上・下の句表示 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

/* マクロ定義 */
#define Mac_Kami 0                /* 上の句の要素番号 */
#define Mac_Simo 1                /* 下の句の要素番号 */
#define Mac_ElemKu (Mac_Simo + 1) /* 句の次元の要素個数 */
#define Mac_ElemStr 49          /* 最大文字列長 */

/* プロトタイプ宣言 */
void ku_out(char ku[][Mac_ElemStr]);

int main(void)
{
    char tanka[][Mac_ElemKu][Mac_ElemStr] = {
        {"しのぶれど色に出りけりわが恋は","ものや思ふと人の問ふまで"},
        {"恋すてふわが名はまだき立ちにけり","人知れずこそ思ひそめしか"}
    };
    int max_uta = sizeof(tanka) / sizeof(tanka[0]);
    int i;
    for (i = 0; i < max_uta; i++)
    {
        ku_out(tanka[i]);
    }

    return (0);
}

/* 上の句と下の句を標準出力へ出力 */
#define Mac_MsgFmt "上の句 : %s\n下の句 : %s\n\n"

void ku_out(char ku[][Mac_ElemStr])
{
    printf(Mac_MsgFmt, ku[Mac_Kami], ku[Mac_Simo]);
    return;
}
#undef Mac_MsgFmt