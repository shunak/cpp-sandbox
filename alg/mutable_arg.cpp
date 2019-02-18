/* 46_03.c 可変個の引数 */
#include <stdio.h>
#include <stdarg.h>

/* プロトタイプ宣言 */
void sub(int num, ...);

int main(void)
{
    /* 可変個数の引数部分が省略された場合 */
    printf("sub( 0 )                : ");
    sub(0);
    /* 可変個数の引数が一つの場合 */
    printf("sub( 1, 10 )            : ");
    sub(1, 10);
    /* 可変個数の引数が五つの場合 */
    printf("sub( 5, 1, 2, 3, 4, 5 ) : ");
    sub(5, 1, 2, 3, 4, 5);

    return (0);
}

void sub(int num, ...)
{
    va_list p;
    int i;
    int d; /* 取得した引数の値格納用 */

    if (num <= 0)
    {
        puts("可変個数部分の引数はありません");
        return;
    }

    va_start(p, num); /* 可変個の引数処理開始 */
    for (i = 0; i < num; i++)
    {
        /* 引数の値を指定した型で取得*/
        d = va_arg(p, int);
        printf("%d", d);
    }
    puts("");
    va_end(p); /* 可変個の引数処理終了 */

    return;
}