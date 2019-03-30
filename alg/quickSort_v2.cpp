#include <stdio.h>
#include <vector>
#include <algorithm>

#define Cnum 10000000

using namespace std;

int N;
// char CardImg[Cnum];
// int CardNum[Cnum];

typedef struct{

    char suite;
    int value;

} card;

card Crd[Cnum];

card defCards[Cnum];


// プロトタイプ宣言(仮引数定義には、データ型を付与することを忘れずに)
int partition(card *C, int p, int r);

void quickSort(card *C, int p, int r);

// int getOrderDefault(int N, card *B);
vector<char> getOrderDefault(int N, card *B);

void compareVec(std::vector<int> &vec, card *C);

void printVec_suite(std::vector<char> &vec);


int main(void)
{

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s %d", &Crd[i].suite, &Crd[i].value); //scanfで改行 を含めてしまうと、それも一字になるので注意

    }
    // defCards = Crd;
    // (注意) scanfで文字列を読み込む　→　文字型を渡すなら%cでよいが、配列型の文字を渡すなら%sとする必要がある

    // 元の順番の絵柄を配列（vector型）として取得（vector型のほうが配列を扱いやすい）
    vector<char> defOrd;
    defOrd = getOrderDefault(N, Crd);

    // puts("");
    quickSort(&Crd[-1], 0, N);

    // quickSortした結果の絵柄の並び順を配列に確保
    vector<char> afterOrd(N);
    for(int i = 0; i < N; i++)
    {
        afterOrd[i]=Crd[i].suite;
    }
    // printVec_suite(afterOrd);

    // もとの順番とクイックソートしたあとの絵柄の順番の比較
    // printVec_suite(defOrd);
    // 安定性判定
    if (afterOrd==defOrd) {
        puts("Stable");
    }else{
        puts("Not stable");
    }

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

// vectorプリント用
void printVec_suite(std::vector<char> &vec)
{
    // std::cout << "";
    puts("");
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        printf("%c\n", *it);
    }
    // std::cout << std::endl;
}
void printVec_value(std::vector<int> &vec)
{
    // std::cout << "";
    puts("");
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        printf("%d\n", *it);
    }
    // std::cout << std::endl;
}



// 最初の順番を取得する処理
vector<char> defVec_(std::vector<int> &vec, card *C, int N)
{
    int n = 0;           //counter var
    vector<char> defOrd(N);  //buffer array
    vector<int> defOrd_v(N); //buffer array

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {

        for (int i = 0; i < N; i++)
        {

            if (C[i].value ==*it)
            {

                defOrd[n] = C[i].suite;
                defOrd_v[n] = C[i].value;
                n++;

                // printVec_suite(defOrd);
                // printVec_value(defOrd_v);
            }

        }

    }

    // printVec_suite(defOrd);


     // 例
    // vector<char> ex = {'D','C','H','D','D','S'};

    // if (defOrd==ex) {
    //     puts("同じ順序です");
    // }else{
    //     puts("違います");
    // }


    return defOrd;




}


// judgeOrderStability
    // クイックソートの安定性判定用
    // 元の順序のままのカード順を取得
vector<char> getOrderDefault(int N, card *B){
    // void getOrderDefault(int N, card *B){
// vector<char> getOrderDefault(vector<char> dO, int N, card *B){
// int judgeOrderStability(int N, card *B)
// {

    vector<int> defltOrder(N);
    vector<char> defOrd;

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
    // printVec(defltOrder);

    defOrd = defVec_(defltOrder, B, N);
    // dO = defVec_(defltOrder, B, N);


    // vector<char> ex = {'D','C','H','D','D','S'};

    // // if (defOrd==ex) {
    //     puts("同じ順序です");
    // }else{
    //     puts("違います");
    // }

    // return dO;
    return defOrd;


    // return 0;

}
