/* 29_04.c 配列と関数、そのプロトタイプ宣言、
        そして文字列 "ABC\0EF\0" の例           */
#include <stdio.h>
#include <string.h>

/* プロトタイプ宣言 */
void std_out(char s[], int size);

int main(void)
{
    char str[] = "ABCDEF";
    int size = strlen(str) + 1; /* 文字列長 + 1 == 配列の大きさ */

    /* 通常の文字列 */
    printf("str = %s\n", str);
    std_out(str, size);

    /* 途中を \0 に書き換え */
    str[3] = '\0';
    printf("\n書き換え後\nstr = %s\n", str);
    std_out(str, size);

    return (0);
}

void std_out(char s[], int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf(
            "%d 文字目 : コード = %2d, 文字 = %c\n",
            i, s[i], s[i]);
    }
}