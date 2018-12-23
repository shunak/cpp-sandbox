/* 23_01.c atoi 関数の検証 */
#include <stdio.h>
#include <stdlib.h>
#include "c_prac_base.h"

/* プロトタイプ宣言 */
void input_str(char *buf, int len, int endmark);
int flush_gets(char *buf, int len);

/* マクロ定義 */
#define Mac_PrgEndChar '@'
#define Mac_MaxStrLen (15 + 1)
#define Mac_ErrAlloc (-1)

int main(void)
{
    char *buf;

    buf = (char *)malloc(sizeof(char) * Mac_MaxStrLen + 4);
    if (buf == NULL)
    {
        exit(Mac_ErrAlloc);
    }

    input_str(buf, Mac_MaxStrLen, Mac_PrgEndChar);

    free(buf);
    return (0);
}
#undef Mac_PrgEndChar
#undef Mac_MaxStrLen
#undef Mac_ErrAlloc

/********************************************************************
        void input_str(
        [i/o]   char * buf,     // 文字列格納アドレスへのポインター
        [in ]   int    len,     // 文字列格納領域のバイト単位の大きさ
        [in ]   int    endmark  // 文字列入力処理終了文字コード
        );
        返し値
                無し
        処理詳細
                文字列を入力し atoi 関数により数値化、その値を表示。
                文字列先頭が endmark になるまで繰り返す。
********************************************************************/
void input_str(char *buf, int len, int endmark)
{
    int ret;

    if (buf == NULL)
    {
        return;
    }

    ret = flush_gets(buf, len);
    while ((*buf != endmark) && (ret != MacFalse))
    {
        printf("数値 = %d\n", atoi(buf));
        ret = flush_gets(buf, len);
    }
    return;
}

/********************************************************************
        int flush_gets(
        [out]   char * buf,     // 文字列格納アドレスへのポインター
        [in ]   len             // 文字列格納領域のバイト単位の大きさ
        );
        返し値
                成功 : MacTrue
                失敗 : MacFalse
        処理詳細
                入力バッファ初期化後、
                標準入力から最大 len - 1 文字入力する。
********************************************************************/
#define Mac_Msg "数記号:"

int flush_gets(char *buf, int len)
{
    fflush(stdin);
    printf(Mac_Msg);
    buf = fgets(buf, len, stdin);
    if (buf == NULL)
    {
        return (MacFalse);
    }
    return (MacTrue);
}
#undef Mac_Msg