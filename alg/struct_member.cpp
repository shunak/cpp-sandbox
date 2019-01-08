/* 39_00.c 構造体とそのメンバー変数の使用法 */
#include <stdio.h>
#include <string.h>

/* 構造体型宣言 */
struct tag_goods /* ファイル・スコープ */
{
    char name[64];
    int price;
};

/* プロトタイプ宣言 */
void out(const struct tag_goods gd[], int n);
void sub(void);

/* main 関数 */
int main(void)
{
    struct tag_goods goods[4];
    const int num = 2;

    strcpy(goods[num].name, "たのしいこと");
    goods[num].price = 700;
    out(goods, num);
    sub();

    return (0);
}

/* out 関数 : 構造体の配列の指定要素の内容を出力 */
void out(const struct tag_goods gd[], int n)
{
    printf("name  = %s\nprice = %d\n", gd[n].name, gd[n].price);
    return;
}

/* sub 関数 : 構造体型の局所宣言とその使用 */
void sub(void)
{
    struct tag_drink
    {
        int water;
        int tea;
    };
    struct tag_drink drink;
    struct tag_drink *drink2 = &drink;

    drink2->water = 500;
    drink2->tea = 350;
    printf("water = %d\ntea   = %d\n", drink.water, drink.tea);

    return;
}
