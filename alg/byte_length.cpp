#include <stdio.h>

int main(void)
{
    int ret1;
    int ret2;

    ret1 = printf("ABCDEFG\n");
    ret2 = printf("ABCD\n");

    printf("結果 : ret1 = %d / ret2 = %d\n", ret1, ret2);

    return (0);
}