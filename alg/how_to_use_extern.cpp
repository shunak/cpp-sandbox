/* 37_00.c 外部変数の使用例 */
#include <stdio.h>

/* 外部変数の宣言と定義及び初期化 */
int gbl_i = 20;          /* extern を省略 */
extern int gbl_ext = 30; /* extern を明示的に指定 */

/* プロトタイプ宣言 */
void sub(void);

int main(void)
{
    printf("main : gbl_i = %3d, gbl_ext = %3d\n", gbl_i, gbl_ext);
    gbl_i += 100;
    gbl_ext -= 20;
    sub();
    printf("main : gbl_i = %3d, gbl_ext = %3d\n", gbl_i, gbl_ext);

    return (0);
}

void sub(void)
{
    printf("sub  : gbl_i = %3d, gbl_ext = %3d\n", gbl_i, gbl_ext);
    gbl_i += 200;
    gbl_ext -= 50;

    return;
}