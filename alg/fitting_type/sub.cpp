#include <stdio.h>

/* 型定義 */
typedef int INT;
typedef struct tag
{
    INT a; /* INT は int と適合する型 */
} ST;

/* プロトタイプ宣言 */
void sub(ST s);

void sub(ST s)
{
    printf("%d\n", s.a);
    return;
}