#include "managerrenyuanaddwidget.h"

MannagerRenYuanAddWidget::MannagerRenYuanAddWidget()
{
    label_1=new QLabel;
    label_2=new QLabel;
    label_1->setText("账号");
    label_2->setText("密码");
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;

    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_1->addWidget(label_1,2);
    layout_1->addWidget(lineEdit_1,4);
    layout_2->addWidget(label_2,2);
    layout_2->addWidget(lineEdit_2,4);

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(b_layout);
}
