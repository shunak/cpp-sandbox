#include <iostream>

using namespace std;

int last, S[10000], n, q;

void enqueue(int x){
    S[++last] = x;
}

int dequeue(){
    return S[0];
}

int main(){
    int n,q;
    cin >> n >> q;
    cout << "n=" << n << "q=" << q << endl;
    return 0;
}

