#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){

    char c, s[256];
    int i=0;

    // c = getchar();
    printf("文字列を入力:");
    scanf("%s",s);
    printf("文字列の長さ:");
    while(s[i]!='\0'){
        i++;
    }
    printf("%d文字\n",i);


    return 0;

}