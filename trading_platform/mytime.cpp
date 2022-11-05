#include "mytime.h"
#include<ctime>

MyTime::MyTime()
{

}

void MyTime::getMyTime(string& a,int& day2)
{
    time_t nowtime;
    struct tm*p;
    time(&nowtime);
    day2=nowtime;
    p=localtime(&nowtime);
    int year=p->tm_year+1900;
    int month=p->tm_mon+1;
    int day=p->tm_mday;
    int hour=p->tm_hour;
    int min=p->tm_min;
    int sec=p->tm_sec;
    a.push_back((year/1000)+'0');
    a.push_back((year%1000)/100+'0');
    a.push_back((year%100)/10+'0');
    a.push_back((year%10)+'0');
    a.push_back('-');
    a.push_back((month/10)+'0');
    a.push_back((month%10)+'0');
    a.push_back('-');
    a.push_back((day/10)+'0');
    a.push_back((day%10)+'0');
    a.push_back(' ');
    a.push_back((hour/10)+'0');
    a.push_back((hour%10)+'0');
    a.push_back(':');
    a.push_back((min/10)+'0');
    a.push_back((min%10)+'0');
    a.push_back(':');
    a.push_back((sec/10)+'0');
    a.push_back((sec%10)+'0');
    return;
}
