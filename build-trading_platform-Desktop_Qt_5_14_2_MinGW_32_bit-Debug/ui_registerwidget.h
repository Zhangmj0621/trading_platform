/********************************************************************************
** Form generated from reading UI file 'registerwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWIDGET_H
#define UI_REGISTERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterWidget
{
public:
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *btn_register;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *btn_register_cancell;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QLineEdit *line_register_phone;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_6;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_4;
    QLineEdit *line_register_password1;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_3;
    QLineEdit *line_register_address;
    QLineEdit *line_register_password2;
    QLineEdit *line_register_username;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QWidget *RegisterWidget)
    {
        if (RegisterWidget->objectName().isEmpty())
            RegisterWidget->setObjectName(QString::fromUtf8("RegisterWidget"));
        RegisterWidget->resize(463, 304);
        RegisterWidget->setMinimumSize(QSize(463, 304));
        RegisterWidget->setMaximumSize(QSize(463, 304));
        widget_3 = new QWidget(RegisterWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(50, 240, 371, 46));
        horizontalLayout = new QHBoxLayout(widget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        btn_register = new QPushButton(widget_3);
        btn_register->setObjectName(QString::fromUtf8("btn_register"));

        horizontalLayout->addWidget(btn_register);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        btn_register_cancell = new QPushButton(widget_3);
        btn_register_cancell->setObjectName(QString::fromUtf8("btn_register_cancell"));

        horizontalLayout->addWidget(btn_register_cancell);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        label_2 = new QLabel(RegisterWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 10, 321, 17));
        label_2->setTextFormat(Qt::MarkdownText);
        label_2->setAlignment(Qt::AlignCenter);
        widget = new QWidget(RegisterWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 50, 381, 181));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        line_register_phone = new QLineEdit(widget);
        line_register_phone->setObjectName(QString::fromUtf8("line_register_phone"));

        gridLayout->addWidget(line_register_phone, 9, 3, 1, 1);

        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 9, 1, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_4, 8, 1, 1, 1);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 5, 1, 1, 1);

        line_register_password1 = new QLineEdit(widget);
        line_register_password1->setObjectName(QString::fromUtf8("line_register_password1"));

        gridLayout->addWidget(line_register_password1, 3, 3, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 7, 1, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 3, 1, 1, 1);

        line_register_address = new QLineEdit(widget);
        line_register_address->setObjectName(QString::fromUtf8("line_register_address"));

        gridLayout->addWidget(line_register_address, 7, 3, 1, 1);

        line_register_password2 = new QLineEdit(widget);
        line_register_password2->setObjectName(QString::fromUtf8("line_register_password2"));

        gridLayout->addWidget(line_register_password2, 5, 3, 1, 1);

        line_register_username = new QLineEdit(widget);
        line_register_username->setObjectName(QString::fromUtf8("line_register_username"));

        gridLayout->addWidget(line_register_username, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 4, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_5, 10, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_6, 0, 1, 1, 1);


        retranslateUi(RegisterWidget);

        QMetaObject::connectSlotsByName(RegisterWidget);
    } // setupUi

    void retranslateUi(QWidget *RegisterWidget)
    {
        RegisterWidget->setWindowTitle(QCoreApplication::translate("RegisterWidget", "Form", nullptr));
        btn_register->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214", nullptr));
        btn_register_cancell->setText(QCoreApplication::translate("RegisterWidget", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterWidget", "\346\263\250\345\206\214", nullptr));
        label->setText(QCoreApplication::translate("RegisterWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterWidget", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterWidget", "\345\206\215\346\254\241\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterWidget", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterWidget", "\345\257\206\347\240\201\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterWidget: public Ui_RegisterWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWIDGET_H
