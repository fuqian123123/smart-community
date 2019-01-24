#include <QWidget>
#include "manager_form.h"

extern QString GLOBAL_ACCOUNT_NUM;
/*管理员主界面*/
ManagerForm::ManagerForm(QWidget *parent) :
    QWidget(parent)
{
    this->resize(800,500);
    this->setWindowIcon(QIcon(":/myres/images/icons/community.png"));
    this->setWindowTitle("智慧小区");

    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>管理员");
    //页头按钮
    h_btn_1=new QPushButton;
    h_btn_2=new QPushButton;
    h_btn_3=new QPushButton;
    h_btn_1->setText("人员管理");
    h_btn_2->setText("考勤管理");
    h_btn_3->setText("月度出勤");
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn_1);
    h_layout->addWidget(h_btn_2);
    h_layout->addWidget(h_btn_3);
    //页面中部
    mrymw=new ManagerRenYuanManageWidget;
    mkqmw=new ManagerKaoQinManageWidget;
    mcqmw=new ManagerChuQinManageWidget;
    c_stackedWidget=new QStackedWidget(this);

    c_stackedWidget->addWidget(mrymw);
    c_stackedWidget->addWidget(mkqmw);
    c_stackedWidget->addWidget(mcqmw);
    //页面底部
    b_btn=new QPushButton;
    b_btn->setText("退出");

    //排版
    layout->addWidget(h_label);
    layout->addLayout(h_layout);
    layout->addWidget(c_stackedWidget);
    layout->addWidget(b_btn);

    //信号和槽关联
    connect(b_btn,QPushButton::clicked,this,quit);
    connect(h_btn_1,QPushButton::clicked,this,checkoutRenYuan);
    connect(h_btn_2,QPushButton::clicked,this,checkoutKaoQin);
    connect(h_btn_3,QPushButton::clicked,this,checkoutChuQin);
}
void ManagerForm::checkoutRenYuan(){
    int index=c_stackedWidget->currentIndex();
    if(index!=0){
        index=0;
        c_stackedWidget->setCurrentIndex(index);
    }
}
void ManagerForm::checkoutKaoQin(){
    int index=c_stackedWidget->currentIndex();
    if(index!=1){
        index=1;
        c_stackedWidget->setCurrentIndex(index);
    }
}void ManagerForm::checkoutChuQin(){
    int index=c_stackedWidget->currentIndex();
    if(index!=2){
        index=2;
        c_stackedWidget->setCurrentIndex(index);
    }
}
void ManagerForm::quit(){
    QSqlQuery query;
    QString str=QString("update user set u_flag=0"
                        " where account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("失败"),tr("退出失败!"),QMessageBox::Ok);
        return;
    }
    exit(0);
}
ManagerForm::~ManagerForm(){

}
