/* 21_01.c   y = a + b をポインターを用いて行う */
#include <stdio.h>

int main( void )
{
        int y;
        int a;
        int b;

        int * py;
        int * pa;
        int * pb;

        py = &y;
        pa = &a;
        pb = &b;

        *pa = 15;
        *pb = 23;
        *py = *pa + *pb;

        printf(
                "a = %d, b = %d, a + b = %d\n",
                a, b, y
        );

        return ( 0 );
}