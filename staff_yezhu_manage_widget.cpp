#include <QMessageBox>
#include "staff_yezhu_manage_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
StaffYeZhuManageWidget::StaffYeZhuManageWidget()
{
    b_btn_4=new QPushButton;

    b_btn_1->setText("添加");
    b_btn_2->setText("修改");
    b_btn_3->setText("详情");
    b_btn_4->setText("删除");

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    b_layout->addWidget(b_btn_3);
    b_layout->addWidget(b_btn_4);

    //为关联信号和槽做准备
    syzaw=new StaffYeZhuAddWidget;
    syzew=new StaffYeZhuEditWidget;
    syzdw=new StaffYeZhuDetailWidget;

    //点击按钮信号和槽，信息刷新信号和槽
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_2,QPushButton::clicked,this,edit);
    connect(b_btn_3,QPushButton::clicked,this,detail);
    connect(b_btn_4,QPushButton::clicked,this,del);
    connect(syzaw,&StaffYeZhuAddWidget::newUser,this,refreshData);
    connect(syzew,&StaffYeZhuEditWidget::editUser,this,refreshData);
    this->init();
}
void StaffYeZhuManageWidget::init(){
    int type=3;
    QString queryStr=QString("select account_num"
                             " ,u_password "
                             " from user where u_type=%1 ").arg(type);
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "账号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "密码");
}
void StaffYeZhuManageWidget::setAccountNum(QString &str){
    int rowNum=tableView->currentIndex().row();
    QAbstractItemModel *qaim = tableView->model();
    QModelIndex qmi=qaim->index(rowNum,0);
    QVariant qv=qaim->data(qmi);
    str=qv.toString();
}
void StaffYeZhuManageWidget::add(){
    syzaw->setWindowTitle("添加");
    syzaw->setWindowModality(Qt::ApplicationModal);
    syzaw->show();
}
void StaffYeZhuManageWidget::edit(){
    QString accountNum;
    setAccountNum(accountNum);
    syzew->loadData(accountNum);
    syzew->setWindowTitle("修改");
    syzew->setWindowModality(Qt::ApplicationModal);
    syzew->show();
}
void StaffYeZhuManageWidget::detail(){
    QString accountNum;
    setAccountNum(accountNum);
    syzdw->loadData(accountNum);
    syzdw->setWindowTitle("详情");
    syzdw->setWindowModality(Qt::ApplicationModal);
    syzdw->show();
}
void StaffYeZhuManageWidget::del(){
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "警告", "确定删除?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No){
        return ;
    }
    QString accountNum;
    setAccountNum(accountNum);
    QString queryStr=QString("delete from user where account_num='%1' ").arg(accountNum);
    q_model->setQuery(queryStr);
    this->refreshData();
}
void StaffYeZhuManageWidget::refreshData(){
    this->init();
}
