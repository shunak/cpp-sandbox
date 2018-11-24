#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;
// neglect compile error
// https://teratail.com/questions/9652

char T[100000], buf[100000], S[100000];
// string S;


int main()
{
    // vector<char> data;
    vector<char> box;

    scanf("%s",S);
    // gets(S);

    int lenInput = strlen(S);

    for(int i = 0; i < lenInput ; i++)
    {
        // S[i]);
        box.push_back(S[i]);
    }

    printf("%s\n",&box[0]);

    char data[][8] = {"dream","erase","eraser","dreamer"};

    printf("%s\n",&data[1][0]);
    
    int count=0;
    int i=0;
    while(i<lenInput){

        if (box[i]==data[2][i]) {
            count++;
        }

        i++;
        
    }



    // judge
    if (count==lenInput) {
        printf("%s, %d\n","Yes",count);
    }else{
        printf("%s, %d\n","no",count);
    }



    return 0;

}
