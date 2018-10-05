#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main(){
    CCalc<int> i1; // int型のインスタンスを生成
    CCalc<string> i2; // string型のインスタンスを生成
    i1.set(1,2);
    i2.set("ABC","DEF");
    cout << i1.add() << endl << i2.add() << endl;
    return 0;
}









