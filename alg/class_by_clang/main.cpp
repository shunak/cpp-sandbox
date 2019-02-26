/* 52_00.c 関数名を構造体で覆う */
#include <stdio.h>
#include "sub_public.h"

int main(void)
{
    int i = 5;
    char s0[][10] = {"abcdefg", "opqrs"};
    STutil *u1 = NULL;
    STutil *u2 = NULL;

    /* 実体生成 */
    new_util(&u1);
    if (u1 == NULL)
    {
        fputs("実体作成失敗 1", stderr);
        goto func_exit;
    }

    new_util(&u2);
    if (u2 == NULL)
    {
        fputs("実体作成失敗 2", stderr);
        goto func_exit;
    }

    /* 作成した実体の関数呼び出し */
    u1->print_int(i);
    u1->print_str(s0[0]);
    u2->print_int(i * i);
    u2->print_str(s0[1]);

func_exit:
    /* 実体削除 */
    delete_util(&u2);
    delete_util(&u1);

    return (0);
}