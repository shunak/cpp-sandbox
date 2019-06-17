#include <stdio.h>

typedef unsigned short u16;
typedef unsigned int u32;

u16 changeEngian16(u16 n);
u32 changeEngian32(u32 n);

int main(void)
{
    u16 n1 = 0x1234;
    u32 n2 = 0x12345678;

    n1 = changeEngian16(n1);
    printf( "%x\n", n1 );
    n1 = changeEngian16(n1);
    printf( "%x\n", n1 );

    n2 = changeEngian32(n2);
    printf( "%x\n", n2 );
    n2 = changeEngian32(n2);
    printf( "%x\n", n2 );

    return 0;
}

/*
 *     16bit の整数値のエンディアンを、リトル・ビッグ間で変換する。
 *     */
u16 changeEngian16(u16 n)
{
        u16 r;

            r  = n / 0x100;
                r += (n % 0x100) * 0x100;
                    return r;
}

/*
 *     32bit の整数値のエンディアンを、リトル・ビッグ間で変換する。
 *     */
u32 changeEngian32(u32 n)
{
    u32 r;

    r  = ((n / 0x1000000) % 0x100);
    r += ((n / 0x10000) % 0x100) * 0x100;
    r += ((n / 0x100) % 0x100) * 0x10000;
    r += (n % 0x100) * 0x1000000;
    return r;
}



