#ifndef TDXWIN_H
#define TDXWIN_H

#include "windows.h"
#include "QProcess"
#include "WINAPI/winapi.h"

class TdxWin
{
public:
    char* Soft_Location;
    HWND  Tdx_Main_HWND;
    HWND  Sign_In_HWND;

    TdxWin();
    bool Soft_Initial();
    void Set_Main_Top();
private:
    WinAPI   api;
    QProcess Tdx;
    bool Open_Soft();
    bool Wait_For_Sign_In();
    bool HWND_Initial();
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


#endif

#endif
