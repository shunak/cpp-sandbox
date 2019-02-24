#include <stdio.h>
#include <vector>
#include <algorithm>

#define Cnum 1000000000

using namespace std;






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

int getOrderDefault(int N, card *B);


int main(void){

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s %d", &Crd[i].suite, &Crd[i].value); //scanfで改行 を含めてしまうと、それも一字になるので注意
    }

    // (注意) scanfで文字列を読み込む　→　文字型を渡すなら%cでよいが、配列型の文字を渡すなら%sとする必要がある

    getOrderDefault(N, &Crd[0]);

    puts("");
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
    card buf;//card型でのバッファ定義

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

// クイックソートの定義(パーティションソートの再帰処理で書ける)
void quickSort(card *C, int p, int r){

    int q;

    if (p < r) {

        q = partition(C, p, r);
        quickSort(C, p, q-1);//前半部分のクイックソート
        quickSort(C, q+1, r);//後半部分のクイックソート

    }


}

// vectorプリント用
void printVec(std::vector<int> &vec)
{
    // std::cout << "";
    puts("");
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        printf("%d\n",*it);
    }
    // std::cout << std::endl;
}

// 元の順序のままのカード順を取得
int getOrderDefault(int N, card *B){

    vector<int> defltOrder(N);

    // 取得したカード番号を読み込む
    for(int i = 0; i < N; i++)
    {
      defltOrder[i]=B[i].value;

    }
    // ベクトルを順番通りにソート
    sort(defltOrder.begin(), defltOrder.end());
    // unique：隣接する重複データを削除。返り値が新たな終端の値。vectorのサイズはそのままなので、
    // 新たな終端以降のデータを削除するために、eraseを適用erase(新たな終端,終端)として、新たな終端値以降のvectorデータを削除する
    defltOrder.erase(unique(defltOrder.begin(), defltOrder.end()),defltOrder.end());

    // ベクトルをprintf
    printVec(defltOrder);

    return 0;

}
