#include "mainwindow.h"
#include "DATA/data.h"
#include "MOUSE/mouse.h"
#include "TDXWIN/tdxwin.h"
#include <QApplication>

#include "iostream"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    /*
    MainWindow w;
    w.show();
    */

    /*
    Data D;
    while(1)
    {
        char *C;
        cin>>C;
        D.Send_Code(C);
        D.Get_Real_Time_Data();
    }
    */

    /*
    Mouse M;
    int x,y,xx,yy;
    while(true)
    {
        M.Get_Mouse_Loc(&xx,&yy);
        if(x!=xx||y!=yy)
        {
            x=xx;
            y=yy;
            printf("\rX:%5d  Y:%5d",x,y);
        }
    }
    */

    TdxWin tdx;
    tdx.Soft_Initial();

    return a.exec();
}
