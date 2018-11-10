#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
// neglect compile error
// https://teratail.com/questions/9652

char S[100000], T[100000], buf[100000];

int main()
{

    vector<char*> data;

    scanf("%s",S);

    data.push_back("dream");
    data.push_back("dreamer");
    data.push_back("erase");
    data.push_back("eraser");

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
