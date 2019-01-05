/* 36_00.c 1 から 3 までの整数の合計を再帰処理で求める */
#include <stdio.h>

/* プロトタイプ宣言 */
int total(int n);

/* main 関数 */
int main(void)
{
    int ans;

    ans = total(3);
    printf("1 + 2 + 3 = %d\n", ans);

    return (0);
}

/* n から 1 までの加算を再帰で処理 */
int total(int n)
{
    int ans;

    printf("n = %d, &ans = %p\n", n, &ans);
    /* 再帰終了判断 */
    /*  0 加算は結果に影響しない為、1 の時に再帰処理末端 */
    if (n <= 1)
    {
        printf("再帰末端    : n = %d, &ans = %p\n", n, &ans);
        return (1);
    }

    ans = n + total(n - 1); /* 再帰呼び出し */
    printf(
        "return 直前 : n = %d, ans = %d, &ans = %p\n",
        n, ans, &ans);
    return (ans);
}
