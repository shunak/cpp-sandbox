/* 43_02.c バイナリ・ファイルのランダム書き込み */
#include <stdio.h>
#include "c_prac_base2.h"
#include "header.h"

int main(void)
{
    const char *file_name = "testbin";
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

    /* データをランダムに書き込み */
    if (write_random(fp) == MacFalse)
    {
        return (MacFalse);
    }

    /* 一旦読み込み位置を先頭へ */
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        err_msg_out(func_name, msg_err_fseek);
        return (MacFalse);
    }

    /* データを順次読み込み、標準出力へ出力*/
    return (read_stdout(fp));
}

/* ランダム書き込み */
int write_random(FILE *fp)
{
    const char *func_name = "write_random : ";
    const char *msg_err_fseek = "fseek error\n";
    const char *msg_err_fwrite = "fwrite error\n";
    const char *msg_header = "<<< ランダム書き込み >>>\n";
    const char *fmt_data =
        "i = %d, 書込位置 = %d, 書込データ = %d\n";
    const char w_data[] = {3, 5, 7}; /* 書き込みデータ */
    const int w_order[] = {2, 0, 1}; /* 書き込みの順番 */
    const size_t sc = sizeof(char);
    const int max = sizeof(w_data) / sizeof(w_data[0]);

    int i;
    int ret;
    char wd; /* 書き込みデータ */

    fputs(msg_header, stdout);
    for (i = 0; i < max; i++)
    {
        ret = fseek(fp, sc * w_order[i], SEEK_SET);
        if (ret != 0)
        {
            err_msg_out(func_name, msg_err_fseek);
            return (MacFalse);
        }
        wd = w_data[w_order[i]];
        fprintf(stdout, fmt_data, i, w_order[i], wd);
        fwrite(&wd, sc, 1, fp);
        if (check_stream(fp) == MacStreamError)
        {
            err_msg_out(func_name, msg_err_fwrite);
            return (MacFalse);
        }
    }
    return (MacTrue);
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

/* データを順次読み込み、標準出力へ出力 */
int read_stdout(FILE *fp)
{
    const char *func_name = "read_stdout : ";
    const char *msg_err_fread = "fread error\n";
    const char *msg_header =
        "\n<<< ファイル先頭から順次読み込み >>> \n";
    const char *fmt_data = "データ = %d\n";

    char data;
    int ret;

    fputs(msg_header, stdout);
    fread(&data, sizeof(char), 1, fp);
    ret = check_stream(fp);
    while (ret == MacStreamSuccess)
    {
        fprintf(stdout, fmt_data, data);
        fread(&data, sizeof(char), 1, fp);
        ret = check_stream(fp);
    }
    if (ret == MacStreamError)
    {
        err_msg_out(func_name, msg_err_fread);
        return (MacFalse);
    }
    return (MacTrue);
}