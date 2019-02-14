/* 46_00.c 関数型オブジェクト */
#include <stdio.h>

/* プロトタイプ宣言 */
int add(int a, int b);

int main(void)
{
    int (*f)(int x, int y) = add;

    printf("   add( 2, 3 ) = %d\n", add(2, 3));
    printf("     f( 2, 3 ) = %d\n", f(2, 3));
    printf("(*f  )( 2, 3 ) = %d\n", (*f)(2, 3));
    printf("(&add)( 2, 3 ) = %d\n", (&add)(2, 3));

    return (0);
}

/* 単純加算関数 */
int add(int a, int b)
{
    return (a + b);
}