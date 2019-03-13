#include <stdio.h>

int main(void)
{
    int y;
    int a;
    int b;

    int *py;
    int *pa;
    int *pb;

    py = &y;
    pa = &a;
    pb = &b;

    *pa = 15;
    *pb = 23;
    *py = *pa + *pb;

    printf("a=%d\n",a);
    // 変数aへ値を代入するというのは、変数aのアドレスのメモリに値を書き込むことを意味する

    // printf(
    //     "*pa = %d, *pb = %d, *pa + *pb = %d\n",
    //     *pa, *pb, *py);

    return (0);
}
