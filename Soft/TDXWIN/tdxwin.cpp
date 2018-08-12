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

}

bool TdxWin::HWND_Initial()
{

}
