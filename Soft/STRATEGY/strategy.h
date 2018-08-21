#ifndef STRATEGY_H
#define STRATEGY_H

#if defined STRATEGY_CPP

#include "string.h"
using namespace std;

#endif

#include "DATA/data.h"
#include "QString"
#include "map"

#define Num_Of_Strategy 2

#define BUY   1
#define SALE -1
#define NONE  0

#define STOP_LOSS 0

typedef struct Operate_Signal{
    int  operate;
    int  price;
    int  amount;
} OPS;

class Strategy
{
public:
    static wchar_t *Strategy_Name[Num_Of_Strategy];
    static std::map<QString,int> Name_To_Num;
    static wchar_t *Strategy_Description[Num_Of_Strategy];

    Strategy();
    static void Initial();
    static OPS Stop_Loss(RTD rtd,IND ind,DED ded);
private:

};

#endif
