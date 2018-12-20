/* 22_04.c 型の大きさによるポインターの変化 */
#include <stdio.h>
#include <stdlib.h>

/* マクロ定義 */
#define MacErrMalloc (-1) /* malloc エラー */
#define MacAllocSz 2      /* malloc 確保する個数 */

int main(void)
{
    short *ps;
    char *pc;

    ps = (short *)malloc(sizeof(short) * MacAllocSz);
    pc = (char *)ps; /* ps のアドレスを char 型で操作の為 */
    if (ps == NULL)
    {
        exit(MacErrMalloc);
    }
    /* メモリ領域を short 値で初期化 */
    *(ps + 0) = (short)0x1234;
    *(ps + 1) = (short)0x5678;
    /* ポインターの指し示すアドレスとその内容を表示 */
    printf("ps + 0 = %p / *( ps + 0 ) = %X\n", ps + 0, *(ps + 0));
    printf("ps + 1 = %p / *( ps + 1 ) = %X\n", ps + 1, *(ps + 1));
    printf("pc + 0 = %p / *( pc + 0 ) = %X\n", pc + 0, *(pc + 0));
    printf("pc + 1 = %p / *( pc + 1 ) = %X\n", pc + 1, *(pc + 1));

    free(ps);
    return (0);
}