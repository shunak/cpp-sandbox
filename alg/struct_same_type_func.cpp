/* 39_01.c 構造体そのものを関数の引数及び戻り値とする */
#include <stdio.h>
#include <string.h>

/* 構造体型の宣言 */
struct tag_str
{
    char s[200];
};

/* プロトタイプ宣言 */
struct tag_str sub(struct tag_str str); /*struct tag_str型で関数を宣言　構造体は同一の型であれば通常の変数と同じ様に構造体変数間で代入が可能です。となると同一の構造体型なら関数の引数や戻り値としても使用可能であり、次のプログラムはその一例です。*/

int main(void)
{
    struct tag_str str;

    strcpy(str.s, "レキシントンの幽霊");
    printf("str.s = %s\n", str.s);
    str = sub(str);
    printf("str.s = %s\n", str.s);

    return (0);
}

/* sub 側 */
struct tag_str sub(struct tag_str str)
{
    strcpy(str.s, "東京奇譚集");
    return (str);
}