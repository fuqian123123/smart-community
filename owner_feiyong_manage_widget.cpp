#include "owner_feiyong_manage_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
OwnerFeiYongManageWidget::OwnerFeiYongManageWidget()
{
    ofysw=new OwnerFeiYongSearchWidget;
    ofyaw=new OwnerFeiYongAddWidget;

    b_btn_1->setText("查询");
    b_btn_2->setText("缴费");
    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);

    connect(b_btn_1,QPushButton::clicked,this,search);
    connect(b_btn_2,QPushButton::clicked,this,jiaofei);
    connect(ofysw,ofysw->newSearch,this,this->receive);
    connect(ofyaw,ofyaw->newFeiYong,this,refresh);
    this->init();
}
void OwnerFeiYongManageWidget::init(){
    QString queryStr=QString("select "
                        " case f_type"
                        " when 1 then '物业费'"
                        " when 2 then '车位费'"
                        " when 3 then '故障维修费'"
                        " end as f_type"
                        " ,f_count,f_date"
                        " from feiyong"
                        " where f_del=0"
                        " and account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "缴费类型");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "缴费数目");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "缴费日期");
}
void OwnerFeiYongManageWidget::refresh(){
    this->init();
}

void OwnerFeiYongManageWidget::receive(const int &f_type){
    QString queryStr=QString("select"
                        " case f_type"
                        " when 1 then '物业费'"
                        " when 2 then '车位费'"
                        " when 3 then '故障维修费'"
                        " end as f_type"
                        " ,f_count,f_date"
                        " from feiyong"
                        " where f_del=0"
                        " and f_type=%1"
                        " and account_num='%2'").arg(f_type).arg(GLOBAL_ACCOUNT_NUM);
    this->load(queryStr);
    ofysw->hide();
}

void OwnerFeiYongManageWidget::search(){
    ofysw->move(550,350);
    ofysw->setWindowTitle("查询");
    ofysw->setWindowModality(Qt::ApplicationModal);
    ofysw->show();
}
void OwnerFeiYongManageWidget::jiaofei(){
    ofyaw->init();
    ofyaw->setWindowTitle("自助缴费");
    ofyaw->setWindowModality(Qt::ApplicationModal);
    ofyaw->show();
}
