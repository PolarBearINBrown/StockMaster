#ifndef DATA_H
#define DATA_H

#if defined DATA_CPP

#include "QString"
#include "WEB/web.h"
#include "TDXWIN/tdxwin.h"
#include "string.h"
#include "iostream"
#include "WINAPI/winapi.h"
using namespace std;

#endif

#include "vector"

typedef struct Real_Time_Data
{
    bool      error;
    char      code[10];
    wchar_t   name[6];
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
    bool    error;
    char    code[10];
    wchar_t name[6];
    struct KDJ
    {
        float K;
        float D;
        float J;
    } KDJ;
    struct VOL_TDX
    {
        double WOL;
        double VOLUME;
        double MA8;
        double MA89;
    } VOL_TDX;
} IND;

typedef struct Account_Data
{
    bool   error;
    double available;
    double holding;
    double assets;
} ACD;

typedef struct Decision_Data
{
    bool    error;
    char    code[10];
    wchar_t name[6];
    int     securities_quantity;
    int     hold_quantity;
    int     available_quantity;
    float   cost_price;
    float   highest_price;
    std::vector<int> strategy;
} DED;

class Data
{
public:
    Data();

    RTD R;
    IND I;
    DED D;
    static ACD A;

    void Send_Code(const char *code);
    void Send_Name(const char *name);
    bool Refresh_Real_Time_Data();
    bool Refresh_Index_Data();
    bool Refresh_Decision_Data();
    void Send_Decision_Data(DED sd);
    void Add_Strategy(int s);
    void Swap_Strategy(int a,int b);
private:
    bool Process_String(char *dat);
    bool Read_KDJ();
    void Output_RTD();
    void Output_IND();
};

#endif
