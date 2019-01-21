#include "staff_chewei_manage_widget.h"

StaffCheWeiManageWidget::StaffCheWeiManageWidget()
{
    b_btn_4=new QPushButton;
    b_btn_5=new QPushButton;
    b_btn_6=new QPushButton;
    b_layout_2=new QHBoxLayout;
    label_1=new QLabel;
    label_2=new QLabel;

    label_1->setText("车位管理");
    label_2->setText("车位租售");
    b_btn_1->setText("添加");
    b_btn_2->setText("修改");
    b_btn_3->setText("查询");
    b_btn_4->setText("删除");
    b_btn_5->setText("出租");
    b_btn_6->setText("出售");

    //为关联信号和槽做准备
    scwaw=new StaffCheWeiAddWidget;

    b_layout->addWidget(label_1,2);
    b_layout->addWidget(b_btn_1,3);
    b_layout->addWidget(b_btn_2,3);
    b_layout->addWidget(b_btn_3,3);
    b_layout->addWidget(b_btn_4,3);
    b_layout_2->addWidget(label_2,1);
    b_layout_2->addWidget(b_btn_5,3);
    b_layout_2->addWidget(b_btn_6,3);
    layout->addLayout(b_layout_2);

    //为关联信号和槽做准备
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_5,QPushButton::clicked,this,chuzu);
    connect(b_btn_6,QPushButton::clicked,this,chushou);

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
                             " ,case c_chongdian"
                             " when 0 then '无'"
                             " when 1 then '有'"
                             " ,c_price_1"
                             " ,c_price_2"
                             " from chewei");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "车位号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "业主账号");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "租售状态");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "充电桩状态");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "出租价格");
    q_model->setHeaderData(5, Qt::Orientation::Horizontal, "出售价格");
}
void StaffCheWeiManageWidget::refreshData(){
    this->init();
}
void StaffCheWeiManageWidget::add(){
    scwaw->setWindowTitle("添加");
    scwaw->setWindowModality(Qt::ApplicationModal);
    scwaw->show();
}
void StaffCheWeiManageWidget::edit(){

}
void StaffCheWeiManageWidget::search(){

}
void StaffCheWeiManageWidget::del(){

}

void StaffCheWeiManageWidget::chuzu(){

}
void StaffCheWeiManageWidget::chushou(){

}
