/* 37_02a.c 外部変数のスコープ */
#include "scp.h"

/* 外部変数の定義 */
int gbl_i = 10;

int main(void)
{
    sub0();
    sub1();
    sub2();

    return (0);
}
