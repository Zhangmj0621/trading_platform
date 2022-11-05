#include "read.h"
#include"global.h"
#include"fstream"
#include<QDebug>
#include<QString>
#include<QDir>
#include<sstream>
#include<string>
#include<cstdlib>
using namespace std;


Read::Read()
{

}

int Read::readUser()
{
    qDebug()<<qdir.absoluteFilePath("");
    fstream io_file(qdir.absoluteFilePath("user.txt").toStdString(),ios::in|ios::out);
    int count = 0;
    //io_file.seekg(0);
    string s;
    getline(io_file, s);
    while (s != "")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',') s[i] = ' ';
            else if (s[i] == ' ') s[i] = ',';
        }
        istringstream str(s);
        string words[10];
        int i = 0;
        while (str >> words[i])
        {
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < words[j].size(); k++)
            {
                if (words[j][k] == ',')
                {
                    words[j][k] = ' ';
                }
            }
        }
        userfile[count].userId=words[0];
        userfile[count].userName=words[1];
        userfile[count].password=words[2];
        userfile[count].phoneNumber=words[3];
        userfile[count].address=words[4];
        userfile[count].balance=atof(words[5].c_str());
        if(words[6]=="1") userfile[count].userState=forbidden;
        else userfile[count].userState=active;
        userfile[count].password_ex=words[7];
        count++;
        getline(io_file, s);
    }
    io_file.close();
    return count;
}

int Read::readModity()
{
    fstream io_file(qdir.absoluteFilePath("modity.txt").toStdString(),ios::in|ios::out);
    int count = 0;
    //io_file.seekg(0);
    string s;
    getline(io_file, s);
    while (s != "")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',') s[i] = ' ';
            else if (s[i] == ' ') s[i] = ',';
        }
        istringstream str(s);
        string words[100];
        int i = 0;
        while (str >> words[i])
        {
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < words[j].size(); k++)
            {
                if (words[j][k] == ',')
                {
                    words[j][k] = ' ';
                }
            }
        }
        modityfile[count].commodityId=words[0];
        modityfile[count].commodityName=words[1];
        modityfile[count].price=atof(words[2].c_str());
        modityfile[count].number=atoi(words[3].c_str());
        modityfile[count].description=words[4];
        modityfile[count].sellerId=words[5];
        modityfile[count].date=words[6];
        modityfile[count].day=atoi(words[7].c_str());
        if(words[8]=="0") modityfile[count].state=removed;
        else if(words[8]=="1") modityfile[count].state=onAuction;
        else modityfile[count].state=sold;
        int j=9;
        while(j<i)
        {
            string userid;
            info tempinfo;
            userid=words[j];
            tempinfo.num=atoi(words[j+1].c_str());
            tempinfo.date=words[j+2];
            tempinfo.second=atoi(words[j+3].c_str());
            tempinfo.price=atof(words[j+4].c_str());
            modityfile[count].want.insert(pair<string,info>(userid,tempinfo));
            j+=5;
        }
        count++;
        getline(io_file, s);
    }
    io_file.close();
    return count;
}

int Read::readOrder()
{
    fstream io_file(qdir.absoluteFilePath("order.txt").toStdString(),ios::in|ios::out);
    int count = 0;
    //io_file.seekg(0);
    string s;
    getline(io_file, s);
    while (s != "")
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ',') s[i] = ' ';
            else if (s[i] == ' ') s[i] = ',';
        }
        istringstream str(s);
        string words[10];
        int i = 0;
        while (str >> words[i])
        {
            i++;
        }
        for (int j = 0; j < i; j++)
        {
            for (int k = 0; k < words[j].size(); k++)
            {
                if (words[j][k] == ',')
                {
                    words[j][k] = ' ';
                }
            }
        }
        orderfile[count].orderId=words[0];
        orderfile[count].commodityId=words[1];
        orderfile[count].unitprice=atof(words[2].c_str());
        orderfile[count].number=atoi(words[3].c_str());
        orderfile[count].date=words[4];
        orderfile[count].sellerId=words[5];
        orderfile[count].buyerId=words[6];
        count++;
        getline(io_file, s);
    }
    io_file.close();
    return count;
}
