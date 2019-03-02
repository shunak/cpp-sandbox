#include <stdio.h>

#define Cnum 1000000000

int N;
// char CardImg[Cnum];
// int CardNum[Cnum];

typedef struct{

    char suite;
    int value;

} card;

card Crd[Cnum];

// プロトタイプ宣言(仮引数定義には、データ型を付与することを忘れずに)
int partition(card *C, int p, int r);

void quickSort(card *C, int p, int r);


int main(void){

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s %d", &Crd[i].suite, &Crd[i].value); //scanfで改行 を含めてしまうと、それも一字になるので注意
    }

    // (注意) scanfで文字列を読み込む　→　文字型を渡すなら%cでよいが、配列型の文字を渡すなら%sとする必要がある
    // quickSort(&Crd[0], 0, N);
    quickSort(&Crd[N], 0, N);

    puts("");
    for (int i = 0; i < N; i++)
    {
        printf("%c %d\n",Crd[i].suite, Crd[i].value);
    }

    return 0;

}


// パーティション関数の定義
int partition(int *A, int p, int r)
{

    int x, i, buf;

    x = A[r];
    i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (A[j] <= x)
        {
            i++;
            buf = A[i];
            A[i] = A[j];
            A[j] = buf;
        }
    }

    buf = A[i + 1];
    A[i + 1] = A[r];
    A[r] = buf;

    return i + 1; //パーティションの値を返す
}


// クイックソートの定義
void quickSort(int *A, int p, int r)
{

    int q;

    if (p < r)
    {

        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}
