#include "staff_form.h"

StaffForm::StaffForm(QWidget *parent) : QWidget(parent)
{
    this->resize(800,500);
    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>工作人员");
    //页头按钮
    h_btn_1=new QPushButton;
    h_btn_2=new QPushButton;
    h_btn_3=new QPushButton;
    h_btn_4=new QPushButton;
    h_btn_5=new QPushButton;
    h_btn_1->setText("业主管理");
    h_btn_2->setText("个人考勤");
    h_btn_3->setText("车位管理");
    h_btn_4->setText("费用管理");
    h_btn_5->setText("故障查询");
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn_1);
    h_layout->addWidget(h_btn_2);
    h_layout->addWidget(h_btn_3);
    h_layout->addWidget(h_btn_4);
    h_layout->addWidget(h_btn_5);
    //页面中部
    c_stackedWidget=new QStackedWidget(this);
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

}
void StaffForm::quit(){
    exit(0);
}
