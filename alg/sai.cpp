/* 25_02.c 采の目を十回求めて表示する*/
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int r; /* 采の目 */
    int i;

    for (i = 0; i < 10; i++)
    {
        r = rand() % 6 + 1; /* 采の目を求める */
        printf("%d ", r);
    }
    puts("");

    return (0);
}