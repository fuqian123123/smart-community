#include "base_add_widget.h"

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
}
void BaseAddWidget::init(){
}

void BaseAddWidget::enter(){
}
void BaseAddWidget::clear(){
}
