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
    vector<char*> data;
    vector<char> box;

    scanf("%s",S);
    // gets(S);

    int lenInput = strlen(S);

    for(int i = 0; i < 5; i++)
    {
        // S[i]);
        box.push_back(S[i]);

    }
    
    
    if (&box[0]=="dream") {
        printf("%s\n","Yes");
    }else{
        printf("%s\n","no");
    }
    
    

    // for(int i = 0; i < 5; i++)
    // {
    
    //     // printf("%c\n",box[i]);
    // }
 printf("%s\n",&box[0]);





    data.push_back("dream");
    data.push_back("erase");
    data.push_back("eraser");
    data.push_back("dreamer");

    // strcat(data[0],data[1]);
    // strcpy(buf,data[0]);
    // strcat(buf,data[1]);
    // printf("%s\n",buf);

    int c = data.size();
    for(int i = 0; i < c; i++)
    {
        printf("%s\n",data[i]);
    }

    return 0;

}
