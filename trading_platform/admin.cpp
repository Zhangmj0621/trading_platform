#include "admin.h"
#include"global.h"
#include"modity.h"
#include"user.h"
#include<string.h>
#include<string>
#include<QString>

admin::admin()
{

}

void admin::checkModity()
{
    //不用写
}

int admin::viewModityList(QString modityname,Modity modity[])
{
    int count=0;
    for(int i=0;i<modity_count;i++)
    {
        QString str = QString::fromStdString(modityfile[i].commodityName);
        if(str.contains(modityname))
        {
            modity[count]=modityfile[i];
            count++;
        }
    }
    return count;
}

int admin::viewModityByName(Modity modity[100],string modityname)
{
    int count=0;
    for(int i=0;i<modity_count;i++)
    {
        if(strstr(modityfile[i].commodityName.c_str(),modityname.c_str()))
        {
            modity[count]=modityfile[i];
            count++;
        }
    }
    return count;
}

void admin::deleteModity(string modityid)
{
    for(int i=0;i<modity_count;i++)
    {
        if(modityfile[i].commodityId==modityid)
        {
            modityfile[i].state=removed;
            modityfile[i].want.clear();
            break;
        }
    }
}

void admin::checkOrder()
{
    //不用写
}

void admin::checkUser()
{
    //不用写
}

void admin::deleteUser(string userid)
{
    for(int i=0;i<user_count;i++)
    {
        if(userfile[i].userId==userid)
        {
            userfile[i].userState=forbidden;
            break;
        }
    }
}
