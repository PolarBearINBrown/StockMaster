#define STRATEGY_CPP
#include "strategy.h"

Strategy::Strategy()
{}

OPS Strategy::Stop_Loss(RTD rtd, IND ind, DED ded)
{
    OPS o;
    memset(&o,0,sizeof(OPS));
    if(rtd.current<ded.highest_price*0.95)
    {
        o.operate=BUY;
        o.price=rtd.current;
        o.amount=ded.available_quantity;
    }
    return o;
}
