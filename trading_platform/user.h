#ifndef USER_H
#define USER_H

#include<iostream>
using namespace std;
#include"dialog.h"

enum UserState
{
    active,  forbidden
};

class User
{
public:
    string userId;		//4位，U开头，系统分配编号不可更改仅可查看
        string userName;	//10位，英文字母
        string password;	//20位，小写字母加英文
        string phoneNumber;	//20位
        string address;		//40位，英文字母
        double balance;		//保留一位小数
        UserState userState;	//状态，在线或者离线，可增加免打扰模式，如在线但其他人看见离线
        string friendList[50];	//好友列表，上限50人，可进行私聊操作
        int friendnum=0;
        Dialog dialog[50];
        string password_ex;


        //判断用户名是否存在
        static bool ifexitusername(string username);
        //设置免打扰状态
        //void setUserState();
        //通过userId添加好友，返回是否添加成功
        bool getFriend(string userIdFriend);
        //通过userId删除好友，返回是否删除成功
        bool deleteFriend(string userIdFriend);
        //查看好友列表
        void viewFriendList();
        //个人信息管理
        //查看个人信息
        void viewUserInfo();
        //修改个人信息
        //修改用户名，密码，手机号，地址，需通过二级密码认证
        bool setUserId(string newUserId);
        bool setPassword(string newPassword);
        bool setPhoneNumber(string newPhoneNumber);
        bool setAddress(string newAddress);

        //修改二级密码
        bool setPassword_ex(string newPassword_ex);

        //充值系统
        bool plusBalance(double money);

        //发送消息
        void write_dialog();
        //接受消息
        void get_dialog();
};

#endif // USER_H
