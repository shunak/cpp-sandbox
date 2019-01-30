/* 43_00.c バイナリ・ファイルの順次読み書き */
#include <stdio.h>
#include "c_prac_base2.h"
#include "header.h"

/* main 関数 */
int main(void)
{
    const char *file_name = "item_master";
    const char *open_mode = "wb+";
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

    /* 商品マスター・ファイル作成 */
    if (write_master_file(fp) == MacFalse)
    {
        return (MacFalse);
    }

    /* ファイルの先頭へ読み書き位置を移動 */
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        err_msg_out(func_name, msg_err_fseek);
        return (MacFalse);
    }

    /* 商品マスター・ファイルを読み込み、標準出力へ出力 */
    return (read_stdout_master_file(fp));
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

/* 商品マスター・ファイル作成 */
int write_master_file(FILE *fp)
{
    const int max_item = 5;
    const int size_STitem = sizeof(STitem);
    const int rw_cnt = 1;
    const char *func_name = "write_master_file : ";
    const char *msg_err_fwrite = "fwrite error\n";

    STitem item;
    int i;
    int ret;

    /* 商品マスター・ファイル作成 */
    for (i = 0; i < max_item; i++)
    {
        set_item(&item, i);
        ret = fwrite(&item, size_STitem, rw_cnt, fp);
        if (ret < rw_cnt)
        {
            err_msg_out(func_name, msg_err_fwrite);
            return (MacFalse);
        }
    }

    return (MacTrue);
}

/* STitem 型変数へデバッグ用データ格納 */
void set_item(STitem *item, const int i)
{
    static const int start_cd = 10002000;
    static const int price = 1000;
    static const char *fmt_code = "%08d";
    static const char *fmt_name = "商品名-------%02d";
    /*1234567890123*/

    sprintf(item->code, fmt_code, start_cd + i);
    sprintf(item->name, fmt_name, i);
    item->price = (i + 1) * price;
    return;
}

/* 商品マスター・ファイル読み込み、標準出力へ出力 */
int read_stdout_master_file(FILE *fp)
{
    const int size_STitem = sizeof(STitem);
    const int rw_cnt = 1;
    const char *func_name = "read_stdout_master_file : ";
    const char *msg_err_fread = "fread error\n";

    STitem item;
    int ret;

    fread(&item, size_STitem, rw_cnt, fp);
    ret = check_stream(fp);
    while (ret == MacStreamSuccess)
    {
        item_stdout(&item);
        fread(&item, size_STitem, rw_cnt, fp);
        ret = check_stream(fp);
    }

    if (ret == MacStreamError)
    {
        err_msg_out(func_name, msg_err_fread);
        return (MacFalse);
    }

    return (MacTrue);
}

/* item の内容を標準出力へ出力 */
void item_stdout(STitem *item)
{
    static const char *fmt_head =
        "商品コード  商品名           通常小売価格\n"
        "--------    ---------------  ------------\n";
    static const char *fmt_item = "%8s    %s  %12d\n";

    static int flg = MacFalse;

    if (flg == MacFalse) /* 題の表示は最初の一回だけ */
    {
        flg = MacTrue;
        fputs(fmt_head, stdout);
    }
    fprintf(stdout, fmt_item, item->code, item->name, item->price);
    return;
}
