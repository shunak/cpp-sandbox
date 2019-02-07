/* 44_03.c 自己参照の構造体によるスタック */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_prac_base2.h"
#include "stack_prac.h"

/* main 関数 */
#define MacEndLoopStr "@end\n"

int main(void)
{
    const int len = MacTitemSize - 4;
    const char *fmt_head =
        "<<< スタック試験。一行最大 %d 文字入力。"
        "@end で終了 >>>\n";
    const char *fmt_in = "文字列 : ";

    Titem item;

    printf(fmt_head, len);
    fflush(stdin); /* 規格外 */
    printf(fmt_in);
    while ((fgets(item, len, stdin) != NULL) &&
           (strcmp(MacEndLoopStr, item) != 0))
    {
        if (stack_push(item) == MacFalse)
        {
            puts("stack_push error ");
        }
        fflush(stdin); /* 規格外 */
        printf(fmt_in);
    }

    puts("\n<<< スタックに格納された文字列を出力 >>>");
    while (stack_pop(item) != MacFalse)
    { /* 改行もデータに含まれているので不要 */
        printf("pop : item = %s", item);
    }

    stack_free(); /* 最後に必ず呼び出す */
    return (0);
}