#ifndef TDXWIN_H
#define TDXWIN_H

#include "windows.h"
#include "MOUSE/mouse.h"
#include "QProcess"
#include "WINAPI/winapi.h"

class TdxWin
{
public:
    char* Soft_Location;
    char* Account_Number;
    char* Password;
    HWND  Tdx_Main_HWND;
    HWND  Sign_In_HWND;

    TdxWin();
    bool Soft_Initial();
    void Set_Main_Top();
    bool Buy(char* code,float price,int amount);
    bool Sale(char* code,float price,int amount);
private:
    WinAPI   api;
    QProcess Tdx;
    Mouse    Mos;
    bool Open_Soft();
    bool Wait_For_Sign_In();
    bool HWND_Initial();
    void Focus_Buy();
    void Focus_Sale();
};

#if defined TDXWIN_CPP

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

#endif
