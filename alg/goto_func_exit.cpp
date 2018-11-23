#include <stdio.h>

int main(void)
{
    int i;

    i = 11;
    if (i == 10)
    {
        goto i_wa_10;
    }
    if (i != 10)
    {
        goto i_wa_10_denai;
    }

    /* i == 10 の場合 */
i_wa_10:
    printf("i は 10 です : i = %d\n", i);
    goto func_exit;

    /* i != 10 の場合 */
i_wa_10_denai:
    printf("i は 10 ではありません : i = %d\n", i);
    goto func_exit;

func_exit:
    return (0);
}