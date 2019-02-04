#include <stdio.h>

// マクロ定義
#define MAX 100000

int A[MAX];

int p, r;

// プロトタイプ宣言(仮引数定義には、データ型を付与することを忘れずに)
int partition(int * A, int p, int r);


int main(){

    // 変数定義部
    int n,ret;

    // 標準入力
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[i]);
    }

    // パーティション関数
    ret = partition(A, 0, n-1);

    // 標準出力部分
    for(int i = 0; i < n; i++)
    {

        if(i!=0) printf(" ");
        if(i==ret) printf("[");
        printf("%d", A[i]);
        if(i==ret) printf("]");

    }
    printf("\n");


    return 0;
}


// パーティション関数の定義
int partition(int * A, int p, int r){

    int x,i,buf;

    x = A[r];
    i = p-1;

    for(int j = p; j < r; j++)
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









