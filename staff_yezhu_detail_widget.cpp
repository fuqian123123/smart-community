#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "staff_yezhu_detail_widget.h"

StaffYeZhuDetailWidget::StaffYeZhuDetailWidget()
{
    this->resize(350,150);
    this->setWindowIcon(QIcon(":/myres/images/icons/xiangqing.png"));

    label_1=new QLabel;
    label_1_1=new QLabel;
    label_2=new QLabel;
    label_2_1=new QLabel;
    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout=new QVBoxLayout(this);

    layout_1->addWidget(label_1);
    layout_1->addWidget(label_1_1);
    layout_2->addWidget(label_2);
    layout_2->addWidget(label_2_1);

    label_1->setText("账号");
    label_2->setText("密码");

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
}
void StaffYeZhuDetailWidget::loadData(const QString &key){
    QSqlQuery query;
    QString str=QString("select account_num,u_password from user where account_num='%1'").arg(key);
    bool flag=query.exec(str);
    if(flag){
        query.next();
        QString accountNum=query.value(0).toString();
        QString password=query.value(1).toString();
        label_1_1->setText(accountNum);
        label_2_1->setText(password);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}
