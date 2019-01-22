#include "staff_chewei_detail_widget.h"

StaffCheWeiDetailWidget::StaffCheWeiDetailWidget()
{
    label_1=new QLabel;
    label_1_1=new QLabel;
    label_2=new QLabel;
    label_2_1=new QLabel;
    label_3=new QLabel;
    label_3_1=new QLabel;
    label_4=new QLabel;
    label_4_1=new QLabel;
    label_5=new QLabel;
    label_5_1=new QLabel;
    label_6=new QLabel;
    label_6_1=new QLabel;
    label_7=new QLabel;
    label_7_1=new QLabel;
    h_layout_1=new QHBoxLayout;
    h_layout_2=new QHBoxLayout;
    h_layout_3=new QHBoxLayout;
    h_layout_4=new QHBoxLayout;
    h_layout_5=new QHBoxLayout;
    h_layout_6=new QHBoxLayout;
    h_layout_7=new QHBoxLayout;

    label_1->setText("车位号");
    label_2->setText("业主账号");
    label_3->setText("租售状态");
    label_4->setText("车位类型");
    label_5->setText("充电桩状态");
    label_6->setText("出租价格(元)");
    label_7->setText("出售价格(元)");

    //布局
    h_layout_1->addWidget(label_1,1);
    h_layout_1->addWidget(label_1_1,3);
    h_layout_2->addWidget(label_2,1);
    h_layout_2->addWidget(label_2_1,3);
    h_layout_3->addWidget(label_3,1);
    h_layout_3->addWidget(label_3_1,3);
    h_layout_4->addWidget(label_4,1);
    h_layout_4->addWidget(label_4_1,3);
    h_layout_5->addWidget(label_5,1);
    h_layout_5->addWidget(label_5_1,3);
    h_layout_6->addWidget(label_6,1);
    h_layout_6->addWidget(label_6_1,3);
    h_layout_7->addWidget(label_7,1);
    h_layout_7->addWidget(label_7_1,3);
    layout=new QVBoxLayout(this);
    layout->addLayout(h_layout_1);
    layout->addLayout(h_layout_2);
    layout->addLayout(h_layout_3);
    layout->addLayout(h_layout_4);
    layout->addLayout(h_layout_5);
    layout->addLayout(h_layout_6);
    layout->addLayout(h_layout_7);
}
bool StaffCheWeiDetailWidget::loadData(const QString &key){
    QString queryStr=QString("select pp_num"
                             ", case account_num"
                             " when '0' then '空'"
                             " else account_num"
                             " end as account_num"
                             " ,case c_status"
                             " when 0 then '待租/售'"
                             " when 1 then '已租'"
                             " when 2 then '已售'"
                             " end as c_status"
                             " ,case c_type"
                             " when 1 then '小型车位'"
                             " when 2 then '中型车位'"
                             " when 3 then '大型车位'"
                             " end as c_type"
                             " ,case c_chongdian"
                             " when 0 then '无'"
                             " when 1 then '有'"
                             " end as c_chongdian"
                             " ,c_price_1"
                             " ,c_price_2"
                             " from chewei"
                             " where pp_num=%1").arg(key.toInt());
    QSqlQuery query;
    bool flag=query.exec(queryStr);
    if(!flag){
        return false;
    }
    query.next();
    label_1_1->setText(query.value(0).toString());
    label_2_1->setText(query.value(1).toString());
    label_3_1->setText(query.value(2).toString());
    label_4_1->setText(query.value(3).toString());
    label_5_1->setText(query.value(4).toString());
    label_6_1->setText(query.value(5).toString());
    label_7_1->setText(query.value(6).toString());
    return true;
}
