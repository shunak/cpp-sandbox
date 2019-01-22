/********************************************************************
        c_prac_compare.c

                        変換処理
********************************************************************/
#include "c_prac_base2.h"
#include "c_prac_compare.h"

/*
関数名                  機能
----------------------- ---------------------------------------------
string_compare          文字列比較
*/

/********************************************************************
        int string_compare(
                const STstrcmp * sc,    // 被比較、比較文字列の情報
                      int      * result // 結果格納用
        );
        返し値
                成功 : MacTrue
                       *result に以下の値を格納
                         被比較文字列 < 比較文字列 : 負
                         被比較文字列 = 比較文字列 : 零
                         被比較文字列 > 比較文字列 : 正
                失敗 : MacFalse
                       *result は不定
        処理詳細
                二つの文字列を文字コードにより比較する。
                以下の場合は失敗する。
                        ( sc->s0.s  == NULL ) 又は
                        ( sc->s1.s  == NULL ) 又は
                        ( sc->s0.sz <= 0    ) 又は
                        ( sc->s1.sz <= 0    )
                sc のメンバー変数のポインターが指し示す先も
                変更しない。
********************************************************************/
int string_compare(const STstrcmp *sc, int *result)
{
    typedef unsigned char UChar;
    int i;   /* 汎用 */
    int max; /* 繰り返しの限度回数 */
    int s0;  /* 比較される文字コード */
    int s1;  /* 比較す  る     〃    */
    /* ShiftJis は 0x80 以上で負になる為 UChar * 型 */
    UChar *ps0 = (UChar *)(sc->s0.s); /* 比較される文字列のアドレス */
    UChar *ps1 = (UChar *)(sc->s1.s); /* 比較す  る       〃        */

    /* エラー検査 */
    if (string_compare_chk(sc) == MacFalse)
    {
        return (MacFalse);
    }

    /* 文字単位で文字コードによる文字列比較 */
    max = string_compare_getmax(sc);
    i = 0;
    do
    {
        s0 = *(ps0++);
        s1 = *(ps1++);
        *result = s0 - s1;
        i++;
    } while ((*result == 0) && (s0 != '\0') &&
             (s1 != '\0') && (i < max));

    /* \0 が無い文字列への対応処理 */
    string_compare_no_nul(result, i, max, sc, ps0, ps1);

    return (MacTrue);
}

/********************************************************************
        static int string_compare_chk(
                const STstrcmp * sc     // 比較する文字列とその情報
        );
        返し値
                正常 : MacTrue
                異常 : MacFalse
        処理詳細
                *sc の引数を検査する。
                以下の場合は異常と判断。
                        ( sc->s0.s  == NULL ) 又は
                        ( sc->s1.s  == NULL ) 又は
                        ( sc->s0.sz <= 0    ) 又は
                        ( sc->s1.sz <= 0    )
********************************************************************/
static int string_compare_chk(const STstrcmp *sc)
{
    if ((sc->s0.s == NULL) || (sc->s1.s == NULL) ||
        (sc->s0.sz <= 0) || (sc->s1.sz <= 0))
    {
        return (MacFalse);
    }
    return (MacTrue);
}

/********************************************************************
        static int string_compare_getmax(
                const STstrcmp * sc     // 比較する文字列とその情報
        );
        返し値
                正常 : MacTrue
                異常 : MacFalse
        処理詳細
                配列の大きさの、より小さい値を取得
********************************************************************/
static int string_compare_getmax(const STstrcmp *sc)
{
    if (sc->s0.sz < sc->s1.sz)
    {
        return (sc->s0.sz);
    }
    return (sc->s1.sz);
}

/********************************************************************
        static void string_compare_no_nul(
                               int  * result,   // 結果格納用
                const          int    i,        // 繰り返した回数
                const          int    max,      // 比較最大回数
                const STstrcmp      * sc,       // 比較する文字列とその情報
                const unsigned char * ps0,      // 被比較文字へのポインター
                const unsigned char * ps1       // 比較文字へのポインター
        );
        返し値
                無し
        処理詳細
                文字列が '\0' で終わっておらず、且つ
                文字列は異なるが等しいと判断されてしまった場合の処理
********************************************************************/
static void string_compare_no_nul(
    int *result, const int i, const int max, const STstrcmp *sc,
    const unsigned char *ps0, const unsigned char *ps1)
{
    size_t st_max; /* max を size_t 型に型変換した値を格納 */

    /* 大小決定済み */
    if ((*result != 0) || (i < max))
    {
        return;
    }

    st_max = (size_t)max;
    /* 比較・被比較文字列全てを比較したので処理不要 */
    if ((sc->s0.sz == st_max) && (sc->s1.sz == st_max))
    {
        return;
    }
    /* 実際の文字列データは異なるので、比較結果を修正 */
    if (sc->s0.sz == st_max)
    {
        *result = -(*ps1);
    }
    else
    {
        *result = *ps0;
    }
    return;
}