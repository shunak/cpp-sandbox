/* 39_03.c 構造体型の入れ子 */
#include <stdio.h>

/* 構造体型の宣言 */
struct tag_a
{
    char s[16];
    int max;
};

struct tag_b
{
    struct tag_a a; /* 入れ子 */
    double d;
};

/* プロトタイプ宣言 */
void sub(struct tag_b *b);

int main(void)
{
    struct tag_b b =
        {
            {"abcdef", 6},
            3.14};

    sub(&b);

    return (0);
}

/* sub 関数側 */
void sub(struct tag_b *b)
{
    printf("b->a.s   = %s\n", b->a.s);
    printf("b->a.max = %d\n", b->a.max);
    printf("b->d     = %f\n", b->d);
    return;
}