#include "base_search_widget.h"

BaseSearchWidget::BaseSearchWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(350,50);
    label=new QLabel;
    lineEdit=new QLineEdit;
    h_layout_1=new QHBoxLayout;
    h_layout_2=new QHBoxLayout;
    layout=new QVBoxLayout(this);
    btn_1=new QPushButton;
    btn_2=new QPushButton;

    btn_1->setText("确定");
    btn_2->setText("清空");
    lineEdit->setFocus();

    //布局
    h_layout_1->addWidget(label,1);
    h_layout_1->addWidget(lineEdit,3);
    h_layout_2->addWidget(btn_1);
    h_layout_2->addWidget(btn_2);
    layout->addLayout(h_layout_1);
    layout->addLayout(h_layout_2);
}
void BaseSearchWidget::sendSignal(){
    if(lineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("输入不能为空!"),QMessageBox::Ok);
        return;
    }
    emit entered(lineEdit->text());
}
void BaseSearchWidget::clear(){
    lineEdit->setText("");
}
