/* stack_prac.c 自己参照の構造体によるスタックの練習 */
#define MacDebugMode /* デバッグ情報表示用。不要なら注釈化 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_prac_base2.h"
#include "stack_prac.h"

/* 内部リンケージの外部変数の定義 */
static STsrs *InGnow = NULL;  /* 現在のデータへのポインター */
static STsrs *InGwork = NULL; /* InGnow 退避用 */

/* デバッグ情報表示マクロの定義 */
#ifdef MacDebugMode
#define MacDebugMalloc printf("\talloc : %p\n", InGnow)
#define MacDebugFree printf("\tfree   : %p\n", InGwork)
#define MacDebugFreeBef                          \
    printf("\tInGnow = %p, InGnow->next = %p\n", \
           InGnow, InGnow->next)
#else                   /* MacDebugMode が未定義なら */
#define MacDebugMalloc  /*   無効化 */
#define MacDebugFree    /*   無効化 */
#define MacDebugFreeBef /*   無効化 */
#endif                  /* MacDebugMode */

/*
関数名                  機能
----------------------- ---------------------------------------------
stack_free              スタックが不要になったら必ず呼び出す
stack_push              スタックに Titem を格納
stack_pop               スタックから Titem を取り出す
*/

/* 確保した領域を全て開放する */
void stack_free(void)
{
    extern STsrs *InGnow; /* 外部変数の宣言 */

    while (InGnow != NULL)
    {
        stack_free_one();
    }
    return;
}

/* スタックからデータを取り出した領域を一つだけ開放、リストを更新 */
static void stack_free_one(void)
{
    extern STsrs *InGnow;  /* 外部変数の宣言 */
    extern STsrs *InGwork; /* 同上           */

    MacDebugFreeBef;
    /* (データを取り出した)現在のデータ位置を一つ前の位置へ */
    InGnow = InGnow->next;
    MacDebugFree;
    /* (データを取り出した)領域を、退避アドレスにより開放 */
    free(InGwork);
    /* 次のデータの更新に備えて InGnow を退避 */
    InGwork = InGnow;

    return;
}

/* スタックへ格納 */
Tboolean stack_push(const Titem item)
{
    extern STsrs *InGnow;  /* 外部変数の宣言 */
    extern STsrs *InGwork; /* 同上           */

    static STsrs *ma; /* 領域確保が失敗した時の保険 */

    ma = (STsrs *)malloc(sizeof(STsrs));
    if (ma == NULL)
    {
        return (MacFalse);
    }

    /* 確保した新たな領域を現在のデータ(スタック格納)領域とする */
    InGnow = ma;
    MacDebugMalloc;
    /* 文字列をスタックに格納 */
    strcpy(InGnow->item, item);
    /* 一つ前のデータのアドレスを格納 */
    InGnow->next = InGwork;
    /* 現在のデータのアドレスを退避 */
    InGwork = InGnow;

    return (MacTrue);
}

/* スタックから取り出し */
Tboolean stack_pop(Titem item)
{
    extern STsrs *InGnow; /* 外部変数の宣言 */

    /* スタックが空なら失敗 */
    if (InGnow == NULL)
    {
        return (MacFalse);
    }

    /* スタックからデータを取得 */
    strcpy(item, InGnow->item);
    /* 取り出した領域を開放し、スタック位置を更新 */
    stack_free_one();

    return (MacTrue);
}