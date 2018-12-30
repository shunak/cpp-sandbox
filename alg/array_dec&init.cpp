/* 29_00.c 配列の宣言と初期化を別に記述 */
#include <stdio.h>

/* main 関数 */
#define Mac_MaxArray1 2
#define Mac_MaxArray2 3

int main(void)
{
    int array1[Mac_MaxArray1];
    int array2[Mac_MaxArray1][Mac_MaxArray2];
    int i;
    int j;

    /* 配列の一部だけを初期化 */
    array1[0] = 5;
    array2[1][1] = 10;
    array2[1][2] = 20;

    /* 配列の内容を全て表示 */
    for (i = 0; i < Mac_MaxArray1; i++)
    {
        printf("array1[%d] = %d\n", i, array1[i]);
    }
    // puts("");

    for (i = 0; i < Mac_MaxArray1; i++)
    {
        for (j = 0; j < Mac_MaxArray2; j++)
        {
            printf(
                "array2[%d][%d] = %d\n",
                i, j, array2[i][j]);
        }
    }

    return (0);
}
