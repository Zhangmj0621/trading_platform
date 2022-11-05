#ifndef DIALOG_H
#define DIALOG_H
#include<iostream>
using namespace std;

struct Sentence
{
    string message;
    string date;
};


class Dialog
{
public:
    Dialog();
    Sentence sentence[100];	//最多保存100条消息
    int sread = 0;			//存消息指针
    int pread = 0;			//读消息指针
    int unread = 0;			//未读消息数量
};

#endif // DIALOG_H
