#define DATA_CPP
#include "data.h"

bool Data::Refresh_Real_Time_Data()
{
    char Sub[100]="list=sh";
    strcat(Sub,R.code);
    W.Get_Infomation(Sub);
    return false;
}

bool Data::Refresh_Index_Data()
{

}

Data::Data()
{
    memset(&R,0,sizeof(RTD));
    memset(&I,0,sizeof(IND));
    W.Send_Host("hq.sinajs.cn");
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
    else
    {
        R.run=0;
        return R;
    }
}

IND Data::Get_Index_Data()
{
    if(Refresh_Index_Data())
    {
        I.run=1;
        return I;
    }
    else
    {
        I.run=0;
        return I;
    }
}
