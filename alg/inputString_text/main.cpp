/* 42_02.c 入力した文字列をテキスト・ファイルに保存。
           その後そのファイルを読み込み文字列を表示 */
#include <stdio.h>
#include <string.h>
#include "c_prac_base2.h"
#include "header.h"

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

/* main 関数の補助 */
int assist_main(AssistPrm *ap, const char *input_end)
{
    const char *msg_err_fseek = "assist_main : fseek error\n";
    const char *msg_input_start =
        "文字列を入力してください。ファイルに書き込みます。\n"
        "終了するには @end と入力してください。\n"
        "---------------------------------------------------\n\n";
    const char *msg_textout_start =
        "---------------------------------------------------\n\n"
        "書き込んだファイルの内容を出力します。\n\n";

    /* データを標準入力から入力 */
    fputs(msg_input_start, stdout);
    if (input_stdin(ap) == MacFalse)
    {
        return (MacFalse);
    }
    while (strcmp(ap->buf, input_end) != 0)
    {
        /* データをファイルへ記録 */
        if (text_write(ap) == MacFalse)
        {
            return (MacFalse);
        }
        /* データを標準入力から入力 */
        if (input_stdin(ap) == MacFalse)
        {
            return (MacFalse);
        }
    }
    /* 読み書き開始位置をファイルの先頭へ移動 */
    if (fseek(ap->fp, 0, SEEK_SET) != 0)
    {
        fputs(msg_err_fseek, stderr);
        return (MacFalse);
    }
    /* データを標準出力へ出力 */
    fputs(msg_textout_start, stdout);
    return (text_stdout(ap));
}

/* ストリームの検査 */
int check_stream(FILE *fp)
{
    if (ferror(fp) != 0)
    {
        return (MacStreamError);
    }
    if (feof(fp) != 0)
    {
        return (MacStreamEnd);
    }
    return (MacStreamSuccess);
}

/* 標準入力から指定文字数読み込み */
#define MacFncNm "input_stdin : "

int input_stdin(const AssistPrm *ap)
{
    const char *msg_err_fflush = MacFncNm "fflush error\n";
    const char *msg_err_fgets = MacFncNm "fgets error\n";
    const char *msg_eof_fgets = MacFncNm "fgets eof\n";

    if (fflush(stdin) != 0) /* 規格外 */
    {
        fputs(msg_err_fflush, stderr);
        return (MacFalse);
    }
    fgets(ap->buf, ap->buf_sz, stdin);
    switch (check_stream(stdin))
    {
    case MacStreamError:
        fputs(msg_err_fgets, stderr);
        return (MacFalse);
    case MacStreamEnd:
        fputs(msg_eof_fgets, stderr);
        return (MacFalse);
    }
    return (MacTrue);
}
#undef MacFncNm

/* データをテキスト・ファイルへ書き込む */
int text_write(AssistPrm *ap)
{
    fputs(ap->buf, ap->fp);
    if (check_stream(ap->fp) != MacStreamSuccess)
    {
        return (MacFalse);
    }
    return (MacTrue);
}

/* テキスト・ファイルの内容を標準出力へ出力 */
#define MacFncNm "text_stdout : "

int text_stdout(AssistPrm *ap)
{
    const char *msg_err_fgets = MacFncNm "fgets error\n";
    int ret;

    fgets(ap->buf, ap->buf_sz, ap->fp);
    ret = check_stream(ap->fp);
    while (ret == MacStreamSuccess)
    {
        fputs(ap->buf, stdout);
        fgets(ap->buf, ap->buf_sz, ap->fp);
        ret = check_stream(ap->fp);
    }

    if (ret == MacStreamError)
    {
        fputs(msg_err_fgets, stderr);
        return (MacFalse);
    }
    return (MacTrue);
}
#undef MacFncNm
