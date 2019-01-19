#include "manager_renyuan_manage_widget.h"

ManagerRenYuanManageWidget::ManagerRenYuanManageWidget()
{
    b_btn_1->setText("添加");
    b_btn_2->setText("修改");
    b_btn_3->setText("详情");

    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    b_layout->addWidget(b_btn_3);
    //为关联信号和槽做准备
    mryaw=new ManagerRenYuanAddWidget;
    mryew=new ManagerRenYuanEditWidget;
    mrydw=new ManagerRenYuanDetailWidget;

    //信号和槽关联
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_2,QPushButton::clicked,this,edit);
    connect(b_btn_3,QPushButton::clicked,this,detail);
    connect(mryaw,&ManagerRenYuanAddWidget::newUser,this,refreshData);
    connect(mryew,&ManagerRenYuanEditWidget::editUser,this,refreshData);
    this->init();
}
void ManagerRenYuanManageWidget::refreshData(){
    this->init();
}
void ManagerRenYuanManageWidget::init(){
    this->loadData("user");
    model->setHeaderData(0, Qt::Orientation::Horizontal, "账号");
    model->setHeaderData(1, Qt::Orientation::Horizontal, "类型");
    model->setHeaderData(2, Qt::Orientation::Horizontal, "密码");
}
void ManagerRenYuanManageWidget::add(){
    mryaw->setWindowTitle("添加");
    mryaw->setWindowModality(Qt::ApplicationModal);
    mryaw->show();
}
void ManagerRenYuanManageWidget::edit(){
    int rowNum=tableView->currentIndex().row();
    QAbstractItemModel *qaim = tableView->model();
    QModelIndex qmi=qaim->index(rowNum,0);
    QVariant qv=qaim->data(qmi);
    QString accountNum=qv.toString();

    mryew->loadData(accountNum);
    mryew->setWindowTitle("修改");
    mryew->setWindowModality(Qt::ApplicationModal);
    mryew->show();
}
void ManagerRenYuanManageWidget::detail(){
    int rowNum=tableView->currentIndex().row();
    QAbstractItemModel *qaim = tableView->model();
    QModelIndex qmi=qaim->index(rowNum,0);
    QVariant qv=qaim->data(qmi);
    QString accountNum=qv.toString();

    mrydw->loadData(accountNum);
    mrydw->setWindowTitle("详情");
    mrydw->setWindowModality(Qt::ApplicationModal);
    mrydw->show();
}
