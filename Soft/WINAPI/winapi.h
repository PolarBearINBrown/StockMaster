#ifndef WINAPI_H
#define WINAPI_H

#if defined WINAPI_CPP


#endif

#include "windows.h"

class WinAPI
{
public:
    WinAPI();
    HWND Get_Win_HWND(HWND Father,int Layer,WCHAR *ClaName[],WCHAR *WinName[],int Trail[]);
    void Set_Top_Win(HWND hwnd);
    void Click_Window(HWND hwnd,int x,int y);
    void Double_Click_Window(HWND hwnd,int x,int y);
    void Send_String(HWND hwnd,char* acc);
private:

};

#endif
