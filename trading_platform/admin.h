#ifndef ADMIN_H
#define ADMIN_H

#include<ctime>
#include"modity.h"
#include<iostream>
#include<QString>
using namespace std;

class admin
{
public:
    admin();
    //查看所有商品
    void checkModity();
    //通过模糊搜索
    int viewModityList(QString modityname,Modity modity[]);
    //下架商品
    void deleteModity(string modityid);
    //查看所有订单
    void checkOrder();
    //查看所有用户
    void checkUser();
    //封禁用户
    void deleteUser(string userid);

    int viewModityByName(Modity modity[100],string modityname);
};

#endif // ADMIN_H
