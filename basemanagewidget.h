#ifndef BASEMANAGEWIDGET_H
#define BASEMANAGEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class BaseManageWidget;
}

class BaseManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseManageWidget(QWidget *parent = 0);
    ~BaseManageWidget();

private:
    Ui::BaseManageWidget *ui;
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
};

#endif // BASEMANAGEWIDGET_H
