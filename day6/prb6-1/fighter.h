#ifndef _FIGHTER_H_
#define _FIGHTER_H_

#include "airplane.h"

//  戦闘機クラス(inherit ariplane class)
class Fighter : public Airplane{
  public:
    // 戦闘する
    void fight();

};

#endif // _FIGHTER_H_