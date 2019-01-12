/* 39_03.c 構造体型の入れ子 */
#include <stdio.h>

/* 構造体型の宣言 */
struct tag_a
{
    char s[16];
    int max;
};

struct tag_b
{
    struct tag_a a; /* 入れ子 */
    double d;
};

/* プロトタイプ宣言 */
void sub(struct tag_b *b);

int main(void)
{
    struct tag_b b =
        {
            {"abcdef", 6},
            3.14};

    sub(&b);

    return (0);
}

/* sub 関数側 */
void sub(struct tag_b *b)
{
    printf("b->a.s   = %s\n", b->a.s);
    printf("b->a.max = %d\n", b->a.max);
    printf("b->d     = %f\n", b->d);
    return;
}



/***
 * struct tag_b の構造体型の宣言を見てください。その中で構造体型変数を宣言しています。これが入れ子です。
　main 関数にて、 struct tag_b 型の変数を宣言と同時に初期化を記述しています。構造体型の入れ子の初期化記述は気を付けてください。その部分は中括弧で囲み、構造体型の入れ子の部分である事を明確にします。
　その後この構造体型変数のアドレスを引数にして sub 関数を呼び出しています。
　sub 関数側では構造体の内容を表示しています。 b は struct tag_b * 型です。そのメンバーの参照はアロー演算子を用います。よって double 型のメンバー変数 d を対象にするなら b->d となります。
　問題は入れ子の構造体型のメンバー参照です。まず b->a ここまでは良いでしょう。今度は b->a の型を考えます。 struct tag_b 型のメンバーである a は struct tag_a 型です。 b-> によって struct tag_b 型のメンバー参照が可能になるのですから b->a は struct tag_a 型です。ポインターではありませんから、struct tag_b 型内の struct tag_a 型のメンバーに対しては通常のメンバー参照演算子を用います。
　よって ( b->a ).max とすれば struct tag_b 型へのポインターの struct tag_a 型のメンバー変数 max を参照出来ます。演算子の優先順位はアロー演算子もメンバー参照演算子も同じです。結合規則は左から右なので b->a.max と記述可能です。
　これが分かれば b->a.s とすれば char [] 型の先頭アドレスを取得出来るのも分かると思います。
 * */ 