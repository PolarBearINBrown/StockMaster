#include "mainwindow.h"
#include "DATA/data.h"
#include "MOUSE/mouse.h"
#include "TDXWIN/tdxwin.h"
#include "STOCK/stock.h"
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

    /*
    TdxWin::Soft_Initial();
    Data D;
    D.Send_Code("600000");
    D.Get_Index_Data();
    */

    //TdxWin::Soft_Initial();
    Stock::Get_Account_Data();

    return a.exec();
}
