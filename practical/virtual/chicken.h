#ifndef _CHICKEN_H_
#define _CHICKEN_H_

#include "bird.h"


// define chicken class
class CChicken : public CBird{
    public:

        void sing(){
            cout << "こけっこ" << endl;
        }

        void fly(){
            cout << "CHICKENS can`t fly" << endl;
        }
};



#endif