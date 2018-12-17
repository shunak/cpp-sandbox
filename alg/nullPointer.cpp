#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

/* プロトタイプ宣言 */
void isnp(char *s, void *p);

int main(void)
{
        int i = 10;
        int * pi;

        pi=NULL;              /* ヌル・ポインターのマクロ */
        isnp("pi = NULL                  :", pi);

        pi=0;                 /* 定数 */
        isnp("pi = 0                     :", pi);

        pi=5-5;             /* 定数演算 */
        isnp("pi = ( 5 - 5 )             :", pi);

        pi=(void *)3-2-1; /* 定数演算と型変換 */
        isnp("pi = (void *)( 3 - 2 - 1 ) :", pi);

        pi=&i;                /* 変数 i のアドレスを代入 */
        isnp("pi = &i                    :", pi);

        return 0;
}

/* ヌル・ポインターか否かを判断し、結果を表示 */
void isnp(char *s, void *p)
{
        printf(s);
        if (p==NULL)
        {
                puts(" ヌル・ポインターです");
        }
        else
        {
                puts(" ヌル・ポインターではありません" );
        }

        return;
}