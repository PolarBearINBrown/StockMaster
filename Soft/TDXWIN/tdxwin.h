#ifndef TDXWIN_H
#define TDXWIN_H

#if defined TDXWIN_CPP

#include "MOUSE/mouse.h"
#include "QProcess"
#include "WINAPI/winapi.h"
#include "iostream"
using namespace std;

//-------登录窗口信息-------
HWND   Sign_In_Father=NULL;
int    Sign_In_Layer=1;
WCHAR *Sign_In_ClaName[1]={
    L"#32770"
};
WCHAR *Sign_In_WinName[1]={
    L"通达信模拟交易终端V8.05"
};
int    Sign_In_Trail[1]={1};

//-------主窗口信息-------
HWND   Main_Father=NULL;
int    Main_Layer=1;
WCHAR *Main_ClaName[1]={
    L"TdxW_MainFrame_Class"
};
WCHAR *Main_WinName[1]={
    NULL
};
int    Main_Trail[1]={1};

//-------买入按钮信息-------
int Buy_Button_x=232;
int Buy_Button_y=466;

//-------卖出按钮信息-------
int Sale_Button_x=262;
int Sale_Button_y=466;

//-------持仓按钮信息-------
int Hold_Button_x=360;
int Hold_Button_y=466;

//-------输出按钮信息-------
int Output_Button_x=1333;
int Output_Button_y=550;

//-------输出目录信息-------
int Output_Content_Button_x=900;
int Output_Content_Button_y=566;

#endif

#include "windows.h"

class TdxWin
{
public:
    static char* Soft_Location;
    static HWND  Tdx_Main_HWND;
    static HWND  Sign_In_HWND;

    TdxWin();
    static bool Soft_Initial();
    static void Set_Main_Top();
    static bool Buy(char* code,float price,int amount);
    static bool Sale(char* code,float price,int amount);
private:
    static bool Open_Soft();
    static bool Wait_For_Sign_In();
    static bool HWND_Initial();
    static void Focus_Buy();
    static void Focus_Sale();
    static void Focus_Hold();
};

#endif
