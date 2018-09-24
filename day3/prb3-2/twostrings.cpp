#include "twostrings.h"
#include <string>

//  一つ目の文字列を設定
void TwoStrings::setString1(string s){
    m_string1 = s;
};

//  二つ目の文字列を設定
void TwoStrings::setString2(string s){
    m_string2 = s;
};


//  一つ目の文字列を取得
string TwoStrings::getString1(){
    return m_string1;
}


//  二つ目の文字列を取得
string TwoStrings::getString2(){
    return m_string2;
};


//  二つの文字列をつないだものを取得
string TwoStrings::getConnectedString(){
    std::string s1 = m_string1;
    std::string s2 = m_string2;
    std::string buf = s1 + s2;
    return buf;
};


//  getConnectedString()で得られる文字列の長さを取得
int TwoStrings::getConnectedLength(){

    string s = getConnectedString();
    return s.size();

};