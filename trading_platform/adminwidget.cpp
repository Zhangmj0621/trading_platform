#include "adminwidget.h"
#include "ui_adminwidget.h"
#include"global.h"
#include<QString>
#include"widget.h"
#include<QTableWidgetItem>
#include<QTableWidget>
#include<QMessageBox>
#include<QDebug>
#include"buyer.h"

int temp_modity_count=modity_count;
int temp_order_count=order_count;

AdminWidget::AdminWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminWidget)
{
    ui->setupUi(this);


    temp_modity_count=modity_count;
    temp_order_count=order_count;

    //点击注销返回主界面
    connect(ui->btn_exit,&QPushButton::clicked,[=](){
        Widget* newwidget=new Widget();
        this->close();
        newwidget->show();
    });

    //先设置用户表
    //设置行数列数表头
    ui->tableWidget_user->setColumnCount(6);
    ui->tableWidget_user->setRowCount(100);
    ui->tableWidget_user->setHorizontalHeaderLabels(QStringList()<<"用户id"<<"用户名"<<"联系方式"<<"地址"<<"钱包余额"<<"用户状态");

    //设置只能选中整行
    ui->tableWidget_user->setSelectionBehavior(QTableWidget::SelectRows);

    //先对用户界面进行操作
    for(int i=0;i<user_count;i++)
    {
        //设置单元格无法修改
        QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(userfile[i].userId));
        a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(userfile[i].userName));
        a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a3=new QTableWidgetItem(QString::fromStdString(userfile[i].phoneNumber));
        a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a4=new QTableWidgetItem(QString::fromStdString(userfile[i].address));
        a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a5=new QTableWidgetItem(QString::number(userfile[i].balance,'f',1));
        a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a6;
        if(userfile[i].userState==forbidden) a6=new QTableWidgetItem(QString("封禁"));
        else a6=new QTableWidgetItem(QString("正常"));
        a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

        //添加单元格
        ui->tableWidget_user->setItem(i,0,a1);
        ui->tableWidget_user->setItem(i,1,a2);
        ui->tableWidget_user->setItem(i,2,a3);
        ui->tableWidget_user->setItem(i,3,a4);
        ui->tableWidget_user->setItem(i,4,a5);
        ui->tableWidget_user->setItem(i,5,a6);

    }

    //封禁用户

    connect(ui->btn_deleteuser,&QPushButton::clicked,this,[=]()mutable{
        int row=ui->tableWidget_user->currentRow();
        if(row>=user_count)
        {
            QMessageBox::critical(this,"错误","请选择正确的用户！");
        }
        else
        {
            QTableWidgetItem* tempstate=ui->tableWidget_user->item(row,5);
            if(tempstate->text()=="封禁")
            {
                QMessageBox::critical(this,"错误","该用户之前已经被封禁！");
            }
            else
            {
                tempstate->setText("封禁");
                string tempid=ui->tableWidget_user->item(row,0)->text().toStdString();
                for(int i=0;i<user_count;i++)
                {
                    if(tempid==userfile[i].userId)
                    {
                        userfile[i].userState=forbidden;
                        break;
                    }
                }
                QMessageBox::information(this,"完成","该用户已成功被封禁！");
            }
        }
    });

    //对商品界面进行判断

    //显示所有商品
    ui->tableWidget_modity->setColumnCount(7);
    ui->tableWidget_modity->setRowCount(100);
    ui->tableWidget_modity->setHorizontalHeaderLabels(QStringList()<<"商品id"<<"商品名称"<<"价格"<<"数量"<<"上架日期"<<"状态"<<"卖家ID");

    //设置只能选中整行
    ui->tableWidget_modity->setSelectionBehavior(QTableWidget::SelectRows);

    //先对用户界面进行操作
    for(int i=0;i<modity_count;i++)
    {
        //设置单元格无法修改
        QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modityfile[i].commodityId));
        a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(modityfile[i].commodityName));
        a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a3=new QTableWidgetItem(QString::number(modityfile[i].price,'f',1));
        a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a4=new QTableWidgetItem(QString::number(modityfile[i].number,'f',0));
        a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(modityfile[i].date));
        a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a6;
        if(modityfile[i].state==onAuction) a6=new QTableWidgetItem(QString("销售中"));
        else if(modityfile[i].state==removed) a6=new QTableWidgetItem(QString("已下架"));
        else a6=new QTableWidgetItem(QString("已售出"));
        a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a7=new QTableWidgetItem(QString::fromStdString(modityfile[i].sellerId));
        a5->setFlags(a7->flags() & (~Qt::ItemIsEditable));

        //添加单元格
        ui->tableWidget_modity->setItem(i,0,a1);
        ui->tableWidget_modity->setItem(i,1,a2);
        ui->tableWidget_modity->setItem(i,2,a3);
        ui->tableWidget_modity->setItem(i,3,a4);
        ui->tableWidget_modity->setItem(i,4,a5);
        ui->tableWidget_modity->setItem(i,5,a6);
        ui->tableWidget_modity->setItem(i,6,a7);

    }


    //下架商品
    connect(ui->btn_deletemodity,&QPushButton::clicked,[=](){
        int row=ui->tableWidget_modity->currentRow();
        if(row>=modity_count)
        {
            QMessageBox::critical(this,"错误","请选择正确的商品");
            return;
        }
        string tempid=ui->tableWidget_modity->item(row,0)->text().toStdString();
        if(QMessageBox::Yes==QMessageBox::question(this,"提问","确认要下架该商品吗？"))
        {
            QTableWidgetItem* tempstate=ui->tableWidget_modity->item(row,5);
            if(tempstate->text()=="已下架" || tempstate->text()=="已售出")
            {
                QMessageBox::critical(this,"错误","该商品不在销售中");
                return;
            }
            admin123.deleteModity(tempid);

            tempstate->setText("已下架");
            QMessageBox::information(this,"正确","您已经成功下架该商品");
            return;
        }
        else
            QMessageBox::information(this,"错误","您已经取消下架该商品");
    });

    //搜索商品
    ui->tableWidget_modity_byname->setRowCount(100);
    ui->tableWidget_modity_byname->setColumnCount(7);
    ui->tableWidget_modity_byname->setHorizontalHeaderLabels(QStringList()<<"商品ID"<<"商品名称"<<"价格"<<"数量"<<"上架日期"<<"卖家id"<<"状态");

    //设置只能选中整行
    ui->tableWidget_modity_byname->setSelectionBehavior(QTableWidget::SelectRows);
    //商品搜索页
    connect(ui->btn_search_name,&QPushButton::clicked,[=](){
        ui->tableWidget_modity_byname->clearContents();
        string name=ui->lineEdit_modity_name->text().toStdString();

        Modity modity[100];
        int count_modity_byname=admin123.viewModityByName(modity,name);

        for(int i=0;i<count_modity_byname;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modity[i].commodityId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(modity[i].commodityName));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(modity[i].price,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(modity[i].number));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(modity[i].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(modity[i].sellerId));
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a7;
            if(modityfile[i].state==onAuction) a7=new QTableWidgetItem(QString("销售中"));
            else if(modityfile[i].state==removed) a7=new QTableWidgetItem(QString("已下架"));
            else a7=new QTableWidgetItem(QString("已售出"));
            a6->setFlags(a7->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_modity_byname->setItem(i,0,a1);
            ui->tableWidget_modity_byname->setItem(i,1,a2);
            ui->tableWidget_modity_byname->setItem(i,2,a3);
            ui->tableWidget_modity_byname->setItem(i,3,a4);
            ui->tableWidget_modity_byname->setItem(i,4,a5);
            ui->tableWidget_modity_byname->setItem(i,5,a6);
            ui->tableWidget_modity_byname->setItem(i,6,a7);
        }

    });

    //查看订单
    ui->tableWidget_order->setRowCount(100);
    ui->tableWidget_order->setColumnCount(7);
    ui->tableWidget_order->setHorizontalHeaderLabels(QStringList()<<"订单ID"<<"商品ID"<<"交易单价"<<"交易数量"<<"交易时间"<<"卖家ID"<<"买家ID");

    //设置只能选中整行
    ui->tableWidget_order->setSelectionBehavior(QTableWidget::SelectRows);

    Order order[100];

    for(int i=0;i<order_count;i++)
    {
        QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(orderfile[i].orderId));
        a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(orderfile[i].commodityId));
        a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a3=new QTableWidgetItem(QString::number(orderfile[i].unitprice,'f',1));
        a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a4=new QTableWidgetItem(QString::number(orderfile[i].number,'f',0));
        a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(orderfile[i].date));
        a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(orderfile[i].sellerId));
        a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a7=new QTableWidgetItem(QString::fromStdString(orderfile[i].buyerId));
        a7->setFlags(a7->flags() & (~Qt::ItemIsEditable));

        ui->tableWidget_order->setItem(i,0,a1);
        ui->tableWidget_order->setItem(i,1,a2);
        ui->tableWidget_order->setItem(i,2,a3);
        ui->tableWidget_order->setItem(i,3,a4);
        ui->tableWidget_order->setItem(i,4,a5);
        ui->tableWidget_order->setItem(i,5,a6);
        ui->tableWidget_order->setItem(i,6,a7);
    }

    //如果收到refresh信号，更新商品和订单表
    connect(refresh,&Refresh::refreshsignal,[=](string modityid)mutable{
        qDebug()<<QString::fromStdString(modityid);
        qDebug()<<QString::number(temp_order_count);
        qDebug()<<QString::number(order_count);
        //更新商品
        Buyer buyer;
        Modity modity;
        buyer.viewModityById(modity,modityid);
        for(int i=0;i<temp_modity_count;i++)
        {
            QTableWidgetItem* tempid=ui->tableWidget_modity->item(i,0);
            if(tempid->text().toStdString()==modityid)
            {
                QTableWidgetItem* tempnum=ui->tableWidget_modity->item(i,3);
                tempnum->setText(QString::number(modity.number,'f',0));
                QTableWidgetItem* tempdate=ui->tableWidget_modity->item(i,4);
                tempdate->setText(QString::fromStdString(modity.date));
                QTableWidgetItem* tempstate=ui->tableWidget_modity->item(i,5);
                if(modity.state==onAuction) tempstate->setText(QString::fromStdString("销售中"));
                else if(modity.state==sold) tempstate->setText(QString::fromStdString("已售出"));
                else tempstate->setText(QString::fromStdString("已下架"));
                break;
            }
        }
        //更新订单
        for(int i=temp_order_count;i<order_count;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(orderfile[i].orderId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(orderfile[i].commodityId));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(orderfile[i].unitprice,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(orderfile[i].number,'f',0));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(orderfile[i].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(orderfile[i].sellerId));
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a7=new QTableWidgetItem(QString::fromStdString(orderfile[i].buyerId));
            a7->setFlags(a7->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_order->setItem(i,0,a1);
            ui->tableWidget_order->setItem(i,1,a2);
            ui->tableWidget_order->setItem(i,2,a3);
            ui->tableWidget_order->setItem(i,3,a4);
            ui->tableWidget_order->setItem(i,4,a5);
            ui->tableWidget_order->setItem(i,5,a6);
            ui->tableWidget_order->setItem(i,6,a7);
        }
        //对于新增订单中的每一个buyid和sellerid更新余额
        for(int i=0;i<user_count;i++)
        {
            QTableWidgetItem* tempuserid=ui->tableWidget_user->item(i,0);
            if(tempuserid->text().toStdString()==modity.sellerId)
            {
                QTableWidgetItem* tempbalance=ui->tableWidget_user->item(i,4);
                tempbalance->setText(QString::number(userfile[i].balance,'f',1));
                break;
            }
        }
        for(int i=temp_order_count;i<order_count;i++)
        {

            for(int j=0;j<user_count;j++)
            {
                if(userfile[j].userId==orderfile[i].buyerId)
                {

                    QTableWidgetItem* tempbalance=ui->tableWidget_user->item(j,4);
                    tempbalance->setText(QString::number(userfile[j].balance,'f',1));
                    break;
                }
            }
        }
        temp_order_count=order_count;
    });

}

AdminWidget::~AdminWidget()
{
    delete ui;
}
