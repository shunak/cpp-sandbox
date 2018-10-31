#ifndef _BIRD_H_
#define _BIRD_H_

#include <iostream>
#include <string>

using namespace std;

class CBird{

    public:
        // pure virtual function
        virtual void sing()=0;

        void fly(){
            cout << "birds fly" << endl;
        }

};


#endif









