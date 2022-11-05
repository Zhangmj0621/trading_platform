#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QWidget>
#include<QTreeWidgetItem>
#include"user.h"


namespace Ui {
class mainWidget;
}

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit mainWidget(QWidget *parent = nullptr,User* user=NULL);
    ~mainWidget();

    User* user;
public slots:
    void on_itemClicked(QTreeWidgetItem* item, int i);

private:
    Ui::mainWidget *ui;
};

#endif // MAINWIDGET_H
