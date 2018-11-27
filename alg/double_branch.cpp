/* 実数の多分岐処理関数とその検査 */
#include <stdio.h>

/* プロトタイプ宣言 */
int check_d(double d, double d_s);
int process_int_arg(double d, int i);
void debug_print(int i);

int main(void)
{
    int min;
    int max;
    int i;

    min = 0;
    max = 4;
    for (i = min; i <= max; i++)
    {
        debug_print(-i); /* 負数 */
        debug_print(i);  /* 正数 */
    }

    return (0);
}

/**********************************************************
        void debug_print(
                int    i        // 検査対象値
        );
        返し値
                無し
        処理内容
                process_int_arg 関数を実行し、
                その結果を表示する。
**********************************************************/
void debug_print(int i)
{
    int ret;

    ret = process_int_arg((double)i, i);
    printf(
        "検査値 = %23.20f : 加工値 = %2d : 戻り値 = %2d\n",
        (double)i, i, ret);

    return;
}
/**************************************

***********************************/

/**********************************************************
        int process_int_arg(
                double d,       // 処理分岐の対象値
                int    i        // 加工対象値
        );
        返し値
                d == 1.0 ±0.1以内 :  i * 2
                d == 2.0 ±0.1以内 :  i * 6
                d == 3.0 ±0.1以内 : -i
                上記以外 0(零)
        処理内容
                d が d_s の±0.1以内の値かを検査する
**********************************************************/
int process_int_arg(double d, int i)
{
    double one;
    double two;
    double three;
    int flse;

    one = 1.0;
    two = 2.0;
    three = 3.0;
    flse = 0;

    if (check_d(d, one) != flse) /* 1.0 */
    {
        return (i * 2);
    }
    if (check_d(d, two) != flse) /* 2.0 */
    {
        return (i * 6);
    }
    if (check_d(d, three) != flse) /* 3.0 */
    {
        return (-i);
    }
    return (0); /* 条件一致せず */
}

/**********************************************************
        int check_d(
        [in ]   double d,       // 検査する実数
        [in ]   double d_s      // 比較元となる実数
        );
        返し値
                真 : ±0.1以内
                偽 : ±0.1ではない
        処理内容
                d が d_s の±0.1以内の値かを検査する
**********************************************************/
int check_d(double d, double d_s)
{
    int flse;  /* 返し値 */
    double err; /* 誤差 */

    flse = 0;
    err = 0.1;

    if ((d >= (d_s - err)) &&
        (d <= (d_s + err)))
    {
        return (!flse);
    }
    return (flse);
}