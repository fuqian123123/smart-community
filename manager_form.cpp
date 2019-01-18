#include <QWidget>
#include "manager_form.h"

/*管理员主界面*/
ManagerForm::ManagerForm(QWidget *parent) :
    QWidget(parent)
{
    this->resize(800,500);
    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>管理员");
    //页头按钮
    h_btn1=new QPushButton;
    h_btn2=new QPushButton;
    h_btn1->setText("人员管理");
    h_btn2->setText("考勤管理");
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn1);
    h_layout->addWidget(h_btn2);
    //页面中部
    mrymw=new ManagerRenYuanManageWidget;
    c_stackedWidget=new QStackedWidget(this);
    c_stackedWidget->addWidget(mrymw);
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

    /*layout->setMargin(0);
    layout->setSpacing(15);
    layout->setContentsMargins(10,10,10,10);*/
}
void ManagerForm::quit(){
    exit(0);
}

ManagerForm::~ManagerForm(){

}
