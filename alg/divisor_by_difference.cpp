/* 25_01.c 商を減算で求める */
#include <stdio.h>

/* プロトタイプ宣言 */
int divide(int dividend, int divisor);

int main(void)
{
    int dividend;
    int divisor;
    int quotient;

    for (dividend = 100; dividend > 70; dividend -= 3)
    {
        for (divisor = 5; divisor <= 7; divisor += 2)
        {
            quotient = divide(dividend, divisor);
            printf(
                "%3d / %2d = %d\n",
                dividend, divisor, quotient);
        }
    }

    return (0);
}

/* 除算を減算で行う。余りは無視 */
int divide(int dividend, int divisor)
{
    int quotient = 0;
    int work = dividend - divisor;

    while (work >= 0)
    {
        quotient++;
        dividend = work;
        work = dividend - divisor;
    }
    return (quotient);
}