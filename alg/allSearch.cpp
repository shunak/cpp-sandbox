#include <stdio.h>

int n, A[2000];

// 入力値のMから選んだ要素を引いていく再帰関数
int solve(int i, int m){
    if(m==0) return 1;
    if(i>=n) return 0;
    int res = solve(i+1,m) || solve(i+1,m-A[i]); // solve(i,m)をより小さな問題である、solve(i+1,m)とsolve(i+1,m-A[i])に分割
    return res;
}

int main(){

    int q, m[2000];

    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",&A[i]);

    scanf("%d",&q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d",&m[i]);

        if (solve(0,m[i])) puts("yes");
        else puts("no");

    }

    return 0;
}







