#include "manager_renyuan_manage_widget.h"

ManagerRenYuanManageWidget::ManagerRenYuanManageWidget()
{
    //为关联信号和槽做准备
    mryaw=new ManagerRenYuanAddWidget;
    mryew=new ManagerRenYuanEditWidget;

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
    /*if(model->submitAll()){
        if(model->database().commit())
            QMessageBox::information(this,tr("成功"),tr("添加成功!"),QMessageBox::Ok);
        else
            qDebug()<<model->lastError().text();
        this->clear();
    }
    else{
        model->database().rollback();
        QMessageBox::information(this,tr("失败")
        ,tr("添加失败:%1!").arg(model->lastError().text()),QMessageBox::Ok);
    }*/
}
void ManagerRenYuanManageWidget::detail(){}
