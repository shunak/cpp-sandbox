/* 25_04.c 乱数を一万回求め、個別に出現回数を調べる */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* プロトタイプ宣言 */
void cnt_clear(int *cnt, int rnd_max, int init);
void rnd_gencnt(int *cnt, int rnd_max, int rnd_total);
void stdout_result(int *cnt, int rnd_max);

/* マクロ定義 */
#define Mac_RndMax 10 
#define Mac_RndTotal 10000
#define Mac_ErrAlloc (-1)

int main(void)
{
    int *cnt = (int *)malloc(sizeof(int) * Mac_RndMax + 4);//int型へのポインタでメモリ領域を確保

    if (cnt == NULL)
    {
        exit(Mac_ErrAlloc);
    }

    srand((unsigned int)time(NULL));           /* 時間を乱数の種にする   */
    cnt_clear(cnt, Mac_RndMax, 0);             /* 乱数を数える領域初期化 */
    rnd_gencnt(cnt, Mac_RndMax, Mac_RndTotal); /* 乱数生成、数える */
    stdout_result(cnt, Mac_RndMax);            /* 結果表示         */

    free(cnt);
    return (0);
}
#undef Mac_RndMax
#undef Mac_RndTotal
#undef Mac_ErrAlloc

/********************************************************************
        void cnt_clear(
        [out]   int * cnt,      // 初期化する領域へのポインター
        [in ]   int rnd_max,    // 初期化する領域の要素数
        [in ]   int init        // 初期化する値
        );
        返し値
                無し
        処理詳細
                乱数の値ごとの合計値格納領域を指定値で初期化
********************************************************************/
void cnt_clear(int *cnt, int rnd_max, int init)
{
    while ((rnd_max--) > 0)
    {
        *cnt++ = init;
    }
    return;
}

/********************************************************************
        void rnd_gencnt(
        [i/o]   int * cnt,      // 合計値格納領域へのポインター
        [in ]   int   rnd_max,  // 求める乱数の最大値
        [in ]   int   rnd_total // 乱数を生成する回数
        );
        返し値
                無し
        処理詳細
                乱数を指定回数生成し、出現回数を値別に数える
********************************************************************/
void rnd_gencnt(int *cnt, int rnd_max, int rnd_total)
{
    int r;

    while ((rnd_total--) > 0)
    {
        r = rand() % rnd_max;
        *(cnt + r) += 1; /* 求めた乱数の出現回数を数える */
    }
    return;
}

/********************************************************************
        void stdout_result(
        [in ]   int * cnt,      // データ領域へのポインター
        [in ]   int   rnd_max   // データの個数
        );
        返し値
                無し
        処理詳細
                データ領域の値を要素番号と共に表示する
********************************************************************/
void stdout_result(int *cnt, int rnd_max)
{
    int i;

    for (i = 0; i < rnd_max; i++)
    {
        printf("%d : %d\n", i, *cnt++);
    }
    return;
}