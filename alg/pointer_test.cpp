#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>




int main(){



    const int i = 4;
    int   *pi   = &i;

    *pi = 2;


    printf("%d\n",i);
    return 0;


}
