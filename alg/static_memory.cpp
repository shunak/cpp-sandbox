/* 28_00.c 静的変数の特徴 */
#include <stdio.h>

/* プロトタイプ宣言 */
void func_auto(void);
void func_static1(void);
void func_static2(void);

/* main 関数 */
#define Mac_MaxLoop 3

int main(void)
{
    int i;

    puts("** 自動変数。宣言と同時に0で初期化を記述 **");
    for (i = 0; i < Mac_MaxLoop; i++)
    {
        func_auto();
    }

    puts("\n** 明示的な初期化をしない **");
    for (i = 0; i < Mac_MaxLoop; i++)
    {
        func_static1();
    }

    puts("\n** 宣言と同時に51で初期化を記述 **");
    for (i = 0; i < Mac_MaxLoop; i++)
    {
        func_static2();
    }

    return (0);
}

/* 自動変数 */
void func_auto(void)
{
    int i = 0; /* 自動変数 */

    printf("自動変数 : i = %d\n", i++);
    return;
}

/* 静的変数1 明示的に初期化をしない */
void func_static1(void)
{
    static int i; /* 静的変数 */

    printf("静的変数1: i = %d\n", i++);
    return;
}

/* 静的変数2 明示的に初期化 */
void func_static2(void)
{
    static int i = 51; /* 静的変数 */

    printf("静的変数2: i = %d\n", i++);
    return;
}