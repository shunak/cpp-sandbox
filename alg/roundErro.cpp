#include <stdio.h>

/* プロトタイプ宣言 */
int check_d(double d, double d_s);

int main(void)
{
    int min;
    int max;
    int i;
    int boolean;
    double d_org;
    double d;
    double d_cnv;

    d_org = 2.0;
    d_cnv = 0.01;
    min = -11;
    max = 11;
    for (i = min; i <= max; i++)
    {
        d = d_org + ((double)i * d_cnv);
        boolean = check_d(d, d_org);
        printf(
            "検査値 = %.20f : 比較元 = %.20f : 結果 = %d\n",
            d, d_org, boolean);
    }

    return (0);
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