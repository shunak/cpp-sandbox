/* 47_01.c コンマ演算子 その二 */
#include <stdio.h>

int main(void)
{
    int x;
    int y;

    for (x = 0, y = x + 1; x < 5; x++, y++)
    {
        printf("x = %d : y = %d\n", x, y);
    }

    return (0);
}