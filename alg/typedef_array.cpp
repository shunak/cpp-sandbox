/* 40_01.c 配列を typedef 定義 */
#include <stdio.h>

int main(void)
{
    typedef char moji[256];

    moji s = "abcdefg";

    printf("sizeof( s ) = %d, s = %s\n", sizeof(s), s);

    return (0);
}