#include <cstdio>
#include <cstdlib>
#include <cstring>

int main()
{   

    struct list{
        char value[100];
        int next=-1;
    };
    
    struct list List;
    char mvalue;
    int ls = 0;
    int First = -1;


    scanf("%s\n",&mvalue);

    // List.value[100] = mvalue;

    // printf("%s\n",List.value[100]);

    return 0;
}