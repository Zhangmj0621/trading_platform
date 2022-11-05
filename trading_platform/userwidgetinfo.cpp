#include "userwidgetinfo.h"
#include "ui_userwidgetinfo.h"
#include<QMessageBox>
#include<QString>
#include"global.h"
#include<QDebug>
#include"buyer.h"
#include<QMetaType>

int temp_order_count2=order_count;

UserWidgetInfo::UserWidgetInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserWidgetInfo)
{
    ui->setupUi(this);

    qRegisterMetaType<string>("string");
    qRegisterMetaType<QVector<int>>("QVector<int>");//QStandardItemModel

    temp_order_count2=order_count;
    //qDebug()<<"你的userwidgetinfo中的user为"<<QString::fromStdString(this->user->password);
    //充值
    connect(ui->btn_money,&QPushButton::clicked,[=](){
        double money1=ui->moneyline1->text().toDouble();
        double money2=ui->moneyline2->text().toDouble();
        if(money1!=money2)
        {
            QMessageBox::critical(this,"错误","两次金额输入不一致！");
        }
        else
        {
            QString temp=QString::number(money1,'f',1);
            QString temp2=QString::number(money1,'f',0);
            if(temp!=ui->moneyline1->text() && temp2!=ui->moneyline1->text())
            {
                QMessageBox::critical(this,"错误","仅支持输入至多有一位小数的数字！");
            }
            else
            {
                QMessageBox::information(this,"成功","充值成功！");
                for(int i=0;i<user_count;i++)
                {
                    if(userfile[i].userId==this->user->userId)
                    {
                        this->user->balance+=money1;
                        userfile[i].balance=this->user->balance;
                        break;
                    }
                }
                ui->labelbalance->setText(QString::number(user->balance,'f',1));
            }
        }
    });


    //修改信息
    connect(ui->btn_revise,&QPushButton::clicked,[=](){
        if(ui->password2line->text().toStdString()!=user->password_ex)
        {
            QMessageBox::critical(this,"错误","二级密码输入错误！");
        }
        else
        {
            //修改用户名
            if(ui->rbtn_user->isChecked())
            {
                bool iftrue=User::ifexitusername(ui->userline->text().toStdString());
                if(iftrue)
                {
                    QMessageBox::critical(this,"错误","该用户名已存在！");
                }
                else
                {
                    QMessageBox::information(this,"成功","修改用户名成功！");
                    for(int i=0;i<user_count;i++)
                    {
                        if(userfile[i].userId==this->user->userId)
                        {
                            userfile[i].userName=ui->userline->text().toStdString();
                            break;
                        }
                    }
                    user->userName=ui->userline->text().toStdString();
                    ui->labelname->setText(QString::fromStdString(user->userName));
                }
            }
            //修改联系方式
            if(ui->rbtn_phone->isChecked())
            {
                QMessageBox::information(this,"成功","修改联系方式成功！");
                for(int i=0;i<user_count;i++)
                {
                    if(userfile[i].userId==this->user->userId)
                    {
                        userfile[i].phoneNumber=ui->phoneline->text().toStdString();
                        break;
                    }
                }
                user->phoneNumber=ui->phoneline->text().toStdString();
                ui->labelphone->setText(QString::fromStdString(user->phoneNumber));
            }
            //修改地址
            if(ui->rbtn_address->isChecked())
            {
                QMessageBox::information(this,"成功","修改地址成功！");
                for(int i=0;i<user_count;i++)
                {
                    if(userfile[i].userId==this->user->userId)
                    {
                        userfile[i].address=ui->addressline->text().toStdString();
                        break;
                    }
                }
                user->address=ui->addressline->text().toStdString();
                ui->labeladdress->setText(QString::fromStdString(user->address));
            }
            //修改密码
            if(ui->rbtn_password->isChecked())
            {
                QMessageBox::information(this,"成功","修改密码成功！");
                for(int i=0;i<user_count;i++)
                {
                    if(userfile[i].userId==this->user->userId)
                    {
                        userfile[i].password=ui->passwordline->text().toStdString();
                        break;
                    }
                }
                user->password=ui->passwordline->text().toStdString();
            }
        }


    });

    //修改二级密码
    connect(ui->btn_revise_password2,&QPushButton::clicked,[=]()mutable{
        string password2below=ui->password2belowline->text().toStdString();
        if(password2below!=user->password_ex)
        {
            QMessageBox::critical(this,"错误","原二级密码输入错误！");
        }
        else
        {
            string password21=ui->password2newline->text().toStdString();
            string password22=ui->password2newecholine->text().toStdString();
            if(password21!=password22)
            {
                QMessageBox::critical(this,"错误","两次二级密码输入不一致！");
            }
            else
            {
                QMessageBox::information(this,"成功","二级密码修改成功！");
                for(int i=0;i<user_count;i++)
                {
                    if(userfile[i].userId==this->user->userId)
                    {
                        userfile[i].password_ex=ui->password2newline->text().toStdString();
                        break;
                    }
                }
                user->password_ex=ui->password2newline->text().toStdString();
            }
        }
    });

    //更新余额
    connect(ui->btn_refresh,&QPushButton::clicked,[=](){
        bool judge=false;
        if(temp_order_count2<order_count)
        {
            for(int i=temp_order_count2;i<order_count;i++)
            {
                if(loginuser->userId==orderfile[i].buyerId || loginuser->userId==orderfile[i].sellerId)
                {
                    judge=true;
                    break;
                }
            }
        }
        if(true)
        {
            for(int j=0;j<user_count;j++)
            {
                if(userfile[j].userId==loginuser->userId)
                {
                    ui->labelbalance->setText(QString::number(userfile[j].balance,'f',1));
                    break;
                }
            }

        }
        temp_order_count2=order_count;

    });
}

void UserWidgetInfo::setlabel()
{
    ui->labelid->setText(QString::fromStdString(user->userId));
    ui->labelname->setText(QString::fromStdString(user->userName));
    ui->labelphone->setText(QString::fromStdString(user->phoneNumber));
    ui->labeladdress->setText(QString::fromStdString(user->address));
    ui->labelbalance->setText(QString::number(user->balance,'f',1));
}

UserWidgetInfo::~UserWidgetInfo()
{
    delete ui;
}
