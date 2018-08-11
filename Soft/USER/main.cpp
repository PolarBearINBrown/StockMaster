#include "mainwindow.h"
#include "TRADE/trade.h"
#include "DATA/data.h"
#include <QApplication>

#include "iostream"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Data D;
    while(1)
    {
        char *C;
        cin>>C;
        D.Send_Code(C);
        RTD T=D.Get_Real_Time_Data();
    }
    return a.exec();
}
