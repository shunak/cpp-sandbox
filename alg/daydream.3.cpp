#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string T[4]={"dream","dreamer","erase","eraser"};

int main()
{

    string S;
    cin >> S;
    // scanf("%s\n",S);

    reverse(S.begin(), S.end());

    for(int i = 0; i < 4; i++) reverse(T[i].begin(),T[i].end());

    bool judge = true;

    for(int i = 0; i < S.size();)
    {
        bool judge2 = false;
        for(int j = 0; j < 4; j++)
        {
            string t = T[j];

            if (S.substr(i,t.size())==t) {
                judge2 = true;
                i+=t.size();
            }

        }

        if (!judge2) {
            judge = false;
            break;
        }
    }

    if (judge) {
        puts("YES");
    }else{
        puts("NO");
    }

    return 0;

}
