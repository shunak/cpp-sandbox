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

    // quickSort(Crd.value, 0, N);
    quickSort(&Crd[-1], 0, N);

    puts("");
    for (int i = 0; i < N; i++)
    {
        printf("%c %d\n",Crd[i].suite, Crd[i].value);
    }

    return 0;

}

// パーティション関数の定義
int partition(card *C, int p, int r){

    int x,i;
    card buf;

    x = C[r].value;
    i = p-1;

    for(int j = p; j < r; j++)
    {
        if (C[j].value <= x) {
            i++;
            buf = C[i];
            C[i] = C[j];
            C[j] = buf;
        }
    }

    buf = C[i+1];
    C[i+1] = C[r];
    C[r] = buf;

    return i+1;//パーティションの値を返す
}

// クイックソートの定義
void quickSort(card *C, int p, int r){

    int q;

    if (p < r) {

        q = partition(C, p, r);
        quickSort(C, p, q-1);//前半部分のクイックソート
        quickSort(C, q+1, r);//後半部分のクイックソート

    }


}

