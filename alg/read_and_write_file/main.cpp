/* 42_01.c テキスト・ファイルの書き込み */
#include <stdio.h>
#include "c_prac_base2.h"

/* マクロ定義 */
#define MacS0 "abc文字列      左はタブです。\\これは円記号です。\n"
#define MacS1 "     先頭五文字は半角空白です。\n"
#define MacS2 "     先頭と末尾に五文字ずつ半角空白。     \n"
#define MacS3 "次行は改行だけです。\n"
#define MacS4 "\n"
#define MacS5 "改行だけの後です。\n"
#define MacFileName "textfile"
#define MacOpenMode "w+"
#define MacBufferSize 128

/* プロトタイプ宣言 */
int text_write(FILE *fp, const char *s[], size_t sz);
int text_read(FILE *fp, char *buf, int buf_sz);

int main(void)
{
    char buf[MacBufferSize + 4];
    const char *s[] = {MacS0, MacS1, MacS2, MacS3, MacS4, MacS5};
    const size_t sz = sizeof(s) / sizeof(s[0]);
    FILE *fp = fopen(MacFileName, MacOpenMode);

    if (fp == NULL)
    {
        fputs("fopen error\n", stderr);
        goto err_exit;
    }

    /* 書き込み */
    if (text_write(fp, s, sz) == MacFalse)
    {
        goto err_exit;
    }

    /* ファイルの読み書き位置を先頭へ移動 */
    if (fseek(fp, 0, SEEK_SET) != 0)
    {
        fputs("fseek error\n", stderr);
        goto err_exit;
    }

    /* 読み込みと標準出力へ出力 */
    if (text_read(fp, buf, MacBufferSize) == MacFalse)
    {
        goto err_exit;
    }

    /* 後始末 */
    if (fclose(fp) == 0) /* プログラム終了前に必ず閉じる */
    {
        return (MacReturnOk);
    }
    fputs("fclose error\n", stderr);
    return (MacReturnErr);

    /* エラー発生、ファイルを閉じて終了 */
err_exit:
    if (fp != NULL)
    {
        fclose(fp); /* プログラム終了前に必ず閉じる */
    }
    return (MacReturnErr);
}





/* 書き込み */
int text_write(FILE *fp, const char *s[], size_t sz)
{
    size_t i;
    int ret;

    for (i = 0; i < sz; i++)
    {
        ret = fputs(s[i], fp);
        if (!(ret >= 0))
        {
            fputs("fputs error\n", stderr);
            return (MacFalse);
        }
    }
    return (MacTrue);
}

/***
 * 本関数の第一引数が FILE 型へのポインター、第二引数は書き込むデータの配列、第三引数がデータの配列の最大要素数です。

ret = fputs( s[ i ], fp );
　この文でファイルの書き込みを行っています。書き込むデータは text_write 関数の第二引数の配列値で、それは文字列リテラルの先頭アドレスです。
　ファイルを "w+" の更新新規作成で開いた直後、ファイルの読み書き開始位置はそのファイルの先頭を指しています。データを書き込むとファイルの読み書き開始位置はそのデータの分だけ進みます。ファイルの最後を常に示すので連続して書き込んでもデータは最後に追加される形になります。便利ですね。
　fputs の戻り値検査をご覧ください。

if ( !( ret >= 0 ) )
　fputs の戻り値は成功すれば 0 以上の整数、失敗すれば EOF です。では何故 EOF で判断しないか、です。成功した時の値が「 EOF ではない値」であれば EOF か否かで判断すべきです。しかし EOF は単一の値で負数です。その他の負数の場合はどうするのか、といった条件判断するには不明確な領域があります。それを排除するには成功した時の否定を用いるのが良いでしょう。成功していない、即ち失敗です。これなら条件が明確になるのでこの様な記述をしてみました。勿論 if ( ret == EOF ) も正しい記述です。

 * */

/* 読み込み */
int text_read(FILE *fp, char *buf, int buf_sz)
{
    int ret = MacTrue;
    char *st;

    for (;;)                         /* 無限ループ */
    {                                /* 悪例 */
        st = fgets(buf, buf_sz, fp); /* 読み込み */
        /* ファイル終端なら無限ループ脱出 */
        if (feof(fp) != 0)
        {
            break;
        }
        /* エラーならその旨を出力の後無限ループ脱出 */
        if (st == NULL)
        {
            fputs("fgets error\n", stderr);
            ret = MacFalse;
            break;
        }
        fputs(buf, stdout); /* 標準出力へ出力 */
    }
    return (ret);
}



/**
 * 本関数の第一引数は FILE 型へのポインターです。第二引数は一行分のデータを格納するバッファーの先頭アドレスです。第三引数はバッファーの大きさです。

st = fgets( buf, buf_sz, fp );
ここでファイルから一行読み込み、読み込んだデータを指定アドレスに対し最大で指定された容量を書き込みます。読み込んだデータ末尾に文字列終端を示すヌル文字を追加するので、読み込む最大容量は指定した大きさより 1 少なくなります。
　この関数の戻り値は、成功すれば指定したバッファーの先頭アドレスが、失敗或いはファイルの最後に達した場合はヌル・ポインターです。読み込み失敗なのか或いはファイルの最後に到達したのかを切り分ける必要があります。そこで一旦 st にポインター値を格納します。
　fgets 関数の戻り値を条件判断の材料にする場合、判断する順番は大切です。最初に fgets 関数の戻り値を判断してしまっては条件の切り分けが出来ません。
　ここではまずファイルの最後かを判断し、その後でエラーか否かを判断しています。今回用いたこの手法はしてはいけません。説明の為に敢えて行ったのです。理由は後述します。
　まずは feof 関数を用いてファイルの終端であれば読み込みの無限ループを抜けます。まだファイルの途中であれば退避しておいた fgets 関数の戻り値を調べます。この条件を判断するのはファイルの終端ではない場合です。従って fgets 関数の戻り値がヌル・ポインターならそれはエラーの時だけになります。エラーならばそれに応じた処理をします。
　ファイルの終端でもなくエラーでもない。即ち正常にデータを読み込めたので fputs 関数にて標準出力に今読み込んだデータを出力しています。ここでも fputs 関数を使用しています。 puts 関数と異なり改行処理は行われません。しかしデータ内には改行コード '\n' が含まれていますから大丈夫です。
 * 
 * 
 * 
 * 
 * */ 