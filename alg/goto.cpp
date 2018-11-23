#include <stdio.h>

int main(void)
{
    int i;

    i = 10;
    if (i == 10)
    {
        goto i_wa_10;
    }
    printf("i は 10 ではありません : i = %d\n", i);

i_wa_10: /* ラベル名 */
    printf("i は 10 です : i = %d\n", i);

    return (0);
}