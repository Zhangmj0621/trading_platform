#include"global.h"
#include"read.h"

User userfile[21];
Modity modityfile[201];
Order orderfile[2001];

int user_count;
int modity_count;
int order_count;

QDir qdir;

User* loginuser;


bool getUserById(string id,User& user)
{

    for(int i=0;i<user_count;i++)
    {
        if(id==userfile[i].userId)
        {
            user=userfile[i];
            return true;
        }
    }
    return false;
}
