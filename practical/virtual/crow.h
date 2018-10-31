#ifndef _CROE_H_
#define _CROW_H_

#include "bird.h"


// define bird class
class CCrow : public CBird{
    public:
        // sing
        void sing(){
            cout << "カーカー" << endl;
        }

        void fly(){
            cout << "crows fly" << endl;
        }
};

#endif







