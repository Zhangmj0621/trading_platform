#ifndef SELLER_H
#define SELLER_H
#include"user.h"
#include"order.h"
#include<map>

class Seller:User
{
public:
    Seller();

    //发布商品
    void releaseModity(string modityname,double price,int number,string moditydescription,User* user);
    //查看发布商品
    void checkModity();
    //修改商品信息
    void reviseModity(string modityid,string modityname,double price,int number,string moditydescription);
    //下架商品
    void deleteModity(string tempid);
    //查看历史订单
    int checkOrder(Order order[100],string tempid);
    //上架商品
    int recoverModity(string tempid);
};

#endif // SELLER_H
