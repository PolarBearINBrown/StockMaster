#ifndef KEYBOARD_H
#define KEYBOARD_H

#if defined KEYBOARD_CPP

#include "cstdio"
#include "windows.h"
#include "iostream"
#include "stdlib.h"
using namespace std;

#endif

class Keyboard
{
public:
    Keyboard();
    static void Key_Backspace();
    static void Key_Enter();
    static void Key_Esc();
    static void Key_String(const char *acc);
private:

};

#endif
