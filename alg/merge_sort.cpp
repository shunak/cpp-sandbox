#include <stdio.h>
#include <math.h>
// #include <iostream>
// #include <string.h>

// マージソートは分割統治法にもとづく高速なアルゴリズム
// divide, solve, conquer

int n;
int c=0;
// int S[500000];
int A[500000];
// int left,right;


// プロトタイプ宣言
void mergeSort(int A[], int n, int left, int right);
void merge(int A[], int n, int left, int mid, int right);


int main(){

    scanf("%d\n",&n);

    // while(c < n-1){

    //     scanf("%d\n",&A[n]);
    //     // scanf("%d\n",&S[n]);
    //     c++;
    // }
    
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&A[n]);
    }
    

    mergeSort(A, n, 0, n);
    // mergeSort(A, 0, n);
    // merge(S,0,n/2,n);

    for(int i = 0; i < n; i++)
    {
        printf("%d\n",A[n]);
    }

    return 0;
}

// 統合する「conquer」関数
void merge(int A[], int n, int left, int mid, int right){
// void merge(int A[], int left, int mid, int right){

    int n1, n2, L[n1], R[n2];

    n1 = mid - left;
    n2 = right - mid;

    for(int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }

    for(int i = 0; i < n2; i++)
    {
        R[i] = A[mid+i];
    }

    L[n1] = 10000000;
    R[n2] = 10000000;

    int i=0,j=0;
    for(int k = left; k < right; k++)
    {

        if (L[i]<=R[j]) {

            A[k] = L[i];
            i++;

        }else{

            A[k] = R[j];
            j++;

        }

    }

    // return;

}

// ソートする「Divide」
void mergeSort(int A[], int n, int left, int right){
// void mergeSort(int A[], int left, int right){

    // int mid;
    if (left+1 < right) {
        int mid = (left + right)/2;
        mergeSort(A, n, left, mid);
        mergeSort(A, n, mid, right);
        merge(A, n, left, mid, right);
    }

    // return;

}

