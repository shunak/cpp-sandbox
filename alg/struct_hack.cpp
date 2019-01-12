/* 39_04.c 規格違反だが有名な手法 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 構造体型の宣言 */
struct tag_mem
{
    int size;
    char buf[1];
};

/* マクロ定義 */
#define MacBufferSize 1024
#define MacStr "構造体型の配列長より長い文字列を複写します"
#define MacFmt0 "バッファ容量 : %d\n文   字   列 : %s\n"
#define MacFmt1 "&( mem->buf[ %d ] ) = %p\n"

int main(void)
{
    struct tag_mem *mem;
    int i;

    mem = (struct tag_mem *)malloc(
        sizeof(struct tag_mem) +
        sizeof(char) * (MacBufferSize - 1));
    if (mem == NULL)
    {
        exit(-1);
    }
    mem->size = MacBufferSize;
    strcpy(mem->buf, MacStr);
    printf(MacFmt0, mem->size, mem->buf);
    for (i = 0; i < 100; i++)
    {
        printf(MacFmt1, i, &(mem->buf[i]));
    }

    free(mem);
    return (0);
}



/**
 * 規格、即ち C90 では配列の要素に対し、宣言時の要素数以上の値を指定した場合の動作は未定義です。どうなるか分からないので指定してはいけません。例えば char c[ 2 ]; との宣言があると、 c[ 1 ] は正しい指定ですが c[ 2 ] の結果は予想出来ません。
　ところが実際問題として、 c[ 2 ] は c[ 1 ] より char 型一つ分先を示す動作をするコンパイラーが多いです。これを逆手に取って次のプログラムの様な有名な技法が生まれました。何度も書きますが未定義動作であり規格違反です。
 * 
 * **/