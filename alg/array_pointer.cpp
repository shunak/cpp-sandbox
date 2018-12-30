/* 29_03.c 配列のポインターの関係 */
#include <stdio.h>

int main(void)
{
    char * s = "ABCDEFG";

    printf("s[ 5 ]       = %c\n", s[5]);
    printf("5[ s ]       = %c\n", 5 [s]);
    printf("5[\"ABCDEFG\"] = %c\n", 5 ["ABCDEFG"]);

    return (0);
}