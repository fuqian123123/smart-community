#include "owner_guzhang_manage_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
OwnerGuZhangManageWidget::OwnerGuZhangManageWidget()
{
    ogzaw=new OwnerGuZhangAddWidget;
    ogzpjw=new OwnerGuZhangPingJiaWidget;

    b_btn_1->setText("申报");
    b_btn_1->setIcon(QIcon(":/myres/images/icons/shenbao.png"));
    b_btn_2->setText("评价");
    b_btn_2->setIcon(QIcon(":/myres/images/icons/pingjia.png"));

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);

    connect(b_btn_1,QPushButton::clicked,this,shenbao);
    connect(b_btn_2,QPushButton::clicked,this,pingjia);
    connect(ogzaw,ogzaw->newGuZhang,this,refresh);
    connect(ogzpjw,ogzpjw->newGuZhang,this,refresh);
    this->init();
}
void OwnerGuZhangManageWidget::init(){
    QString queryStr=QString("select fault_num"
                             " ,case g_status when 0 then '已申报'"
                             " when 1 then '正在处理'"
                             " when 2 then '处理完成'"
                             " when 3 then '已评价'"
                             " end as g_status"
                             " ,g_reason"
                             " ,g_detail"
                             " ,g_pingjia"
                             " ,g_date"
                             " from guzhang"
                             " where g_del=0"
                             " and account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "故障号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "状态");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "故障原因");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "详情");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "评价");
    q_model->setHeaderData(5, Qt::Orientation::Horizontal, "故障申报时间");
}
void OwnerGuZhangManageWidget::shenbao(){
    ogzaw->setWindowTitle("申报");
    ogzaw->setWindowModality(Qt::ApplicationModal);
    ogzaw->show();
}
int OwnerGuZhangManageWidget::getStatus(const QString &key){
    QString faultNum;
    setMajorKey(faultNum);
    QSqlQuery query;
    QString str=QString("select g_status from guzhang"
                        " where fault_num='%1'").arg(faultNum);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("失败"),tr("加载失败!"),QMessageBox::Ok);
        return -1;
    }
    query.next();
    return query.value(0).toInt();

}

void OwnerGuZhangManageWidget::pingjia(){
    QString faultNum;
    setMajorKey(faultNum);
    int status=getStatus(faultNum);
    if(status!=2){
        QMessageBox::information(this,tr("提示"),tr("仅处理完成的维修信息可评价!"),QMessageBox::Ok);
        return ;
    }
    ogzpjw->loadData(faultNum);
    ogzpjw->setWindowTitle("评价");
    ogzpjw->setWindowModality(Qt::ApplicationModal);
    ogzpjw->show();
}

void OwnerGuZhangManageWidget::refresh(){
    this->init();
}
