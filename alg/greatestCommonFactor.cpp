#include <cstdio>
#include <cstdlib>
#include <cstring>

int main(){

    int r, m, n;

    scanf("%d %d",&m ,&n);

    while(r!=0){
        r=m%n;
        m=n;
        n=r;
    }

    printf("%d\n",m);

    return 0;
}



