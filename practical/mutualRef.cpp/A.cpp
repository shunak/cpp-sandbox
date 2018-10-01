#include "A.h"
#include "B.h"
#include <iostream>


using namespace std;


A::A(){
    m_pB = new B(this);
}

void A::foo(){
    cout << "foo" << endl;
}

void A::bar(){
    m_pB->hoge();
}