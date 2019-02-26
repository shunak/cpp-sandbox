/* 52_00_sub_public.h 関数名を構造体で覆う
        sub 側 公開ヘッダー */
#ifndef __sub_public_h__
#define __sub_public_h__

/* 型定義 */
typedef struct /* STutil 型 */
{
    void (*print_int)(int a);
    int (*print_str)(const char *s);
} STutil;

/* 公開関数のプロトタイプ宣言 */
extern void new_util(STutil **stu);
extern void delete_util(STutil **stu);

#endif /* __52_00_sub_public_h__ */