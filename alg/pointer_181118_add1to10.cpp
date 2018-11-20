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
    char stack[2]; //要素数2のchar型の配列を準備
    char *ans = stack;//ポインタ変数*ansにstack[0]のアドレスを参照させる
    char *cnt = &stack[1];//ポインタ変数*cntにstack[1]のアドレスを参照させる

    *ans = (char)0x1;//*ansポインタがいま参照しているアドレスstack[0]のなかに(char)0x1を代入
    *cnt = (char)0x2;

    do
    {
        *ans+=*cnt;
        (*cnt)++;
    } while (*cnt<=(char)0xa);

    printf("%x\n",*ans);

    return (0); 


}