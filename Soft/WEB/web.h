#ifndef WEB_H
#define WEB_H

#if defined WEB_CPP

#include "string.h"
#include "iostream"
using namespace std;

#endif

#include "winsock2.h"

class Web
{
public:
    Web();
    static bool  Send_Host(char* hos);
    static char* Get_Infomation(char* Sub);
private:
    static char*       host;
    static char*       subdirectory;
    static WSADATA     data;
    static hostent     *h;
    static in_addr     ina;
    static LPSTR       ipstr;
    static sockaddr_in si;
    static int         sock;

    static bool Web_Initial();
    static bool Get_IPaddr();
    static bool Sock_Package();
    static bool Send_Request();
    static bool Release_Variable();
};

#endif
