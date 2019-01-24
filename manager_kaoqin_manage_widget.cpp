#include "manager_kaoqin_manage_widget.h"

ManagerKaoQinManageWidget::ManagerKaoQinManageWidget()
{
    b_btn_1->setText("批准");
    b_btn_1->setIcon(QIcon(":/myres/images/icons/pizhun.png"));
    b_btn_2->setText("驳回");
    b_btn_2->setIcon(QIcon(":/myres/images/icons/bohui.png"));
    b_btn_3->setText("查看月度出勤");
    b_btn_3->setIcon(QIcon(":/myres/images/icons/chuqin.png"));

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    //b_layout->setMargin(20);
    //为关联信号和槽做准备


    //信号和槽关联
    connect(b_btn_1,QPushButton::clicked,this,allow);
    connect(b_btn_2,QPushButton::clicked,this,reject);
    connect(this,editInfo,this,refreshData);
    this->init();
}
void ManagerKaoQinManageWidget::refreshData(){
    this->init();
}

void ManagerKaoQinManageWidget::init(){
    QString queryStr=QString("select k_id,account_num"
                             " ,case k_type when 1 then '请假'"
                             " when 2 then '销假'"
                             " when 3 then '打卡'"
                             " end as k_type"
                             " ,k_date "
                             " ,case k_allow when 0 then '未批准'"
                             " when 1 then '已批准' end as k_allow"
                             " from kaoqin"
                             " where k_type=1 or k_type=2");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "请假号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "账号");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "类型");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "日期");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "批准情况");
}
int ManagerKaoQinManageWidget::getKid(){
    int rowNum=tableView->currentIndex().row();
    QAbstractItemModel *qaim = tableView->model();
    QModelIndex qmi=qaim->index(rowNum,0);
    QVariant qv=qaim->data(qmi);
    return qv.toInt();
}

void ManagerKaoQinManageWidget::allow(){
    int k_id=getKid();
    QSqlQuery query;
    QString str=QString("update kaoqin set k_allow=%1 where k_id='%2'").arg(1).arg(k_id);
    bool flag=query.exec(str);
    if(flag){
        QMessageBox::information(this,tr("成功"),tr("已批准!"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("error!"),QMessageBox::Ok);
    }
    this->sendSigal();
}
void ManagerKaoQinManageWidget::reject(){
    int k_id=getKid();
    QSqlQuery query;
    QString str=QString("update kaoqin set k_allow=%1 where k_id='%2'").arg(0).arg(k_id);
    bool flag=query.exec(str);
    if(flag){
        QMessageBox::information(this,tr("成功"),tr("已驳回!"),QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("error!"),QMessageBox::Ok);
    }
    this->sendSigal();
}
void ManagerKaoQinManageWidget::sendSigal(){
    emit editInfo();
}
