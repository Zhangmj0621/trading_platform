#ifndef MODITY_H
#define MODITY_H

#include<iostream>
using namespace std;
#include<map>

struct info {
    double price;
    int num;
    string date;
    int second;
};

enum State{
    removed,onAuction,sold
};

class Modity
{
public:
    string commodityId;		//4位，M开头
    string commodityName;	//20位，英文字符
    double price;			//精确到一位小数
    int number;				//数量，正整数
    string description;		//不超过200个，对商品描述
    string sellerId;		//4位，开头位U
    string date;			//日期
    int day;
    State state;		//状态，下架、销售中、已售完

    map<string, info> want;	//对该商品的预购，包括用户id，和预购的数量和出价
};

#endif // MODITY_H
