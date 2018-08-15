#ifndef DATA_H
#define DATA_H

#if defined DATA_CPP

#include "QString"
#include "WEB/web.h"
#include "string.h"
#include "iostream"
using namespace std;

#endif

typedef struct Real_Time_Data
{
    bool      run;
    char*     code;
    char*     name;
    float     open;
    float     close_yes;
    float     current;
    float     highest;
    float     lowest;
    float     bid;       //竞买价
    float     auction;   //竞卖价
    int       volume;
    double    turnover;
    int       buy_1_amount;
    float     buy_1_price;
    int       buy_2_amount;
    float     buy_2_price;
    int       buy_3_amount;
    float     buy_3_price;
    int       buy_4_amount;
    float     buy_4_price;
    int       buy_5_amount;
    float     buy_5_price;
    int       sale_1_amount;
    float     sale_1_price;
    int       sale_2_amount;
    float     sale_2_price;
    int       sale_3_amount;
    float     sale_3_price;
    int       sale_4_amount;
    float     sale_4_price;
    int       sale_5_amount;
    float     sale_5_price;
    char*     date;
    char*     time;
} RTD;

typedef struct Index_Data
{
    bool      run;
    char*     code;
    char*     name;
} IND;

class Data
{
public:
    Data();
    void Send_Code(char* code);
    RTD Get_Real_Time_Data();
    IND Get_Index_Data();
private:
    RTD R;
    IND I;
    bool Process_String(char *dat);
    bool Refresh_Real_Time_Data();
    bool Refresh_Index_Data();
    void Output_RTD();
    void Output_IND();
};

#endif
