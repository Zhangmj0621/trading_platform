#include "buyerwidget.h"
#include "ui_buyerwidget.h"
#include<QPushButton>
#include<QString>
#include<QTableWidgetItem>
#include<QTableWidget>
#include<QMessageBox>
#include"global.h"
#include"mytime.h"
#include"buyer.h"
#include<QDebug>
#include<QMetaType>

int want_count;
int temp_order_count3=order_count;
int temp_modity_count3=modity_count;
int temp_modity_search3=0;
int temp_want_count3=0;

BuyerWidget::BuyerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BuyerWidget)
{
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);

    qRegisterMetaType<string>("string");
    qRegisterMetaType<QVector<int>>("QVector<int>");//QStandardItemModel

    //我的出价界面
    ui->tableWidget_want->setRowCount(100);
    ui->tableWidget_want->setColumnCount(5);
    ui->tableWidget_want->setHorizontalHeaderLabels(QStringList()<<"商品ID"<<"出价"<<"求购数量"<<"出价日期"<<"卖家id");

    //设置只能选中整行
    ui->tableWidget_want->setSelectionBehavior(QTableWidget::SelectRows);

    Buyer tempbuyer;
    Want wantlist[100];
    want_count=tempbuyer.viewyourwant(wantlist,loginuser->userId);
    temp_want_count3=want_count;
    for(int i=0;i<want_count;i++)
    {
        QTableWidgetItem* want1=new QTableWidgetItem(QString::fromStdString(wantlist[i].modityid));
        want1->setFlags(want1->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* want2=new QTableWidgetItem(QString::number(wantlist[i].yourinfo.price,'f',1));
        want2->setFlags(want2->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* want3=new QTableWidgetItem(QString::number(wantlist[i].yourinfo.num,'f',0));
        want3->setFlags(want3->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* want4=new QTableWidgetItem(QString::fromStdString(wantlist[i].yourinfo.date));
        want4->setFlags(want4->flags() & (~Qt::ItemIsEditable));
        QTableWidgetItem* want5=new QTableWidgetItem(QString::fromStdString(wantlist[i].sellerid));
        want5->setFlags(want5->flags() & (~Qt::ItemIsEditable));

        ui->tableWidget_want->setItem(i,0,want1);
        ui->tableWidget_want->setItem(i,1,want2);
        ui->tableWidget_want->setItem(i,2,want3);
        ui->tableWidget_want->setItem(i,3,want4);
        ui->tableWidget_want->setItem(i,4,want5);
    }
    //所有商品界面

    ui->tableWidget_all_modity->setRowCount(100);
    ui->tableWidget_all_modity->setColumnCount(6);
    ui->tableWidget_all_modity->setHorizontalHeaderLabels(QStringList()<<"商品ID"<<"商品名称"<<"价格"<<"数量"<<"上架日期"<<"卖家id");

    //设置只能选中整行
    ui->tableWidget_all_modity->setSelectionBehavior(QTableWidget::SelectRows);

    int modity_cout_count=0;
    for(int i=0;i<modity_count;i++)
    {
        //选取在销售中的商品
        if(modityfile[i].state==onAuction)
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
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(modityfile[i].sellerId));
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

    qDebug()<<modity_cout_count;
    temp_modity_count3=modity_cout_count;

    ui->tableWidget_modity_info->setRowCount(7);
    ui->tableWidget_modity_info->setColumnCount(2);
    ui->tableWidget_modity_info->setHorizontalHeaderLabels(QStringList()<<"属性"<<"信息");

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
    QTableWidgetItem* c6=new QTableWidgetItem("上架时间");
    c6->setFlags(Qt::ItemIsEditable);
    QTableWidgetItem* c7=new QTableWidgetItem("卖家ID");
    c7->setFlags(Qt::ItemIsEditable);


    ui->tableWidget_modity_info->setItem(0,0,c5);
    ui->tableWidget_modity_info->setItem(1,0,c1);
    ui->tableWidget_modity_info->setItem(2,0,c2);
    ui->tableWidget_modity_info->setItem(3,0,c3);
    ui->tableWidget_modity_info->setItem(4,0,c4);
    ui->tableWidget_modity_info->setItem(5,0,c6);
    ui->tableWidget_modity_info->setItem(6,0,c7);
    //输入商品id查看商品详细信息
    connect(ui->btn_search_info,&QPushButton::clicked,[=](){
        string modityid=ui->lineEdit_search->text().toStdString();

        Modity modity;
        Buyer buyer3;
        bool judge=buyer3.viewModityById(modity,modityid);
        if(judge)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(modity.commodityId));
            a1->setFlags(a1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(modity.commodityName));
            a2->setFlags(a2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(modity.price,'f',1));
            a3->setFlags(a3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(modity.number));
            a4->setFlags(a4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a7=new QTableWidgetItem(QString::fromStdString(modity.description));
            a7->setFlags(a7->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(modity.date));
            a5->setFlags(a5->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(modity.sellerId));
            a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_modity_info->setItem(0,1,a1);
            ui->tableWidget_modity_info->setItem(1,1,a2);
            ui->tableWidget_modity_info->setItem(2,1,a3);
            ui->tableWidget_modity_info->setItem(3,1,a4);
            ui->tableWidget_modity_info->setItem(4,1,a7);
            ui->tableWidget_modity_info->setItem(5,1,a5);
            ui->tableWidget_modity_info->setItem(6,1,a6);
        }
        else
        {
            QMessageBox::critical(this,"错误","请输入正确的商品ID");
        }
    });


    ui->tableWidget_modity_byname->setRowCount(100);
    ui->tableWidget_modity_byname->setColumnCount(6);
    ui->tableWidget_modity_byname->setHorizontalHeaderLabels(QStringList()<<"商品ID"<<"商品名称"<<"价格"<<"数量"<<"上架日期"<<"卖家id");

    //设置只能选中整行
    ui->tableWidget_modity_byname->setSelectionBehavior(QTableWidget::SelectRows);
    //商品搜索页
    connect(ui->btn_search_name,&QPushButton::clicked,[=](){
        ui->tableWidget_modity_byname->clearContents();
        string name=ui->lineEdit_modity_name->text().toStdString();

        Modity modity[100];
        Buyer buyer;
        int count_modity_byname=buyer.viewModityByName(modity,name);
        temp_modity_search3=count_modity_byname;

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

            ui->tableWidget_modity_byname->setItem(i,0,a1);
            ui->tableWidget_modity_byname->setItem(i,1,a2);
            ui->tableWidget_modity_byname->setItem(i,2,a3);
            ui->tableWidget_modity_byname->setItem(i,3,a4);
            ui->tableWidget_modity_byname->setItem(i,4,a5);
            ui->tableWidget_modity_byname->setItem(i,5,a6);
        }

    });

    connect(ui->btn_discharge,&QPushButton::clicked,[=]()mutable{
        double price=ui->lineEdit_price->text().toDouble();
        int number=ui->lineEdit_number->text().toInt();

        QString price1=QString::number(price,'f',1);
        QString price2=QString::number(price,'f',0);

        QString number1=QString::number(number,'f',0);
        if(ui->lineEdit_price->text()!=price1 && ui->lineEdit_price->text()!=price2)
        {
            QMessageBox::critical(this,"错误","输入价格格式非法");
        }
        else
        {
            if(ui->lineEdit_number->text()!=number1)
            {
                QMessageBox::critical(this,"错误","输入数量格式非法");
            }
            else
            {
                int row=ui->tableWidget_modity_byname->currentRow();
                if(row>=ui->tableWidget_modity_byname->rowCount())
                {
                    QMessageBox::critical(this,"错误","请选择正确的商品！");
                }
                else
                {
                    QTableWidgetItem* tempitem=ui->tableWidget_modity_byname->item(row,0);
                    QTableWidgetItem* tempprice=ui->tableWidget_modity_byname->item(row,2);
                    QTableWidgetItem* tempnum=ui->tableWidget_modity_byname->item(row,3);
                    Buyer buyer;
                    if(QMessageBox::Yes==QMessageBox::question(this,"提问","是否确认出价？"))
                    {
                        if(tempprice->text().toDouble()>price)
                        {
                            QMessageBox::critical(this,"错误","您的出价过低，出价失败！");
                            return;
                        }
                        if(tempnum->text().toInt()<number)
                        {
                            QMessageBox::critical(this,"错误","您要求购买的商品数过多!");
                            return;
                        }
                        if(price*number>loginuser->balance)
                        {
                            QMessageBox::critical(this,"错误","您的余额不支持这次交易，请充值后再来！");
                            return;
                        }
                        bool judge=buyer.buyModity(tempitem->text().toStdString(),loginuser->userId,number,price);
                        if(!judge)
                        {
                            QMessageBox::critical(this,"错误","您已经对该商品存在报价，请在我的出价中查看！");
                        }
                        else
                        {
                            QMessageBox::information(this,"正确","您已成功出价，可在我的出价中进行查看！");
                            //在我的出价中添加表象
                            //获取出价
                            for(int j=0;j<modity_count;j++)
                            {
                                if(modityfile[j].commodityId==tempitem->text().toStdString())
                                {
                                    map<string,info>::iterator it;
                                    it=modityfile[j].want.find(loginuser->userId);

                                    QTableWidgetItem* want1=new QTableWidgetItem(QString::fromStdString(modityfile[j].commodityId));
                                    want1->setFlags(want1->flags() & (~Qt::ItemIsEditable));
                                    QTableWidgetItem* want2=new QTableWidgetItem(QString::number(it->second.price,'f',1));
                                    want2->setFlags(want2->flags() & (~Qt::ItemIsEditable));
                                    QTableWidgetItem* want3=new QTableWidgetItem(QString::number(it->second.num,'f',0));
                                    want3->setFlags(want3->flags() & (~Qt::ItemIsEditable));
                                    QTableWidgetItem* want4=new QTableWidgetItem(QString::fromStdString(it->second.date));
                                    want4->setFlags(want4->flags() & (~Qt::ItemIsEditable));
                                    QTableWidgetItem* want5=new QTableWidgetItem(QString::fromStdString(modityfile[j].sellerId));
                                    want5->setFlags(want5->flags() & (~Qt::ItemIsEditable));

                                    ui->tableWidget_want->setItem(temp_want_count3,0,want1);
                                    ui->tableWidget_want->setItem(temp_want_count3,1,want2);
                                    ui->tableWidget_want->setItem(temp_want_count3,2,want3);
                                    ui->tableWidget_want->setItem(temp_want_count3,3,want4);
                                    ui->tableWidget_want->setItem(temp_want_count3,4,want5);
                                    temp_want_count3++;
                                }
                            }

                        }
                    }
                    else
                        QMessageBox::critical(this,"错误","您已取消出价");

                }
            }
        }
    });

    //删除报价
    connect(ui->btn_delete_want,&QPushButton::clicked,[=]()mutable{
        int row=ui->tableWidget_want->currentRow();
        if(row>=temp_want_count3)
        {
            QMessageBox::critical(this,"错误","请选择正确的出价！");
        }
        else
        {
            if(QMessageBox::Yes==QMessageBox::question(this,"提问","确认要删除该出价吗？"))
            {
                QMessageBox::information(this,"正确","您已成功删除该出价！");
                QTableWidgetItem* tempmodityid=ui->tableWidget_want->item(row,0);
                for(int i=0;i<modity_count;i++)
                {
                    if(modityfile[i].commodityId==tempmodityid->text().toStdString())
                    {
                        map<string,info>::iterator it;
                        it=modityfile[i].want.find(loginuser->userId);
                        modityfile[i].want.erase(it);
                        break;
                    }
                }
                ui->tableWidget_want->removeRow(row);
                temp_want_count3--;
            }
        }
    });

    //查看订单信息
    ui->tableWidget_order->setRowCount(100);
    ui->tableWidget_order->setColumnCount(6);
    ui->tableWidget_order->setHorizontalHeaderLabels(QStringList()<<"订单ID"<<"商品ID"<<"交易单价"<<"交易数量"<<"交易时间"<<"卖家ID");

    //设置只能选中整行
    ui->tableWidget_order->setSelectionBehavior(QTableWidget::SelectRows);

    Buyer buyer;
    Order order[100];

    int order_list_count=buyer.viewOrderList(order,loginuser->userId);
    for(int i=0;i<order_list_count;i++)
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
        QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order[i].sellerId));
        a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

        ui->tableWidget_order->setItem(i,0,a1);
        ui->tableWidget_order->setItem(i,1,a2);
        ui->tableWidget_order->setItem(i,2,a3);
        ui->tableWidget_order->setItem(i,3,a4);
        ui->tableWidget_order->setItem(i,4,a5);
        ui->tableWidget_order->setItem(i,5,a6);
    }

    temp_order_count3=order_list_count;

    //修改报价信息
    connect(ui->btn_revise_want,&QPushButton::clicked,[=](){
        int row=ui->tableWidget_want->currentRow();

        QTableWidgetItem* tempmodityid=ui->tableWidget_want->item(row,0);
        QTableWidgetItem* tempmodityprice=ui->tableWidget_want->item(row,1);
        QTableWidgetItem* tempmoditynumber=ui->tableWidget_want->item(row,2);
        QTableWidgetItem* tempmoditydate=ui->tableWidget_want->item(row,3);
        int bh=0;
        for(;bh<modity_count;bh++)
        {
            if(modityfile[bh].commodityId==tempmodityid->text().toStdString())
                break;
        }
        double price=ui->lineEdit_price_revise->text().toDouble();
        int number=ui->lineEdit_number_revise->text().toInt();

        QString price1=QString::number(price,'f',1);
        QString price2=QString::number(price,'f',0);

        QString number1=QString::number(number,'f',0);

        if(QMessageBox::Yes==QMessageBox::question(this,"提问","确定要修改商品信息吗？"))
        {
            if(ui->checkBox_price->isChecked())
            {
                if(ui->lineEdit_price_revise->text()!=price1 && ui->lineEdit_price_revise->text()!=price2)
                {
                    QMessageBox::critical(this,"错误","输入价格格式非法！");
                    return;
                }
                if(price<modityfile[bh].price)
                {
                    QMessageBox::critical(this,"错误","输入价格低于商品底价！");
                    return;
                }
                if(ui->checkBox_number->isChecked())
                {
                    if(ui->lineEdit_number_revise->text()!=number1)
                    {
                        QMessageBox::critical(this,"错误","输入数量格式非法！");
                        return;
                    }
                    if(number>modityfile[bh].number)
                    {
                        QMessageBox::critical(this,"错误","输入求购数量过多！");
                        return;
                    }
                    map<string,info>::iterator it;
                    it=modityfile[bh].want.find(loginuser->userId);
                    modityfile[bh].want.erase(it);
                    info newinfo;
                    newinfo.price=price;
                    newinfo.num=number;
                    string tempdate;
                    int tempday;
                    MyTime::getMyTime(tempdate,tempday);
                    newinfo.date=tempdate;
                    newinfo.second=tempday;
                    modityfile[bh].want.insert(pair<string,info>(loginuser->userId,newinfo));
                    tempmodityprice->setText(QString::number(price,'f',1));
                    tempmoditynumber->setText(QString::number(number,'f',0));
                    tempmoditydate->setText(QString::fromStdString(tempdate));
                }
                else
                {
                    map<string,info>::iterator it;
                    it=modityfile[bh].want.find(loginuser->userId);

                    info newinfo;
                    newinfo.price=price;
                    newinfo.num=it->second.num;
                    string tempdate;
                    int tempday;
                    MyTime::getMyTime(tempdate,tempday);
                    newinfo.date=tempdate;
                    newinfo.second=tempday;
                    modityfile[bh].want.erase(it);
                    modityfile[bh].want.insert(pair<string,info>(loginuser->userId,newinfo));

                    tempmodityprice->setText(QString::number(price,'f',1));
                    tempmoditydate->setText(QString::fromStdString(tempdate));
                }
            }
            else
            {
                if(ui->lineEdit_number_revise->text()!=number1)
                {
                    QMessageBox::critical(this,"错误","输入数量格式非法！");
                    return;
                }
                if(number>modityfile[bh].number)
                {
                    QMessageBox::critical(this,"错误","输入求购数量过多！");
                    return;
                }
                map<string,info>::iterator it;
                it=modityfile[bh].want.find(loginuser->userId);
                info newinfo;
                newinfo.price=it->second.price;
                newinfo.num=number;
                string tempdate;
                int tempday;
                MyTime::getMyTime(tempdate,tempday);
                newinfo.date=tempdate;
                newinfo.second=tempday;
                modityfile[bh].want.erase(it);
                modityfile[bh].want.insert(pair<string,info>(loginuser->userId,newinfo));
                tempmoditynumber->setText(QString::number(number,'f',0));
                tempmoditydate->setText(QString::fromStdString(tempdate));
            }
            QMessageBox::information(this,"正确","您已成功修改商品信息！");
        }
        else
        {
            QMessageBox::information(this,"错误","您已取消修改商品信息");
        }
    });

    //修改商品列表，搜索商品列表，我的出价列表，我的订单列表
    /*connect(refresh,&Refresh::refreshsignal2,[=](string modityid){
        //修改所有商品列表
        Buyer buyer;
        Modity modity;
        buyer.viewModityById(modity,modityid);
        qDebug()<<ui->tableWidget_all_modity->rowCount();
        for(int i=0;i<temp_modity_count3;i++)
        {
            QTableWidgetItem* tempid2=ui->tableWidget_all_modity->item(i,0);
            if(tempid2->text().toStdString()==modityid)
            {
                if(modity.state==sold || modity.state==removed)
                {
                    ui->tableWidget_all_modity->removeRow(i);
                    break;
                }
                else
                {
                    QTableWidgetItem* tempnum=ui->tableWidget_all_modity->item(i,3);
                    QTableWidgetItem* tempdate=ui->tableWidget_all_modity->item(i,4);
                    tempnum->setText(QString::number(modity.number));
                    tempdate->setText(QString::fromStdString(modity.date));
                    break;
                }
            }
        }

        //修改搜索商品列表
        int row_search=temp_modity_search3;
        for(int i=0;i<row_search;i++)
        {
            QTableWidgetItem* tempid=ui->tableWidget_modity_byname->item(i,0);
            if(tempid->text().toStdString()==modityid)
            {
                if(modity.state==sold || modity.state==removed)
                {
                    ui->tableWidget_modity_byname->removeRow(i);
                    break;
                }
                else
                {
                    QTableWidgetItem* tempnum=ui->tableWidget_modity_byname->item(i,3);
                    QTableWidgetItem* tempdate=ui->tableWidget_modity_byname->item(i,4);
                    tempnum->setText(QString::number(modity.number));
                    tempdate->setText(QString::fromStdString(modity.date));
                    break;
                }
            }
        }

        //修改我的出价列表
        int row_want=temp_want_count3;
        for(int i=0;i<row_want;i++)
        {
            QTableWidgetItem* tempid=ui->tableWidget_want->item(i,0);
            if(tempid->text().toStdString()==modityid)
            {
                ui->tableWidget_want->removeRow(i);
                break;
            }
        }

        //修改我的订单信息
        Order order2[100];

        int new_order_list_count=buyer.viewOrderList(order2,loginuser->userId);
        for(int i=temp_order_count3;i<new_order_list_count;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(order2[i].orderId));
            a1->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(order2[i].commodityId));
            a2->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(order2[i].unitprice,'f',1));
            a3->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(order2[i].number,'f',0));
            a4->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(order2[i].date));
            a5->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order2[i].sellerId));
            a6->setFlags(Qt::ItemIsEditable);

            ui->tableWidget_order->setItem(i,0,a1);
            ui->tableWidget_order->setItem(i,1,a2);
            ui->tableWidget_order->setItem(i,2,a3);
            ui->tableWidget_order->setItem(i,3,a4);
            ui->tableWidget_order->setItem(i,4,a5);
            ui->tableWidget_order->setItem(i,5,a6);
        }
        temp_order_count3=new_order_list_count;

    });*/

    connect(ui->btn_refresh1,&QPushButton::clicked,[=](){
        Buyer tempbuyer;
        ui->tableWidget_all_modity->clearContents();

        int new_modity_cout_count=0;
        for(int i=0;i<modity_count;i++)
        {
            //选取在销售中的商品
            if(modityfile[i].state==onAuction)
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
                QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(modityfile[i].sellerId));
                a6->setFlags(a6->flags() & (~Qt::ItemIsEditable));

                ui->tableWidget_all_modity->setItem(new_modity_cout_count,0,a1);
                ui->tableWidget_all_modity->setItem(new_modity_cout_count,1,a2);
                ui->tableWidget_all_modity->setItem(new_modity_cout_count,2,a3);
                ui->tableWidget_all_modity->setItem(new_modity_cout_count,3,a4);
                ui->tableWidget_all_modity->setItem(new_modity_cout_count,4,a5);
                ui->tableWidget_all_modity->setItem(new_modity_cout_count,5,a6);

                new_modity_cout_count++;
            }
        }
        temp_modity_count3=new_modity_cout_count;
    });

    connect(ui->btn_refresh2,&QPushButton::clicked,[=](){
        ui->tableWidget_all_modity->clearContents();

        temp_modity_search3=0;
    });

    connect(ui->btn_refresh3,&QPushButton::clicked,[=](){
        Buyer tempbuyer2;
        ui->tableWidget_want->clearContents();
        Want wantlist2[100];
        int want_count2=tempbuyer2.viewyourwant(wantlist2,loginuser->userId);
        temp_want_count3=want_count2;
        for(int i=0;i<want_count2;i++)
        {
            QTableWidgetItem* want1=new QTableWidgetItem(QString::fromStdString(wantlist[i].modityid));
            want1->setFlags(want1->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* want2=new QTableWidgetItem(QString::number(wantlist[i].yourinfo.price,'f',1));
            want2->setFlags(want2->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* want3=new QTableWidgetItem(QString::number(wantlist[i].yourinfo.num,'f',0));
            want3->setFlags(want3->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* want4=new QTableWidgetItem(QString::fromStdString(wantlist[i].yourinfo.date));
            want4->setFlags(want4->flags() & (~Qt::ItemIsEditable));
            QTableWidgetItem* want5=new QTableWidgetItem(QString::fromStdString(wantlist[i].sellerid));
            want5->setFlags(want5->flags() & (~Qt::ItemIsEditable));

            ui->tableWidget_want->setItem(i,0,want1);
            ui->tableWidget_want->setItem(i,1,want2);
            ui->tableWidget_want->setItem(i,2,want3);
            ui->tableWidget_want->setItem(i,3,want4);
            ui->tableWidget_want->setItem(i,4,want5);
        }
    });

    connect(ui->btn_refresh4,&QPushButton::clicked,[=](){
        Buyer tempbuyer2;
        Order order2[100];

        int new_order_list_count=tempbuyer2.viewOrderList(order2,loginuser->userId);
        for(int i=temp_order_count3;i<new_order_list_count;i++)
        {
            QTableWidgetItem* a1=new QTableWidgetItem(QString::fromStdString(order2[i].orderId));
            a1->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a2=new QTableWidgetItem(QString::fromStdString(order2[i].commodityId));
            a2->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a3=new QTableWidgetItem(QString::number(order2[i].unitprice,'f',1));
            a3->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a4=new QTableWidgetItem(QString::number(order2[i].number,'f',0));
            a4->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a5=new QTableWidgetItem(QString::fromStdString(order2[i].date));
            a5->setFlags(Qt::ItemIsEditable);
            QTableWidgetItem* a6=new QTableWidgetItem(QString::fromStdString(order2[i].sellerId));
            a6->setFlags(Qt::ItemIsEditable);

            ui->tableWidget_order->setItem(i,0,a1);
            ui->tableWidget_order->setItem(i,1,a2);
            ui->tableWidget_order->setItem(i,2,a3);
            ui->tableWidget_order->setItem(i,3,a4);
            ui->tableWidget_order->setItem(i,4,a5);
            ui->tableWidget_order->setItem(i,5,a6);
        }
        temp_order_count3=new_order_list_count;

    });
}

BuyerWidget::~BuyerWidget()
{
    delete ui;
}
