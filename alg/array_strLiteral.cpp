/* 29_01.c 配列に文字列リテラルを格納する */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char a1[16];
    char a2[16];
    char a3[] = {"あいうえお"};   /* 宣言と同時に初期化を記述1 */
    char a4[] = "はにほへといろ"; /* 宣言と同時に初期化を記述2 */

    /* 一つずつ代入 */
    a1[0] = 'A';
    a1[1] = 'B';
    a1[2] = 'C';
    a1[3] = '\0';

    /* strcpy を使用 */
    strcpy(a2, "xyz");

    printf(
        "a1 = %s\na2 = %s\na3 = %s\na4 = %s\n",
        a1, a2, a3, a4);

    return (0);
}