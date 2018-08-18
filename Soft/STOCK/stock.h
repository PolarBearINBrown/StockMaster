#ifndef STOCK_H
#define STOCK_H

#if defined STOCK_CPP

#include "QString"
#include "stdio.h"
#include "TDXWIN/tdxwin.h"
#include "WINAPI/winapi.h"
using namespace std;

#endif

#include "string"
#include "map"
#include "DATA/data.h"

class Stock
{
public:
    Stock();
    static bool Get_Account_Data();
private:
    static std::map<std::string,Data> My_Stock;
};

#endif
