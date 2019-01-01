/* 33_00.c ポインターへのポインター */
#include <stdio.h>

int main(void)
{
    char a = 10;
    char *pa = &a;
    char **pp = &pa;

    printf(
        "変数の値\n"
        "a  = %d\npa = %p\npp = %p\n\n",
        a, pa, pp);
    printf(
        "変数のアドレス\n"
        "&a  = %p\n&pa = %p\n&pp = %p\n\n",
        &a, &pa, &pp);
    printf("間接参照\n*pa = %d\n*pp = %p\n\n", *pa, *pp);

    printf("間接参照の間接参照\n**pp     = %d\n", **pp);
    printf("間接参照の間接参照\n*( *pp ) = %d\n", *(*pp));

    return (0);
}