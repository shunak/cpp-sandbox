/* 45_01.c 列挙体の使用例 */
#include <stdio.h>

/* プロトタイプ宣言 */
void sub( void );

int main( void )
{
        enum    /* タグ名無し */
        {
                Blue,
                Red,
                Green   /* コンマは付けない */
        };      /* オブジェクトも無し */

        printf( "Blue = %d, Red = %d, Green = %d\n", Blue, Red, Green );
        sub();

        return ( 0 );
}

void sub( void )
{
        enum tag
        {       
                One  = 1,
                Five = 5,
                Six  = One + Five,
                Nine = 10 - One,
        };

        // enum tag num;
        int num;

        printf( "sizeof( num ) = %d\n", sizeof( num ) );
        printf(
                "One = %d, Five = %d, Six = %d, Nine = %d\n",
                One, Five, Six, Nine
        );
        num = Six + Nine;
        printf( "num = Six + Nine : num = %d\n", num );
        return;
}