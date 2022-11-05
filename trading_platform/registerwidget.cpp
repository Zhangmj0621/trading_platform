#include "registerwidget.h"
#include "ui_registerwidget.h"
#include<QPushButton>
#include<QMessageBox>


using namespace std;

RegisterWidget::RegisterWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWidget)
{
    ui->setupUi(this);

    connect(ui->btn_register,&QPushButton::clicked,[=](){
        string username = ui->line_register_username->text().toStdString();
        string password1=ui->line_register_password1->text().toStdString();
        string password2=ui->line_register_password2->text().toStdString();
        string addr=ui->line_register_address->text().toStdString();
        string phone=ui->line_register_phone->text().toStdString();
        if(password1==password2)
        {
            bool judge=log.userRegister(username,password1,addr,phone);
            if(judge==true)
            {
                QMessageBox::information(this,"成功","您已经成功注册！");
                this->close();
            }
            else
            {
                QMessageBox::critical(this,"错误","该用户名已被注册！");
            }
        }
        else
        {
            QMessageBox::critical(this,"错误","两次密码输入不一致！");
        }
    });

    connect(ui->btn_register_cancell,&QPushButton::clicked,[=](){
        this->close();
    });

}

RegisterWidget::~RegisterWidget()
{
    delete ui;
}
