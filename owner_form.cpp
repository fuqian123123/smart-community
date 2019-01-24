#include "owner_form.h"

extern QString GLOBAL_ACCOUNT_NUM;
OwnerForm::OwnerForm(QWidget *parent) : QWidget(parent)
{
    this->resize(800,500);
    this->setWindowIcon(QIcon(":/myres/images/icons/community.png"));
    this->setWindowTitle("智慧小区");

    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>业主");
    //页头按钮
    h_btn_1=new QPushButton;
    h_btn_2=new QPushButton;
    h_btn_3=new QPushButton;
    h_btn_1->setText("车位管理");
    h_btn_1->setIcon(QIcon(":/myres/images/icons/chewei.png"));
    h_btn_2->setText("费用管理");
    h_btn_2->setIcon(QIcon(":/myres/images/icons/feiyong.png"));
    h_btn_3->setText("维修管理");
    h_btn_3->setIcon(QIcon(":/myres/images/icons/weixiu.png"));
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn_1);
    h_layout->addWidget(h_btn_2);
    h_layout->addWidget(h_btn_3);
    //页面中部
    ocwmw=new OwnerCheWeiManageWidget;
    ofymw=new OwnerFeiYongManageWidget;
    ogzmw=new OwnerGuZhangManageWidget;
    c_stackedWidget=new QStackedWidget(this);
    c_stackedWidget->addWidget(ocwmw);
    c_stackedWidget->addWidget(ofymw);
    c_stackedWidget->addWidget(ogzmw);
    //页面底部
    b_btn=new QPushButton;
    b_btn->setIcon(QIcon(":/myres/images/icons/tuichu.png"));
    b_btn->setText("退出");

    //排版
    layout->addWidget(h_label);
    layout->addLayout(h_layout);
    layout->addWidget(c_stackedWidget);
    layout->addWidget(b_btn);
    //信号和槽关联
    connect(b_btn,QPushButton::clicked,this,quit);
    connect(h_btn_1,QPushButton::clicked,this,checkoutCheWei);
    connect(h_btn_2,QPushButton::clicked,this,checkoutFeiYong);
    connect(h_btn_3,QPushButton::clicked,this,checkoutGuZhang);
}
void OwnerForm::checkout(const int &num){
    int index=c_stackedWidget->currentIndex();
    if(index!=num){
        index=num;
        c_stackedWidget->setCurrentIndex(index);
    }
}
void OwnerForm::checkoutCheWei(){
    ocwmw->init();
    checkout(0);
}
void OwnerForm::checkoutFeiYong(){
    checkout(1);
}
void OwnerForm::checkoutGuZhang(){
    checkout(2);
}
void OwnerForm::quit(){
    QSqlQuery query;
    QString str=QString("update user set u_flag=0"
                        " where account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("失败"),tr("退出失败!"),QMessageBox::Ok);
        return;
    }
    this->hide();
}
