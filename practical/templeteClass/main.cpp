#include <iostream>
#include <string>
#include "calc.h"

using namespace std;

int main(){
    CCalc<int> i1; // int型のインスタンスを生成
    CCalc<string> i2; // string型のインスタンスを生成
    CCalc<double> i3;
    i1.set(1,2);
    i2.set("ABC","DEF");
    i3.set(1.4,3.9);
    cout << i1.add() << endl << i2.add() << endl << i3.add() << endl;
    return 0;
}









