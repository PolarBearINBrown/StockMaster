#ifndef STRATEGY_H
#define STRATEGY_H

#if defined STRATEGY_CPP

#include "string.h"
using namespace std;

#endif

#include "DATA/data.h"

#define BUY   1
#define SALE -1
#define NONE  0

#define STOP_LOSS 1

typedef struct Operate_Signal{
    int  operate;
    int  price;
    int  amount;
} OPS;

class Strategy
{
public:
    Strategy();
    static OPS Stop_Loss(RTD rtd,IND ind,DED ded);
private:
};

#endif
