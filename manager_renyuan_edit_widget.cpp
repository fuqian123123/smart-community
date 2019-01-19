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
    radioBtn_1=new QRadioButton;
    radioBtn_2=new QRadioButton;
    radioBtn_3=new QRadioButton;
    radioBtn_1->setText("管理员");
    radioBtn_2->setText("工作人员");
    radioBtn_3->setText("业主");
    qbg=new QButtonGroup;
    qbg->addButton(radioBtn_1);
    qbg->addButton(radioBtn_2);
    qbg->addButton(radioBtn_3);
    qbg->setId(radioBtn_1,1);
    qbg->setId(radioBtn_2,2);
    qbg->setId(radioBtn_3,3);

    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_3=new QHBoxLayout;
    layout_1->addWidget(label_1,2);
    layout_1->addWidget(lineEdit_1,4);
    layout_2->addWidget(label_2,2);
    layout_2->addWidget(lineEdit_2,4);
    layout_3->addWidget(radioBtn_1);
    layout_3->addWidget(radioBtn_2);
    layout_3->addWidget(radioBtn_3);

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(layout_3);
    layout->addLayout(b_layout);

    //信号和槽关联
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
    //model初始化
    model=new QSqlTableModel(this);
}
void ManagerRenYuanEditWidget::sendSignal(){
    emit editUser();
}
void ManagerRenYuanEditWidget::loadData(const QString &accountNum){
    QSqlQuery query;
    bool flag=query.exec(QString("select u_type,u_password from user where account_num='%1'").arg(accountNum));
    if(flag){
        query.next();
        int b_id=query.value(0).toInt();
        QString password=query.value(1).toString();
        lineEdit_1->setText(accountNum);
        lineEdit_2->setText(password);
        qbg->button(b_id)->setChecked(true);
    }
}

void ManagerRenYuanEditWidget::enter(){
    if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("密码不能为空!"),QMessageBox::Ok);
        return;
    }
    QString accountNum=lineEdit_1->text();
    QString password=lineEdit_2->text();
    int type=qbg->checkedId();
    QString str=QString("update user set u_type=%1,u_password='%2' where account_num='%3'").arg(type).arg(password).arg(accountNum);
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
