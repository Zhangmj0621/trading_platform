#include "log.h"
#include<iostream>
using namespace std;
#include"global.h"
#include"user.h"
#include<string>
#include<string.h>
#include<QDebug>
#include<QString>


Log::Log()
{

}

int Log::userLog(string name,string password,User& user)
{
    for (int i = 0; i < user_count; i++)
    {
        qDebug()<<QString::fromStdString(userfile[i].userName);
        if (name== userfile[i].userName && password==userfile[i].password)
        {
            if(userfile[i].userState==active){
                user = userfile[i];
                return 1;
            }
            else
            {
                return 2;
            }
        }
        else continue;
    }
    return 0;
}

bool Log::userRegister(string name,string password,string addr,string phone)
{
    for(int i=0;i<user_count;i++)
    {
        if(name==userfile[i].userName)
        {
            return false;
        }
        else continue;
    }
    //用户名不重复，可以创建用户对象
    int usernum=user_count+1;
    User user;
    string userid(4, '\0');
    userid[0]='U';
    userid[1]=(usernum/100+'0');
    userid[2]=(usernum/10)%10+'0';
    userid[3]=usernum%10+'0';
    user.userId=userid;
    user.userName=name;
    user.password=password;
    user.address=addr;
    user.phoneNumber=phone;
    user.balance=0.0;
    user.password_ex="123";
    user.userState=active;
    userfile[user_count]=user;
    user_count++;
    return true;;
}
