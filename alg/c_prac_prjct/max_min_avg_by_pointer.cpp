/* 23_02.c int 型の数値を五つ入力し、最大、最小、算術平均を求める */
#include <stdio.h>
#include <stdlib.h>
#include "c_prac_base.h"

/* プロトタイプ宣言 */
int get_min(int *buf, int max_array);
int get_max(int *buf, int max_array);
double get_mean(int *buf, int max_array);
double get_total(int *buf, int max_array);
int in_num(int *buf, int max_array, int len);
int get_int(int *buf, char *buf_str, int len);

/* マクロ定義 */
#define Mac_InStrLen (8 + 1) /* +1 は '\0' の分 */
#define Mac_MaxArray 5
#define Mac_ErrAlloc (-1)
#define Mac_ErrStdin (Mac_ErrAlloc - 1)
#define Mac_PrintFmt "最小値  :%10d\n最大値  :%10d\n算術平均:%12.1f\n"

int main(void)
{
    int ret = 0;
    int *buf;    /* 数値格納領域 */
    int min;     /* 最小値 */
    int max;     /* 最大値 */
    double mean; /* 算術平均 */

    buf = (int *)malloc(sizeof(int) * Mac_MaxArray + 4);
    if (buf == NULL)
    {
        exit(Mac_ErrAlloc);
    }

    if (in_num(buf, Mac_MaxArray, Mac_InStrLen) == MacFalse)
    {
        puts("文字列入力にて問題発生。処理を中止します。");
        ret = Mac_ErrStdin;
    }
    else
    {
        min = get_min(buf, Mac_MaxArray);
        max = get_max(buf, Mac_MaxArray);
        mean = get_mean(buf, Mac_MaxArray);
        printf(Mac_PrintFmt, min, max, mean);
    }

    free(buf);
    return (ret);
}
#undef Mac_InStrLen
#undef Mac_MaxArray
#undef Mac_ErrAlloc
#undef Mac_ErrStdin
#undef Mac_PrintFmt

/* 数値入力。len は 1 以上 */
int in_num(int *buf, int max_array, int len)
{
    int ret;
    char *buf_str; /* 文字列入力用領域へのポインター */

    if ((buf == NULL) || (len <= 0))
    {
        return (MacFalse);
    }

    buf_str = (char *)malloc(sizeof(char) * len + 4);
    if (buf_str == NULL)
    {
        return (MacFalse);
    }

    /* 数値入力を max_array 回行う */
    do
    {
        ret = get_int(buf, buf_str, len);
        buf += 1;
        max_array -= 1;
    } while ((max_array > 0) && (ret != MacFalse));

    free(buf_str);
    return (ret);
}

/* 標準入力から文字列を入力、int 値へ変換 */
#define Mac_Msg "数値を入力してください:"

int get_int(int *buf, char *buf_str, int len)
{
    fflush(stdin);
    printf(Mac_Msg);
    buf_str = fgets(buf_str, len, stdin);
    if (buf_str == NULL)
    {
        *buf = 0;
        return (MacFalse);
    }
    *buf = atoi(buf_str);
    return (MacTrue);
}
#undef Mac_Msg

/* 最小値を求める */
int get_min(int *buf, int max_array)
{
    int min = *buf; /* 仮の最小値 */

    buf += 1; /* 仮の最小値に最初の値を使用した為、次の要素へ */
    max_array -= 1;
    while (max_array > 0)
    {
        if (min > *buf)
        {
            min = *buf;
        }
        buf += 1;
        max_array -= 1;
    }
    return (min);
}

/* 最大値を求める */
int get_max(int *buf, int max_array)
{
    int max = *buf; /* 仮の最大値 */

    buf += 1; /* 仮の最大値に最初の値を使用した為、次の要素へ */
    max_array -= 1;
    while (max_array > 0)
    {
        if (max < *buf)
        {
            max = *buf;
        }
        buf += 1;
        max_array -= 1;
    }
    return (max);
}

/* 算術平均を求める */
double get_mean(int *buf, int max_array)
{
    double total = get_total(buf, max_array);

    return (total / max_array);
}

/* 総和を求める */
double get_total(int *buf, int max_array)
{
    double total = 0.0;

    while (max_array > 0)
    {
        total += (double)(*buf);
        buf += 1;
        max_array -= 1;
    }
    return (total);
}