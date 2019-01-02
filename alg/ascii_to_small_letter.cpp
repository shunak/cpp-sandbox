
/* 34_01.c 英字の大文字を小文字に変換
                制限 : ASCII コード専用、全角文字含まず */
#include <stdio.h>

/* プロトタイプ宣言 */
void to_small_letter(unsigned char s[], int sz);

int main(void)
{
    unsigned char greek_goddes[][10] =
        {
            "APHRODITE", "Athena", "ArTeMiS", "teST87@\\"};
    int max = sizeof(greek_goddes) / sizeof(greek_goddes[0]);
    int i;

    for (i = 0; i < max; i++)
    {
        printf("変換前 : %s\n", greek_goddes[i]);
        to_small_letter(greek_goddes[i], sizeof(greek_goddes[i]));
        printf("変換後 : %s\n\n", greek_goddes[i]);
    }

    return (0);
}

/* 英大文字を小文字に変換 */
#define Mac_ToSml ((unsigned char)0x20) /* 大文字→小文字 */
#define Mac_BigA ((unsigned char)'A')
#define Mac_BigZ ((unsigned char)'Z')
#define Mac_Nul ((unsigned char)'\0')

void to_small_letter(unsigned char s[], int sz)
{
    int i = 0;

    while ((s[i] != Mac_Nul) && (i < sz))
    {
        if ((s[i] >= Mac_BigA) && (s[i] <= Mac_BigZ))
        {
            s[i] |= Mac_ToSml;
        }
        i++;
    }
    return;
}
#undef Mac_ToSml
#undef Mac_BigA
#undef Mac_BigZ
#undef Mac_Nul