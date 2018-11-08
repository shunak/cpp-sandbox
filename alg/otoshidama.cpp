#include <cstdio>
#include <cstdlib>
#include <cstring>

int N, Y, x, y, z, sum, count, otoshidama;

int main(){
    
    scanf("%d %d",&N, &Y);

    
// 全ての組み合わせを求める
for(int x = 0; x < N; x++)
{
    
    for(int y = 0; y < N; y++)
    {

        for(int z = 0; z < N; z++)
        {

            sum = x+y+z;
            otoshidama = 10000*x+5000*y+1000*z;
            
            if (N==sum && Y==otoshidama) {

                printf("%d %d %d\n",x,y,z);

            }
            

        }

    }
    
}







    // printf("%d %d %d\n", x, y, z);


    return 0;

}
















