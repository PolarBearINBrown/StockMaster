#define TDXWIN_CPP
#include "tdxwin.h"

char* TdxWin::Soft_Location;
HWND  TdxWin::Tdx_Main_HWND;
HWND  TdxWin::Sign_In_HWND;

TdxWin::TdxWin()
{
    Tdx_Main_HWND=NULL;
    Sign_In_HWND=NULL;
}

bool TdxWin::Soft_Initial()
{
    Open_Soft();
    Wait_For_Sign_In();
    Focus_Buy();
    Focus_Sale();
    Focus_Hold();
}

void TdxWin::Set_Main_Top()
{
    WinAPI::Set_Top_Win(Tdx_Main_HWND);
}

void TdxWin::Focus_Buy()
{
    Set_Main_Top();
    Mouse::Mouse_Click(Buy_Button_x,Buy_Button_y);
}

void TdxWin::Focus_Sale()
{
    Set_Main_Top();
    Mouse::Mouse_Click(Sale_Button_x,Sale_Button_y);
}

void TdxWin::Focus_Hold()
{
    Set_Main_Top();
    Mouse::Mouse_Click(Hold_Button_x,Hold_Button_y);
}

bool TdxWin::Open_Soft()
{
    Soft_Location="C:\\new_tdx_zcgl\\TdxW.exe";
    QProcess::startDetached(Soft_Location);
    while(!Sign_In_HWND)
    {
        Sign_In_HWND=WinAPI::Get_Win_HWND(Sign_In_Father,Sign_In_Layer,Sign_In_ClaName,Sign_In_WinName,Sign_In_Trail);
    }
    //cout<<Sign_In_HWND;
}

bool TdxWin::Wait_For_Sign_In()
{
    while(!Tdx_Main_HWND)
    {
        Tdx_Main_HWND=WinAPI::Get_Win_HWND(Main_Father,Main_Layer,Main_ClaName,Main_WinName,Main_Trail);
    }
}

bool TdxWin::HWND_Initial()
{

}
