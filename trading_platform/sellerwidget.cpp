#include "sellerwidget.h"
#include "ui_sellerwidget.h"
#include<QPushButton>
#include<QString>
#include<QTableWidgetItem>
#include<QTableWidget>
#include<QMessageBox>
#include"global.h"
#include"mytime.h"
#include"seller.h"
#include"buyer.h"
#include<QDebug>
#include<QMetaType>

int temp_modity_count4=modity_count;
int temp_order_count4=order_count;



SellerWidget::SellerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellerWidget)
{

    ui->setupUi(this);

    qRegisterMetaType<string>("string");
    qRegisterMetaType<QVector<int>>("QVector<int>");//QStandardItemModel

    ui->tabWidget->setCurrentIndex(0);

    ui->tableWidget_modity->setRowCount(4);
    ui->tableWidget_modity->setColumnCount(2);
    ui->tableWidget_modity->setHorizontalHeaderLabels(QStringList()<<"属性"<<"信息");

    QTableWidgetItem* b1=new QTableWidgetItem("商品名称");
    b1->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* b2=new QTableWidgetItem("商品价格");
    b2->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* b3=new QTableWidgetItem("商品数量");
    b3->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* b4=new QTableWidgetItem("商品描述");
    b4->setFlags(Qt::ItemIsEditable);


    ui->tableWidget_modity->setItem(0,0,b1);
    ui->tableWidget_modity->setItem(1,0,b2);
    ui->tableWidget_modity->setItem(2,0,b3);
    ui->tableWidget_modity->setItem(3,0,b4);
    //先设置发布商品页
    connect(ui->btn_release1,&QPushButton::clicked,[=](){
        string modityname=ui->lineEdit_modityname->text().toStdString();
        string moditydes=ui->lineEdit_moditydescprition->text().toStdString();
        double modityprice=ui->lineEdit_modityprice->text().toDouble();
        int moditynum=ui->lineEdit_moditynumber->text().toInt();

        //需要判断输入的价格数量是否合法
        QString temp1_price=QString::number(modityprice,'f',1);
        QString temp2_price=QString::number(modityprice,'f',0);
        QString temp1_num=QString::number(moditynum,'f',0);

        if(temp1_num!=ui->lineEdit_moditynumber->text()
                || (temp1_price!=ui->lineEdit_modityprice->text()&&temp2_price!=ui->lineEdit_modityprice->text()))
        {
            QMessageBox::critical(this,"错误","价格或数量输入格式非法！");
        }
        else
        {

            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modityname));
            a1->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a2=new QTableWidgetItem(QString::number(modityprice,'f',1));
            a2->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(moditynum));
            a3->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a4=new QTableWidgetItem(QString::fromStdString(moditydes));
            a4->setFlags(Qt::ItemIsEditable);

            ui->tableWidget_modity->setItem(0,1,a1);
            ui->tableWidget_modity->setItem(1,1,a2);
            ui->tableWidget_modity->setItem(2,1,a3);
            ui->tableWidget_modity->setItem(3,1,a4);
        }
    });



    //修改商品界面
    //显示所发布的所有商品
    ui->tableWidget_all_modity->setRowCount(100);
    ui->tableWidget_all_modity->setColumnCount(6);
    ui->tableWidget_all_modity->setHorizontalHeaderLabels(QStringList()<<"商品ID"<<"商品名称"<<"价格"<<"数量"<<"上架日期"<<"状态");

    //设置只能选中整行
    ui->tableWidget_all_modity->setSelectionBehavior(QTableWidget::SelectRows);

    int modity_cout_count=0;
    for(int i=0;i<modity_count;i++)
    {
        //选取是该用户发布的商品
        if(modityfile[i].sellerId==loginuser->userId && modityfile[i].state!=sold)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modityfile[i].commodityId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(modityfile[i].commodityName));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(modityfile[i].price,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(modityfile[i].number));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(modityfile[i].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6;
            if(modityfile[i].state==removed) a6=new QTableWidgetItem("已下架");
            else if(modityfile[i].state==onAuction) a6=new QTableWidgetItem("销售中");
            else a6=new QTableWidgetItem("已售出");
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_all_modity->setItem(modity_cout_count,0,a1);
            ui->tableWidget_all_modity->setItem(modity_cout_count,1,a2);
            ui->tableWidget_all_modity->setItem(modity_cout_count,2,a3);
            ui->tableWidget_all_modity->setItem(modity_cout_count,3,a4);
            ui->tableWidget_all_modity->setItem(modity_cout_count,4,a5);
            ui->tableWidget_all_modity->setItem(modity_cout_count,5,a6);

            modity_cout_count++;
        }
    }
    temp_modity_count4=modity_cout_count;

    //商品正式发布
    connect(ui->btn_release,&QPushButton::clicked,[=]()mutable{
        if(QMessageBox::Yes==QMessageBox::question(this,"提问","是否确认发布商品"))
        {
            string modityname=ui->tableWidget_modity->item(0,1)->text().toStdString();
            double price = ui->tableWidget_modity->item(1,1)->text().toDouble();
            int number=ui->tableWidget_modity->item(2,1)->text().toInt();
            string moditydescription=ui->tableWidget_modity->item(3,1)->text().toStdString();

            Seller seller;
            seller.releaseModity(modityname,price,number,moditydescription,this->user);



            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modityfile[modity_count-1].commodityId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(modityname));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(price,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(number));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(modityfile[modity_count-1].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6;
            if(modityfile[modity_count-1].state==removed) a6=new QTableWidgetItem("已下架");
            else if(modityfile[modity_count-1].state==onAuction) a6=new QTableWidgetItem("销售中");
            else a6=new QTableWidgetItem("已售出");
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_all_modity->setItem(modity_cout_count,0,a1);
            ui->tableWidget_all_modity->setItem(modity_cout_count,1,a2);
            ui->tableWidget_all_modity->setItem(modity_cout_count,2,a3);
            ui->tableWidget_all_modity->setItem(modity_cout_count,3,a4);
            ui->tableWidget_all_modity->setItem(modity_cout_count,4,a5);
            ui->tableWidget_all_modity->setItem(modity_cout_count,5,a6);

            modity_cout_count++;
            temp_modity_count4++;
            QMessageBox::information(this,"成功","发布商品成功！");
        }
        else
        {
            QMessageBox::information(this,"失败","您已取消发布商品！");
        }
    });

    //下架商品
    connect(ui->btn_deletemodity,&QPushButton::clicked,[=](){
        int row=ui->tableWidget_all_modity->currentRow();
        if(row>= modity_cout_count)
        {
            QMessageBox::critical(this,"错误","请选择正确的商品！");
        }
        else
        {
            QTableWidgetItem* tempstate=ui->tableWidget_all_modity->item(row,5);
            if(tempstate->text()=="已下架" || tempstate->text()=="已售出")
            {
                QMessageBox::critical(this,"错误","该商品已经下架或售出！");
            }
            else
            {
                tempstate->setText("已下架");
                string tempid=ui->tableWidget_all_modity->item(row,0)->text().toStdString();

                Seller seller;
                seller.deleteModity(tempid);
                QMessageBox::information(this,"完成","该商品已成功下架！");
            }
        }
    });

    //上架商品
    connect(ui->btn_recovermodity,&QPushButton::clicked,[=](){
        int row=ui->tableWidget_all_modity->currentRow();
        if(row>= modity_cout_count)
        {
            QMessageBox::critical(this,"错误","请选择正确的商品！");
        }
        else
        {
            QTableWidgetItem* tempstate=ui->tableWidget_all_modity->item(row,5);
            if(tempstate->text()=="已售出" || tempstate->text()=="销售中")
            {
                QMessageBox::critical(this,"错误","该商品已经在销售中或已经售出！");
            }
            else
            {

                tempstate->setText("销售中");
                string tempid=ui->tableWidget_all_modity->item(row,0)->text().toStdString();

                Seller seller;
                int temp_i=seller.recoverModity(tempid);
                QTableWidgetItem* tempdate=ui->tableWidget_all_modity->item(row,4);
                tempdate->setText(QString::fromStdString(modityfile[temp_i].date));

                QMessageBox::information(this,"完成","该商品已成功上架且日期已经进行更新！");
            }
        }
    });

    //在预修改表中显示表头
    ui->tableWidget_modity_revise->setRowCount(5);
    ui->tableWidget_modity_revise->setColumnCount(2);
    ui->tableWidget_modity_revise->setHorizontalHeaderLabels(QStringList()<<"属性"<<"信息");

    QTableWidgetItem* c5=new QTableWidgetItem("商品ID");
    c5->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* c1=new QTableWidgetItem("商品名称");
    c1->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* c2=new QTableWidgetItem("商品价格");
    c2->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* c3=new QTableWidgetItem("商品数量");
    c3->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* c4=new QTableWidgetItem("商品描述");
    c4->setFlags(Qt::ItemIsEditable);


    ui->tableWidget_modity_revise->setItem(0,0,c5);
    ui->tableWidget_modity_revise->setItem(1,0,c1);
    ui->tableWidget_modity_revise->setItem(2,0,c2);
    ui->tableWidget_modity_revise->setItem(3,0,c3);
    ui->tableWidget_modity_revise->setItem(4,0,c4);

    //预修改信息
    connect(ui->btn_revise1,&QPushButton::clicked,[=](){
        int row=ui->tableWidget_all_modity->currentRow();
        if(row>= modity_cout_count)
        {
            QMessageBox::critical(this,"错误","请选择正确的商品！");
        }
        else
        {
            QTableWidgetItem* tempstate=ui->tableWidget_all_modity->item(row,5);
            if(tempstate->text()=="已售出")
            {
                QMessageBox::critical(this,"错误","该商品已经售出！");
            }
            else if(tempstate->text()=="销售中")
            {
                QMessageBox::critical(this,"错误","请将该商品下架后在进行修改！");
            }
            else
            {
                string tempid=ui->tableWidget_all_modity->item(row,0)->text().toStdString();
                for(int i=0;i<modity_count;i++)
                {
                    if(tempid==modityfile[i].commodityId)
                    {
                        string tempname=modityfile[i].commodityName;
                        double tempprice=modityfile[i].price;
                        int tempnum=modityfile[i].number;
                        string tempdes=modityfile[i].description;

                        if(ui->rbtn_name->isChecked())
                        {
                            tempname=ui->line_name->text().toStdString();
                        }
                        if(ui->rbtn_price->isChecked())
                        {
                            tempprice=ui->line_price->text().toDouble();
                            QString judge1=QString::number(tempprice,'f',1);
                            QString judge=QString::number(tempprice,'f',0);
                            if(ui->line_price->text()!=judge1 && ui->line_price->text()!=judge)
                            {
                                QMessageBox::critical(this,"错误","价格输入格式非法！");
                                return;
                            }
                        }
                        if(ui->rbtn_number->isChecked())
                        {
                            tempnum=ui->line_number->text().toInt();
                            QString judge =QString::number(tempnum,'f',0);
                            if(judge!=ui->line_number->text())
                            {
                                QMessageBox::critical(this,"错误","数量输入格式非法！");
                                return;
                            }
                        }
                        if(ui->rbtn_description->isChecked())
                        {
                            tempdes=ui->line_description->text().toStdString();
                        }

                        QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modityfile[i].commodityId));
                        a1->setFlags(Qt::ItemIsEditable);
                        QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(tempname));
                        a2->setFlags(Qt::ItemIsEditable);
                        QTableWidgetItem* a3=new QTableWidgetItem(QString::number(tempprice,'f',1));
                        a3->setFlags(Qt::ItemIsEditable);
                        QTableWidgetItem* a4=new QTableWidgetItem(QString::number(tempnum));
                        a4->setFlags(Qt::ItemIsEditable);
                        QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(tempdes));
                        a5->setFlags(Qt::ItemIsEditable);

                        ui->tableWidget_modity_revise->setItem(0,1,a1);
                        ui->tableWidget_modity_revise->setItem(1,1,a2);
                        ui->tableWidget_modity_revise->setItem(2,1,a3);
                        ui->tableWidget_modity_revise->setItem(3,1,a4);
                        ui->tableWidget_modity_revise->setItem(4,1,a5);
                        break;
                    }
                }
            }
        }
    });

    //正式修改
    connect(ui->btn_revise,&QPushButton::clicked,[=](){
        if(QMessageBox::Yes==QMessageBox::question(this,"提问","是否确认修改商品信息"))
        {
            string modityid=ui->tableWidget_modity_revise->item(0,1)->text().toStdString();
            string modityname=ui->tableWidget_modity_revise->item(1,1)->text().toStdString();
            double price = ui->tableWidget_modity_revise->item(2,1)->text().toDouble();
            int number=ui->tableWidget_modity_revise->item(3,1)->text().toInt();
            string moditydescription=ui->tableWidget_modity_revise->item(4,1)->text().toStdString();

            Seller seller;
            seller.reviseModity(modityid,modityname,price,number,moditydescription);

            for(int i=0;i<modity_cout_count;i++)
            {
                if(modityid==ui->tableWidget_all_modity->item(i,0)->text().toStdString())
                {
                    QTableWidgetItem* finalname=ui->tableWidget_all_modity->item(i,1);
                    finalname->setText(QString::fromStdString(modityname));
                    QTableWidgetItem* finalprice=ui->tableWidget_all_modity->item(i,2);
                    finalprice->setText(QString::number(price,'f',1));
                    QTableWidgetItem* finalnumber=ui->tableWidget_all_modity->item(i,3);
                    finalnumber->setText(QString::number(number,'f',0));
                }
            }

            QMessageBox::information(this,"成功","修改商品信息成功！");
        }
        else
        {
            QMessageBox::information(this,"失败","您已取消修改商品信息！");
        }
    });

    //显示历史订单
    ui->tableWidget_order->setRowCount(100);
    ui->tableWidget_order->setColumnCount(6);
    ui->tableWidget_order->setHorizontalHeaderLabels(QStringList()<<"订单ID"<<"商品ID"<<"交易单价"<<"交易数量"<<"交易时间"<<"买家ID");

    //设置只能选中整行
    ui->tableWidget_order->setSelectionBehavior(QTableWidget::SelectRows);

    Seller seller;
    Order order[100];
    int order_cout_count=seller.checkOrder(order,loginuser->userId);
    temp_order_count4=order_cout_count;

    for(int i=0;i<order_cout_count;i++)
    {
        QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(order[i].orderId));
        a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(order[i].commodityId));
        a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a3=new QTableWidgetItem(QString::number(order[i].unitprice,'f',1));
        a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a4=new QTableWidgetItem(QString::number(order[i].number,'f',0));
        a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(order[i].date));
        a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order[i].buyerId));
        a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

        ui->tableWidget_order->setItem(i,0,a1);
        ui->tableWidget_order->setItem(i,1,a2);
        ui->tableWidget_order->setItem(i,2,a3);
        ui->tableWidget_order->setItem(i,3,a4);
        ui->tableWidget_order->setItem(i,4,a5);
        ui->tableWidget_order->setItem(i,5,a6);
    }

    //修改发布商品和订单
    /*connect(refresh,&Refresh::refreshsignal3,[=](string modityid){
        qDebug()<<QString::fromStdString(modityid);
        qDebug()<<temp_modity_count4<<" "<<temp_order_count4;
        Buyer buyer;
        Modity modity;
        buyer.viewModityById(modity,modityid);



        for(int i=0;i<temp_modity_count4;i++)
        {
            QTableWidgetItem* tempid1=ui->tableWidget_all_modity->item(i,0);
            if(tempid1->text().toStdString()==modityid)
            {
                QTableWidgetItem* tempnum1=ui->tableWidget_all_modity->item(i,3);
                QTableWidgetItem* tempdate1=ui->tableWidget_all_modity->item(i,4);
                QTableWidgetItem* tempstate1=ui->tableWidget_all_modity->item(i,5);

                if(modity.state==sold)
                {
                    ui->tableWidget_all_modity->removeRow(i);
                    temp_modity_count4--;
                    break;
                }
                else
                {
                    tempnum1->setText(QString::number(modity.number));
                    tempdate1->setText(QString::fromStdString(modity.date));
                    if(modity.state==onAuction) tempstate1->setText("销售中");
                    else tempstate1->setText("已下架");
                    break;
                }
            }
        }


        Seller seller2;
        //修改订单
        Order order2[100];
        int order_cout_count2=seller2.checkOrder(order2,loginuser->userId);
        qDebug()<<temp_order_count4<<" "<<order_cout_count2;
        for(int i=temp_order_count4;i<order_cout_count2;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(order2[i].orderId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(order2[i].commodityId));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(order2[i].unitprice,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(order2[i].number,'f',0));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(order2[i].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order2[i].buyerId));
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_order->setItem(i,0,a1);
            ui->tableWidget_order->setItem(i,1,a2);
            ui->tableWidget_order->setItem(i,2,a3);
            ui->tableWidget_order->setItem(i,3,a4);
            ui->tableWidget_order->setItem(i,4,a5);
            ui->tableWidget_order->setItem(i,5,a6);
        }
        temp_order_count4=order_cout_count2;
    });
    */

    connect(ui->btn_refresh_1,&QPushButton::clicked,[=](){
        Buyer tempbuyer;
        for(int i=0;i<temp_modity_count4;i++)
        {
            Modity modity;
            QTableWidgetItem* tempid=ui->tableWidget_all_modity->item(i,0);
            tempbuyer.viewModityById(modity,tempid->text().toStdString());
            QTableWidgetItem* tempnum=ui->tableWidget_all_modity->item(i,3);
            QTableWidgetItem* tempdate=ui->tableWidget_all_modity->item(i,4);
            QTableWidgetItem* tempstate=ui->tableWidget_all_modity->item(i,5);

            if(modity.state==sold)
            {
                ui->tableWidget_all_modity->removeRow(i);
                temp_modity_count4--;
                continue;
            }
            else
            {
                tempnum->setText(QString::number(modity.number));
                tempdate->setText(QString::fromStdString(modity.date));
                if(modity.state==onAuction) tempstate->setText("销售中");
                else tempstate->setText("已下架");
            }

        }
    });

    connect(ui->btn_refresh_2,&QPushButton::clicked,[=](){
        Seller seller2;
        Order order2[100];
        int new_order_cout_count=seller2.checkOrder(order2,loginuser->userId);
        for(int i=temp_order_count4;i<new_order_cout_count;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(order2[i].orderId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(order2[i].commodityId));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(order2[i].unitprice,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(order2[i].number,'f',0));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(order2[i].date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order2[i].buyerId));
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_order->setItem(i,0,a1);
            ui->tableWidget_order->setItem(i,1,a2);
            ui->tableWidget_order->setItem(i,2,a3);
            ui->tableWidget_order->setItem(i,3,a4);
            ui->tableWidget_order->setItem(i,4,a5);
            ui->tableWidget_order->setItem(i,5,a6);
        }
        temp_order_count4=new_order_cout_count;
    });
}

SellerWidget::~SellerWidget()
{
    delete ui;
}
