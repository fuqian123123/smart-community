#include "staff_yezhu_add_widget.h"
#include "staff_yezhu_manage_widget.h"

/*人员添加弹出页面*/
StaffYeZhuAddWidget::StaffYeZhuAddWidget()
{
    //元素初始化
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
    //model初始化
}
void StaffYeZhuAddWidget::sendSignal(){
    emit newUser();
}
void StaffYeZhuAddWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("账号不能为空!"),QMessageBox::Ok);
        lineEdit_1->setFocus();
    }
    else if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("密码不能为空!"),QMessageBox::Ok);
        lineEdit_2->setFocus();
    }
    else{
        QString accountNum=lineEdit_1->text();
        QString password=lineEdit_2->text();
        quint16 type=3;

        QString filter=QString("account_num='%1'").arg(accountNum);
        QSqlTableModel *model=new QSqlTableModel;

        model->setTable("user");
        model->setFilter(filter);
        model->select();
        if(model->rowCount()>0){
            QMessageBox::information(this,tr("错误"),tr("账号已存在!"),QMessageBox::Ok);
            lineEdit_1->setFocus();
            this->clear();
            return;
        }
        QSqlQuery query;
        query.prepare("insert into user(account_num,u_type,u_password) "
                      "values(:accountNum,:type,:password)");
        query.bindValue(":accountNum",accountNum);
        query.bindValue(":type",type);
        query.bindValue(":password",password);
        if(query.exec()){
            QMessageBox::information(this,tr("成功"),tr("添加成功!"),QMessageBox::Ok);
        }
        else
            QMessageBox::information(this,tr("失败")
            ,tr("添加失败:%1!").arg(model->lastError().text()),QMessageBox::Ok);
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void StaffYeZhuAddWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
}
