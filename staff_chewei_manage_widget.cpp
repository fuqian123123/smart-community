#include "staff_chewei_manage_widget.h"

StaffCheWeiManageWidget::StaffCheWeiManageWidget()
{
    b_btn_1->setText("出租");
    b_btn_2->setText("出售");

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    //为关联信号和槽做准备
    connect(b_btn_1,QPushButton::clicked,this,chuzu);
    connect(b_btn_2,QPushButton::clicked,this,chushou);

    this->init();
}
void StaffCheWeiManageWidget::init(){
    QString queryStr=QString("select pp_num"
                             ", case account_num"
                             " when account_num is null then '空'"
                             " end as account_num"
                             " ,case c_status"
                             " when 0 then '待租/售'"
                             " when 1 then '已租'"
                             " when 2 then '已售'"
                             " end as c_status"
                             " ,c_price"
                             " from chewei");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "车位号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "业主账号");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "车位状态");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "车位价格");
}
void StaffCheWeiManageWidget::refreshData(){
    this->init();
}
void StaffCheWeiManageWidget::chuzu(){

}
void StaffCheWeiManageWidget::chushou(){

}
