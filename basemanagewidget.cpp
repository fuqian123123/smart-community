#include "basemanagewidget.h"

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    layout=new QVBoxLayout(this);

    b_btn1=new QPushButton;
    b_btn2=new QPushButton;
    b_btn3=new QPushButton;
    b_btn1->setText("添加");
    b_btn2->setText("修改");
    b_btn3->setText("详情");

    b_layout=new QHBoxLayout;
    b_layout->addWidget(b_btn1);
    b_layout->addWidget(b_btn2);
    b_layout->addWidget(b_btn3);

    tableWidget=new QTableWidget;

    layout->addWidget(tableWidget);
    layout->addLayout(b_layout);
}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
