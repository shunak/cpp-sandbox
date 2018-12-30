/* 29_08.c 関数の引数に二次元配列を使った場合、
           関数側ではどうなるかを確認する  */
#include <stdio.h>

/* マクロ定義 */
#define Mac_Elem2 10

/* プロトタイプ宣言 */
void func(char a[][Mac_Elem2]);

int main(void)
{
    char a[2][Mac_Elem2];

    func(a);

    return (0);
}

/* 関数側 */
void func(char a[][Mac_Elem2])
{
    printf("void func( char a[][ %d ] )\n", Mac_Elem2);
    printf("sizeof( a           ) = %d\n", sizeof(a));
    printf("sizeof( a[ 0 ]      ) = %d\n", sizeof(a[0]));
    printf("sizeof( a[ 0 ][ 0 ] ) = %d\n", sizeof(a[0][0]));

    return;
}