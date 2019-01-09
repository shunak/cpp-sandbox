/* 39_02.c 構造体型のメンバーにポインター変数が含まれていた時の挙動 */
#include <stdio.h>

/* 構造体型の宣言 */
struct tag_ip
{
        int * i;
};

/* プロトタイプ宣言 */
void func_p( struct tag_ip * ip );
void func_s( struct tag_ip   ip );

/* main 関数 */
#define MacFmt  "i = %3d, *( ip.i ) = %3d\n"

int main( void )
{
        struct tag_ip ip;
        int           i = 20;

        ip.i = &i;
        printf( MacFmt, i, *( ip.i ) );
        func_p( &ip );
        printf( MacFmt, i, *( ip.i ) );
        func_s( ip );
        printf( MacFmt, i, *( ip.i ) );

        return ( 0 );
}
#undef MacFmt

/* 構造体をポインターで受け取った場合 */
void func_p( struct tag_ip * ip )
{
        *( ip->i ) = 100;
        return;
}

/* 構造体をそのまま受け取った場合 */
void func_s( struct tag_ip   ip )
{
        *( ip.i ) = 7;
        return;
}