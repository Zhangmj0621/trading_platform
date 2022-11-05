/********************************************************************************
** Form generated from reading UI file 'buyerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUYERWIDGET_H
#define UI_BUYERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuyerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_all_modity;
    QTableWidget *tableWidget_all_modity;
    QLineEdit *lineEdit_search;
    QLabel *label;
    QPushButton *btn_search_info;
    QTableWidget *tableWidget_modity_info;
    QPushButton *btn_refresh1;
    QWidget *tab_buy_modity;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_modity_name;
    QPushButton *btn_search_name;
    QTableWidget *tableWidget_modity_byname;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit_price;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEdit_number;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_5;
    QPushButton *btn_discharge;
    QPushButton *btn_refresh2;
    QWidget *tab_see_want;
    QTableWidget *tableWidget_want;
    QPushButton *btn_delete_want;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_price;
    QCheckBox *checkBox_number;
    QLineEdit *lineEdit_price_revise;
    QLineEdit *lineEdit_number_revise;
    QPushButton *btn_revise_want;
    QPushButton *btn_refresh3;
    QWidget *tab_see_order;
    QTableWidget *tableWidget_order;
    QPushButton *btn_refresh4;

    void setupUi(QWidget *BuyerWidget)
    {
        if (BuyerWidget->objectName().isEmpty())
            BuyerWidget->setObjectName(QString::fromUtf8("BuyerWidget"));
        BuyerWidget->resize(778, 523);
        BuyerWidget->setMinimumSize(QSize(778, 523));
        BuyerWidget->setMaximumSize(QSize(778, 523));
        horizontalLayout = new QHBoxLayout(BuyerWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(BuyerWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_all_modity = new QWidget();
        tab_all_modity->setObjectName(QString::fromUtf8("tab_all_modity"));
        tableWidget_all_modity = new QTableWidget(tab_all_modity);
        tableWidget_all_modity->setObjectName(QString::fromUtf8("tableWidget_all_modity"));
        tableWidget_all_modity->setGeometry(QRect(20, 20, 481, 441));
        lineEdit_search = new QLineEdit(tab_all_modity);
        lineEdit_search->setObjectName(QString::fromUtf8("lineEdit_search"));
        lineEdit_search->setGeometry(QRect(550, 50, 113, 21));
        label = new QLabel(tab_all_modity);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 20, 111, 16));
        btn_search_info = new QPushButton(tab_all_modity);
        btn_search_info->setObjectName(QString::fromUtf8("btn_search_info"));
        btn_search_info->setGeometry(QRect(550, 80, 111, 28));
        tableWidget_modity_info = new QTableWidget(tab_all_modity);
        tableWidget_modity_info->setObjectName(QString::fromUtf8("tableWidget_modity_info"));
        tableWidget_modity_info->setGeometry(QRect(520, 130, 221, 331));
        btn_refresh1 = new QPushButton(tab_all_modity);
        btn_refresh1->setObjectName(QString::fromUtf8("btn_refresh1"));
        btn_refresh1->setGeometry(QRect(660, 0, 93, 28));
        tabWidget->addTab(tab_all_modity, QString());
        tab_buy_modity = new QWidget();
        tab_buy_modity->setObjectName(QString::fromUtf8("tab_buy_modity"));
        widget = new QWidget(tab_buy_modity);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(27, 40, 411, 46));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_modity_name = new QLineEdit(widget);
        lineEdit_modity_name->setObjectName(QString::fromUtf8("lineEdit_modity_name"));

        horizontalLayout_2->addWidget(lineEdit_modity_name);

        btn_search_name = new QPushButton(widget);
        btn_search_name->setObjectName(QString::fromUtf8("btn_search_name"));

        horizontalLayout_2->addWidget(btn_search_name);

        tableWidget_modity_byname = new QTableWidget(tab_buy_modity);
        tableWidget_modity_byname->setObjectName(QString::fromUtf8("tableWidget_modity_byname"));
        tableWidget_modity_byname->setGeometry(QRect(20, 100, 411, 351));
        widget_2 = new QWidget(tab_buy_modity);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(460, 140, 240, 171));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        lineEdit_price = new QLineEdit(widget_2);
        lineEdit_price->setObjectName(QString::fromUtf8("lineEdit_price"));

        gridLayout->addWidget(lineEdit_price, 0, 2, 1, 1);

        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        lineEdit_number = new QLineEdit(widget_2);
        lineEdit_number->setObjectName(QString::fromUtf8("lineEdit_number"));

        gridLayout->addWidget(lineEdit_number, 1, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 3, 1, 1);

        label_5 = new QLabel(tab_buy_modity);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(550, 110, 72, 15));
        btn_discharge = new QPushButton(tab_buy_modity);
        btn_discharge->setObjectName(QString::fromUtf8("btn_discharge"));
        btn_discharge->setGeometry(QRect(540, 330, 93, 28));
        btn_refresh2 = new QPushButton(tab_buy_modity);
        btn_refresh2->setObjectName(QString::fromUtf8("btn_refresh2"));
        btn_refresh2->setGeometry(QRect(640, 10, 93, 28));
        tabWidget->addTab(tab_buy_modity, QString());
        tab_see_want = new QWidget();
        tab_see_want->setObjectName(QString::fromUtf8("tab_see_want"));
        tableWidget_want = new QTableWidget(tab_see_want);
        tableWidget_want->setObjectName(QString::fromUtf8("tableWidget_want"));
        tableWidget_want->setGeometry(QRect(30, 30, 491, 411));
        btn_delete_want = new QPushButton(tab_see_want);
        btn_delete_want->setObjectName(QString::fromUtf8("btn_delete_want"));
        btn_delete_want->setGeometry(QRect(580, 100, 93, 28));
        groupBox = new QGroupBox(tab_see_want);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(540, 170, 77, 181));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        checkBox_price = new QCheckBox(groupBox);
        checkBox_price->setObjectName(QString::fromUtf8("checkBox_price"));

        verticalLayout->addWidget(checkBox_price);

        checkBox_number = new QCheckBox(groupBox);
        checkBox_number->setObjectName(QString::fromUtf8("checkBox_number"));

        verticalLayout->addWidget(checkBox_number);

        lineEdit_price_revise = new QLineEdit(tab_see_want);
        lineEdit_price_revise->setObjectName(QString::fromUtf8("lineEdit_price_revise"));
        lineEdit_price_revise->setGeometry(QRect(620, 230, 113, 21));
        lineEdit_number_revise = new QLineEdit(tab_see_want);
        lineEdit_number_revise->setObjectName(QString::fromUtf8("lineEdit_number_revise"));
        lineEdit_number_revise->setGeometry(QRect(620, 290, 113, 21));
        btn_revise_want = new QPushButton(tab_see_want);
        btn_revise_want->setObjectName(QString::fromUtf8("btn_revise_want"));
        btn_revise_want->setGeometry(QRect(580, 350, 93, 28));
        btn_refresh3 = new QPushButton(tab_see_want);
        btn_refresh3->setObjectName(QString::fromUtf8("btn_refresh3"));
        btn_refresh3->setGeometry(QRect(640, 10, 93, 28));
        tabWidget->addTab(tab_see_want, QString());
        tab_see_order = new QWidget();
        tab_see_order->setObjectName(QString::fromUtf8("tab_see_order"));
        tableWidget_order = new QTableWidget(tab_see_order);
        tableWidget_order->setObjectName(QString::fromUtf8("tableWidget_order"));
        tableWidget_order->setGeometry(QRect(20, 30, 711, 421));
        btn_refresh4 = new QPushButton(tab_see_order);
        btn_refresh4->setObjectName(QString::fromUtf8("btn_refresh4"));
        btn_refresh4->setGeometry(QRect(640, 0, 93, 28));
        tabWidget->addTab(tab_see_order, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(BuyerWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(BuyerWidget);
    } // setupUi

    void retranslateUi(QWidget *BuyerWidget)
    {
        BuyerWidget->setWindowTitle(QCoreApplication::translate("BuyerWidget", "Form", nullptr));
        label->setText(QCoreApplication::translate("BuyerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201id:", nullptr));
        btn_search_info->setText(QCoreApplication::translate("BuyerWidget", "\346\237\245\347\234\213\350\257\246\347\273\206\344\277\241\346\201\257", nullptr));
        btn_refresh1->setText(QCoreApplication::translate("BuyerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_all_modity), QCoreApplication::translate("BuyerWidget", "\345\225\206\345\223\201\345\210\227\350\241\250", nullptr));
        label_2->setText(QCoreApplication::translate("BuyerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        btn_search_name->setText(QCoreApplication::translate("BuyerWidget", "\346\220\234\347\264\242", nullptr));
        label_3->setText(QCoreApplication::translate("BuyerWidget", "\345\207\272\344\273\267\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("BuyerWidget", "\346\225\260\351\207\217:", nullptr));
        label_5->setText(QCoreApplication::translate("BuyerWidget", "\350\264\255\344\271\260\345\225\206\345\223\201", nullptr));
        btn_discharge->setText(QCoreApplication::translate("BuyerWidget", "\350\264\255\344\271\260", nullptr));
        btn_refresh2->setText(QCoreApplication::translate("BuyerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_buy_modity), QCoreApplication::translate("BuyerWidget", "\350\264\255\344\271\260\345\225\206\345\223\201", nullptr));
        btn_delete_want->setText(QCoreApplication::translate("BuyerWidget", "\345\217\226\346\266\210\346\212\245\344\273\267", nullptr));
        groupBox->setTitle(QCoreApplication::translate("BuyerWidget", "\344\277\256\346\224\271\344\277\241\346\201\257", nullptr));
        checkBox_price->setText(QCoreApplication::translate("BuyerWidget", "\346\212\245\344\273\267", nullptr));
        checkBox_number->setText(QCoreApplication::translate("BuyerWidget", "\346\225\260\351\207\217", nullptr));
        btn_revise_want->setText(QCoreApplication::translate("BuyerWidget", "\344\277\256\346\224\271\346\212\245\344\273\267", nullptr));
        btn_refresh3->setText(QCoreApplication::translate("BuyerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_see_want), QCoreApplication::translate("BuyerWidget", "\346\210\221\347\232\204\345\207\272\344\273\267", nullptr));
        btn_refresh4->setText(QCoreApplication::translate("BuyerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_see_order), QCoreApplication::translate("BuyerWidget", "\346\210\221\347\232\204\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BuyerWidget: public Ui_BuyerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUYERWIDGET_H
