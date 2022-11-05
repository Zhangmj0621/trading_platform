#ifndef REFRESH_H
#define REFRESH_H

#include<QObject>
using namespace std;

class Refresh:public QObject
{
    Q_OBJECT
public:
    Refresh();
signals:
    void refreshsignal(string id);

    void refreshsignal2(string id);

    void refreshsignal3(string id);

    void refreshsignal4(string id);

};

#endif // REFRESH_H
