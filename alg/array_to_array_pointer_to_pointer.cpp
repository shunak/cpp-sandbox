/* 33_01.c 配列の配列と、配列へのポインター */
#include <stdio.h>

int main(void)
{
    /* 要素数 5 の配列の、要素数 2 の char 型配列 */
    char a[][5] = {"abcd", "efgh"};
    /* 要素数 5 の char 型配列へのポインター */
    char(*p)[5] = a;

    puts(
        "char a[][ 5 ]     = { \"abcd\",\"efg\"};\n"
        "char ( * p )[ 5 ] = a\n");

    printf("sizeof( a ) = %d\n", sizeof(a));
    printf("sizeof( p ) = %d\n\n", sizeof(p));
    printf("sizeof( a[ 0 ] ) = %d\n", sizeof(a[0]));
    printf("sizeof( *p     ) = %d\n\n", sizeof(*p));

    printf("a = %p\np = %p\n", a, p);
    printf("a[ 0 ] = %s\n*p     = %s\n", a[0], *p);

    /* a++; */ /* a は配列なのでアドレスは変更出来ない */
    p++;       /* p はポインターなので可 */

    printf("\n加算後\np = %p\n", p);
    printf("a[ 1 ] = %s\n*p     = %s\n", a[1], *p);

    return (0);
}