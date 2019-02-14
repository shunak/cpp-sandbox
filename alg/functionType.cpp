/* 46_01.c 関数型の型定義 */
#include <stdio.h>

/* プロトタイプ宣言 */
int mul(int a, int b);

/* 型定義 */
typedef int (*Tf)(int a, int b);

int main(void)
{
    Tf f = mul;

    printf("mul( 2, 3 ) = %d\n", mul(2, 3));
    printf("  f( 2, 3 ) = %d\n", f(2, 3));

    return (0);
}

/* 単純乗算関数 */
int mul(int a, int b)
{
    return (a * b);
}