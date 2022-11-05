/********************************************************************************
** Form generated from reading UI file 'adminwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWIDGET_H
#define UI_ADMINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWidget
{
public:
    QPushButton *btn_exit;
    QTabWidget *tabWidget;
    QWidget *tab_user;
    QTableWidget *tableWidget_user;
    QPushButton *btn_deleteuser;
    QWidget *tab_modity;
    QTableWidget *tableWidget_modity;
    QPushButton *btn_deletemodity;
    QLineEdit *lineEdit_modity_name;
    QPushButton *btn_search_name;
    QTableWidget *tableWidget_modity_byname;
    QWidget *tab_order;
    QTableWidget *tableWidget_order;

    void setupUi(QWidget *AdminWidget)
    {
        if (AdminWidget->objectName().isEmpty())
            AdminWidget->setObjectName(QString::fromUtf8("AdminWidget"));
        AdminWidget->resize(1065, 646);
        AdminWidget->setMinimumSize(QSize(1065, 646));
        AdminWidget->setMaximumSize(QSize(1065, 646));
        btn_exit = new QPushButton(AdminWidget);
        btn_exit->setObjectName(QString::fromUtf8("btn_exit"));
        btn_exit->setGeometry(QRect(950, 20, 93, 28));
        tabWidget = new QTabWidget(AdminWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 40, 1021, 591));
        tab_user = new QWidget();
        tab_user->setObjectName(QString::fromUtf8("tab_user"));
        tableWidget_user = new QTableWidget(tab_user);
        tableWidget_user->setObjectName(QString::fromUtf8("tableWidget_user"));
        tableWidget_user->setGeometry(QRect(135, 30, 871, 521));
        btn_deleteuser = new QPushButton(tab_user);
        btn_deleteuser->setObjectName(QString::fromUtf8("btn_deleteuser"));
        btn_deleteuser->setGeometry(QRect(20, 100, 93, 28));
        tabWidget->addTab(tab_user, QString());
        tab_modity = new QWidget();
        tab_modity->setObjectName(QString::fromUtf8("tab_modity"));
        tableWidget_modity = new QTableWidget(tab_modity);
        tableWidget_modity->setObjectName(QString::fromUtf8("tableWidget_modity"));
        tableWidget_modity->setGeometry(QRect(480, 30, 521, 521));
        btn_deletemodity = new QPushButton(tab_modity);
        btn_deletemodity->setObjectName(QString::fromUtf8("btn_deletemodity"));
        btn_deletemodity->setGeometry(QRect(310, 40, 93, 28));
        lineEdit_modity_name = new QLineEdit(tab_modity);
        lineEdit_modity_name->setObjectName(QString::fromUtf8("lineEdit_modity_name"));
        lineEdit_modity_name->setGeometry(QRect(30, 40, 141, 31));
        btn_search_name = new QPushButton(tab_modity);
        btn_search_name->setObjectName(QString::fromUtf8("btn_search_name"));
        btn_search_name->setGeometry(QRect(180, 40, 93, 28));
        tableWidget_modity_byname = new QTableWidget(tab_modity);
        tableWidget_modity_byname->setObjectName(QString::fromUtf8("tableWidget_modity_byname"));
        tableWidget_modity_byname->setGeometry(QRect(30, 100, 431, 451));
        tabWidget->addTab(tab_modity, QString());
        tab_order = new QWidget();
        tab_order->setObjectName(QString::fromUtf8("tab_order"));
        tableWidget_order = new QTableWidget(tab_order);
        tableWidget_order->setObjectName(QString::fromUtf8("tableWidget_order"));
        tableWidget_order->setGeometry(QRect(100, 30, 841, 511));
        tabWidget->addTab(tab_order, QString());

        retranslateUi(AdminWidget);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(AdminWidget);
    } // setupUi

    void retranslateUi(QWidget *AdminWidget)
    {
        AdminWidget->setWindowTitle(QCoreApplication::translate("AdminWidget", "Form", nullptr));
        btn_exit->setText(QCoreApplication::translate("AdminWidget", "\346\263\250\351\224\200", nullptr));
        btn_deleteuser->setText(QCoreApplication::translate("AdminWidget", "\345\260\201\347\246\201\347\224\250\346\210\267", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_user), QCoreApplication::translate("AdminWidget", "\346\237\245\347\234\213\347\224\250\346\210\267", nullptr));
        btn_deletemodity->setText(QCoreApplication::translate("AdminWidget", "\344\270\213\346\236\266\345\225\206\345\223\201", nullptr));
        btn_search_name->setText(QCoreApplication::translate("AdminWidget", "\346\220\234\347\264\242\345\225\206\345\223\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_modity), QCoreApplication::translate("AdminWidget", "\346\237\245\347\234\213\345\225\206\345\223\201", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_order), QCoreApplication::translate("AdminWidget", "\346\237\245\347\234\213\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdminWidget: public Ui_AdminWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWIDGET_H
