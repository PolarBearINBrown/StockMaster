#ifndef WEB_H
#define WEB_H

#if defined WEB_CPP

#include "string.h"
#include "iostream"
using namespace std;

#endif

#include "QString"
#include "stdlib.h"
#include "winsock2.h"
#pragma comment(lib,"ws2_32.lib")

class Web
{
public:
    Web();
    bool Send_Host(char* hos);
    QString Get_Infomation(char* Sub);
private:
    char*       host;
    char*       subdirectory;
    WSADATA     data;
    hostent     *h;
    in_addr     ina;
    LPSTR       ipstr;
    sockaddr_in si;
    int         sock;
    int         ret;

    bool Web_Initial();
    bool Get_IPaddr();
    bool Sock_Package();
    bool Send_Request();
    bool Release_Variable();
};

#endif
