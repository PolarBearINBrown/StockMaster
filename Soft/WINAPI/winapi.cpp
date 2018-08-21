#define WINAPI_CPP
#include "winapi.h"

WinAPI::WinAPI()
{
}

HWND WinAPI::Get_Win_HWND(HWND Father, int Layer, WCHAR *ClaName[], WCHAR *WinName[], int Trail[])
{
    HWND Child=NULL;
    for(int i=0;i<Layer;i++)
    {
        for(int j=0;j<Trail[i];j++)
        {
            Child=FindWindowEx(Father,Child,ClaName[i],WinName[i]);
            if(!Child)
            {
                return (HWND)-i;
            }
        }
        Father=Child;
        Child=NULL;
    }
    return Father;
}

void WinAPI::Set_Top_Win(HWND hwnd)
{
    ShowWindow(hwnd,SW_MAXIMIZE);
    HWND Judge=GetForegroundWindow();
    while(Judge!=hwnd)
    {
        ShowWindow(Judge,SW_MINIMIZE);
        //SendMessage(hwnd,WM_DESTROY,0,0);
        Judge=GetForegroundWindow();
    }
    return;
}

void WinAPI::Destroy_Win(HWND hwnd)
{
    SendMessage(hwnd,WM_DESTROY,0,0);
    return;
}

void WinAPI::Click_Window(HWND hwnd, int x, int y)
{
    PostMessage(hwnd,WM_SETFOCUS,0,0);
    PostMessage(hwnd,WM_LBUTTONDOWN,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_GETDLGCODE,DLGC_BUTTON,0);
    PostMessage(hwnd,WM_LBUTTONUP,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_KILLFOCUS,0,0);
    return;
}

void WinAPI::Double_Click_Window(HWND hwnd, int x, int y)
{
    PostMessage(hwnd,WM_SETFOCUS,0,0);
    PostMessage(hwnd,WM_LBUTTONDOWN,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_GETDLGCODE,DLGC_BUTTON,0);
    PostMessage(hwnd,WM_LBUTTONUP,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_LBUTTONDOWN,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_GETDLGCODE,DLGC_BUTTON,0);
    PostMessage(hwnd,WM_LBUTTONUP,0,MAKELPARAM(x,y));
    PostMessage(hwnd,WM_KILLFOCUS,0,0);
    return;
}

void WinAPI::Send_String(HWND hwnd,const char *acc)
{
    int len=strlen(acc);
    for(int i=0;i<len;i++)
    {
        Sleep(10);
        SendMessage(hwnd,WM_CHAR,acc[i],0);
    }
    return;
}

void WinAPI::Char_To_WChar(const char *acc,WCHAR *name)
{
    MultiByteToWideChar(CP_ACP,0,acc,-1,name,8);
    return;
}

void WinAPI::WChar_To_Char(WCHAR *acc, const char *name)
{
    WideCharToMultiByte(CP_OEMCP,0,acc,-1,(LPSTR)name,10,NULL,0);
}

int  WinAPI::Check_Time(int h,int m,int s)
{
    SYSTEMTIME Tim;
    GetLocalTime(&Tim);
    if((int)Tim.wHour>h)
    {
        return 1;
    }
    else if((int)Tim.wHour<h)
    {
        return -1;
    }
    else
    {
        if(Tim.wMinute>m)
        {
            return 1;
        }
        else if(Tim.wMinute<m)
        {
            return -1;
        }
        else
        {
            if(Tim.wSecond>s)
            {
                return 1;
            }
            else if(Tim.wSecond<s)
            {
                return -1;
            }
            else
            {
                return 0;
            }
        }
    }
}
