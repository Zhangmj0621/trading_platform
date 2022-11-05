#include "write.h"
#include<fstream>
#include"global.h"
using namespace std;

Write::Write()
{

}

void Write::writeUser()
{
    fstream io_file(qdir.absoluteFilePath("user.txt").toStdString(),ios::in|ios::out);
    //io_file.seekg(0);
    for(int i=0;i<user_count;i++)
    {
        io_file<<userfile[i].userId<<","<<userfile[i].userName<<","<<userfile[i].password<<","<<userfile[i].phoneNumber
              <<","<<userfile[i].address<<","<<userfile[i].balance<<","<<userfile[i].userState<<","<<userfile[i].password_ex;
        io_file<<endl;
    }

    io_file.close();
    return;
}

void Write::writeModity()
{
    fstream io_file(qdir.absoluteFilePath("modity.txt").toStdString(),ios::in|ios::out);
    //io_file.seekg(0);
    for(int i=0;i<modity_count;i++)
    {
        io_file<<modityfile[i].commodityId<<","<<modityfile[i].commodityName<<","<<modityfile[i].price<<","<<modityfile[i].number
              <<","<<modityfile[i].description<<","<<modityfile[i].sellerId<<","<<modityfile[i].date<<","
             <<modityfile[i].day<<","<<modityfile[i].state;
        //io_file<<",";
        //输出报价列表
        map<string,info>::iterator it;
        for(it=modityfile[i].want.begin();it!=modityfile[i].want.end();it++)
        {
            io_file<<","<<it->first<<","<<it->second.num<<","<<it->second.date<<","<<it->second.second<<","<<it->second.price;
        }
        io_file<<endl;
    }

    io_file.close();
    return;
}

void Write::writeOrder()
{
    fstream io_file(qdir.absoluteFilePath("order.txt").toStdString(),ios::in|ios::out);
    //io_file.seekg(0);
    for(int i=0;i<order_count;i++)
    {
        io_file<<orderfile[i].orderId<<","<<orderfile[i].commodityId<<","<<orderfile[i].unitprice<<","<<orderfile[i].number
              <<","<<orderfile[i].date<<","<<orderfile[i].sellerId<<","<<orderfile[i].buyerId;
        io_file<<endl;
    }

    io_file.close();
    return;
}
