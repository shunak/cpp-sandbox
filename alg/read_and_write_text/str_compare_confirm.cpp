/* 42_00.c 文字列比較汎用関数とその検証 */
#include <stdio.h>
#include "c_prac_compare.h"

/* プロトタイプ宣言 */
void sub(void);

/* マクロ定義 */
#define MacFmt "ret = %d : s0 = %-9s : s1 = %-13s : result = %d\n"

int main(void)
{
    STstrcmp sc;
    int i;
    int j;
    int ret;
    int result;
    char s0[256] = "abcあいう";
    char s1[][60] =
        {/*     同じ       , 大きい        , 小さい      */
         "abcあいう", "abcあいうabc", "$abcあいう",
         /*     空文字列, 小さい,大きい  , 小さい      */
         "", "abc", "あいう", "1234567890"};
    const int max = sizeof(s1) / sizeof(s1[0]);

    /* s0 と s1[i] の比較。j == 1 の時 s0 はヌル・ストリング */
    sc.s0.s = s0;
    sc.s0.sz = sizeof(s0);    /* 配列の大きさは不変 */
    sc.s1.sz = sizeof(s1[i]); /*     〃     〃      */
    for (j = 0; j < 2; j++)
    { /* s0 の文字列とs1 配列内の文字列を順に比較 */
        for (i = 0; i < max; i++)
        {
            sc.s1.s = s1[i];
            ret = string_compare(&sc, &result);
            printf(MacFmt, ret, s0, s1[i], result);
        }
        s0[0] = '\0';
    }
    /* 文字列が '\0' で終わっていない場合*/
    sub();
    /* string_compare の第一引数エラー検査の動作確認*/
    sc.s0.sz = 0; /* sc.s0.sz == 0 の時 */
    sc.s1.s = s1[0];
    sc.s1.sz = sizeof(s1[0]);
    printf("sc.s0.sz = 0    : ret = %d\n", string_compare(&sc, &result));
    sc.s0.sz = sizeof(s0);
    sc.s1.sz = 0; /* sc.s1.sz == 0 の時 */
    printf("sc.s1.sz = 0    : ret = %d\n", string_compare(&sc, &result));
    sc.s1.sz = sizeof(s1[0]);
    sc.s0.s = NULL; /* sc.s0.s == NULL の時 */
    printf("sc.s0.s  = NULL : ret = %d\n", string_compare(&sc, &result));
    sc.s0.s = "abc";
    sc.s1.s = NULL; /* sc.s1.s == NULL の時 */
    printf("sc.s1.s  = NULL : ret = %d\n", string_compare(&sc, &result));

    return (0);
}
#undef MacFmt

/* sub 関数 */
void sub(void)
{
    char a[3] = "ab";
    char b[4] = "abc";
    char c[3] = "ab";
    char d[3] = "ab";

    int ret;
    int result;
    STstrcmp sc;

    sc.s0.s = a;
    sc.s0.sz = sizeof(a);
    sc.s1.s = b;
    sc.s1.sz = sizeof(b);
    ret = string_compare(&sc, &result);
    printf("ret = %d : a[2]=\"ab\"  : b[3]=\"abc\" : "
           "result = %d\n",
           ret, result);

    sc.s0.s = b;
    sc.s0.sz = sizeof(b);
    sc.s1.s = a;
    sc.s1.sz = sizeof(a);
    ret = string_compare(&sc, &result);
    printf("ret = %d : b[3]=\"abc\" : a[2]=\"ab\"  : "
           "result = %d\n",
           ret, result);

    sc.s0.s = c;
    sc.s0.sz = sizeof(c);
    sc.s1.s = d;
    sc.s1.sz = sizeof(d);
    ret = string_compare(&sc, &result);
    printf("ret = %d : c[2]=\"ab\"  : d[3]=\"ab\"  : "
           "result = %d\n",
           ret, result);

    sc.s0.s = d;
    sc.s0.sz = sizeof(d);
    sc.s1.s = c;
    sc.s1.sz = sizeof(c);
    ret = string_compare(&sc, &result);
    printf("ret = %d : d[3]=\"ab\"  : c[2]=\"ab\"  : "
           "result = %d\n",
           ret, result);

    sc.s0.s = a;
    sc.s0.sz = sizeof(a);
    sc.s1.s = c;
    sc.s1.sz = sizeof(c);
    ret = string_compare(&sc, &result);
    printf("ret = %d : a[2]=\"ab\"  : c[2]=\"ab\"  : "
           "result = %d\n",
           ret, result);

    return;
}