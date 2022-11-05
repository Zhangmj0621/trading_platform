#include "user.h"
#include"global.h"

bool User::ifexitusername(string username)
{
    for(int i=0;i<user_count;i++)
    {
        if(userfile[i].userName==username)
        {
            return true;
        }
    }
    return false;
}

bool User::getFriend(string user)
{
    return false;
}

bool User::deleteFriend(string userIdFriend)
{
    return false;
}

void User::viewFriendList()
{
}

void User::viewUserInfo()
{
}

bool User::setUserId(string newUserId)
{
    return false;
}

bool User::setPassword(string newPassword)
{
    return false;
}

bool User::setPhoneNumber(string newPhoneNumber)
{
    return false;
}

bool User::setAddress(string newAddress)
{
    return false;
}

bool User::setPassword_ex(string newPassword_ex)
{
    return false;
}

bool User::plusBalance(double money)
{
    return false;
}

void User::write_dialog()
{
}

void User::get_dialog()
{
}
