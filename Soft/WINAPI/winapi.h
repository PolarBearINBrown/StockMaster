#ifndef WINAPI_H
#define WINAPI_H

#if defined WINAPI_CPP


#endif

#include "windows.h"

class WinAPI
{
public:
    WinAPI();
    static HWND Get_Win_HWND(HWND Father,int Layer,WCHAR *ClaName[],WCHAR *WinName[],int Trail[]);
    static void Set_Top_Win(HWND hwnd);
    static void Destroy_Win(HWND hwnd);
    static void Click_Window(HWND hwnd,int x,int y);
    static void Double_Click_Window(HWND hwnd,int x,int y);
    static void Send_String(HWND hwnd,const char *acc);
    static void Char_To_WChar(const char *acc,WCHAR *name);
    static void WChar_To_Char(WCHAR *acc,const char *name);
    static int  Check_Time(int h,int m,int s);
private:

};

#endif
