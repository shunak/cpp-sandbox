#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

/* 02_01.c */
int main(void)
{
    char stack[3];
    char *data0 = &(stack[0]);
    char *data1 = &(stack[1]);
    char *answer = &(stack[2]);

    /* アドレス */
    *data0 = (char)0x9;                /* 1000     */
    *data1 = (char)0x1;                /* 1001     */
    *answer = (char)(*data0 + *data1); /* 1002     */

    // ポインタ型の値を10進数で表示
    printf("%d\n",*answer);
    // ポインタ型の値を16進数で表示
    printf("%x\n",*answer);

    return (0); /* 1003     */
}