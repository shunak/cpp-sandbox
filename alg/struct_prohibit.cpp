/* 39_06.c 構造体メンバー間をポインターで相対指定してはいけない理由 */
#include <stdio.h>

#define MacFmt "&( st.a ) = %p\n&( st.b ) = %p\n&( st.c ) = %p\n"

int main(void)
{
    struct tag
    {
        int a;
        char b;
        int c;
    };

    struct tag st;

    printf(MacFmt, &(st.a), &(st.b), &(st.c));

    return (0);
}