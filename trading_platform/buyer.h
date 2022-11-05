#ifndef BUYER_H
#define BUYER_H

#include"user.h"
#include"modity.h"
#include"order.h"

struct Want{
    info yourinfo;
    string modityid;
    string sellerid;
};

class Buyer:User
{
public:
    Buyer();

    //查看商品列表
    int viewModityList(Modity modity[100]);
    //通过商品id购买商品
    bool buyModity(string modityid,string userid,int num,double price);
    //通过商品名称查找商品，支持模糊查找，即字符串包含即可查到
    int viewModityByName(Modity modity[100],string modityname);
    //查看历史订单
    int viewOrderList(Order order[100],string userid);
    //通过id查看商品详细信息
    bool viewModityById(Modity& modity,string modityid);
    //查看自己的出价，返回一个结构体数组
    int viewyourwant(Want* wantlist,string userid);
};

#endif // BUYER_H
