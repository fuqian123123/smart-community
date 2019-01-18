#ifndef BASEMANAGEWIDGET_H
#define BASEMANAGEWIDGET_H

#include <QWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>

class BaseManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseManageWidget(QWidget *parent = 0);
    ~BaseManageWidget();

private:
    QPushButton* b_btn1;
    QPushButton* b_btn2;
    QPushButton* b_btn3;
    QTableWidget* tableWidget;
    QVBoxLayout* layout;
    QHBoxLayout* b_layout;
};

#endif // BASEMANAGEWIDGET_H
