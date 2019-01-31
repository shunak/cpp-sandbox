/* 43_01.c バイナリ・ファイルのランダム読み込み */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_prac_base2.h"
#include "header.h"

/* main 関数 */
int main(void)
{
    const char *file_name = "item_master";
    const char *open_mode = "rb";//read binary
    const char *func_name = "main : ";
    const char *msg_err_fopen = "fopen error\n";
    const char *msg_err_fclose = "fclose error\n";

    FILE *fp = fopen(file_name, open_mode);

    if (fp == NULL)
    {
        err_msg_out(func_name, msg_err_fopen);
        return (MacReturnErr);
    }

    /* 主処理 */
    if (assist_main(fp) == MacFalse)
    {
        fclose(fp);
        return (MacReturnErr);
    }

    /* 後始末 */
    if (fclose(fp) != 0)
    {
        err_msg_out(func_name, msg_err_fclose);
        return (MacReturnErr);
    }
    return (MacReturnOk);
}

/* 関数内のエラー表示 */
void err_msg_out(const char *func_name, const char *msg)
{
    fputs(func_name, stderr);
    fputs(msg, stderr);
    return;
}

/* main 関数の補助 */
int assist_main(FILE *fp)
{
    const char *func_name = "assist_main : ";
    const char *msg_err_fseek = "fseek error\n";
    const char *msg_mode[] = {
        "<<先頭からの絶対位置を指定します>>\n",
        "<<現在位置からの相対位置を指定します>>\n"};

    char buf[MacStdinBuffer + 4];
    int ret;

    /* 配列の様にファイルからデータを読み込み */
    fputs(msg_mode[MacModeArray], stdout);
    ret = input_read(fp, buf, MacStdinBuffer, MacModeArray);
    if (ret == MacFalse)
    {
        return (MacFalse);
    }
    /* 一旦読み込み位置を先頭へ */
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        err_msg_out(func_name, msg_err_fseek);
        return (MacFalse);
    }
    /* ポインターの様にファイルからデータを読み込み */
    fputs(msg_mode[MacModePointer], stdout);
    ret = input_read(fp, buf, MacStdinBuffer, MacModePointer);

    return (ret);
}

/* 標準入力から入力した値を元に、ファイルからデータを読み込み */
int input_read(FILE *fp, char *buf, const int buf_size, const int mode)
{
    const char *func_name = "input_read : ";
    const char *msg_err_fread = "fread error\n";
    const int seek_mode[] = {SEEK_SET, SEEK_CUR};
    const size_t read_cnt = 1;
    const size_t sz = sizeof(STitem);

    int result;        /* 入力文字列を整数化した値 */
    int r;             /* 汎用 */
    STitem item;       /* 読み込みデータ格納用 */
    long now_pos;      /* 現在のファイル読み書き位置 */
    long bef_pos;      /* 直前のファイル読み書き位置 */
    TstreamStatus ret; /* ストリームの状態格納用 */

    if (get_nowpos(fp, sz, &now_pos) == MacFalse)
    {
        return (MacFalse);
    }
    ret = input_stdin(buf, buf_size, now_pos, &result);
    while (ret == MacStreamSuccess)
    {
        r = move_pos(fp, sz, result, seek_mode[mode]);
        if (r == MacFalse)
        {
            return (MacFalse);
        }
        /* fread のエラーに備えて現在の読み書き位置を取得 */
        if (get_nowpos(fp, sz, &bef_pos) == MacFalse)
        {
            return (MacFalse);
        }
        fread(&item, sizeof(STitem), read_cnt, fp);
        if (check_stream(fp) == MacStreamSuccess)
        {
            data_stdout(&item);
        }
        else
        {
            err_msg_out(func_name, msg_err_fread);
            clearerr(fp); /* 処理続行の為エラー初期化 */
            /* fread 直前に取得した読み書き位置へ移動する。
                           fread エラー後は読み書き位置が不定になり
                           ftell も不定になる為、退避していた値を使用 */
            r = move_pos(fp, sz, bef_pos, SEEK_SET);
            if (r == MacFalse)
            {
                return (MacFalse);
            }
        }
        if (get_nowpos(fp, sz, &now_pos) == MacFalse)
        {
            return (MacFalse);
        }
        ret = input_stdin(buf, buf_size, now_pos, &result);
    }
    return (MacTrue);
}

/* 現在の読み書き位置を
   オブジェクトの大きさの先頭からの相対値として取得し、
   *pos へ格納。エラー時 *pos は不定 */
int get_nowpos(FILE *fp, const size_t size, long *pos)
{
    static const char *func_name = "get_nowpos : ";
    static const char *msg_err_ftell = "ftell error\n";

    static long now_pos;

    now_pos = ftell(fp);
    if (now_pos < 0)
    {
        err_msg_out(func_name, msg_err_ftell);
        return (MacFalse);
    }
    *pos = now_pos / size;
    return (MacTrue);
}

/* 読み書き位置を変更 */
int move_pos(FILE *fp, const size_t size, const long pos,
             const int mode)
{
    static const char *func_name = "move_pos : ";
    static const char *msg_err_fseek = "fseek error\n";

    if (fseek(fp, size * pos, mode) != 0)
    {
        err_msg_out(func_name, msg_err_fseek);
        return (MacFalse);
    }
    return (MacTrue);
}

/* 標準入力からデータを入力、数値化して *result へ格納 */
TstreamStatus input_stdin(char *buf, const int buf_size,
                          const int now_pos, int *result)
{
    if (fflush(stdin) == EOF) /* 規格外 */
    {
        return (MacStreamError);
    }
    fprintf(stdout, "現在位置 [ %2d ] : ", now_pos);
    if (fgets(buf, buf_size, stdin) == NULL)
    {
        return (MacStreamError);
    }
    if (strcmp(buf, MacStrInputEnd) == 0)
    {
        return (MacStreamEnd);
    }
    *result = atoi(buf);
    return (MacStreamSuccess);
}

/* ストリームの検査 */
TstreamStatus check_stream(FILE *fp)
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

/* 商品データを標準出力へ出力 */
void data_stdout(const STitem *item)
{
    static const char *fmt =
        "商品コード : %s, 商品名 : %s, 通常小売価格 : %d\n";

    fprintf(stdout, fmt, item->code, item->name, item->price);
    return;
}
