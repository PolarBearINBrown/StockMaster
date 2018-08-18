#define STOCK_CPP
#include "stock.h"

map<string,Data> Stock::My_Stock;

Stock::Stock()
{
}

bool Stock::Get_Account_Data()
{
    TdxWin::Output();
    FILE *file;
    file=_wfopen(TdxWin::Output_Location,L"r+");
    if(!file)
    {
        return true;
    }
    char tmp[400];
    char *dat=tmp;
    fgets(dat,400,file);
    dat+=13;
    while(!(*dat++==':'));

    //------获取可用资金------
    for(int i=0;;i++)
    {
        if(dat[i]==' ')
        {
            dat[i]='\0';
            QString Temp=dat;
            Data::A.available=Temp.toDouble();
            dat+=i+1;
            break;
        }
    }
    while(!(*dat++==':'));

    //------获取持有资产------
    for(int i=0;;i++)
    {
        if(dat[i]==' ')
        {
            dat[i]='\0';
            QString Temp=dat;
            Data::A.holding=Temp.toDouble();
            dat+=i+1;
            break;
        }
    }
    while(!(*dat++==':'));
    while(!(*dat++==':'));

    //------获取总资产------
    for(int i=0;;i++)
    {
        if(dat[i]==' ')
        {
            dat[i]='\0';
            QString Temp=dat;
            Data::A.assets=Temp.toDouble();
            dat+=i+1;
            break;
        }
    }

    dat=tmp;
    fgets(dat,400,file);
    dat=tmp;
    fgets(dat,400,file);
    dat=tmp;
    fgets(dat,400,file);
    dat=tmp;

    DED Inf;
    Inf.highest_price=0;
    Inf.error=false;
    while(fgets(dat,400,file))
    {
        //------获取证券代码------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                My_Stock[dat].Send_Code(dat);
                strcpy(Inf.code,dat);
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        //------获取证券名称------
        for(int i=0;;i++)
        {
            if(dat[i]==' '&&dat[i+1]==' ')
            {
                dat[i]='\0';
                My_Stock[dat].Send_Name(dat);
                WinAPI::Process_Name(dat,Inf.name);
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        //------获取证券数量------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString Tmp=dat;
                Inf.securities_quantity=Tmp.toFloat();
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        //------获取持仓量------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString Tmp=dat;
                Inf.hold_quantity=Tmp.toFloat();
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        //------获取可卖数量------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString Tmp=dat;
                Inf.available_quantity=Tmp.toFloat();
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat+=i+1;
                break;
            }
        }
        while(*dat++==' ');
        dat--;

        //------获取成本价------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString Tmp=dat;
                Inf.cost_price=Tmp.toFloat();
                dat+=i+1;
                break;
            }
        }

        My_Stock[Inf.code].Send_Decision_Data(Inf);
        dat=tmp;
    }

    fclose(file);
    return false;
}
