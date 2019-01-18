#include "manager_renyuan_manage_widget.h"

ManagerRenYuanManageWidget::ManagerRenYuanManageWidget()
{
    //信号和槽关联
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_2,QPushButton::clicked,this,edit);
    connect(b_btn_3,QPushButton::clicked,this,detail);
    this->init();
}
void ManagerRenYuanManageWidget::init(){
    this->loadData("user");
}
void ManagerRenYuanManageWidget::add(){
    mryaw=new ManagerRenYuanAddWidget;
    mryaw->setWindowTitle("添加");
    mryaw->setWindowModality(Qt::ApplicationModal);
    mryaw->show();
}
void ManagerRenYuanManageWidget::edit(){
}
void ManagerRenYuanManageWidget::detail(){
}
