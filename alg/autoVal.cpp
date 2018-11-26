/* 17_06.c switch 文と自動変数 */
#include <stdio.h>

int main(void)
{
    int i = 20;

    switch (i)
    {
        int a; /* switch ブロックの自動変数 a */

    case 1:
        a = 0;
        printf("case 1  : a = %d\n", a);
        break;
    case 20:
        a = i;
        printf("case 20 : a = %d\n", a);
        break;
    }

    return (0);
}