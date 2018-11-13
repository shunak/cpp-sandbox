#include <cstdio>
#include <cstdlib>
#include <cstring>
#define N 10

int henkan(char M){

    int i;
    char digit[N];

    for(int i = 1; i <= N; i++)
    {
        digit[i]='i';
    }

    i=1;
    while(M!=digit[i]) {
        i++;
    }

    return i%10;
}


int main(){

    char M;
    int IM;

    scanf("%s",&M);

    IM = henkan(M);

    printf("%d\n",IM);

    return 0;
}