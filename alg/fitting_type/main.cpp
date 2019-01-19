/* 型定義 */
typedef struct tag
{
    int a;
} ST;

/* プロトタイプ宣言 */
void sub(ST s);

int main(void)
{
    ST s = {10};

    sub(s);
    return (0);
}