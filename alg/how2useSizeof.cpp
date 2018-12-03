/* 20_00 sizeof 演算子の使用例 */
#include <stdio.h>

int main(void)
{
    char c = 10;
    int i = 20;

    printf("sizeof ( char )    = %d\n", sizeof(char));
    printf("sizeof ( int )     = %d\n", sizeof(int));
    printf("sizeof ( c )       = %d\n", sizeof(c));
    printf("sizeof ( i )       = %d\n", sizeof(i));
    printf("sizeof ( (char)i ) = %d\n", sizeof((char)i));
    printf("sizeof ( c + i )   = %d\n", sizeof(c + i));
    printf("通常演算 : c + i   = %d\n", c + i);
    printf("sizeof   6         = %d\n", sizeof 6);
    printf("sizeof   7         = %d\n", sizeof 7);
    printf("sizeof   6 + 7     = %d\n", sizeof 6 + 7);
    printf("sizeof ( 6 + 7 )   = %d\n", sizeof(6 + 7));

    return (0);
}
