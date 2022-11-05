/********************************************************************************
** Form generated from reading UI file 'mainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <userwidgetinfo.h>
#include "buyerwidget.h"
#include "sellerwidget.h"

QT_BEGIN_NAMESPACE

class Ui_mainWidget
{
public:
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    QWidget *page_user;
    QVBoxLayout *verticalLayout;
    UserWidgetInfo *widget1;
    QWidget *page_buyer;
    QHBoxLayout *horizontalLayout;
    BuyerWidget *widget2;
    QWidget *page_seller;
    SellerWidget *widget3;
    QWidget *page;
    QWidget *widget;

    void setupUi(QWidget *mainWidget)
    {
        if (mainWidget->objectName().isEmpty())
            mainWidget->setObjectName(QString::fromUtf8("mainWidget"));
        mainWidget->resize(992, 561);
        treeWidget = new QTreeWidget(mainWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(20, 30, 141, 521));
        stackedWidget = new QStackedWidget(mainWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(190, 20, 800, 550));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        stackedWidget->setMinimumSize(QSize(800, 550));
        stackedWidget->setMaximumSize(QSize(800, 550));
        page_user = new QWidget();
        page_user->setObjectName(QString::fromUtf8("page_user"));
        verticalLayout = new QVBoxLayout(page_user);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget1 = new UserWidgetInfo(page_user);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setMinimumSize(QSize(778, 523));
        widget1->setMaximumSize(QSize(778, 523));

        verticalLayout->addWidget(widget1);

        stackedWidget->addWidget(page_user);
        page_buyer = new QWidget();
        page_buyer->setObjectName(QString::fromUtf8("page_buyer"));
        horizontalLayout = new QHBoxLayout(page_buyer);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget2 = new BuyerWidget(page_buyer);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        widget2->setMinimumSize(QSize(778, 523));
        widget2->setMaximumSize(QSize(778, 523));

        horizontalLayout->addWidget(widget2);

        stackedWidget->addWidget(page_buyer);
        page_seller = new QWidget();
        page_seller->setObjectName(QString::fromUtf8("page_seller"));
        widget3 = new SellerWidget(page_seller);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setGeometry(QRect(10, 10, 778, 523));
        widget3->setMinimumSize(QSize(778, 523));
        widget3->setMaximumSize(QSize(778, 523));
        stackedWidget->addWidget(page_seller);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        widget = new QWidget(page);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(110, 80, 511, 311));
        stackedWidget->addWidget(page);

        retranslateUi(mainWidget);

        stackedWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(mainWidget);
    } // setupUi

    void retranslateUi(QWidget *mainWidget)
    {
        mainWidget->setWindowTitle(QCoreApplication::translate("mainWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWidget: public Ui_mainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
