/********************************************************************
        26_kzat_main.c
                        数当てゲームの本体
********************************************************************/
#include <stdlib.h>
#include <time.h>
#include "c_prac_base2.h"
#include "26_kzat_main.h"
#include "26_kzat_sub.h"

int main(void)
{
    int com_num;          /* コンピューターの考えた数 */
    int in_num;           /* 人が入力した数 */
    int ret;              /* 成否の戻り値格納用 */
    int flg_lp = MacTrue; /* 繰り返し判断。MacFalse:終了 */
    int cnt = 0;          /* 当てるまでに要した回数 */

    srand((unsigned int)time(NULL));
    com_num = think_number(Mac_NumMin, Mac_NumMax);
    do
    {
        cnt++;
        /* 入力 */
        ret = input_number(Mac_NumMin, Mac_NumMax, &in_num);
        if (ret == MacFalse)
        {
            break;
        }

        /* 当たり判定 */
        if (com_num == in_num)
        { /* 当たり */
            hit_number(cnt);
            if (continue_game() == MacFalse)
            { /* ゲーム終了フラグを立てる */
                flg_lp = MacFalse;
            }
            else
            { /* 新たな数を考える */
                com_num = think_number(Mac_NumMin, Mac_NumMax);
                cnt = 0; /* 入力回数初期化 */
            }
        }
        else
        { /* 外れ */
            miss_number(com_num, in_num);
        }
    } while (flg_lp != MacFalse);

    if (ret == MacFalse)
    {
        return (MacReturnErr);
    }
    return (MacReturnOk);
}