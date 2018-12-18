/* 22_02.c malloc と free 関数の使用法 */
#include <stdio.h>
#include <stdlib.h>

/* マクロ定義 */
#define MacElem 4        /* 確保する要素数 */
#define MacErrAlloc (-1) /* 領域確保失敗 */

int main(void)
{
    char *pc;

    /* char * 型のメモリ領域を確保 */
    pc = (char *)malloc(sizeof(char) * MacElem);
    if (pc == NULL)
    {
        fputs("malloc 失敗", stderr);
        exit(MacErrAlloc);
    }
    puts("char * 型のメモリ領域の確保に成功");
    free(pc); /* 確保した領域を開放 */

    return (0);
}
