#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#define N 10
using namespace std;

// int henkan(int M){
int henkan(char M){

    int i;
    vector<char> digit;
    // char digit[N];
    digit={'0','1','2','3','4','5','6','7','8','9','0'};
    // for(int i = 1; i <= N; i++)
    // {
    //     digit.push_back((char)i);
    //     // digit[i]='i';

    // }
    // printf("%s",&digit[2]);

    i=1;
    while(M!=digit[i]) {
        i+=1;
    }

    // if(i==10){
    //     return 0;
    // }else{
    //     return i;
    // }
    return i%10;
}




int main(){

    char M;
    // int M;
    int IM;

    // scanf("%d",&M);
    scanf("%s",&M);

    IM = henkan(M);

    printf("%d\n",IM);

    return 0;
}