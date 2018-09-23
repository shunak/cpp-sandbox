#include <iostream>
#include <string>

using namespace std;

int head, last, S[10000], n, q, a, f[10000], lst, t, k, l, arr[10000][2];
string s;

// def struct
typedef struct RR{
    string name[10000];
    int tm[10000];
} rr;

rr rob;

// add to tail
void enQ(string p,int x){
    rob.name[++last]=p;
    rob.tm[++last]=x;
}

// get name
string deQ_n(){
    return rob.name[++head];
}

// get time
int deQ_t(){
    return rob.tm[++head];
}

int main(){

    // int n,q;
    // cin >> n >> q;
    // cout << "n=" << n << endl;
    // cout << "q=" << q << endl;
    // get to array
    int cp = n;
    while(n>0){
        cin >> s >> a;
        enQ(s,a);
        n--;
    }

    // int* a = new int[10];

    // for(int i = 0; i < 10; i++)
    // {
    //     printf("%d\n",a[i]);
    // }

    // cout << dequeue() << endl;

    // for(int i = 1; i <= last; i++)
    // {
    while(cp+1>0){
        cout << rob.name[cp] << endl;
        cp--;
    }
    // }

    // cout << inp.name[i] << endl;


    // process round robin

        // if (a-q>0) {
        //     t+=q;
            // enqueue(a-q);
        // }else if(a-q<=0){
        //     t+=q;
        //     finque(a+t);
        // }







    // output
    // for (int i = 1; i <= lst; i++)
    // {
    //     // cout << S[last] << endl;
    //     // cout << dequeue() << endl;
    //     cout << f[i] << endl;
    //     // cout << sizeof(S)/sizeof(*S) << endl;
    // }


    return 0;

}

