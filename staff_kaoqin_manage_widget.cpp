#include "staff_kaoqin_manage_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
StaffKaoQinManageWidget::StaffKaoQinManageWidget()
{
    b_btn_1->setText("打卡");
    b_btn_2->setText("请假");
    b_btn_3->setText("销假");

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    b_layout->addWidget(b_btn_3);
    //为关联信号和槽做准备
    connect(b_btn_1,QPushButton::clicked,this,daka);
    connect(b_btn_2,QPushButton::clicked,this,qingjia);
    connect(b_btn_3,QPushButton::clicked,this,xiaojia);
    //mryaw=new ManagerRenYuanAddWidget;
    //mryew=new ManagerRenYuanEditWidget;
    //mrydw=new ManagerRenYuanDetailWidget;

    this->init();
}
void StaffKaoQinManageWidget::init(){
    QString queryStr=QString("select k_id"
                             " ,case k_type when 1 then '请假'"
                             " when 2 then '销假'"
                             " when 3 then '打卡'"
                             " end as k_type"
                             " ,k_date "
                             " ,case k_allow when 0 then '未批准'"
                             " when 1 then '已批准' end as k_allow"
                             " from kaoqin"
                             " where account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "请假号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "类型");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "日期");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "批准情况");
}
void StaffKaoQinManageWidget::refreshData(){
    this->init();
}

bool StaffKaoQinManageWidget::isFree(){
    QSqlQuery query;
    QString today;
    getTodayDate(today);
    QString queryStr=QString("select count(*) from kaoqin where account_num='%1'"
                             " and k_date='%2'").arg(GLOBAL_ACCOUNT_NUM).arg(today);
    if(!query.exec(queryStr)){
        qDebug()<<query.lastError().databaseText();
    }
    query.next();
    if(query.value(0).toInt()==0)
        return true;
    return false;
}

void StaffKaoQinManageWidget::getTodayDate(QString &today){
    QDateTime current_date_time =QDateTime::currentDateTime();
    today =current_date_time.toString("yyyy-MM-dd");
}
void StaffKaoQinManageWidget::handleToday(const int &type){
    if(!isFree()){
        QMessageBox::information(this,tr("提示"),tr("今日已操作!"),QMessageBox::Ok);
        return;
    }
    QString today;
    getTodayDate(today);
    QString str=QString("insert into kaoqin (account_num,k_type,k_date)"
                        " values('%1',%2,'%3')").arg(GLOBAL_ACCOUNT_NUM)
                        .arg(type).arg(today);
    QSqlQuery query;
    if(!query.exec(str)){
        qDebug()<<query.lastError().databaseText();
        return;
    }
}
void StaffKaoQinManageWidget::qingjia(){
    handleToday(1);
    this->refreshData();
}
void StaffKaoQinManageWidget::xiaojia(){
    handleToday(2);
    this->refreshData();
}
void StaffKaoQinManageWidget::daka(){
    handleToday(3);
    this->refreshData();
}
