#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s, r;

    cout << "姓を入力:";
    cin >> s;
    cout << "名を入力:";
    cin >> r;
    cout << "名前は「" << s+r << "」です。"<< endl;
    return 0;

}

