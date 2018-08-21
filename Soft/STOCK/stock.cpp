#define STOCK_CPP
#include "stock.h"

char*            Stock::Save_Location;
map<string,Data> Stock::My_Stock;

Stock::Stock()
{
}

void Stock::Stock_Initial()
{
    My_Stock.clear();
}

bool Stock::Get_Output_Data()
{
    TdxWin::Output();
    FILE *file;
    file=fopen(TdxWin::Output_Location,"r+");
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
    Inf.error=false;
    while(fgets(dat,400,file))
    {
        //------获取证券代码------
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                if(My_Stock.count(dat))
                {
                    Inf=My_Stock[dat].D;
                }
                else
                {
                    memset(&Inf,0,sizeof(DED));
                }
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
                My_Stock[Inf.code].Send_Name(dat);
                WinAPI::Char_To_WChar(dat,Inf.name);
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

bool Stock::Read_Save_Data()
{
    Save_Location="D:\\Save.txt";
    FILE *file;
    file=fopen(Save_Location,"r+");
    if(!file)
    {
        strcpy(TdxWin::Soft_Location,"C:\\new_tdx_zcgl\\TdxW.exe");
        return false;
    }
    fgets(TdxWin::Soft_Location,100,file);

    DED Tmp;
    char name[10];
    char get[400];
    char *dat=get;
    int s;
    Tmp.error=false;
    while(true)
    {
        fgets(dat,400,file);
        if(!strcmp(dat,"end"))
        {
            break;
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                strcpy(Tmp.code,dat);
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' '&&dat[i+1]==' ')
            {
                dat[i]='\0';
                strcpy(name,dat);
                dat+=i+2;
                break;
            }
        }
        WinAPI::Char_To_WChar(name,Tmp.name);
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                Tmp.securities_quantity=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                Tmp.hold_quantity=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                Tmp.available_quantity=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                Tmp.cost_price=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                Tmp.highest_price=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        for(int i=0;;i++)
        {
            if(dat[i]==' ')
            {
                dat[i]='\0';
                QString TMP=dat;
                s=TMP.toFloat();
                dat+=i+1;
                break;
            }
        }
        while(s!=-1)
        {
            Tmp.strategy.push_back(s);
            for(int i=0;;i++)
            {
                if(dat[i]==' ')
                {
                    dat[i]='\0';
                    QString TMP=dat;
                    s=TMP.toFloat();
                    dat+=i+1;
                    break;
                }
            }
        }
        dat=get;
        My_Stock[Tmp.code].Send_Decision_Data(Tmp);
    }

    return false;
}

bool Stock::Save_Data()
{
    Save_Location="D:\\Save.txt";
    ofstream file;
    file.open(Save_Location,ios::out);
    if(!file)
    {
        return true;
    }
    file<<TdxWin::Soft_Location<<endl;

    map<string,Data>::iterator it;
    DED Tmp;
    char name[10];
    for(it=My_Stock.begin();it!=My_Stock.end();it++)
    {
        Tmp=it->second.D;
        if(Tmp.strategy.empty()&&Tmp.hold_quantity==0)
        {
            continue;
        }
        file<<Tmp.code<<' ';
        WinAPI::WChar_To_Char(Tmp.name,name);
        file<<name<<'  ';
        file<<Tmp.securities_quantity<<' ';
        file<<Tmp.hold_quantity<<' ';
        file<<Tmp.available_quantity<<' ';
        file<<Tmp.cost_price<<' ';
        file<<Tmp.highest_price<<' ';
        for(int i=0;i<Tmp.strategy.size();i++)
        {
            file<<Tmp.strategy[i]<<' ';
        }
        file<<"-1 "<<endl;
    }
    file<<"end";
    file.flush();
    file.close();
    return false;
}

void Stock::Main_Operate()
{
    while(WinAPI::Check_Time(15,00,00)<0)
    {
        map<string,Data>::iterator i;
        for(i=My_Stock.begin();i!=My_Stock.end();i++)
        {
            Process_Stock(i);
        }
    }
    return;
}

void Stock::Process_Stock(map<string,Data>::iterator stk)
{
    stk->second.Refresh_Real_Time_Data();
    stk->second.Refresh_Decision_Data();
    OPS ops=Judge(stk->second.R,stk->second.I,stk->second.D);
    if(ops.operate==BUY)
    {
        TdxWin::Buy(stk->second.R.code,ops.price,ops.amount);
    }
    else if(ops.operate==SALE)
    {
        TdxWin::Sale(stk->second.R.code,ops.price,ops.amount);
    }
}

OPS  Stock::Judge(RTD rtd,IND ind,DED ded)
{
    OPS o;
    int len=ded.strategy.size();
    for(int i=0;i<len;i++)
    {
        switch (ded.strategy[i]) {
        case STOP_LOSS:
            o=Strategy::Stop_Loss(rtd,ind,ded);
            break;
        case 2:
            break;
        default:
            break;
        }
        if(o.operate!=NONE)
        {
            return o;
        }
    }
}
