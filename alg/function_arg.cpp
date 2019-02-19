/* 46_04.c main 関数の引数を表示 */
#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc == 0)
    {
        puts("argc : 0");
        return (0);
    }

    printf("argc : %d\n", argc);
    for (i = 0; i < argc; i++)
    {
        printf("argv[ %d ] : %s\n", i, argv[i]);
    }
    return (0);
}