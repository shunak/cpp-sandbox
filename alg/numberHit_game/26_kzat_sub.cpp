#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "c_prac_base2.h"
#include "26_kzat_main.h"
#include "26_kzat_sub.h"

// #include <stdlib.h>
// #include <time.h>
// #include <stdio.h>

/********************************************************************
        int think_number(
        [in ]   int min,        // 最小値
        [in ]   int max         // 最大値
        );
        返し値
                生成した乱数
        処理詳細
                min 以上 max 以下の乱数を生成
        注意
                次の場合の動作は保障されない
                        min > max 又は min < 0 又は max < 0
********************************************************************/
int think_number(int min, int max)
{
    /* min から max までの乱数なので、
          その差分 + 1 が生成する乱数の個数 */
    int num = max - min + 1;

    return (rand() % num + min);
}

/********************************************************************
        int continue_game(
                void
        );
        返し値
                継続 : MacTrue
                終了 : MacFalse
        処理詳細
                ゲームを続けるか否かの問い合わせ、その入力を行う
        注意
                先頭一文字だけで判断する
********************************************************************/
#define Mac_MsgAsk "もう一度しますか (Yes/No) : "
#define Mac_MsgInErr "y または n を入力してください"
#define Mac_MsgCont "続けます\n"
#define Mac_MsgEnd "終了します"
#define Mac_MsgErr "エラーが発生しました"
#define Mac_KeyCont1 'y'
#define Mac_KeyCont2 'Y'
#define Mac_KeyEnd1 'n'
#define Mac_KeyEnd2 'N'

int continue_game(void)
{
    int inkey;
    int flg = MacFalse;
    int ret;

    while (flg == MacFalse)
    {
        fflush(stdin); /* 規格外 */
        printf(Mac_MsgAsk);
        inkey = fgetc(stdin);
        switch (inkey)
        {
        case Mac_KeyCont1:
        case Mac_KeyCont2:
            puts(Mac_MsgCont);
            ret = MacTrue;
            flg = MacTrue;
            break;
        case Mac_KeyEnd1:
        case Mac_KeyEnd2:
            puts(Mac_MsgEnd);
            ret = MacFalse;
            flg = MacTrue;
            break;
        case EOF:
            puts(Mac_MsgErr);
            ret = MacFalse;
            flg = MacTrue;
            break;
        default:
            puts(Mac_MsgInErr);
        }
    }
    return (ret);
}
#undef Mac_MsgAsk
#undef Mac_MsgInErr
#undef Mac_MsgCont
#undef Mac_MsgEnd
#undef Mac_MsgErr
#undef Mac_KeyCont1
#undef Mac_KeyCont2
#undef Mac_KeyEnd1
#undef Mac_KeyEnd2

/********************************************************************
        void hit_number(
        [in ]   int num         // 当てるまでに要した回数
        );
        返し値
                無し
        処理詳細
                当たった旨とそれに要した回数を標準出力へ出力
********************************************************************/
#define Mac_MsgNS ""
#define Mac_Msg "わずか "
#define Mac_MsgFmt "%d 回で当たりました\n"

void hit_number(int num)
{
    puts(Mac_MsgNS);
    if (num <= Mac_HitSmall)
    {
        printf(Mac_Msg);
    }
    printf(Mac_MsgFmt, num);
    return;
}
#undef Mac_MsgNS
#undef Mac_Msg
#undef Mac_MsgFmt

/********************************************************************
        void miss_number(
        [in ]   int com_num,    // コンピューターの考えた値
        [in ]   int in_num      // 人が入力した値
        );
        返し値
                無し
        処理詳細
                com_num と in_num とを比較し、
                状況に応じた文字列を標準出力へ出力
********************************************************************/
#define Mac_MsgBig "もっと大きいです"
#define Mac_MsgSml "もっと小さいです"

void miss_number(int com_num, int in_num)
{
    int r = rand() % Mac_FalseProbability;

    if (r == 0)
    { /* 嘘のヒントを出力する為、値を入れ替える */
        swapi(&com_num, &in_num);
    }

    if (com_num > in_num)
    {
        puts(Mac_MsgBig);
    }
    else
    {
        puts(Mac_MsgSml);
    }
    return;
}
#undef Mac_MsgBig
#undef Mac_MsgSml

/********************************************************************
        int swapi(
        [i/o]   int * a,        // 交換対象値その一
        [i/o]   int * b         // 交換対象値その二
        );
        返し値
                何等かのエラー : MacFalse
                正常           : MacTrue
        処理詳細
                *a と *b の値を交換する
********************************************************************/
int swapi(int *a, int *b)
{
    int work;

    if ((a == NULL) || (b == NULL))
    {
        return (MacFalse);
    }

    work = *a;
    *a = *b;
    *b = work;

    return (MacTrue);
}
/********************************************************************
        int input_number(
        [in ]   int min,        // 最小値
        [in ]   int max,        // 最大値
        [out]   int * in_num    // 入力値格納ポインター
        );
        返し値
                何等かのエラー : MacFalse
                正常           : MacTrue
        処理詳細
                最小値以上最大値以下の数記号を入力させ、
                その値を *in_num へ格納する。
********************************************************************/
#define Mac_MsgFmt      "%d から %d までの値を入力してください\n"
#define Mac_MsgInNum    "数は? (%d～%d): "

int input_number( int min, int max, int * in_num )
{
        int    ret;
        int    num;
        char * buf;

        if ( in_num == NULL )
        {
                return ( MacFalse );
        }

        buf = (char *)malloc( sizeof( char ) * Mac_InBufSize + 4 );
        if ( buf == NULL )
        {
                return ( MacFalse );
        }

        for ( ; ; )     /* for の無限ループ */
        {
                ret = fflush( stdin );  /* 規格外 */
                if ( ret == EOF )
                {
                        ret = MacFalse;
                        break;
                }
                printf( Mac_MsgInNum, min, max );
                fgets( buf, Mac_InBufSize, stdin );
                num = atoi( buf );
                if ( ( num < min ) || ( num > max ) )
                {
                        printf( Mac_MsgFmt, min, max );
                }
                else
                {
                        *in_num = num;          /* 変換値を格納 */
                        ret     = MacTrue;
                        break;
                }
        }

        free( buf );
        return ( ret );
}
#undef Mac_MsgFmt
#undef Mac_MsgInNum




