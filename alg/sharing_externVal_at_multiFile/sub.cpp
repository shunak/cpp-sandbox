/* 37_01b.c 複数ファイルでの外部変数の共用 サブ関数 */
#include <stdio.h>

/* 外部変数の宣言 */
extern char gbl_s[];

/* プロトタイプ宣言 */
void sub(void);

void sub(void)
{
    printf("sub  : gbl_s = %s\n", gbl_s);
    gbl_s[0] = (char)'Z';
    printf("sub  : gbl_s = %s\n", gbl_s);
    return;
}