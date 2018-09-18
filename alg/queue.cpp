#include <iostream>
#include <string>

using namespace std;

int last, S[10000], n, q, a;
string s;

void enqueue(int x){
    S[++last] = x;
}

int dequeue(){
    return S[0];
}

int main(){

    // int n,q;
    cin >> n >> q;
    // cout << "n=" << n << endl;
    // cout << "q=" << q << endl;
    while(n>0){
        cin >> s >> a;
        enqueue(a);
        n--;
    }

    // for (int i = 0; i < sizeof(S) / sizeof(S[0]); i++)
    // {
        cout << S[last] << endl;
        // cout << sizeof(S)/sizeof(*S) << endl;
    // }
    

    return 0;

}

