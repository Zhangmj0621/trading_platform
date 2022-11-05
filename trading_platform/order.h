#ifndef ORDER_H
#define ORDER_H

#include<iostream>
using namespace std;

class Order
{
public:
    string orderId;		//4个字符，T开头
    string commodityId;	//4个字符，M开头
    double unitprice;	//小数后一位
    int number;			//数量
    string date;		//日期
    string sellerId;	//4位，U开头
    string buyerId;		//4位，U开头
};

#endif // ORDER_H
