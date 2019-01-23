#include "staff_guzhang_manage_widget.h"

StaffGuZhangManageWidget::StaffGuZhangManageWidget()
{
    b_btn_1->setText("更新故障维修情况");
    sgzew=new StaffGuZhangEditWidget;

    b_layout->addWidget(b_btn_1);
    this->init();

    connect(sgzew,sgzew->editGuZhang,this,refresh);
    connect(b_btn_1,QPushButton::clicked,this,gengxin);
}
void StaffGuZhangManageWidget::init(){
    QString queryStr=QString("select fault_num,account_num"
                             " ,case g_status when 0 then '已申报'"
                             " when 1 then '正在处理'"
                             " when 2 then '已评价'"
                             " end as g_status"
                             " ,g_detail"
                             " ,g_reason"
                             " from guzhang"
                             " where g_del=0");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "故障号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "申报业主账号");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "状态");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "详情");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "故障原因");
}

void StaffGuZhangManageWidget::refresh(){
    this->init();
}
void StaffGuZhangManageWidget::gengxin(){
    QString key;
    setMajorKey(key);
    int status=sgzew->getStatus(key);
    if(status==3){
        QMessageBox::information(this,tr("提示"),tr("该维修信息已评价!"),QMessageBox::Ok);
    }
    sgzew->loadData(key);
    sgzew->setWindowTitle("更新");
    sgzew->setWindowModality(Qt::ApplicationModal);
    sgzew->show();
}
