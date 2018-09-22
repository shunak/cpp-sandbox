#ifndef _CDATA_H_
#define _CDATA_H_

#include <iostream>
#include <string>

using namespace std;

class CData{

  private:
    //  メンバ変数number
    int number;
    //  メンバ変数comment
    string comment;

  public:
    //  初期化
    void init();

    void setNumber(int num);

    int getNumber();

    void setComment(string com);

    string getComment();

    
};

#endif // _CDATA_H_