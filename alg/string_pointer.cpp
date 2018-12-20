/* 22_03.c 文字列リテラルのバイト数を求める */
#include <stdio.h>

/* マクロ定義 */
#define MacS "ABCDEF"

int main(void)
{
    char *pc = MacS;
    // char *pc = "abc";

    printf("MacS = %s\npc   = %s\n", MacS, pc);
    printf("sizeof ( pc )   = %d\n", sizeof(pc));
    printf("sizeof ( MacS ) = %d\n", sizeof(MacS));

    return (0);
}
