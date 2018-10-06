#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include <iostream>
#include <string>

using namespace std;

class CSample{
    private:
        string m_str;
    public:
        CSample();
        void setStr(const string str);
        string getStr() const;
    public:
        static const int m_cst = 100;
};

#endif





