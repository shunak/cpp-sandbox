/* 29_07.c 関数の引数に一次元配列を使った場合、
           ポインターと見なされる事を確認する  */
#include <stdio.h>

/* プロトタイプ宣言 */
void func(int a[]);

int main(void)
{
    int a[10];

    puts("int a[ 10 ];");
    printf("main : sizeof( a ) = %d\n", sizeof(a));
    func(a);

    return (0);
}

/* 関数側 */
void func(int a[])
{
    puts("\nvoid func( int a[] )");
    printf("func : sizeof( a ) = %d\n", sizeof(a));

    return;
}