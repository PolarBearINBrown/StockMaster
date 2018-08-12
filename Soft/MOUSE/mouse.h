#ifndef MOUSE_H
#define MOUSE_H

#if defined MOUSE_CPP

#include "windows.h"
#include "winuser.h"
using namespace std;

#endif

class Mouse
{
public:
    Mouse();
    void Get_Mouse_Loc(int* x,int* y);
    void Mouse_Click(int x,int y);
    void Mouse_Double_Click(int x,int y);
private:

};

#endif
