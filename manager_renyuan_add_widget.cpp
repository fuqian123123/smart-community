#include <QMessageBox>
#include "manager_renyuan_add_widget.h"

ManagerRenYuanAddWidget::ManagerRenYuanAddWidget()
{
    label_1=new QLabel;
    label_2=new QLabel;
    label_1->setText("账号");
    label_2->setText("密码");
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;
    lineEdit_1->setFocus();

    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_1->addWidget(label_1,2);
    layout_1->addWidget(lineEdit_1,4);
    layout_2->addWidget(label_2,2);
    layout_2->addWidget(lineEdit_2,4);

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(b_layout);

    //信号和槽关联
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
}
void ManagerRenYuanAddWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("账号不能为空!"),QMessageBox::Ok);
        lineEdit_1->setFocus();
    }
    else if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("密码不能为空!"),QMessageBox::Ok);
        lineEdit_2->setFocus();
    }
}
void ManagerRenYuanAddWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
}
