#ifndef BASEMANAGEWIDGET_H
#define BASEMANAGEWIDGET_H

#include <QWidget>
#include <QVBoxLayout>

class BaseManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseManageWidget(QWidget *parent = 0);
    ~BaseManageWidget();

private:
    QVBoxLayout* leftLayout;
    QVBoxLayout* rightLayout;
};

#endif // BASEMANAGEWIDGET_H
