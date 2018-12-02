/* 19_01.c 標準入力から文字を入力し、数値化する
           分割コンパイル方式                    */
#include <stdio.h>
#include "c_prac_base.h"
#include "c_prac_inkey.h"

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