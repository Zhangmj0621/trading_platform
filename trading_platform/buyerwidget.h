#ifndef BUYERWIDGET_H
#define BUYERWIDGET_H

#include <QWidget>

namespace Ui {
class BuyerWidget;
}

class BuyerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BuyerWidget(QWidget *parent = nullptr);
    ~BuyerWidget();
private:
    Ui::BuyerWidget *ui;
};

#endif // BUYERWIDGET_H
