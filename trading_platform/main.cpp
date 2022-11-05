#include "widget.h"
#include"global.h"
#include"read.h"
#include"mytimer.h"
#include<QMetaType>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qdir.setPath(a.applicationDirPath());
    qRegisterMetaType<string>("string");
    qRegisterMetaType<QVector<int>>("QVector<int>");//QStandardItemModel
    user_count=0;
    modity_count=0;
    order_count=0;
    //runtimer();
    MyTimer t(1000);
    t.TimerTickEvent += TimerTick;
    t.TimerDoneEvent += TimerDone;
    std::thread th = std::thread(&MyTimer::Start, &t);
    th.detach();
    Read read;
    user_count=read.readUser();
    modity_count=read.readModity();
    order_count=read.readOrder();

    refresh=new Refresh();
    Widget w;

    w.show();

    return a.exec();
}
