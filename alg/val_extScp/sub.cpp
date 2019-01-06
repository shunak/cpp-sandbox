/* 37_02b.c 外部変数のスコープ サブ側 */
#include <stdio.h>
#include "scp.h"

/* sub0 関数 : ブロック・スコープ */
void sub0(void)
{
    extern int gbl_i; /* ブロック・スコープの外部変数 */
    printf("sub0 : gbl_i = %d\n", gbl_i);
    gbl_i++;
    // printf("sub0 : gbl_i = %d\n", gbl_i++);
    return;
}

extern int gbl_i; /* ファイル・スコープの外部変数 */

/* sub1 関数 : ファイル・スコープ */
void sub1(void)
{
    printf("sub1 : gbl_i = %d\n", gbl_i);
    gbl_i++;
    // printf("sub1 : gbl_i = %d\n", gbl_i++);
    return;
}

/* sub2 関数 : ファイル・スコープの外部変数と自動変数の関係 */
void sub2(void)
{
    int gbl_i = -2; /* 自動変数 */

    printf("sub2 : gbl_i = %d\n", gbl_i++);
    /* ブロック */
    {
        extern int gbl_i; /* ブロック・スコープの外部変数 */

        printf("ブロックの中 sub2 : gbl_i = %d\n", gbl_i);
        // printf("ブロックの中 sub2 : gbl_i = %d\n", gbl_i++);
    }
    printf("ブロックの外 sub2 : gbl_i = %d\n", gbl_i++);
    return;
}