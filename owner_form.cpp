#include "owner_form.h"

OwnerForm::OwnerForm(QWidget *parent) : QWidget(parent)
{
    this->resize(800,500);
    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>业主");
    //页头按钮
    h_btn_1=new QPushButton;
    h_btn_2=new QPushButton;
    h_btn_3=new QPushButton;
    h_btn_1->setText("车位管理");
    h_btn_2->setText("费用管理");
    h_btn_3->setText("维修管理");
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn_1);
    h_layout->addWidget(h_btn_2);
    h_layout->addWidget(h_btn_3);
    //页面中部
    ocwmw=new OwnerCheWeiManageWidget;
    c_stackedWidget=new QStackedWidget(this);
    c_stackedWidget->addWidget(ocwmw);
    //页面底部
    b_btn=new QPushButton;
    b_btn->setText("退出");

    //排版
    layout->addWidget(h_label);
    layout->addLayout(h_layout);
    layout->addWidget(c_stackedWidget);
    layout->addWidget(b_btn);
    //信号和槽关联
    connect(b_btn,QPushButton::clicked,this,quit);
    connect(h_btn_1,QPushButton::clicked,this,checkoutCheWei);
    connect(h_btn_2,QPushButton::clicked,this,checkoutFeiYong);
    connect(h_btn_3,QPushButton::clicked,this,checkoutGuZhang);
}
void OwnerForm::quit(){
    exit(0);
}
void OwnerForm::checkoutCheWei(){
    ocwmw->init();
}
void OwnerForm::checkoutFeiYong(){

}
void OwnerForm::checkoutGuZhang(){

}
