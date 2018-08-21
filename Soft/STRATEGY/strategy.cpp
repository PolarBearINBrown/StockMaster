#define STRATEGY_CPP
#include "strategy.h"

wchar_t *Strategy::Strategy_Name[Num_Of_Strategy]={
    L"止损止盈",
    L"追高买入"
};
wchar_t *Strategy::Strategy_Description[Num_Of_Strategy]={
    L"    当股票当前价格低于买入股票起曾到过的最高价的95%时，卖出股票。",
    L"    比开盘价高0.01元买入200股。"
};
map<QString,int> Strategy::Name_To_Num;

Strategy::Strategy()
{}

void Strategy::Initial()
{
    for(int i=0;i<Num_Of_Strategy;i++)
    {
        Name_To_Num[QString::fromWCharArray(Strategy_Name[i])]=i;
    }
}

OPS  Strategy::Stop_Loss(RTD rtd, IND ind, DED ded)
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
