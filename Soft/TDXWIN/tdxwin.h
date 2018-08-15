#ifndef TDXWIN_H
#define TDXWIN_H

#if defined TDXWIN_CPP

#include "MOUSE/mouse.h"
#include "QProcess"
#include "WINAPI/winapi.h"
#include "iostream"
#include "KEYBOARD/keyboard.h"
#include "QString"
using namespace std;

//-------登录窗口信息-------
#define Sign_In_Father NULL
int     Sign_In_Layer=1;
WCHAR*  Sign_In_ClaName[1]={
    L"#32770"
};
WCHAR*  Sign_In_WinName[1]={
    L"通达信模拟交易终端V8.05"
};
int     Sign_In_Trail[1]={1};

//-------主窗口信息-------
#define Main_Father NULL
int     Main_Layer=1;
WCHAR*  Main_ClaName[1]={
    L"TdxW_MainFrame_Class"
};
WCHAR*  Main_WinName[1]={
    NULL
};
int     Main_Trail[1]={1};

//-------输出窗口信息-------
#define Output_Win_Father Tdx_Main_HWND
int     Output_Win_Layer=2;
WCHAR*  Output_Win_ClaName[2]={
    L"#32770",
    L"Edit"
};
WCHAR*  Output_Win_WinName[2]={
    L"输出",
    L""
};
int     Output_Win_Trail[2]={1,1};

//-------买入页面按钮信息-------
int Buy_Page_Button_x=232;
int Buy_Page_Button_y=466;

//-------卖出页面按钮信息-------
int Sale_Page_Button_x=262;
int Sale_Page_Button_y=466;

//-------持仓页面按钮信息-------
int Hold_Page_Button_x=360;
int Hold_Page_Button_y=466;

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
    static char* Output_Location;
    static HWND  Tdx_Main_HWND;
    static HWND  Sign_In_HWND;

    TdxWin();
    static bool Soft_Initial();
    static void Set_Main_Top();
    static bool Buy(char* code,float price,int amount);
    static bool Sale(char* code,float price,int amount);
    static bool Output();
private:
    static bool Open_Soft();
    static bool Wait_For_Sign_In();
    static void Focus_Buy_Page();
    static void Focus_Sale_Page();
    static void Focus_Hold_Page();
    static HWND Check_Output_Win();
};

#endif
