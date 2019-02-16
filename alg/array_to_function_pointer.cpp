/* 46_02.c 関数へのポインターの配列 */
#include <stdio.h>

/* プロトタイプ宣言 */
void func0(int cnt);
void func1(int cnt);
void func2(int cnt);

/* 型定義 */
typedef void Tf(int cnt);

/* マクロ定義 */
#define MacLoopMax 2 /* 繰り返し回数 */

int main(void)
{
    /* 関数へのポインターの配列、最後の NULL は終端印 */
    Tf *f[] = {func0, func1, func2, NULL};
    int i;       /* 繰り返し回数用 */
    int cnt = 0; /* 何回目の関数呼び出しか */
    int idx;     /* 呼び出す関数へのポインター配列の番号 */

    for (i = 0; i < MacLoopMax; i++)
    {
        idx = 0;
        while (f[idx] != NULL)
        {
            (*f[idx++])(cnt++); /* 関数呼び出し */
        }
    }

    return (0);
}

void func0(int cnt)
{
    printf("%d 回目 : func0\n", cnt);
    return;
}

void func1(int cnt)
{
    printf("%d 回目 : func1\n", cnt);
    return;
}

void func2(int cnt)
{
    printf("%d 回目 : func2\n", cnt);
    return;
}