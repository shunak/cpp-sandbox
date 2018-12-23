/* 23_00.c 標準入力から指定文字数分だけ文字列を入力 */
#include <stdio.h>
#include <stdlib.h>

/* プロトタイプ宣言 */
int InputString(char *s, int buf_size);

/* マクロ定義 */
#define Mac_ErrInStr (-1)   /* InputString のエラー */
#define Mac_MaxLen (10 + 1) /* 最大入力文字数。+1は'\0'の分 */

#define Mac_ErrAlloc (-1)

int main(void)
{
    char *buf;
    int len;

    buf = (char *)malloc(sizeof(char) * Mac_MaxLen + 4);
    if (buf == NULL)
    {
        exit(Mac_ErrAlloc);
    }

    fflush(stdin); /* 規格外 */
    len = InputString(buf, Mac_MaxLen);
    if (len == Mac_ErrInStr)
    {
        puts("入力処理失敗");
    }
    else
    {
        printf("入力文字数 = %d\n入力文字列 = %s\n", len, buf);
    }

    free(buf);
    return (0);
}
#undef Mac_ErrAlloc

/********************************************************************
        int InputString(
        [out]   char * s,       // 文字列格納領域へのポインター
        [in ]   int    buf_size // 文字列格納領域のバイト単位の大きさ
        );
        返し値
                成功 : 入力文字列の長さ。終端 '\0' 含まず。
                失敗 : -1 ( Mac_ErrInStr )
        処理詳細
                標準入力から最大 ( buf_size - 1 ) の文字列を読込む。
                格納した文字列終端には '\0' を付加する。
********************************************************************/
int InputString(char *s, int buf_size)
{
    int c;
    int cnt = 0; /* 入力文字数 */

    if (s == NULL)
    {
        return (Mac_ErrInStr);
    }

    buf_size -= 1; /* '\0' の分を読み込ませない為 */
    c = fgetc(stdin);
    while ((c != '\n') && (cnt < buf_size) && (c != EOF))
    {
        *s = (char)c;
        s += 1;
        cnt += 1;
        c = fgetc(stdin);
    }
    *s = (char)'\0'; /* 文字列終端コードの格納 */

    return (cnt);
}