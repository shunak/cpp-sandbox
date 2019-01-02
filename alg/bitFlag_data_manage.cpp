/* 34_03.c ビット・フラグの使用例 */
#include <stdio.h>

/* マクロ定義 */
#define Mac_Milk 0x80      /* 牛乳     */
#define Mac_Tofu 0x40      /* 豆腐     */
#define Mac_Fish 0x20      /* 魚       */
#define Mac_Banana 0x10    /* バナナ   */
#define Mac_Natto 0x08     /* 納豆     */
#define Mac_Aubergine 0x04 /* なす     */
#define Mac_Carrot 0x02    /* にんじん */
#define Mac_Tomato 0x01    /* トマト   */
#define Mac_None 0x00      /* 無し     */
#define Mac_All (Mac_Milk | Mac_Tofu | Mac_Fish |         \
                 Mac_Banana | Mac_Natto | Mac_Aubergine | \
                 Mac_Carrot | Mac_Tomato)

#define Mac_FoodStrLen 13 /* 食品名の最大文字列長 */

/* プロトタイプ宣言 */
void std_out(
    const char name[][Mac_FoodStrLen],
    unsigned char flag, int kind);

/* main 関数 */
#define Mac_KindFood 8 /* 食品の種類 */

int main(void)
{
    const int kind_food = Mac_KindFood;
    const char food_name[][Mac_FoodStrLen] = {/* 最下位ビットから上位ビットへの対応する食品名 */"トマト", "にんじん", "なす", "納豆", "バナナ", "魚", "豆腐", "牛乳"};
    unsigned char food;
    unsigned char work;

    /* 牛乳 */
    food = Mac_Milk;
    std_out(food_name, food, kind_food);
    /* 牛乳と納豆 */
    food = Mac_Milk | Mac_Natto;
    std_out(food_name, food, kind_food);
    /* 豆腐と魚とトマト */
    food = Mac_Tofu | Mac_Fish | Mac_Tomato;
    std_out(food_name, food, kind_food);
    /* トマト取り消し */
    food &= ~Mac_Tomato;
    std_out(food_name, food, kind_food);
    /* なす追加 */
    food |= Mac_Aubergine;
    std_out(food_name, food, kind_food);

    puts("***** 魚検査 *****");
    /* 魚が入っているか調べる */
    if ((food & Mac_Fish) == Mac_Fish)
    {
        puts("魚が入っている");
    }
    /* 魚とにんじんの二つが同時に入っているかを調べる */
    puts("***** 魚とにんじん検査 *****");
    work = Mac_Fish | Mac_Carrot;
    if ((food & work) == work)
    {
        puts("魚もにんじんも入っている");
    }
    else
    {
        puts("どちらか欠けているか、或いはどちらも入っていない");
    }
    puts("***** 魚又はにんじん検査 *****");
    /* 魚又はにんじんが入っていかを調べる */
    if ((food & (Mac_Fish | Mac_Carrot)) != Mac_None)
    {
        puts("魚又はにんじんが入っている");
    }
    else
    {
        puts("どちらも入っていない");
    }
    /* 全ての食品 */
    puts("***** 全ての食品 *****");
    food = Mac_All;
    std_out(food_name, food, kind_food);

    return (0);
}
#undef Mac_KindFood

/*       flg の立っているビットを最下位から順に調べ、
        該当名称を標準出力へ出力                         */
void std_out(
    const char name[][Mac_FoodStrLen],
    unsigned char flg,
    int kind)
{
    int i;

    printf("food = 0x%02X\n", flg);
    if (flg == Mac_None)
    {
        puts("何もありません");
    }

    for (i = 0; i < kind; i++)
    {
        /* 最下位ビットが立っていたら文字列表示 */
        if ((flg & 1) == 1)
        {
            printf("%s ", name[i]);
        }
        /* ビットを一つ右へずらす */
        flg /= (unsigned char)2;
    }
    puts("\n");
    return;
}