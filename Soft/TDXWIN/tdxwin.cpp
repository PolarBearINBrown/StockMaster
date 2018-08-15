#define TDXWIN_CPP
#include "tdxwin.h"

char* TdxWin::Soft_Location;
char* TdxWin::Output_Location;
HWND  TdxWin::Tdx_Main_HWND;
HWND  TdxWin::Sign_In_HWND;

TdxWin::TdxWin()
{
}

bool TdxWin::Soft_Initial()
{
    Tdx_Main_HWND=NULL;
    Sign_In_HWND=NULL;
    Output_Location="D:\\Output.txt";
    Soft_Location="C:\\new_tdx_zcgl\\TdxW.exe";
    if(Open_Soft())
    {
        return true;
    }
    if(Wait_For_Sign_In())
    {
        return true;
    }
    Focus_Buy_Page();
    Focus_Sale_Page();
    Focus_Hold_Page();
    return false;
}

void TdxWin::Set_Main_Top()
{
    WinAPI::Set_Top_Win(Tdx_Main_HWND);
}

void TdxWin::Focus_Buy_Page()
{
    Set_Main_Top();
    Mouse::Mouse_Double_Click(Buy_Page_Button_x,Buy_Page_Button_y);
}

void TdxWin::Focus_Sale_Page()
{
    Set_Main_Top();
    Mouse::Mouse_Double_Click(Sale_Page_Button_x,Sale_Page_Button_y);
}

void TdxWin::Focus_Hold_Page()
{
    Set_Main_Top();
    Mouse::Mouse_Double_Click(Hold_Page_Button_x,Hold_Page_Button_y);
}

bool TdxWin::Buy(char *code,float price,int amount)
{
    Focus_Buy_Page();
    Keyboard::Key_String(code);
    Keyboard::Key_Enter();
    Keyboard::Key_String(QString::number(price).toStdString().c_str());
    Keyboard::Key_Enter();
    Keyboard::Key_String(QString::number(amount).toStdString().c_str());
    Keyboard::Key_Enter();
    return false;
}

bool TdxWin::Sale(char *code,float price,int amount)
{
    Focus_Sale_Page();
    Keyboard::Key_String(code);
    Keyboard::Key_Enter();
    Keyboard::Key_String(QString::number(price).toStdString().data());
    Keyboard::Key_Enter();
    Keyboard::Key_String(QString::number(amount).toStdString().data());
    Keyboard::Key_Enter();
    return false;
}

bool TdxWin::Output()
{
    Set_Main_Top();
    Focus_Hold_Page();
    Mouse::Mouse_Click(Output_Button_x,Output_Button_y);
    HWND Tmp=Check_Output_Win();
    WinAPI::Send_String(Tmp,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    WinAPI::Send_String(Tmp,Output_Location);
    Keyboard::Key_Enter();
    return false;
}

bool TdxWin::Open_Soft()
{
    QProcess::startDetached(Soft_Location);
    while(!Sign_In_HWND)
    {
        Sign_In_HWND=WinAPI::Get_Win_HWND(Sign_In_Father,Sign_In_Layer,Sign_In_ClaName,Sign_In_WinName,Sign_In_Trail);
    }
    //cout<<Sign_In_HWND;
    return false;
}

bool TdxWin::Wait_For_Sign_In()
{
    while(!Tdx_Main_HWND)
    {
        Tdx_Main_HWND=WinAPI::Get_Win_HWND(Main_Father,Main_Layer,Main_ClaName,Main_WinName,Main_Trail);
    }
    return false;
}

HWND TdxWin::Check_Output_Win()
{
    HWND Tmp=NULL;
    while(!Tmp)
    {
        Tmp=WinAPI::Get_Win_HWND(Output_Win_Father,Output_Win_Layer,Output_Win_ClaName,Output_Win_WinName,Output_Win_Trail);
    }
    return Tmp;
}
