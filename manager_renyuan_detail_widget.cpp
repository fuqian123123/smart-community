#include <QDebug>
#include <QSqlQuery>
#include <QMessageBox>
#include "manager_renyuan_detail_widget.h"

ManagerRenYuanDetailWidget::ManagerRenYuanDetailWidget()
{
    this->resize(350,150);
    this->setWindowIcon(QIcon(":/myres/images/icons/xiangqing.png"));

    label_1=new QLabel;
    label_1_1=new QLabel;
    label_2=new QLabel;
    label_2_1=new QLabel;
    label_3=new QLabel;
    label_3_1=new QLabel;
    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_3=new QHBoxLayout;
    layout=new QVBoxLayout(this);

    layout_1->addWidget(label_1);
    layout_1->addWidget(label_1_1);
    layout_2->addWidget(label_2);
    layout_2->addWidget(label_2_1);
    layout_3->addWidget(label_3);
    layout_3->addWidget(label_3_1);

    label_1->setText("账号");
    label_2->setText("密码");
    label_3->setText("所属人员");

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(layout_3);
}
void ManagerRenYuanDetailWidget::loadData(const QString &key){
    QSqlQuery query;
    QString str=QString("select account_num"
                        " ,case u_type"
                        " when 1 then '管理员'"
                        " when 2 then '工作人员'"
                        " when 3 then '业主'"
                        " end as u_type"
                        " ,u_password from user where account_num='%1'").arg(key);
    bool flag=query.exec(str);
    if(flag){
        query.next();
        QString accountNum=query.value(0).toString();
        QString typeStr=query.value(1).toString();
        QString password=query.value(2).toString();
        label_1_1->setText(accountNum);
        label_2_1->setText(password);
        label_3_1->setText(typeStr);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}
