/* 21_04.c pointer利用による二値の交換 */
#include <stdio.h>

/* プロトタイプ宣言 */
void swapi(int *a, int *b);

int main(void)
{
    int x = 12;
    int y = 34;

    printf("処理前 : x = %d, y = %d\n", x, y);
    swapi(&x, &y);
    printf("処理後 : x = %d, y = %d\n", x, y);

    return (0);
}

/* swapi 関数。int 型の二値を交換*/
void swapi(int *a, int *b)
{
    int work;

    work = *a;
    *a = *b;
    *b = work;

    return;
}