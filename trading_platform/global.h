#ifndef GLOBAL_H
#define GLOBAL_H

#include"user.h"
#include"modity.h"
#include"order.h"
#include<QDir>
#include"refresh.h"

extern User userfile[21];
extern Modity modityfile[201];
extern Order orderfile[2001];
extern int user_count;
extern int modity_count;
extern int order_count;

extern QDir qdir;

extern bool getUserById(string id,User& user);

extern User* loginuser;

extern Refresh *refresh;

#endif // GLOBAL_H
