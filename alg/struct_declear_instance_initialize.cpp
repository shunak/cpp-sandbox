
/* 39_07.c 構造体型の宣言、実体作成、初期化を一文に記述 */
#include <stdio.h>

#define MacFmtX "x.a = %3d, x.b = %3d\n"
#define MacFmtY "y.a = %3d, y.b = %3d\n"

int main(void)
{
    struct tag
    {
        int a;
        int b;
    } x = {20, 100};
    struct tag y;

    printf(MacFmtX, x.a, x.b);
    x.a += 10;
    x.b /= 10;
    y = x;
    printf(MacFmtY, y.a, y.b);

    return (0);
}