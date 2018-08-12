#define DATA_CPP
#include "data.h"

Data::Data()
{
    memset(&R,0,sizeof(RTD));
    memset(&I,0,sizeof(IND));
    W.Send_Host("hq.sinajs.cn");
}

bool Data::Process_String(char* dat)
{
    if(!strcmp(dat,"Error"))
    {
        return true;
    }
    while(!(*dat++=='"'));

    //---------name---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            R.name=dat;
            I.name=dat;
            dat+=i+1;
            break;
        }
    }

    //---------open---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.open=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------close_yes---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.close_yes=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------current---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.current=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------highest---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.highest=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------lowest---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.lowest=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------bid---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.bid=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------auction---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.auction=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------volume---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.volume=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------turnover---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.turnover=Temp.toDouble();
            dat+=i+1;
            break;
        }
    }

    //---------buy_1_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_1_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------buy_1_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_1_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------buy_2_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_2_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------buy_2_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_2_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------buy_3_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_3_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------buy_3_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_3_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------buy_4_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_4_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------buy_4_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_4_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------buy_5_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_5_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------buy_5_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.buy_5_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------sale_1_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_1_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------sale_1_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_1_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------sale_2_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_2_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------sale_2_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_2_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------sale_3_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_3_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------sale_3_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_3_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------sale_4_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_4_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------sale_4_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_4_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------sale_5_amount---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_5_amount=Temp.toInt();
            dat+=i+1;
            break;
        }
    }

    //---------sale_5_price---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            QString Temp=dat;
            R.sale_5_price=Temp.toFloat();
            dat+=i+1;
            break;
        }
    }

    //---------date---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            R.date=dat;
            dat+=i+1;
            break;
        }
    }

    //---------time---------
    for(int i=0;;i++)
    {
        if(dat[i]==',')
        {
            dat[i]='\0';
            R.time=dat;
            dat+=i+1;
            break;
        }
    }

    return false;
}

bool Data::Refresh_Real_Time_Data()
{
    char Sub[1024]="";
    if(R.code[0]=='0'||R.code[0]=='3')
    {
        strcpy(Sub,"list=sz");
    }
    else if(R.code[0]=='6')
    {
        strcpy(Sub,"list=sh");
    }
    strcat(Sub,R.code); 
    if(Process_String(W.Get_Infomation(Sub)))
    {
        return true;
    }
    return false;
}

bool Data::Refresh_Index_Data()
{

}

void Data::Send_Code(char* code)
{
    R.code=code;
    I.code=code;
}

RTD Data::Get_Real_Time_Data()
{
    if(Refresh_Real_Time_Data())
    {
        R.run=1;
        return R;
    }
    //Output_RTD();
    R.run=0;
    return R;
}

IND Data::Get_Index_Data()
{
    if(Refresh_Index_Data())
    {
        I.run=1;
        return I;
    }
    //Output_IND();
    I.run=0;
    return I;
}

void Data::Output_RTD()
{
    cout<<R.code<<endl;
    cout<<R.name<<endl;
    cout<<R.open<<endl;
    cout<<R.close_yes<<endl;
    cout<<R.current<<endl;
    cout<<R.highest<<endl;
    cout<<R.lowest<<endl;
    cout<<R.bid<<endl;
    cout<<R.auction<<endl;
    cout<<R.volume<<endl;
    cout<<R.turnover<<endl;
    cout<<R.buy_1_amount<<endl;
    cout<<R.buy_1_price<<endl;
    cout<<R.buy_2_amount<<endl;
    cout<<R.buy_2_price<<endl;
    cout<<R.buy_3_amount<<endl;
    cout<<R.buy_3_price<<endl;
    cout<<R.buy_4_amount<<endl;
    cout<<R.buy_4_price<<endl;
    cout<<R.buy_5_amount<<endl;
    cout<<R.buy_5_price<<endl;
    cout<<R.sale_1_amount<<endl;
    cout<<R.sale_1_price<<endl;
    cout<<R.sale_2_amount<<endl;
    cout<<R.sale_2_price<<endl;
    cout<<R.sale_3_amount<<endl;
    cout<<R.sale_3_price<<endl;
    cout<<R.sale_4_amount<<endl;
    cout<<R.sale_4_price<<endl;
    cout<<R.sale_5_amount<<endl;
    cout<<R.sale_5_price<<endl;
    cout<<R.date<<endl;
    cout<<R.time<<endl;
    return;
}

void Data::Output_IND()
{

}
