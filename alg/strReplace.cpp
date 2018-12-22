/* 22_07 文字列書き換え */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* プロトタイプ宣言 */
void change(char *s, char org, char chg);

/* マクロ定義 */
#define Mac_ErrMalloc (-1)
#define Mac_Strings "hujisanroku oomunaku"
#define Mac_CharOrg 'u'
#define Mac_CharChg '#'

int main(void)
{
    // 文字列リテラルの先頭アドレスをポインタ変数に代入
    char *s = Mac_Strings;
    char *buf;

    buf = (char *)malloc(sizeof(char) * strlen(s) + 5);
    if (buf == NULL)
    {
        exit(Mac_ErrMalloc);
    }

    strcpy(buf, s);
    change(buf, Mac_CharOrg, Mac_CharChg);
    printf("変更前:%s\n変更後:%s\n", s, buf);

    free(buf);
    return (0);
}
#undef Mac_ErrMalloc
#undef Mac_Strings
#undef Mac_CharOrg
#undef Mac_CharChg

/* 文字を変更する */
void change(char *s, char org, char chg)
{
    while (*s != '\0')
    {
        if (*s == org)
        {
            *s = chg;
        }
        s += 1;
    }
    return;
}