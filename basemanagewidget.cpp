#include "basemanagewidget.h"
#include "ui_basemanagewidget.h"
#include <QLabel>
#include <QLineEdit>
#include <QTableView>
#include <QHBoxLayout>

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BaseManageWidget)
{
    ui->setupUi(this);

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

    leftLayout->addLayout(l_layout1);
    leftLayout->addLayout(l_layout2);

    QTableView* tableView=new QTableView;
    rightLayout->addWidget(tableView);

    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->addLayout(leftLayout);
    layout->addLayout(rightLayout);
}

BaseManageWidget::~BaseManageWidget()
{
    delete ui;
}
