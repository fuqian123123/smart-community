#include "staff_chewei_chuzu_widget.h"

StaffCheWeiChuZuWidget::StaffCheWeiChuZuWidget()
{
    //元素初始化
    clear_btn->setText("取消");

    label_1=new QLabel;
    label_2=new QLabel;
    label_3=new QLabel;
    label_1->setText("车位号");
    label_2->setText("业主账号");
    label_3->setText("价格");
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;
    lineEdit_3=new QLineEdit;
    lineEdit_1->setFocusPolicy(Qt::NoFocus);//账号不可修改

    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_3=new QHBoxLayout;
    layout_1->addWidget(label_1,2);
    layout_1->addWidget(lineEdit_1,4);
    layout_2->addWidget(label_2,2);
    layout_2->addWidget(lineEdit_2,4);
    layout_3->addWidget(label_3,2);
    layout_3->addWidget(lineEdit_3,4);

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(layout_3);
    layout->addLayout(b_layout);

    //信号和槽关联
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,cancel);
}
void StaffCheWeiChuZuWidget::enter(){

}
void StaffCheWeiChuZuWidget::cancel(){

}
