/* 44_01.c 複数のビット・フィールド */
#include <stdio.h>

int main(void)
{
    struct
    {
        unsigned int a2 : 2;
        unsigned int a3 : 3;
        unsigned int : 0; /* ビット幅 0 */
        unsigned int b8 : 8;
    } bf2 = {1, 2, 0xff}; /* ビット幅 0 のメンバーは無視する */

    printf("a2 = %d, a3 = %d, b8 = %X\n", bf2.a2, bf2.a3, bf2.b8);
    printf("sizeof( bf2 ) = %d\n", sizeof(bf2));

    return (0);
}
