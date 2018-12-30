/* 29_02.c 文字列リテラルの配列としての使用例
        説明用ですから実際に使用してはいけません */
#include <stdio.h>

int main(void)
{
    char a;

    a = "ABCDEFG"[5];
    printf("%c\n", a);

    return (0);
}