/* 37_03b.c 外部変数の static 指定 サブ側 */

#include <stdio.h>

/* 外部変数定義 */
static int gbl_i = -100;

/* プロトタイプ宣言 */
void sub(void);

void sub(void)
{
    printf("sub  : gbl_i = %d\n", gbl_i++);
    return;
}
