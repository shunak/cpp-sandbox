/* 25_03.c 采の目を十回求めて表示する srand 使用版 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int r; /* 采の目 */
    int i;
    time_t t;

    /* 時間を乱数の種にする */
    t = time(NULL);
    srand((unsigned int)t);

    for (i = 0; i < 10; i++)
    {
        r = rand() % 6 + 1; /* 采の目を求める */
        printf("%d ", r);
    }
    puts("");

    return (0);
}