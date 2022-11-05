#include "buyer.h"
#include"global.h"
#include"modity.h"
#include"mytime.h"
#include<iostream>
#include"string.h"
using namespace std;

Buyer::Buyer()
{

}

int Buyer::viewModityList(Modity modity[100])
{
    int count=0;
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].state==onAuction)
        {
            modity[count]=modityfile[i];
            count++;
        }
    }
    return count;
}

bool Buyer::buyModity(string modityid,string userid,int num,double price)
{
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].commodityId==modityid)
        {
            if(modityfile[i].want.count(userid)) return false;
            info tempinfo;
            tempinfo.num=num;
            tempinfo.price=price;
            MyTime::getMyTime(tempinfo.date,tempinfo.second);
            modityfile[i].want.insert(pair<string,info>(userid,tempinfo));
            return true;
        }
    }
    return false;
}

int Buyer::viewModityByName(Modity modity[100],string modityname)
{
    int count=0;
    for(int i=0;i<modity_count;i++)
    {
        if(strstr(modityfile[i].commodityName.c_str(),modityname.c_str()) && modityfile[i].state==onAuction)
        {
            modity[count]=modityfile[i];
            count++;
        }
    }
    return count;
}

int Buyer::viewOrderList(Order order[100],string userid)
{
    int count=0;
    for(int i=0;i<order_count;i++)
    {
        if(orderfile[i].buyerId==userid)
        {
            order[count]=orderfile[i];
            count++;
        }
    }
    return count;
}

bool Buyer::viewModityById(Modity& modity,string modityid)
{
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].commodityId==modityid)
        {
            modity=modityfile[i];
            return true;
        }
    }
    return false;
}



int Buyer::viewyourwant(Want* wantlist,string userid)
{
    int count=0;
    for(int i=0;i<modity_count;i++)
    {
        map<string,info>::iterator it;
        it=modityfile[i].want.find(userid);
        if(it!=modityfile[i].want.end())
        {
            wantlist[count].yourinfo=it->second;
            wantlist[count].modityid=modityfile[i].commodityId;
            wantlist[count].sellerid=modityfile[i].sellerId;
            count++;
        }
        else continue;
    }
    return count;
}
