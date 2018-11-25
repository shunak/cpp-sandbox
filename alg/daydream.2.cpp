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
    // 長さ 5,5,6,7 →　windowSizeとしてデータ化する

    // printf("%s\n",&data[1][0]);


    int count=0;
    int numData = 4;
    int windowSize[3]={5,6,7};

    // Sで与えられる文字列の長さは、5a+6b+7cで与えられる





    // for(int j = 0; j < numData; j++)
    // {
    int i=0;
    while(i<windowSize[0]){

        if (box[i]==data[0][i]) {
            count++;
        }
        i++;
    }


    int cnt=0;
    if(count==windowSize[0]){
        printf("%s\n",&box[count]);

        for(int i = count; i < lenInput; i++)
        {

            if (box[i]==data[1][i-count]) {
                cnt++;
            }


        }

    }

    printf("%d\n",cnt);
    // }


    // judge
    if (count==lenInput) {
        printf("%s, %d\n","Yes",count);
    }else{
        printf("%s, %d\n","no",count);
    }



    return 0;

}
