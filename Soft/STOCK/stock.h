#ifndef STOCK_H
#define STOCK_H

#if defined STOCK_CPP

#include "QString"
#include "stdio.h"
#include "iostream"
#include "fstream"
#include "TDXWIN/tdxwin.h"
#include "WINAPI/winapi.h"
using namespace std;

#endif

#include "string"
#include "map"
#include "DATA/data.h"
#include "STRATEGY/strategy.h"

class Stock
{
public:
    static char* Save_Location;
    static std::map<std::string,Data> My_Stock;

    Stock();
    static void Stock_Initial();
    static bool Get_Output_Data();
    static bool Read_Save_Data();
    static bool Save_Data();
    static void Main_Operate();
private:
    static void Process_Stock(std::map<std::string,Data>::iterator stk);
    static OPS  Judge(RTD rtd,IND ind,DED ded);
};

#endif
