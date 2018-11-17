#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>


/* 02_00.c */
// ポインタ　：　アドレスが指すメモリの中身
// 例：ポインタにアドレスAを代入すると、Aが指すメモリの中身を指すようになる
int main(void)
{
    char stack[2];
    char *data = stack;
    char left_hand;
    /* アドレス*/
    *data = (char)0x20;      /* 1000    */
    left_hand = *data;       /* 1001    */
    *(data + 1) = left_hand; /* 1002    */

    return (0); /* 1003    */
}