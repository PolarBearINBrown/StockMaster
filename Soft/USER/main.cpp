#include "mainwindow.h"
#include "DATA/data.h"
#include "MOUSE/mouse.h"
#include "TDXWIN/tdxwin.h"
#include "STOCK/stock.h"
#include "WEB/web.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Stock::Read_Save_Data();
    Web::Send_Host("hq.sinajs.cn");
    MainWindow w;
    w.show();
    return a.exec();
}
