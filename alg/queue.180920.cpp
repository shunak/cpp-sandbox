#include <iostream>
#include <string>

using namespace std;

int last, S[10000], n, q, a, f[10000], lst, t, k, l, arr[10000][2];
string s;

typedef struct Input{
    char name[10000];
    int time[10000];
};

struct Input ipt;

// add to tail
void enqueue(int x){
    arr[++last][2]=x;
}

void finque(int x){
    f[++lst]=x;
}

// get head
int dequeue(){
    return arr[2][0];
}

int main(){

    // int n,q;
    cin >> n >> q;
    // cout << "n=" << n << endl;
    // cout << "q=" << q << endl;
    // get to array
    while(n>0){
        cin >> s >> a;
        enqueue(a);
        n--;
    }

    cout << dequeue() << endl;

    for(int i = 2; i <= last+1; i++)
    {
        cout << arr[i][0] << endl;
    }



    // process round robin

        // if (a-q>0) {
        //     t+=q;
        //     enqueue(a-q);
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

