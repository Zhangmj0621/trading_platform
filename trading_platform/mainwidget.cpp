#include "mainwidget.h"
#include "ui_mainwidget.h"
#include<QTreeWidgetItem>
#include<QStringList>
#include<QString>
#include<QDebug>
#include"widget.h"

void mainWidget::on_itemClicked(QTreeWidgetItem* item, int i)
{
    if(item->text(i).toStdString()=="我是买家")
        {
            ui->stackedWidget->setCurrentIndex(1);
        }
        else if(item->text(i).toStdString()=="我是卖家")
        {
            ui->stackedWidget->setCurrentIndex(2);
        }
        else if(item->text(i).toStdString()=="个人信息管理")
        {
            ui->stackedWidget->setCurrentIndex(0);
        }
        else if(item->text(i).toStdString()=="我的VIP")
        {
            ui->stackedWidget->setCurrentIndex(3);
        }
        else
        {
            this->close();
            Widget* newwidget=new Widget();
            newwidget->show();

        }
}

mainWidget::mainWidget(QWidget *parent,User* user) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    this->user=user;
    ui->widget1->user=this->user;
    ui->widget3->user=this->user;
    ui->widget1->setlabel();

    ui->treeWidget->setHeaderLabels(QStringList()<<"操作");

    QTreeWidgetItem* infoitem = new QTreeWidgetItem(QStringList()<<"个人信息管理");
    QTreeWidgetItem* selleritem = new QTreeWidgetItem(QStringList()<<"我是买家");
    QTreeWidgetItem* buyeritem = new QTreeWidgetItem(QStringList()<<"我是卖家");
    QTreeWidgetItem* vipitem = new QTreeWidgetItem(QStringList()<<"我的VIP");
    QTreeWidgetItem* logoutitem = new QTreeWidgetItem(QStringList()<<"退出登录");

    ui->treeWidget->addTopLevelItem(infoitem);
    ui->treeWidget->addTopLevelItem(selleritem);
    ui->treeWidget->addTopLevelItem(buyeritem);
    ui->treeWidget->addTopLevelItem(vipitem);
    ui->treeWidget->addTopLevelItem(logoutitem);


    //设置初始页面
    ui->stackedWidget->setCurrentIndex(0);

    //通过左边点击不同选择来切换stackedwidget
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(on_itemClicked(QTreeWidgetItem*, int)));



}

mainWidget::~mainWidget()
{
    delete ui;
}
