#ifndef LOG_H
#define LOG_H
#include"user.h"
#include<iostream>
using namespace std;

class Log
{
public:
    Log();
    int userLog(string name,string password,User& user);

    bool userRegister(string name,string password,string addr,string phone);
};

#endif // LOG_H
