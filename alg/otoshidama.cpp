#include <cstdio>
#include <cstdlib>
#include <cstring>

int N, Y, x, y, z, rest;

int main(){
    
    scanf("%d %d",&N, &Y);

    N = x + y + z;
    Y = 10000*x+5000*y+1000*z;

    // x = N * 10000;
    // // x = 10 * N * 1000;
    // y = N * 5000;
    // // y = 5 * N * 1000;
    // z = N * 1000;
    // // z = 1 * N * 1000;

    printf("%d %d %d\n", x, y, z);

    printf("%d\n",Y%10000);
    printf("%d\n",Y/10000);

    rest = N-Y/10000;

    if (rest > 500) {

        rest = N-Y/1000;
        
        if (rest<0) {

            rest = N-Y/5000;
        
        }
        

    }
    
    // どう均等にわけるか？


    printf("%d\n",rest);






    return 0;

}
















