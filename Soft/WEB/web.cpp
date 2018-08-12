#define WEB_CPP
#include "web.h"

Web::Web()
{

}

bool Web::Send_Host(char *hos)
{
    host=hos;
    if(Web_Initial())
    {
        return true;
    }
    return false;
}

char* Web::Get_Infomation(char *Sub)
{
    subdirectory=Sub;
    if(Send_Request())
    {
        return "ERROR";
    }
    char* buf=(char*)calloc(1024,1);
    recv(sock,buf,1023,0);
    return buf;
}

bool Web::Web_Initial()
{
    if(Get_IPaddr())
    {
        return true;
    }
    if(Sock_Package())
    {
        return true;
    }
    return false;
}

bool Web::Get_IPaddr()
{
    if(WSAStartup(MAKEWORD(2,2),&data))
    {
        return true;
    }
    h=gethostbyname(host);
    if(!h||h->h_addrtype!=AF_INET)
    {
        return true;
    }
    memmove(&ina,h->h_addr,4);
    ipstr=inet_ntoa(ina);
    return false;
}

bool Web::Sock_Package()
{
    si.sin_family=AF_INET;
    si.sin_port=htons(80);
    si.sin_addr.S_un.S_addr=inet_addr(ipstr);
    sock=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    connect(sock,(SOCKADDR*)&si,sizeof(sockaddr_in));
    if(sock==-1||sock==-2)
    {
        return true;
    }
    return false;
}

bool Web::Send_Request()
{
    char request[1024]="GET /";
    strcat(request,subdirectory);
    strcat(request," HTTP/1.1\r\nHost: ");
    strcat(request,host);
    strcat(request,"\r\nConnection:Close\r\n\r\n");
    send(sock,request,strlen(request),0);
    return false;
}

bool Web::Release_Variable()
{
    closesocket(sock);
    WSACleanup();
    return false;
}
