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
#define Output_Win_Father NULL
int     Output_Win_Layer=2;
WCHAR*  Output_Win_ClaName[2]={
    L"#32770",
    L"Edit"
};
WCHAR*  Output_Win_WinName[2]={
    L"输出",
    NULL
};
int     Output_Win_Trail[2]={1,1};

//-------指标输出路径信息-------
#define Index_Win_Father NULL
int     Index_Win_Layer=2;
WCHAR*  Index_Win_ClaName[2]={
    L"#32770",
    L"Edit"
};
WCHAR*  Index_Win_WinName[2]={
    L"数据导出",
    L""
};
int     Index_Win_Trail[2]={1,1};

//-------确认页面信息-------
#define Confirm_Win_Father NULL
int     Confirm_Win_Layer=1;
WCHAR*  Confirm_Win_ClaName[1]={
    L"#32770"
};
WCHAR*  Confirm_Win_WinName[1]={
    L"TdxW"
};
int     Confirm_Win_Trail[1]={1};

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

//-------主页面信息-------
int Main_Page_x=400;
int Main_Page_y=200;

#endif

#include "windows.h"

class TdxWin
{
public:
    static char*  Soft_Location;
    static char*  Index_Location;
    static WCHAR* Output_Location;
    static HWND   Tdx_Main_HWND;
    static HWND   Sign_In_HWND;

    TdxWin();
    static bool Soft_Initial();
    static void Set_Main_Top();
    static void Click_Main_Page();
    static bool Buy(char* code,float price,int amount);
    static bool Sale(char* code,float price,int amount);
    static bool Output();
    static bool Save_Index(char *code,char *index);
private:
    static bool Open_Soft();
    static bool Wait_For_Sign_In();
    static void Focus_Buy_Page();
    static void Focus_Sale_Page();
    static void Focus_Hold_Page();
    static HWND Check_Output_Win();
    static HWND Check_Index_Win();
    static HWND Check_Confirm_Win();
};

#endif
