#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "manager_renyuan_edit_widget.h"

ManagerRenYuanEditWidget::ManagerRenYuanEditWidget()
{
    //元素初始化
    label_1=new QLabel;
    label_2=new QLabel;
    label_1->setText("账号");
    label_2->setText("密码");
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;
    lineEdit_1->setFocusPolicy(Qt::NoFocus);//账号不可修改

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
void ManagerRenYuanEditWidget::sendSignal(){
    emit editUser();
}
void ManagerRenYuanEditWidget::loadData(const QString &accountNum){
    QSqlQuery query;
    bool flag=query.exec(QString("select u_type,u_password from user where account_num='%1'").arg(accountNum));
    if(flag){
        query.next();
        QString password=query.value(1).toString();
        lineEdit_1->setText(accountNum);
        lineEdit_2->setText(password);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}

void ManagerRenYuanEditWidget::enter(){
    if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("密码不能为空!"),QMessageBox::Ok);
        return;
    }
    QString accountNum=lineEdit_1->text();
    QString password=lineEdit_2->text();
    QString str=QString("update user set u_password='%1' where account_num='%2'").arg(password).arg(accountNum);
    QSqlQuery query;
    if(query.exec(str)){
        QMessageBox::information(this,tr("成功"),tr("修改成功!"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("失败"),tr("修改失败!"),QMessageBox::Ok);
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void ManagerRenYuanEditWidget::clear(){
    lineEdit_2->setText("");
}
