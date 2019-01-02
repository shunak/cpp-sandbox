
/* 34_00.c 英字の小文字を大文字に変換
                制限 : ASCII コード専用、全角文字含まず */
#include <stdio.h>

/* プロトタイプ宣言 */
void to_big_letter(unsigned char s[], int sz);

int main(void)
{
    unsigned char greek_god[][12] =
        {
            "zeus", "appolo", "eros", "poseidon", "TesT123@[]="};
    int max = sizeof(greek_god) / sizeof(greek_god[0]);
    int i;

    // printf("%d\n", max); // 5 // 1次元目の配列要素数
    // printf("%d\n",sizeof(greek_god[0])); // 12 二次元目の配列のサイズ
    // printf("%d\n",sizeof(greek_god)); // 60 配列全体の要素数


    for (i = 0; i < max; i++)
    {
        printf("変換前 : %s\n", greek_god[i]);
        to_big_letter(greek_god[i], sizeof(greek_god[i]));
        printf("変換後 : %s\n\n", greek_god[i]);
    }

    return (0);
}

/* 英小文字を大文字に変換 */
#define Mac_ToBig ((unsigned char)0xDF) /* 小文字→大文字 */　//0xDF=1101 1111
#define Mac_SmlA ((unsigned char)'a')
#define Mac_SmlZ ((unsigned char)'z')
#define Mac_Nul ((unsigned char)'\0')

void to_big_letter(unsigned char s[], int sz)
{
    int i = 0;

    while ((s[i] != Mac_Nul) && (i < sz))
    {
        if ((s[i] >= Mac_SmlA) && (s[i] <= Mac_SmlZ))
        {
            s[i] &= Mac_ToBig;
        }
        i++;
    }
    return;
}
#undef Mac_ToBig
#undef Mac_SmlA
#undef Mac_SmlZ
#undef Mac_Nul
