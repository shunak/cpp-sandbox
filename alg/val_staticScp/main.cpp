/* 37_03a.c 外部変数の static 指定 */
#include <stdio.h>
/* static指定すると、ファイル内だけのスコープになる*/
/* 外部変数定義 */
static int gbl_i = 20;

/* プロトタイプ宣言 */
void sub(void);

int main(void)
{
    printf("main : gbl_i = %d\n", gbl_i++);
    sub();
    printf("main : gbl_i = %d\n", gbl_i++);

    return 0;
}