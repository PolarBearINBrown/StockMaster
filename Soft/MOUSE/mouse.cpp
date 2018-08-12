#define MOUSE_CPP
#include "mouse.h"

Mouse::Mouse()
{

}

void Mouse::Get_Mouse_Loc(int *x, int *y)
{
    POINT PT;
    GetCursorPos(&PT);
    *x=PT.x;
    *y=PT.y;
}

void Mouse::Mouse_Click(int x, int y)
{
    SetCursorPos(x,y);
    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
}

void Mouse::Mouse_Double_Click(int x,int y)
{
    SetCursorPos(x,y);
    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
}
