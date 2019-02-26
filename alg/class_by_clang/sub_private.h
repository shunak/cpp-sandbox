/* 52_00_sub_private.h 関数名を構造体で覆う sub 側
        間接公開及び非公開ヘッダー */
#ifndef __sub_private_h__ // #ifndef = #if !define　これが0か非0かを判定する
#define __sub_private_h__

/* 間接公開関数のプロトタイプ宣言 */
static void int_stdout(int a);
static int str_stdout(const char *s);

#endif /* __52_00_sub_private_h__ */
