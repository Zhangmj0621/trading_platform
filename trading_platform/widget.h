#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"log.h"
#include"read.h"
#include"write.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Log log;//用户登录注册指令操控
    Read read;
    Write write;
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
