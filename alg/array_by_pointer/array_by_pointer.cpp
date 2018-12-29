/* 27_00.c ポインターによる二次元配列 */
#include <stdio.h>
#include <stdlib.h>
#include "c_prac_base2.h"

/* プロトタイプ宣言 */
void set_data(int *buf);
void out_data(int *buf, int max_ary1, int max_ary2);

/* 共通マクロ定義 */
#define Mac_ProduceYear 0
#define Mac_PerformanceTime 1

/* main 関数 */
#define Mac_Array1Max (Mac_PerformanceTime + 1)
#define Mac_Array2Max 4
#define Mac_BufSize (Mac_Array1Max * Mac_Array2Max)

int main(void)
{
    int *buf = (int *)malloc(sizeof(int) * Mac_BufSize + 4);

    if (buf == NULL)
    {
        exit(MacReturnErr);
    }

    set_data(buf);
    out_data(buf, Mac_Array1Max, Mac_Array2Max);

    free(buf);
    return (MacReturnOk);
}
#undef Mac_Array1Max
// #undef Mac_Array2Max
#undef Mac_BufSize

/* データ設定 */
void set_data(int *buf)
{
    // *buf++ = 1800;
    // *buf++ = 32;
    // *buf++ = 1802;
    // *buf++ = 35;
    // *buf++ = 1805;
    // *buf++ = 64;
    // *buf++ = 1806;

    // 上記をループで書き換え

    int loopNum=Mac_Array2Max*2-1;
    int data[]={1800,32,1802,35,1805,64,1806};

    for(int i = 0; i < loopNum; i++)
    {
        *buf++=data[i];
    }
    *buf = 74;
    return;
}

/* データ表示 */
#define Mac_MsgHeader "制作年  演奏時間\n" \
                      "------  --------"
#define Mac_MsgFormat "%6d  %8d\n"

void out_data(int *buf, int max_ary1, int max_ary2)
{
    int y;
    int i;

    puts(Mac_MsgHeader);
    for (y = 0; y < max_ary2; y++)
    {
        i = y * max_ary1;
        printf(
            Mac_MsgFormat,
            *(buf + Mac_ProduceYear + i),
            *(buf + Mac_PerformanceTime + i));
    }
    return;
}
#undef Mac_MsgHeader
#undef Mac_MsgFormat
#undef Mac_Array2Max