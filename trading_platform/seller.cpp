#include "seller.h"
#include"global.h"
#include"mytime.h"

Seller::Seller()
{

}

void Seller::releaseModity(string modityname,double price,int number,string moditydescription,User* user)
{
    int moditynum=modity_count+1;
    Modity modity;
    string modityid(4, '\0');
    modityid[0]='M';
    modityid[1]=(moditynum/100+'0');
    modityid[2]=(moditynum/10)%10+'0';
    modityid[3]=moditynum%10+'0';
    modity.commodityId=modityid;
    modity.commodityName=modityname;
    modity.price=price;
    modity.number=number;
    modity.description=moditydescription;
    modity.state=onAuction;
    modity.sellerId=user->userId;
    MyTime::getMyTime(modity.date,modity.day);
    modityfile[modity_count]=modity;
    modity_count++;
}

void Seller::checkModity()
{
}

void Seller::reviseModity(string modityid,string modityname,double price,int number,string moditydescription)
{
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].commodityId==modityid)
        {
            modityfile[i].commodityName=modityname;
            modityfile[i].price=price;
            modityfile[i].number=number;
            modityfile[i].description=moditydescription;
            break;
        }
    }
}

void Seller::deleteModity(string tempid)
{
    for(int i=0;i<modity_count;i++)
    {
        if(tempid==modityfile[i].commodityId)
        {
            modityfile[i].state=removed;
            //删除所有的报价
            modityfile[i].want.clear();
            break;
        }
    }
}


int Seller::recoverModity(string tempid)
{
    for(int i=0;i<modity_count;i++)
    {
        if(tempid==modityfile[i].commodityId)
        {
            modityfile[i].state=onAuction;
            string tpdate;
            MyTime::getMyTime(tpdate,modityfile[i].day);
            modityfile[i].date=tpdate;

            modityfile[i].want.clear();
            return i;
        }
    }
    return 0;
}

int Seller::checkOrder(Order order[100],string tempid)
{
    int count=0;
    for(int i=0;i<order_count;i++)
    {
        if(orderfile[i].sellerId==tempid)
        {
            order[count]=orderfile[i];
            count++;
        }
    }
    return count;
}
