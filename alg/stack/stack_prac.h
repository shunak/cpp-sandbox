/* stack_prac.h 「自己参照の構造体によるスタックの練習」のヘッダー */
#ifndef __stack_prac_h__
#define __stack_prac_h__

#include "c_prac_base2.h"

/* マクロ定義 */
#define MacTitemSize 128

/* 型定義 */
typedef int Tboolean;
typedef char Titem[MacTitemSize];
typedef struct self_referential_structure STsrs;
struct self_referential_structure
{
    Titem item;  /* 格納データ */
    STsrs *next; /* 取り出す時の次のデータ領域へのポインター */
};

/* プロトタイプ宣言 */
Tboolean stack_push(const Titem item);
Tboolean stack_pop(Titem item);
void stack_free(void);
static void stack_free_one(void);

#endif /* __stack_prac_h__ */
