/* 42_02.c 入力した文字列をテキスト・ファイルに保存。
           その後そのファイルを読み込み文字列を表示 */
#include <stdio.h>
#include <string.h>
#include "c_prac_base2.h"
#include "42_02.h"

/* main 関数 */
#define MacInputEnd "@end\n" /* 入力には改行が含まれる為 */
#define MacFileName "textfile"
#define MacOpenMode "w+"
#define MacBufferSize (127 + 1) /* ヌル文字の分も必要 */
#define MacMsgErrFOpen "error : fopen\n"
#define MacMsgErrFClose "error : fclose\n"

int main(void)
{
    char buf[MacBufferSize + 4];
    AssistPrm ap;

    /* 初期化 */
    ap.fp = fopen(MacFileName, MacOpenMode);
    if (ap.fp == NULL)
    {
        fputs(MacMsgErrFOpen, stderr);
        return (MacReturnErr);
    }
    ap.buf = buf;
    ap.buf_sz = MacBufferSize;

    /* 主処理 */
    if (assist_main(&ap, MacInputEnd) == MacFalse)
    {
        fclose(ap.fp);
        return (MacReturnErr);
    }

    /* 後始末 */
    if (fclose(ap.fp) == 0)
    {
        return (MacReturnOk);
    }
    fputs(MacMsgErrFClose, stderr);
    return (MacReturnErr);
}
#undef MacFileName
#undef MacOpenMode
#undef MacBufferSize
#undef MacInputEnd
#undef MacMsgErrFOpen
#undef MacMsgErrFClose