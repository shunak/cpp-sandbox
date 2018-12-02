/********************************************************************
        c_prac_inkey.c

                        キー入力処理
********************************************************************/
#include <stdio.h>
#include "c_prac_base.h"
#include "c_prac_inkey.h"
#include "c_prac_cnv.h"

/*
関数名                  機能
----------------------- ---------------------------------------------
GetNumStdin             標準入力から一文字読み込み、数記号を数値化
*/

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