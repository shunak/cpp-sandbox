#include <stdio.h>

int main(){

    struct tag
    {
        int *a;
    };

    static int i[] = {12, 24};
    struct tag x = {i};
    struct tag *const y = &x;

    y->a += 1;    /* C  */
    *(y->a) += 1; /* D  */

    printf("%d\n",*(y->a));

    return 0;
}
