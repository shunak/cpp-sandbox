/* 24_02.c 条件式に於けるインクリメント・デクリメント演算子 */
#include <stdio.h>

int main(void)
{
    int i;

    /* ブロック内部で加算 */
    puts("ブロック内で加算");
    i = 0;
    while (i < 5)
    {
        printf("%d ", i);
        i++; /* i を加算 */
    }
    printf("\nブロック終了後 : i = %d\n\n", i);

    /* 条件式で加算 */
    puts("条件式で加算");
    i = 0;
    while ((i++) < 5) /* i を加算 */
    // while ((++i) < 5) /* i を加算 */
    {
        printf("%d ", i);
    }
    printf("\nブロック終了後 : i = %d\n", i);

    return (0);
}