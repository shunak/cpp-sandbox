/* 29_05.c 配列に於ける sizeof 演算子 */
#include <stdio.h>

int main(void)
{
    int a[8];
    int size_a = sizeof(a);
    int size_elem = sizeof(a[0]);

    printf("配列   int a[ 3 ] : %d バイト\n", size_a);
    printf("配列の要素 a[ 0 ] : %d バイト\n", size_elem);
    printf("配列の要素数      : %d\n", size_a / size_elem);

    return (0);
}