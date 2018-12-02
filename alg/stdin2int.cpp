/* 19_00.c 標準入力から文字を入力し、数値化する */
#include <stdio.h>
#include "c_prac_base.h"

/***** マクロ定義及びプロトタイプ宣言 *****/

/* GetNumStdin 用 */
#define MacErr_NotNum (-1)      /* 数記号ではない         */
#define MacErr_GetNumStdin (-2) /* GetNumStdin 内でエラー */
int GetNumStdin(int flg_buf_clear);

/* NumCharToInt 用 */
#define MacErr_NotNumChar (-1) /* 数記号ではない */
int NumCharToInt(int c);

/***** main 関数内のマクロ定義 *****/
#define MacMinNum 0  /* 数値の最小 */
#define MacMaxNum 9  /* 数値の最大 */
#define MacMaxLoop 4 /* 入力回数   */
#define MacFmtRes "%2d 文字目を数値化 : %d\n"
#define MacErrMsgNotNum "数記号以外が入力されました"
#define MacErrMsgOther "何等かのエラーが発生しました"

int main(void)
{
    int i;
    int num;
    int cnt;

    for (i = 0; i < MacMaxLoop; i += 1)
    {
        /* 入力された数記号を順に数値化して表示 */
        cnt = 0;
        num = GetNumStdin(MacTrue);
        while ((num >= MacMinNum) && (num <= MacMaxNum))
        {
            cnt += 1;
            printf(MacFmtRes, cnt, num);
            num = GetNumStdin(MacFalse);
        }

        /* エラーがあれば、その旨表示 */
        switch (num)
        {
        case MacErr_NotNum:
            puts(MacErrMsgNotNum);
            break;
        case MacErr_GetNumStdin:
            puts(MacErrMsgOther);
            break;
        }
    } /* for */

    return (0);
}
#undef MacMinNum
#undef MacMaxNum
#undef MacMaxLoop
#undef MacFmtRes
#undef MacErrMsgNotNum
#undef MacErrMsgOther

/********************************************************************
        int GetNumStdin(
                int flg_buf_clear       // 真 : 最初にバッファ初期化
                                        // 偽 : 初期化しない
        );
        返し値
                成功 : 数記号を数値化した値
                失敗 : 数記号以外が入力された : MacErr_NotNum
                       何等かのエラー         : MacErr_GetNumStdin
        処理詳細
                標準入力から一文字入力し、数記号であれば
                それを数値化して返す。
                数記号で無ければその旨を返す。
                引数が真なら、入力前に標準入力のバッファを初期化する。
        例
                入力文字が "13A\n" なら、二回連続して呼び出すと
                int 型で 1, 3 を順に返す。三回目は数記号ではないので、
                MacErr_NotNum を返す。
********************************************************************/
int GetNumStdin(int flg_buf_clear)
{
    int num;

    /* バッファの初期化判定、及びその実行 */
    if (flg_buf_clear != MacFalse)
    {
        if (fflush(stdin) == EOF) /* 規格外 */
        {
            return (MacErr_GetNumStdin);
        }
    }

    /* 標準入力から一文字取得 */
    num = fgetc(stdin);
    if (num == EOF)
    {
        return (MacErr_GetNumStdin);
    }

    /* 数記号ならその数値を返す */
    num = NumCharToInt(num);
    if (num == MacErr_NotNumChar)
    {
        return (MacErr_NotNum);
    }
    return (num);
}

/********************************************************************
        int NumCharToInt(
                int c   // 文字コード
        );
        返し値
                成功 : 数記号を数値化した値
                失敗 : 数記号ではない : MacErr_NotNumChar
        処理詳細
                文字コードが数記号であればそれを数値化して返す。
                数記号で無ければその旨を返す。
********************************************************************/
int NumCharToInt(int c)
{
    if ((c > '9') || (c < '0'))
    {
        return (MacErr_NotNumChar);
    }
    return (c - '0');
}