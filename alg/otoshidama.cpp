#include <cstdio>
#include <cstdlib>
#include <cstring>

int N, Y, x, y, z, rest;


int main(){
    
    scanf("%d %d",&N, &Y);

    x = N * 10000;
    y = N * 5000;
    z = N * 1000;

    printf("%d %d %d\n", x, y, z);

    printf("%d\n",Y%10000);
    printf("%d\n",Y/10000);

    rest = N-Y/10000;

    if (rest > 500) {

        // rest = N/2-Y/1000 + N/2-Y/5000;
        rest = N-Y/1000;
        
        if (rest<0) {

            rest = N-Y/5000;
        
        }
        

    }



    printf("%d\n",rest);






    return 0;

}
















