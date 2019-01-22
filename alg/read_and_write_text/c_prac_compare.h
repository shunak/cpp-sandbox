/******************************************************************
        c_prac_compare.h

        比較処理のヘッダー
********************************************************************/
#ifndef __c_prac_compare_h__
#define __c_prac_compare_h__

#include <stddef.h>     /* size_t の定義が必要 */

/* 型定義 */
typedef struct
{
        char * s;       /* 文字配列へのポインター */
        size_t sz;      /* 文字配列のバイト単位の大きさ */
} STpssz;

typedef struct
{
        STpssz s0;      /* 被比較文字列 */
        STpssz s1;      /* 比較文字列 */
} STstrcmp;

/* プロトタイプ宣言 */
       int  string_compare(        const STstrcmp * sc, int * result );
static int  string_compare_chk(    const STstrcmp * sc );
static int  string_compare_getmax( const STstrcmp * sc );
static void string_compare_no_nul(
        int * result, const int i, const int max, const STstrcmp * sc,
        const unsigned char * ps0, const unsigned char * ps1            );

#endif  /* __c_prac_compare_h__ */