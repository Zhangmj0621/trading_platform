#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>
#include<QLineEdit>
#include<QString>
#include<QMessageBox>
#include"mainwidget.h"
#include"registerwidget.h"
#include"adminwidget.h"
#include"global.h"
using namespace std;


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //read.readUser();
    //read.readModity();
    //read.readOrder();

    connect(ui->logAdmin,&QPushButton::clicked,[=](){
        string username = ui->lineusername->text().toStdString();
        string password = ui->linepassword->text().toStdString();
        if(username=="admin"&&password=="123")
        {
            QMessageBox::information(this,"成功","您已经成功登录！");
            AdminWidget* adminwidget=new AdminWidget();
            adminwidget->show();
            this->hide();
        }
        else
        {
            QMessageBox::critical(this,"错误","用户名或者密码错误！");
        }
    });

    connect(ui->logUser,&QPushButton::clicked,[=](){
        string username = ui->lineusername->text().toStdString();
        string password = ui->linepassword->text().toStdString();
        User user;
        /*QMessageBox::information(this,"成功","您已经成功登录！");
        mainWidget* mwidget_user=new mainWidget();
        mwidget_user->show();
        this->hide();*/
        int iflogin=log.userLog(username,password,user);
        if(iflogin==2)
        {
            QMessageBox::critical(this,"错误","你的账号已被封禁！");
        }
        else if(iflogin==0)
        {
             QMessageBox::critical(this,"错误","用户名或者密码错误！");
        }
        else
        {
            User* temp=new User();
            temp->userId=user.userId;
            temp->userName=user.userName;
            temp->userState=user.userState;
            temp->balance=user.balance;
            temp->password=user.password;
            temp->password_ex=user.password_ex;
            temp->phoneNumber=user.phoneNumber;
            temp->address=user.address;
            loginuser=temp;
            QMessageBox::information(this,"成功","您已经成功登录！");
            mainWidget* mwidget_user=new mainWidget(nullptr,temp);
            //mwidget_user->user=user;
            mwidget_user->show();
            this->close();
        }
    });

    connect(ui->registerUser,&QPushButton::clicked,[=](){
        RegisterWidget* registerwidget=new RegisterWidget();
        registerwidget->show();

    });

}

Widget::~Widget()
{
    write.writeUser();
    write.writeModity();
    write.writeOrder();
    delete ui;
}

