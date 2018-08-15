#define KEYBOARD_CPP
#include "keyboard.h"

Keyboard::Keyboard()
{
}

void Keyboard::Key_Backspace()
{
    keybd_event(VK_BACK,0,0,0);
    keybd_event(VK_BACK,0,KEYEVENTF_KEYUP,0);
}

void Keyboard::Key_Enter()
{
    keybd_event(VK_RETURN,0,0,0);
    keybd_event(VK_RETURN,0,KEYEVENTF_KEYUP,0);
}

void Keyboard::Key_String(const char *acc)
{
    int len=strlen(acc);
    for(int i=0;i<len;i++)
    {
        if(acc[i]=='.')
        {
            keybd_event(VK_DECIMAL,0,0,0);
            keybd_event(VK_DECIMAL,0,KEYEVENTF_KEYUP,0);
        }
        else
        {
            keybd_event(acc[i],0,0,0);
            keybd_event(acc[i],0,KEYEVENTF_KEYUP,0);
        }
    }
}
