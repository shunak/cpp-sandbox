#include "hoge.h"
#include <iostream>

using namespace std;

void Hoge::foo()
{
    cout << "fooメソッド" << endl;
}

Hoge::Hoge(){
    cout << "コンストラクタ" << endl;
}

Hoge::~Hoge(){
    cout << "デストラクタ" << endl;
}


