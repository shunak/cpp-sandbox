/* 44_00.c ビット・フィールドの基礎 */
#include <stdio.h>

int main(void)
{
    struct
    {
        unsigned int bf0 : 1; /* 符号無し、幅は 1 ビット*/
    } bf;
    int i;

    printf("sizeof( bf )  = %d\n", sizeof(bf));

    bf.bf0 = 0; /* ビット・フィールドの初期化 */
    for (i = 0; i < 3; i++)
    {
        printf("i = %d, bf.bf0 = %d\n", i, bf.bf0);
        bf.bf0++; /* ビット・フィールドの加算 */
    }

    bf.bf0 = 2; /* ビット・フィールドに直値 2 を代入 */
    printf("bf.bf0 = 2 処理後の bf.bf0 は %d\n", bf.bf0);
    // ビットフィールドは幅1のビットの値しかもつことができないので、
    // 2以上の値が割り当てられると桁あふれが発生。


    return (0);
}