#include <iostream>
#include<QDebug>
#include "mytimer.h"
#include"mytime.h"
#include"global.h"
#include"refresh.h"

using namespace std;



void runtimer()
{
    MyTimer t(1000);
    t.TimerTickEvent += TimerTick;
    t.TimerDoneEvent += TimerDone;
    std::thread th = std::thread(&MyTimer::Start, &t);
    th.detach();
}



//拍卖结束判断
void TimerTick()
{
    //qDebug()<<"开始定时器";
    string tempdate;
    int tempday;
    MyTime::getMyTime(tempdate,tempday);
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].state==onAuction&&modityfile[i].number>0)
        {
            if(tempday-modityfile[i].day>=60)
            {
                //该商品已经要结束了
                //先按照商品出价进行排序
                int k=0;
                for(;k<user_count;k++)
                {
                    if(modityfile[i].sellerId==userfile[k].userId) break;
                }
                int count=modityfile[i].want.size();
                if(count==0)
                {
                     modityfile[i].state=removed;
                     continue;
                }
                map<string,bool> isused;
                map<string,info>::iterator it=modityfile[i].want.begin();
                for(;it!=modityfile[i].want.end();it++)
                {
                    isused[it->first]=false;
                }
                int num_remained=modityfile[i].number;
                double temp_max=0;
                map<string,info>::iterator temp_max_it=modityfile[i].want.begin();
                map<string,info>::iterator it2=modityfile[i].want.begin();
                while(num_remained>0)
                {
                    temp_max=0;
                    temp_max_it=modityfile[i].want.begin();
                    if(temp_max_it==modityfile[i].want.end()) break;
                    for(it2=modityfile[i].want.begin();it2!=modityfile[i].want.end();it2++)
                    {
                        if(!isused[it2->first])
                        {
                            if(it2->second.price>temp_max)
                            {
                                temp_max=it2->second.price;
                                temp_max_it=it2;
                            }
                            else if(it2->second.price==temp_max)
                            {
                                if(it2->second.second<temp_max_it->second.second)
                                {
                                    temp_max_it=it2;
                                }
                            }
                        }
                    }
                    isused[temp_max_it->first]=true;
                    for(int j=0;j<user_count;j++)
                    {
                        if(userfile[j].userId==temp_max_it->first)
                        {
                            int num_pro;
                            if(num_remained>=temp_max_it->second.num) num_pro=temp_max_it->second.price*temp_max_it->second.num;
                            else num_pro=temp_max_it->second.price*num_remained;
                            if(userfile[j].balance>=num_pro)
                            {
                                //金钱交易
                                userfile[j].balance-=num_pro;
                                userfile[k].balance+=num_pro;
                                //建立订单
                                orderfile[order_count].commodityId=modityfile[i].commodityId;
                                orderfile[order_count].unitprice=temp_max_it->second.price;
                                if(num_remained>=temp_max_it->second.num) orderfile[order_count].number=temp_max_it->second.num;
                                else orderfile[order_count].number=num_remained;
                                orderfile[order_count].sellerId=modityfile[i].sellerId;
                                orderfile[order_count].buyerId=temp_max_it->first;
                                int ordernum=order_count+1;
                                string orderid(4, '\0');
                                orderid[0]='T';
                                orderid[1]=(ordernum/100+'0');
                                orderid[2]=(ordernum/10)%10+'0';
                                orderid[3]=ordernum%10+'0';
                                orderfile[order_count].orderId=orderid;
                                string tempdate;
                                int tempnum;
                                MyTime::getMyTime(tempdate,tempnum);
                                orderfile[order_count].date=tempdate;
                                order_count++;
                                //删去报价和剩余数量
                                if(num_remained>=temp_max_it->second.num) num_remained-=temp_max_it->second.num;
                                else num_remained=0;
                                modityfile[i].want.erase(temp_max_it);
                            }
                            else
                            {
                                modityfile[i].want.erase(temp_max_it);
                            }
                            break;
                        }
                    }
                }
                if(num_remained==0)
                {
                    modityfile[i].want.clear();
                    modityfile[i].number=0;
                    modityfile[i].state=sold;
                }
                else
                {
                    modityfile[i].number=num_remained;
                    string tempdate1;
                    int tempnum1;
                    MyTime::getMyTime(tempdate1,tempnum1);
                    modityfile[i].date=tempdate1;
                    modityfile[i].day=tempnum1;
                }
                //emit refresh->refreshsignal(modityfile[i].commodityId);
                //emit refresh->refreshsignal2(modityfile[i].commodityId);
                //emit refresh->refreshsignal3(modityfile[i].commodityId);
                //emit refresh->refreshsignal4(modityfile[i].commodityId);
            }
        }
    }
}

void TimerDone()
{
    qDebug()<<"定时器结束";
}
