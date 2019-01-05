/* 37_01a.c 複数ファイルでの外部変数の共用 */
#include <stdio.h>

/* 外部変数の定義と初期化 */
char gbl_s[] = "abcdef";

/* プロトタイプ宣言 */
void sub(void);

int main(void)
{
    printf("main : gbl_s = %s\n", gbl_s);
    sub();
    printf("main : gbl_s = %s\n", gbl_s);
    return (0);
}