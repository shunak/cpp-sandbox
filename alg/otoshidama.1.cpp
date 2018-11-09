#include <cstdio>
#include <cstdlib>
#include <cstring>

int N, Y, x, y, z, otoshidama;

int main(){
    
    scanf("%d %d",&N, &Y);


    // O(n^3)をO(n^2)に
    for(int x = 0; x <= N; x++)
    {

        for(int y = 0; y <= N-x; y++)
        {

            z = N-x-y;

            otoshidama = 10000*x+5000*y+1000*z;

            if (z>=0 && Y==otoshidama) {

                printf("%d %d %d\n",x,y,z);
                return 0;

            }

        }
    }

    puts("-1 -1 -1");
    return 0;

}
















