#include "staff_feiyong_manage_widget.h"

StaffFeiYongManageWidget::StaffFeiYongManageWidget()
{
    sfysw=new StaffFeiYongSearchWidget;
    sfyaw=new StaffFeiYongAddWidget;

    b_btn_1->setText("查询");
    b_btn_2->setText("缴费");
    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);

    connect(b_btn_1,QPushButton::clicked,this,search);
    connect(b_btn_2,QPushButton::clicked,this,jiaofei);
    connect(sfysw,sfysw->newSearch,this,this->receive);
    connect(sfyaw,sfyaw->newFeiYong,this,refresh);
    this->init();
}
void StaffFeiYongManageWidget::init(){
    QString queryStr=QString("select account_num"
                        " ,case f_type"
                        " when 1 then '物业费'"
                        " when 2 then '车位费'"
                        " when 3 then '故障维修费'"
                        " end as f_type"
                        " ,f_count,f_date"
                        " from feiyong"
                        " where f_del=0");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "业主账号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "缴费类型");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "缴费数目");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "缴费日期");
}
void StaffFeiYongManageWidget::refresh(){
    this->init();
}

void StaffFeiYongManageWidget::receive(const int &f_type){
    QString queryStr=QString("select account_num"
                        " ,case f_type"
                        " when 1 then '物业费'"
                        " when 2 then '车位费'"
                        " when 3 then '故障维修费'"
                        " end as f_type"
                        " ,f_count,f_date"
                        " from feiyong"
                        " where f_del=0"
                        " and f_type=%1").arg(f_type);
    this->load(queryStr);
    sfysw->hide();
}

void StaffFeiYongManageWidget::search(){
    sfysw->move(550,350);
    sfysw->setWindowTitle("查询");
    sfysw->setWindowModality(Qt::ApplicationModal);
    sfysw->show();
}
void StaffFeiYongManageWidget::jiaofei(){
    sfyaw->init();
    sfyaw->setWindowTitle("线下缴费");
    sfyaw->setWindowModality(Qt::ApplicationModal);
    sfyaw->show();
}
