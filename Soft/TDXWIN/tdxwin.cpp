#define TDXWIN_CPP
#include "tdxwin.h"

TdxWin::TdxWin()
{
    Tdx_Main_HWND=NULL;
    Sign_In_HWND=NULL;
}

bool TdxWin::Soft_Initial()
{
    Open_Soft();
    Wait_For_Sign_In();
}

void TdxWin::Set_Main_Top()
{
    api.Set_Top_Win(Tdx_Main_HWND);
}

void TdxWin::Focus_Buy()
{
    Set_Main_Top();

}

bool TdxWin::Open_Soft()
{
    Soft_Location="C:\\new_tdx_zcgl\\TdxW.exe";
    Tdx.startDetached(Soft_Location);
    while(!Sign_In_HWND)
    {
        Sign_In_HWND=api.Get_Win_HWND(Sign_In_Father,Sign_In_Layer,Sign_In_ClaName,Sign_In_WinName,Sign_In_Trail);
    }
    //cout<<Sign_In_HWND;
}

bool TdxWin::Wait_For_Sign_In()
{
    while(!Tdx_Main_HWND)
    {
        Tdx_Main_HWND=api.Get_Win_HWND(Main_Father,Main_Layer,Main_ClaName,Main_WinName,Main_Trail);
    }
}

bool TdxWin::HWND_Initial()
{

}
