/********************************************************************************
** Form generated from reading UI file 'userwidgetinfo.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWIDGETINFO_H
#define UI_USERWIDGETINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWidgetInfo
{
public:
    QListWidget *listWidget;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *balancelabel;
    QLabel *addresslabel;
    QSpacerItem *horizontalSpacer_2;
    QLabel *namelabel;
    QLabel *labeladdress;
    QLabel *labelphone;
    QLabel *labelbalance;
    QLabel *labelid;
    QSpacerItem *horizontalSpacer_4;
    QLabel *phonelabel;
    QLabel *labelname;
    QLabel *idlabel;
    QPushButton *btn_revise;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout;
    QRadioButton *rbtn_user;
    QRadioButton *rbtn_phone;
    QRadioButton *rbtn_address;
    QRadioButton *rbtn_password;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *userline;
    QLineEdit *phoneline;
    QLineEdit *addressline;
    QLineEdit *passwordline;
    QLabel *label;
    QWidget *widget_6;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_2;
    QLineEdit *moneyline1;
    QSpacerItem *horizontalSpacer;
    QLineEdit *moneyline2;
    QLabel *label_3;
    QPushButton *btn_money;
    QPushButton *btn_revise_password2;
    QWidget *widget_4;
    QGridLayout *gridLayout_3;
    QLabel *label_4;
    QLineEdit *password2belowline;
    QLabel *label_5;
    QLineEdit *password2newline;
    QLabel *label_6;
    QLineEdit *password2newecholine;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *password2line;
    QLabel *label_9;
    QPushButton *btn_refresh;

    void setupUi(QWidget *UserWidgetInfo)
    {
        if (UserWidgetInfo->objectName().isEmpty())
            UserWidgetInfo->setObjectName(QString::fromUtf8("UserWidgetInfo"));
        UserWidgetInfo->resize(778, 523);
        UserWidgetInfo->setMinimumSize(QSize(778, 523));
        UserWidgetInfo->setMaximumSize(QSize(778, 523));
        listWidget = new QListWidget(UserWidgetInfo);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 10, 421, 281));
        widget = new QWidget(UserWidgetInfo);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 20, 341, 251));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        balancelabel = new QLabel(widget);
        balancelabel->setObjectName(QString::fromUtf8("balancelabel"));

        gridLayout->addWidget(balancelabel, 4, 1, 1, 1);

        addresslabel = new QLabel(widget);
        addresslabel->setObjectName(QString::fromUtf8("addresslabel"));

        gridLayout->addWidget(addresslabel, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        namelabel = new QLabel(widget);
        namelabel->setObjectName(QString::fromUtf8("namelabel"));

        gridLayout->addWidget(namelabel, 1, 1, 1, 1);

        labeladdress = new QLabel(widget);
        labeladdress->setObjectName(QString::fromUtf8("labeladdress"));

        gridLayout->addWidget(labeladdress, 3, 2, 1, 1);

        labelphone = new QLabel(widget);
        labelphone->setObjectName(QString::fromUtf8("labelphone"));

        gridLayout->addWidget(labelphone, 2, 2, 1, 1);

        labelbalance = new QLabel(widget);
        labelbalance->setObjectName(QString::fromUtf8("labelbalance"));

        gridLayout->addWidget(labelbalance, 4, 2, 1, 1);

        labelid = new QLabel(widget);
        labelid->setObjectName(QString::fromUtf8("labelid"));

        gridLayout->addWidget(labelid, 0, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        phonelabel = new QLabel(widget);
        phonelabel->setObjectName(QString::fromUtf8("phonelabel"));

        gridLayout->addWidget(phonelabel, 2, 1, 1, 1);

        labelname = new QLabel(widget);
        labelname->setObjectName(QString::fromUtf8("labelname"));

        gridLayout->addWidget(labelname, 1, 2, 1, 1);

        idlabel = new QLabel(widget);
        idlabel->setObjectName(QString::fromUtf8("idlabel"));

        gridLayout->addWidget(idlabel, 0, 1, 1, 1);

        btn_revise = new QPushButton(UserWidgetInfo);
        btn_revise->setObjectName(QString::fromUtf8("btn_revise"));
        btn_revise->setGeometry(QRect(560, 260, 93, 28));
        widget_5 = new QWidget(UserWidgetInfo);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setGeometry(QRect(470, 10, 271, 151));
        horizontalLayout = new QHBoxLayout(widget_5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_2 = new QWidget(widget_5);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout = new QVBoxLayout(widget_2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        rbtn_user = new QRadioButton(widget_2);
        rbtn_user->setObjectName(QString::fromUtf8("rbtn_user"));
        rbtn_user->setChecked(false);

        verticalLayout->addWidget(rbtn_user);

        rbtn_phone = new QRadioButton(widget_2);
        rbtn_phone->setObjectName(QString::fromUtf8("rbtn_phone"));

        verticalLayout->addWidget(rbtn_phone);

        rbtn_address = new QRadioButton(widget_2);
        rbtn_address->setObjectName(QString::fromUtf8("rbtn_address"));

        verticalLayout->addWidget(rbtn_address);

        rbtn_password = new QRadioButton(widget_2);
        rbtn_password->setObjectName(QString::fromUtf8("rbtn_password"));

        verticalLayout->addWidget(rbtn_password);


        horizontalLayout->addWidget(widget_2);

        widget_3 = new QWidget(widget_5);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        userline = new QLineEdit(widget_3);
        userline->setObjectName(QString::fromUtf8("userline"));

        verticalLayout_3->addWidget(userline);

        phoneline = new QLineEdit(widget_3);
        phoneline->setObjectName(QString::fromUtf8("phoneline"));

        verticalLayout_3->addWidget(phoneline);

        addressline = new QLineEdit(widget_3);
        addressline->setObjectName(QString::fromUtf8("addressline"));

        verticalLayout_3->addWidget(addressline);

        passwordline = new QLineEdit(widget_3);
        passwordline->setObjectName(QString::fromUtf8("passwordline"));

        verticalLayout_3->addWidget(passwordline);


        horizontalLayout->addWidget(widget_3);

        label = new QLabel(UserWidgetInfo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 310, 72, 15));
        widget_6 = new QWidget(UserWidgetInfo);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setGeometry(QRect(10, 350, 431, 81));
        gridLayout_2 = new QGridLayout(widget_6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        label_2 = new QLabel(widget_6);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);

        moneyline1 = new QLineEdit(widget_6);
        moneyline1->setObjectName(QString::fromUtf8("moneyline1"));

        gridLayout_2->addWidget(moneyline1, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 1, 1, 1);

        moneyline2 = new QLineEdit(widget_6);
        moneyline2->setObjectName(QString::fromUtf8("moneyline2"));

        gridLayout_2->addWidget(moneyline2, 2, 2, 1, 1);

        label_3 = new QLabel(widget_6);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 2, 2);

        btn_money = new QPushButton(UserWidgetInfo);
        btn_money->setObjectName(QString::fromUtf8("btn_money"));
        btn_money->setGeometry(QRect(190, 440, 93, 28));
        btn_revise_password2 = new QPushButton(UserWidgetInfo);
        btn_revise_password2->setObjectName(QString::fromUtf8("btn_revise_password2"));
        btn_revise_password2->setGeometry(QRect(540, 440, 101, 28));
        widget_4 = new QWidget(UserWidgetInfo);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(440, 340, 331, 93));
        gridLayout_3 = new QGridLayout(widget_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_4 = new QLabel(widget_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        password2belowline = new QLineEdit(widget_4);
        password2belowline->setObjectName(QString::fromUtf8("password2belowline"));
        password2belowline->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(password2belowline, 0, 1, 1, 1);

        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        password2newline = new QLineEdit(widget_4);
        password2newline->setObjectName(QString::fromUtf8("password2newline"));
        password2newline->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(password2newline, 1, 1, 1, 1);

        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        password2newecholine = new QLineEdit(widget_4);
        password2newecholine->setObjectName(QString::fromUtf8("password2newecholine"));
        password2newecholine->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(password2newecholine, 2, 1, 1, 1);

        label_7 = new QLabel(UserWidgetInfo);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(460, 310, 101, 16));
        label_8 = new QLabel(UserWidgetInfo);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(480, 170, 121, 16));
        password2line = new QLineEdit(UserWidgetInfo);
        password2line->setObjectName(QString::fromUtf8("password2line"));
        password2line->setGeometry(QRect(480, 210, 181, 21));
        password2line->setEchoMode(QLineEdit::Password);
        label_9 = new QLabel(UserWidgetInfo);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(510, 490, 221, 16));
        btn_refresh = new QPushButton(UserWidgetInfo);
        btn_refresh->setObjectName(QString::fromUtf8("btn_refresh"));
        btn_refresh->setGeometry(QRect(10, 480, 93, 28));

        retranslateUi(UserWidgetInfo);

        QMetaObject::connectSlotsByName(UserWidgetInfo);
    } // setupUi

    void retranslateUi(QWidget *UserWidgetInfo)
    {
        UserWidgetInfo->setWindowTitle(QCoreApplication::translate("UserWidgetInfo", "Form", nullptr));
        balancelabel->setText(QCoreApplication::translate("UserWidgetInfo", "\351\222\261\345\214\205\344\275\231\351\242\235\357\274\232", nullptr));
        addresslabel->setText(QCoreApplication::translate("UserWidgetInfo", "\345\234\260\345\235\200\357\274\232", nullptr));
        namelabel->setText(QCoreApplication::translate("UserWidgetInfo", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        labeladdress->setText(QCoreApplication::translate("UserWidgetInfo", "TextLabel", nullptr));
        labelphone->setText(QCoreApplication::translate("UserWidgetInfo", "TextLabel", nullptr));
        labelbalance->setText(QCoreApplication::translate("UserWidgetInfo", "TextLabel", nullptr));
        labelid->setText(QCoreApplication::translate("UserWidgetInfo", "TextLabel", nullptr));
        phonelabel->setText(QCoreApplication::translate("UserWidgetInfo", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        labelname->setText(QCoreApplication::translate("UserWidgetInfo", "TextLabel", nullptr));
        idlabel->setText(QCoreApplication::translate("UserWidgetInfo", "\347\224\250\346\210\267id\357\274\232", nullptr));
        btn_revise->setText(QCoreApplication::translate("UserWidgetInfo", "\344\277\256\346\224\271", nullptr));
        rbtn_user->setText(QCoreApplication::translate("UserWidgetInfo", "\347\224\250\346\210\267\345\220\215", nullptr));
        rbtn_phone->setText(QCoreApplication::translate("UserWidgetInfo", "\350\201\224\347\263\273\346\226\271\345\274\217", nullptr));
        rbtn_address->setText(QCoreApplication::translate("UserWidgetInfo", "\345\234\260\345\235\200", nullptr));
        rbtn_password->setText(QCoreApplication::translate("UserWidgetInfo", "\345\257\206\347\240\201", nullptr));
        label->setText(QCoreApplication::translate("UserWidgetInfo", "\345\205\205\345\200\274", nullptr));
        label_2->setText(QCoreApplication::translate("UserWidgetInfo", "\350\257\267\350\276\223\345\205\245\346\202\250\350\246\201\345\205\205\345\200\274\347\232\204\346\225\260\351\242\235\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("UserWidgetInfo", "\350\257\267\345\234\250\346\254\241\350\276\223\345\205\245\346\202\250\350\246\201\345\205\205\345\200\274\347\232\204\346\225\260\351\242\235\357\274\232", nullptr));
        btn_money->setText(QCoreApplication::translate("UserWidgetInfo", "\347\241\256\350\256\244\345\205\205\345\200\274", nullptr));
        btn_revise_password2->setText(QCoreApplication::translate("UserWidgetInfo", "\344\277\256\346\224\271\344\272\214\347\272\247\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("UserWidgetInfo", "\350\257\267\350\276\223\345\205\245\346\202\250\345\216\237\345\205\210\347\232\204\344\272\214\347\272\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("UserWidgetInfo", "\350\257\267\350\276\223\345\205\245\346\226\260\347\232\204\344\272\214\347\272\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("UserWidgetInfo", "\347\241\256\350\256\244\346\202\250\347\232\204\346\226\260\344\272\214\347\272\247\345\257\206\347\240\201\357\274\232", nullptr));
        label_7->setText(QCoreApplication::translate("UserWidgetInfo", "\344\277\256\346\224\271\344\272\214\347\272\247\345\257\206\347\240\201", nullptr));
        label_8->setText(QCoreApplication::translate("UserWidgetInfo", "\350\276\223\345\205\245\344\272\214\347\272\247\345\257\206\347\240\201\345\244\204", nullptr));
        label_9->setText(QCoreApplication::translate("UserWidgetInfo", "\346\263\250\357\274\232\345\210\235\345\247\213\344\272\214\347\272\247\345\257\206\347\240\201\351\273\230\350\256\244\344\270\272123", nullptr));
        btn_refresh->setText(QCoreApplication::translate("UserWidgetInfo", "\345\210\267\346\226\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWidgetInfo: public Ui_UserWidgetInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWIDGETINFO_H
