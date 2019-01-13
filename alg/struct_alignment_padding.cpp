
/* 39_05.c 構造体のアラインメントとパディング */
#include <stdio.h>

int main(void)
{
    struct tag_a
    {
        int o;
        int p;
    };

    struct tag_b
    {
        int q;
        char r;
    };

    printf("sizeof( struct tag_a ) = %d\n"
           "sizeof( struct tag_b ) = %d\n",
           sizeof(struct tag_a), sizeof(struct tag_b));

    return (0);
}