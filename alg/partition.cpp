#include <stdio.h>

#define MAX 100000

int A[MAX];

int p, r;

// プロトタイプ宣言(仮引数定義には、データ型を付与することを忘れずに)
int partition(int A[MAX], int p, int r);


int main(){

    // 変数定義部
    int n;

    // 標準入力
    scanf("%d",&n);


    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }


    // パーティション関数


    // 標準出力
    for (int i = 0; i < n; i++)
    {
        int ret = partition(&A[i], 1, n);

        printf("%d ", ret);
    }
    puts("");//改行

    // printf("%d\n",A[i]);


    return 0;
}


// パーティション関数の定義
int partition(int A[MAX], int p, int r){

    int x,i,buf,j;

    x = A[r];
    i = p-1;

    for(int i = p; i < r; i++)
    {
        if (A[j] <= x) {
            i++;
            buf = A[i];
            A[i] = A[j];
            A[j] = buf;
        }
    }

    buf = A[i+1];
    A[i+1] = A[r];
    A[r] = buf;

    return i+1;//パーティションの値を返す
}









