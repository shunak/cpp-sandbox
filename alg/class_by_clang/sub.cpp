/* 52_00_sub.c 関数名を構造体で覆う sub 側 */
#include <stdio.h>
#include <stdlib.h>
#include "sub_private.h"
#include "sub_public.h"

/* 公開関数。util に関する処理をする前に呼び出す */
extern void new_util(STutil **stu)
{
    /* 実体の元となるデータ */
    static STutil stutil = {int_stdout, str_stdout};

    if (stu == NULL)
    {
        return;
    }

    /* 実体を格納する為の領域を確保 */
    *stu = (STutil *)malloc(sizeof(STutil));
    if (*stu == NULL)
    {
        return;
    }

    /* 確保した領域へ元となるデータを複写し、実体生成 */
    **stu = stutil;

    return;
}

/* 公開関数。util に関する処理をし終えたら呼び出す */
extern void delete_util(STutil **stu)
{
    if (*stu != NULL)
    {
        free(*stu);  /* 実体領域の開放、即ち実体削除 */
        *stu = NULL; /* 二重開放防止の為 */
    }
    return;
}

/* 間接公開関数。整数を標準出力へ出力 */
static void int_stdout(int a)
{
    printf("引  数 : %d\n", a);
    return;
}

/* 間接公開関数。文字列を標準出力へ出力 */
static int str_stdout(const char *s)
{
    int i;

    i = printf("文字列 : %s\n", s);
    return (i);
}