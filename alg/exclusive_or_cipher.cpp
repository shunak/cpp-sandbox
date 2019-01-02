/* 34_02.c ビット単位の排他的論理和を利用した文字配列の暗号化と復号化 */
#include <stdio.h>

/* プロトタイプ宣言 */
void en_decipher(unsigned char s[], const int sz, const unsigned char key);
void std_out(const unsigned char s[], const int sz);

/* マクロ定義 */
#define Mac_Key 0x35

int main(void)
{
    const unsigned char key = Mac_Key;
    unsigned char str[] = "ABC竹薮焼けた1234";
    const int max = sizeof(str);

    printf("最初\n%s\n", str);
    std_out(str, max);
    puts("\n暗号化後");
    en_decipher(str, max, key); /* 暗号化 */
    std_out(str, max);
    puts("\n復号化後");
    en_decipher(str, max, key); /* 復号化 */
    std_out(str, max);
    printf("\n%s\n", str); /* 元に戻った文字列を表示 */

    return (0);
}

/* データを 1 バイトずつ十六進数で標準出力へ出力 */
void std_out(const unsigned char s[], const int sz)
{
    int i;

    for (i = 0; i < sz; i++)
    {
        printf("%02X, ", s[i]);
    }
    puts("");
    return;
}

/* 暗号化と復号化 */
void en_decipher(unsigned char s[], const int sz, const unsigned char key)
{
    int i;

    for (i = 0; i < sz; i++)
    {
        s[i] ^= key;
    }
    return;
}