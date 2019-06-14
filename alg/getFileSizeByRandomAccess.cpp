#include <stdio.h>
#include <stdlib.h>

long GetFileSize(FILE* fp);

int main(void)
{
    FILE* fp;

    fp = fopen( "test.bin", "rb" );
    if( fp == NULL ){
            fputs( "ファイルオープンに失敗しました。\n", stderr );
            exit( EXIT_FAILURE );
        }

    printf( "%ld\n", GetFileSize( fp ) );

    if( fclose( fp ) == EOF ){
            fputs( "ファイルクローズに失敗しました。\n", stderr );
            exit( EXIT_FAILURE );
        }

    return 0;
}

long GetFileSize(FILE* fp)
{
    long fpos_save, size;

    /* 現在のファイルポジションを保存 */
    fpos_save = ftell( fp );

    /* ファイルの末尾まで移動して、その位置を調べる */
    fseek( fp, 0, SEEK_END );
    size = ftell(fp);

    /* ファイルポジションを元に戻す */
    fseek( fp, fpos_save, SEEK_SET );

    return size;
}









