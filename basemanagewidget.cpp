#include "basemanagewidget.h"
#include "ui_basemanagewidget.h"
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTableWidget>
#include <QHBoxLayout>

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    leftLayout=new QVBoxLayout;
    rightLayout=new QVBoxLayout;

    QHBoxLayout* l_layout1=new QHBoxLayout();
    QLabel* l_label1=new QLabel;
    l_label1->setText("测试");
    QLineEdit* l_lineEdit1=new QLineEdit;
    l_layout1->addWidget(l_label1,2,Qt::AlignLeft);
    l_layout1->addWidget(l_lineEdit1,4,Qt::AlignRight);

    QHBoxLayout* l_layout2=new QHBoxLayout();
    QLabel* l_label2=new QLabel;
    l_label2->setText("测试2");
    QLineEdit* l_lineEdit2=new QLineEdit;
    l_layout2->addWidget(l_label2,2,Qt::AlignLeft);
    l_layout2->addWidget(l_lineEdit2,4,Qt::AlignRight);

    QHBoxLayout* l_b_layout=new QHBoxLayout();
    QPushButton* enter=new QPushButton;
    enter->setText("确定");
    QPushButton* clear=new QPushButton;
    clear->setText("清空");
    l_b_layout->setMargin(10);
    l_b_layout->addWidget(enter);
    l_b_layout->addWidget(clear);

    leftLayout->addLayout(l_layout1);
    leftLayout->addLayout(l_layout2);
    leftLayout->addLayout(l_b_layout);

    QTableWidget* tableWidget=new QTableWidget;
    rightLayout->addWidget(tableWidget);

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->addLayout(leftLayout,2);
    layout->addLayout(rightLayout,5);
}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
