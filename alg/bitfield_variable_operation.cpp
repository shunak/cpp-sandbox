/* 44_02.c 環境依存 変数の内容をビット・フィールドで操作 */
#include <stdio.h>

int main(void)
{
    typedef struct
    {
        unsigned int f3 : 3; /* フラグ 3 */
        unsigned int f2 : 2; /* フラグ 2 */
        unsigned int f1 : 3; /* フラグ 1 */
    } STbf;

    unsigned int flag = 0xB9;
    STbf *bf = (STbf *)(&flag);

    printf(
        "フラグ1 = %d, フラグ2 = %d, フラグ3 = %d\n"
        "sizeof( STbf ) = %d, sizeof( unsigned int ) = %d\n",
        bf->f1, bf->f2, bf->f3,
        sizeof(STbf), sizeof(unsigned int));

    return (0);
}