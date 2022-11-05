/********************************************************************************
** Form generated from reading UI file 'sellerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWIDGET_H
#define UI_SELLERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerWidget
{
public:
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_modity_release;
    QTableWidget *tableWidget_modity;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_moditynumber;
    QLineEdit *lineEdit_moditydescprition;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_4;
    QLineEdit *lineEdit_modityname;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_modityprice;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn_release1;
    QPushButton *btn_release;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_modity_view;
    QTableWidget *tableWidget_all_modity;
    QPushButton *btn_deletemodity;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_name;
    QRadioButton *rbtn_price;
    QRadioButton *rbtn_description;
    QRadioButton *rbtn_number;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *line_name;
    QLineEdit *line_price;
    QLineEdit *line_description;
    QLineEdit *line_number;
    QTableWidget *tableWidget_modity_revise;
    QPushButton *btn_revise1;
    QPushButton *btn_revise;
    QPushButton *btn_recovermodity;
    QPushButton *btn_refresh_1;
    QWidget *tab_order;
    QTableWidget *tableWidget_order;
    QPushButton *btn_refresh_2;

    void setupUi(QWidget *SellerWidget)
    {
        if (SellerWidget->objectName().isEmpty())
            SellerWidget->setObjectName(QString::fromUtf8("SellerWidget"));
        SellerWidget->resize(778, 523);
        SellerWidget->setMinimumSize(QSize(778, 523));
        SellerWidget->setMaximumSize(QSize(778, 523));
        horizontalLayout = new QHBoxLayout(SellerWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tabWidget = new QTabWidget(SellerWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_modity_release = new QWidget();
        tab_modity_release->setObjectName(QString::fromUtf8("tab_modity_release"));
        tableWidget_modity = new QTableWidget(tab_modity_release);
        tableWidget_modity->setObjectName(QString::fromUtf8("tableWidget_modity"));
        tableWidget_modity->setGeometry(QRect(380, 90, 331, 251));
        widget = new QWidget(tab_modity_release);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 90, 315, 251));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_moditynumber = new QLineEdit(widget);
        lineEdit_moditynumber->setObjectName(QString::fromUtf8("lineEdit_moditynumber"));

        gridLayout->addWidget(lineEdit_moditynumber, 3, 3, 1, 1);

        lineEdit_moditydescprition = new QLineEdit(widget);
        lineEdit_moditydescprition->setObjectName(QString::fromUtf8("lineEdit_moditydescprition"));

        gridLayout->addWidget(lineEdit_moditydescprition, 4, 3, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 4, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 1, 1, 1);

        lineEdit_modityname = new QLineEdit(widget);
        lineEdit_modityname->setObjectName(QString::fromUtf8("lineEdit_modityname"));

        gridLayout->addWidget(lineEdit_modityname, 0, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 0, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        lineEdit_modityprice = new QLineEdit(widget);
        lineEdit_modityprice->setObjectName(QString::fromUtf8("lineEdit_modityprice"));

        gridLayout->addWidget(lineEdit_modityprice, 2, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        btn_release1 = new QPushButton(tab_modity_release);
        btn_release1->setObjectName(QString::fromUtf8("btn_release1"));
        btn_release1->setGeometry(QRect(130, 360, 93, 28));
        btn_release = new QPushButton(tab_modity_release);
        btn_release->setObjectName(QString::fromUtf8("btn_release"));
        btn_release->setGeometry(QRect(500, 360, 93, 28));
        label_5 = new QLabel(tab_modity_release);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(380, 60, 151, 16));
        label_6 = new QLabel(tab_modity_release);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 60, 181, 16));
        tabWidget->addTab(tab_modity_release, QString());
        tab_modity_view = new QWidget();
        tab_modity_view->setObjectName(QString::fromUtf8("tab_modity_view"));
        tableWidget_all_modity = new QTableWidget(tab_modity_view);
        tableWidget_all_modity->setObjectName(QString::fromUtf8("tableWidget_all_modity"));
        tableWidget_all_modity->setGeometry(QRect(310, 50, 421, 411));
        btn_deletemodity = new QPushButton(tab_modity_view);
        btn_deletemodity->setObjectName(QString::fromUtf8("btn_deletemodity"));
        btn_deletemodity->setGeometry(QRect(40, 30, 93, 28));
        widget_5 = new QWidget(tab_modity_view);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(20, 60, 271, 151));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbtn_name = new QRadioButton(widget_2);
        rbtn_name->setObjectName(QString::fromUtf8("rbtn_name"));
        rbtn_name->setChecked(false);

        verticalLayout->addWidget(rbtn_name);

        rbtn_price = new QRadioButton(widget_2);
        rbtn_price->setObjectName(QString::fromUtf8("rbtn_price"));

        verticalLayout->addWidget(rbtn_price);

        rbtn_description = new QRadioButton(widget_2);
        rbtn_description->setObjectName(QString::fromUtf8("rbtn_description"));

        verticalLayout->addWidget(rbtn_description);

        rbtn_number = new QRadioButton(widget_2);
        rbtn_number->setObjectName(QString::fromUtf8("rbtn_number"));

        verticalLayout->addWidget(rbtn_number);


        horizontalLayout_2->addWidget(widget_2);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        line_name = new QLineEdit(widget_3);
        line_name->setObjectName(QString::fromUtf8("line_name"));

        verticalLayout_3->addWidget(line_name);

        line_price = new QLineEdit(widget_3);
        line_price->setObjectName(QString::fromUtf8("line_price"));

        verticalLayout_3->addWidget(line_price);

        line_description = new QLineEdit(widget_3);
        line_description->setObjectName(QString::fromUtf8("line_description"));

        verticalLayout_3->addWidget(line_description);

        line_number = new QLineEdit(widget_3);
        line_number->setObjectName(QString::fromUtf8("line_number"));

        verticalLayout_3->addWidget(line_number);


        horizontalLayout_2->addWidget(widget_3);

        tableWidget_modity_revise = new QTableWidget(tab_modity_view);
        tableWidget_modity_revise->setObjectName(QString::fromUtf8("tableWidget_modity_revise"));
        tableWidget_modity_revise->setGeometry(QRect(20, 270, 256, 192));
        btn_revise1 = new QPushButton(tab_modity_view);
        btn_revise1->setObjectName(QString::fromUtf8("btn_revise1"));
        btn_revise1->setGeometry(QRect(20, 230, 93, 28));
        btn_revise = new QPushButton(tab_modity_view);
        btn_revise->setObjectName(QString::fromUtf8("btn_revise"));
        btn_revise->setGeometry(QRect(160, 230, 93, 28));
        btn_recovermodity = new QPushButton(tab_modity_view);
        btn_recovermodity->setObjectName(QString::fromUtf8("btn_recovermodity"));
        btn_recovermodity->setGeometry(QRect(160, 30, 93, 28));
        btn_refresh_1 = new QPushButton(tab_modity_view);
        btn_refresh_1->setObjectName(QString::fromUtf8("btn_refresh_1"));
        btn_refresh_1->setGeometry(QRect(640, 10, 93, 28));
        tabWidget->addTab(tab_modity_view, QString());
        tab_order = new QWidget();
        tab_order->setObjectName(QString::fromUtf8("tab_order"));
        tableWidget_order = new QTableWidget(tab_order);
        tableWidget_order->setObjectName(QString::fromUtf8("tableWidget_order"));
        tableWidget_order->setGeometry(QRect(60, 50, 651, 411));
        btn_refresh_2 = new QPushButton(tab_order);
        btn_refresh_2->setObjectName(QString::fromUtf8("btn_refresh_2"));
        btn_refresh_2->setGeometry(QRect(630, 10, 93, 28));
        tabWidget->addTab(tab_order, QString());

        horizontalLayout->addWidget(tabWidget);


        retranslateUi(SellerWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SellerWidget);
    } // setupUi

    void retranslateUi(QWidget *SellerWidget)
    {
        SellerWidget->setWindowTitle(QCoreApplication::translate("SellerWidget", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\346\225\260\351\207\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\346\217\217\350\277\260\357\274\232", nullptr));
        label->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\350\276\223\345\205\245\345\225\206\345\223\201\344\273\267\346\240\274\357\274\232", nullptr));
        btn_release1->setText(QCoreApplication::translate("SellerWidget", "\351\242\204\345\217\221\345\270\203", nullptr));
        btn_release->setText(QCoreApplication::translate("SellerWidget", "\345\217\221\345\270\203", nullptr));
        label_5->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\347\241\256\350\256\244\346\202\250\347\232\204\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        label_6->setText(QCoreApplication::translate("SellerWidget", "\350\257\267\350\276\223\345\205\245\346\202\250\350\246\201\345\217\221\345\270\203\347\232\204\345\225\206\345\223\201\344\277\241\346\201\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_modity_release), QCoreApplication::translate("SellerWidget", "\345\217\221\345\270\203\345\225\206\345\223\201", nullptr));
        btn_deletemodity->setText(QCoreApplication::translate("SellerWidget", "\344\270\213\346\236\266", nullptr));
        rbtn_name->setText(QCoreApplication::translate("SellerWidget", "\345\225\206\345\223\201\345\220\215\347\247\260", nullptr));
        rbtn_price->setText(QCoreApplication::translate("SellerWidget", "\344\273\267\346\240\274", nullptr));
        rbtn_description->setText(QCoreApplication::translate("SellerWidget", "\346\217\217\350\277\260", nullptr));
        rbtn_number->setText(QCoreApplication::translate("SellerWidget", "\346\225\260\351\207\217", nullptr));
        btn_revise1->setText(QCoreApplication::translate("SellerWidget", "\351\242\204\344\277\256\346\224\271", nullptr));
        btn_revise->setText(QCoreApplication::translate("SellerWidget", "\344\277\256\346\224\271", nullptr));
        btn_recovermodity->setText(QCoreApplication::translate("SellerWidget", "\344\270\212\346\236\266", nullptr));
        btn_refresh_1->setText(QCoreApplication::translate("SellerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_modity_view), QCoreApplication::translate("SellerWidget", "\344\277\256\346\224\271\345\225\206\345\223\201", nullptr));
        btn_refresh_2->setText(QCoreApplication::translate("SellerWidget", "\345\210\267\346\226\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_order), QCoreApplication::translate("SellerWidget", "\350\256\242\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SellerWidget: public Ui_SellerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWIDGET_H
