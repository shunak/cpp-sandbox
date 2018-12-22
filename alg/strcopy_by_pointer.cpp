/* 22_06.c 文字列リテラルのデータを読み書き可能領域へ複写 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* マクロ定義 */
#define MacErrMalloc (-1) /* malloc エラー */
#define MacErr_StrCpy (-2)

/* プロトタイプ宣言 */
int StrCpy(char *s_out, char *s_in);
void copy_print(char *s);

int main(void)
{
    char *pc0 = "ABCDEFG";
    char *pc1 = "あいうえお";

    copy_print(pc0);
    copy_print(pc1);

    return (0);
}

/* 文字列複写領域の確保、開放、複写文字列の出力 */
void copy_print(char *s)
{
    char *mem;
    int len;

    /* +1 は '\0' の分、+4 は予備 */
    mem = (char *)malloc(sizeof(char) * strlen(s) + 1 + 4);
    if (mem == NULL)
    {
        exit(MacErrMalloc);
    }

    len = StrCpy(mem, s);
    if (len != MacErr_StrCpy)
    {
        printf(
            "複写文字列長:%2d / 複写先文字列:%s\n",
            len, mem);
    }

    free(mem);
    return;
}

/********************************************************************
        int StrCpy(
                char * s_out    // 複写先となる文字列へのポインター
                char * s_in     // 複写元         〃             
        );
        返し値
                成功 : 文字列長。終端 '\0' 含まず
                失敗 : MacErr_StrCpy
        処理詳細
                s_in の指し示す文字列を、s_out の領域へ複写する。
                s_in 、s_out の何れかがヌル・ポインターならエラー。
********************************************************************/
int StrCpy(char *s_out, char *s_in)
{
    int len = 0; /* 文字列長 */

    if ((s_out == NULL) || (s_in == NULL))
    {
        return (MacErr_StrCpy);
    }

    while (*s_in != '\0')
    {
        *s_out = *s_in;
        s_out += 1;
        s_in += 1;
        len += 1;
    }
    *s_out = '\0'; /* 注意:while内では '\0' が複写されない為 */

    return (len);
}