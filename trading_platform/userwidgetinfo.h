#ifndef USERWIDGETINFO_H
#define USERWIDGETINFO_H

#include <QWidget>
#include"user.h"

namespace Ui {
class UserWidgetInfo;
}

class UserWidgetInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserWidgetInfo(QWidget *parent = nullptr);
    ~UserWidgetInfo();

    void setlabel();

    User* user;

private:
    Ui::UserWidgetInfo *ui;
};

#endif // USERWIDGETINFO_H
