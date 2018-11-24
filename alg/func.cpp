#include <stdio.h>

/* プロトタイプ宣言 */
int add_int(int a, int b);

int main(void)
{   
    int n2;
    int min;
    int max;
    int answer;

    // i0 = 20;
    // i1 = 30;
    min = 1;
    max = 10;


    for(int n = min; n < max; n++)
    {   
        n2 = n+1;
        answer = add_int(n, n2);
        printf("%d + %d = %d\n", n, n2, answer);
    }


    return (0);
}

/**********************************************************
        int add_int(
        [in ]   int a,  // 加算する値 その一
        [in ]   int b   // 加算する値 その二
        );
        返し値
                加算値
        処理詳細
                a + b の結果を返す
        注意
                オーバーフローは考慮しない
**********************************************************/
int add_int(int a, int b)
{
    int answer;

    answer = a + b;

    return (answer);
}