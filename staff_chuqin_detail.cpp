#include "staff_chuqin_detail.h"

StaffChuQinDetail::StaffChuQinDetail()
{
    this->resize(350,150);
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
    label_2->setText("出勤天数");

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
}
void StaffChuQinDetail::loadData(const QString &key){
    QSqlQuery query;
    QString str=QString("SELECT account_num,COUNT(ALL account_num) AS daka_tianshu"
                             " FROM kaoqin"
                             " WHERE k_type=3"
                             " and DATE_FORMAT(k_date,'%Y%m')=DATE_FORMAT(CURDATE(),'%Y%m')"
                             " and account_num='%1'"
                             " GROUP BY (account_num)").arg(key);
    bool flag=query.exec(str);
    if(flag){
        query.next();
        QString accountNum=query.value(0).toString();
        QString days=query.value(1).toString();
        label_1_1->setText(accountNum);
        label_2_1->setText(days);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}
