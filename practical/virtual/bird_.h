#ifndef _BIRD_H_
#define _BIRD_H_

#include <iostream>
#include <string>

using namespace std;

class CBird{

    public:
        // virtual function
        virtual void sing(){
            cout << "birds cry" << endl;
        }
        void fly(){
            cout << "birds fly" << endl;
        }

};


#endif









