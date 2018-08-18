#define TDXWIN_CPP
#include "tdxwin.h"

char*  TdxWin::Soft_Location;
char*  TdxWin::Index_Location;
WCHAR* TdxWin::Output_Location;
HWND   TdxWin::Tdx_Main_HWND;
HWND   TdxWin::Sign_In_HWND;

TdxWin::TdxWin()
{
}

bool TdxWin::Soft_Initial()
{
    Tdx_Main_HWND=NULL;
    Sign_In_HWND=NULL;
    Output_Location=L"D:\\Documents\\20180818 资金股份查询.txt";
    Soft_Location="C:\\new_tdx_zcgl\\TdxW.exe";
    Index_Location="D:\\";
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

void TdxWin::Click_Main_Page()
{
    Mouse::Mouse_Click(Main_Page_x,Main_Page_y);
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
    Sleep(2000);
    Mouse::Mouse_Click(Output_Button_x,Output_Button_y);
    Check_Output_Win();
    Keyboard::Key_Enter();
    return false;
}

bool TdxWin::Save_Index(char *code, char *index)
{
    Set_Main_Top();
    Click_Main_Page();
    Keyboard::Key_String(code);
    Keyboard::Key_Enter();
    Keyboard::Key_String(index);
    Keyboard::Key_Enter();
    Keyboard::Key_String("34");
    Keyboard::Key_Enter();
    HWND Index_Win_HWND=Check_Index_Win();
    WinAPI::Send_String(Index_Win_HWND,"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
    WinAPI::Send_String(Index_Win_HWND,Index_Location);
    WinAPI::Send_String(Index_Win_HWND,code);
    WinAPI::Send_String(Index_Win_HWND,".txt");
    Keyboard::Key_Enter();
    Check_Confirm_Win();
    Keyboard::Key_Esc();
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
    Sleep(1000);
    return false;
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

HWND TdxWin::Check_Output_Win()
{
    HWND Tmp=NULL;
    while(Tmp==NULL||Tmp==(HWND)4294967295)
    {
        Tmp=WinAPI::Get_Win_HWND(Output_Win_Father,Output_Win_Layer,Output_Win_ClaName,Output_Win_WinName,Output_Win_Trail);
    }
    Sleep(100);
    return Tmp;
}

HWND TdxWin::Check_Index_Win()
{
    HWND Tmp=NULL;
    while(Tmp==NULL||Tmp==(HWND)4294967295)
    {
        Tmp=WinAPI::Get_Win_HWND(Index_Win_Father,Index_Win_Layer,Index_Win_ClaName,Index_Win_WinName,Index_Win_Trail);
    }
    Sleep(100);
    return Tmp;
}

HWND TdxWin::Check_Confirm_Win()
{
    HWND Tmp=NULL;
    while(!Tmp)
    {
        Tmp=WinAPI::Get_Win_HWND(Confirm_Win_Father,Confirm_Win_Layer,Confirm_Win_ClaName,Confirm_Win_WinName,Confirm_Win_Trail);
    }
    return Tmp;
}
