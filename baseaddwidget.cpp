#include "baseaddwidget.h"

BaseAddWidget::BaseAddWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(350,100);
    layout=new QVBoxLayout(this);

    enter_btn=new QPushButton;
    enter_btn->setText("确定");
    clear_btn=new QPushButton;
    clear_btn->setText("清空");
    b_layout=new QHBoxLayout;
    b_layout->addWidget(enter_btn);
    b_layout->addWidget(clear_btn);
    b_layout->setMargin(10);

    //信号和槽关联
    connect(enter_btn,QPushButton::clicked,this,enter);
    connect(clear_btn,QPushButton::clicked,this,clear);
}
void BaseAddWidget::init(){

}
void BaseAddWidget::enter(){

}
void BaseAddWidget::clear(){

}
