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

int main(void){

    scanf("%d", &N);

    for(int i = 0; i < N; i++)
    {
        scanf("%s %d", &Crd[i].suite, &Crd[i].value); //scanfで改行を含めてしまうと、それも一字になるので注意
    }

    // (注意) scanfで文字列を読み込む　→　scanfの引数はポインタをとるので、%cではなく、%sをフォーマット指定子とする

    for(int i = 0; i < N; i++)
    {
        printf("%c %d %i\n",Crd[i].suite, Crd[i].value, i);
    }

    return 0;
}