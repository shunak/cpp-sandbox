#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

int main(){
    string s;
    s = "This is a ";
    s.append("pen.");
    cout << s << endl;
    cout << "文字列の長さ：" << s.length() << endl;
    printf("char*:%s\n", s.c_str());
    return 0;
}