#include<stdio.h>
#define MAX 10000
#define SENTINEL 200000

// define struct card (obj data)
struct Card{
    char suit;
    int value;
};

// declear struct Card variable
struct Card L[MAX/2 + 2], R[MAX/2 + 2];


void merge(struct Card A[], int n, int left, int mid, int right){
    int i, j ,k;
    int n1 = mid - left;
    int n2 = right - mid;
    for(i = 0; i < n1; i++) L[i]=A[left+i];
    for(i = 0; i < n2; i++) R[i]=A[mid+i];
    L[n1].value=R[n2].value=SENTINEL;
    i=j=0;
    for(k = left; k < right; k++)
    {
        // copy to merge tmp memory by asc order
        if (L[i].value<=R[j].value) {
            A[k]=L[i++];
        }else{
            A[k]=R[j++];
        }
    }
}

void mergeSort(struct Card A[], int n, int left, int right){
    int mid;
    if(left+1<right){
        mid = (left + right /2);
        mergeSort(A, n, left, mid); //left zone; recursive deal
        mergeSort(A, n, mid, right); //right zone; recursive deal
        merge(A, n, left, mid, right);
    }
}


int partition(struct Card A[], int n, int p, int r){
    int i, j;
    struct Card t, x;
    x=A[r];
    i=p-1;
    for(j = p; j < r; j++)
    {
        if(A[j].value <= x.value){
            i++;
            // switch A[i], A[j]
            t=A[i];//t is tmp buff
            A[i]=A[j];
            A[j]=t;
        }
    }
    t=A[i+1];
    A[i+1]=A[r];
    A[r]=t;

    return i + 1;

}


void quickSort(struct Card A[], int n, int p, int r){

    int q;
    if(p < r){
        q = partition(A, n, p, r);
        quickSort(A, n, p, q-1);
        quickSort(A, n, q+1, r);
    }

}


int main(){

    int n, i, v;
    struct Card A[MAX], B[MAX];
    char S[10]; //card suite
    int stable = 1; // stability flag

    scanf("%d",&n);

    for( i = 0; i < n; i++)
    {
        scanf("%s %d", S, &v);
        A[i].suit = B[i].suit = S[0];
        A[i].value = B[i].value = v;
    }

    mergeSort(A, n, 0, n);
    quickSort(B, n, 0, n-1);


    for( i = 0; i < n; i++)
    {
        if (A[i].suit!=B[i].suit) {
            stable = 0;
        }
    }


    if(stable == 1) printf("Stable\n");
    else printf("Not stable\n");
    for( i = 0; i < n; i++)
    {
        printf("%c %d\n", B[i].suit, B[i].value);
    }

    return 0;


}


// segmentation fault(core dumped)



































