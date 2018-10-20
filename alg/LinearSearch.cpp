#include <cstdio>
#include <iostream>
#include <cstdio>
using namespace std;


// void si





int linearSearch(int q, int n ,int *S ,int *T){

    int counter=0;

    for(int i = 0; i < q; i++)
    {

        for(int j = 0; j < n; j++)
        {
            
            if (T[i]==S[j]) {
                
                counter++;
                break;
            }
        }

    }

    return counter;
}


int main(){

int n;
int S[10000+1];
int q;
int T[500 + 1];

scanf("%d",&n);

for(int i = 0; i < n; i++)
{
    scanf("%d",&S[i]);
}

scanf("%d",&q);
for(int i = 0; i < q; i++)
{
    scanf("%d",&T[i]);
}

int res;

res = linearSearch(q,n,S,T);

printf("%d\n",res);

return 0;


}





























