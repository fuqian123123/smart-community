#include "manager_chuqin_manage_widget.h"

ManagerChuQinManageWidget::ManagerChuQinManageWidget()
{
    this->init();
}
void ManagerChuQinManageWidget::init(){
    QString queryStr=QString("SELECT account_num,COUNT(ALL account_num) AS daka_tianshu"
                             " FROM kaoqin"
                             " WHERE k_type=3"
                             " and DATE_FORMAT(k_date,'%Y%m')=DATE_FORMAT(CURDATE(),'%Y%m')"
                             " GROUP BY (account_num)");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "账号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "出勤天数");
}
