#include "staff_form.h"

extern QString GLOBAL_ACCOUNT_NUM;
StaffForm::StaffForm(QWidget *parent) : QWidget(parent)
{
    this->resize(800,500);
    this->setWindowIcon(QIcon(":/myres/images/icons/community.png"));
    this->setWindowTitle("智慧小区");

    layout=new QVBoxLayout(this);
    //页头
    h_label=new QLabel;
    h_label->setText("智慧小区>工作人员");
    //页头按钮
    h_btn_1=new QPushButton;
    h_btn_2=new QPushButton;
    h_btn_3=new QPushButton;
    h_btn_4=new QPushButton;
    h_btn_5=new QPushButton;
    h_btn_1->setText("业主管理");
    h_btn_1->setIcon(QIcon(":/myres/images/icons/renyuan.png"));
    h_btn_2->setText("个人考勤");
    h_btn_2->setIcon(QIcon(":/myres/images/icons/kaoqin.png"));
    h_btn_3->setText("车位管理");
    h_btn_3->setIcon(QIcon(":/myres/images/icons/chewei.png"));
    h_btn_4->setText("费用管理");
    h_btn_4->setIcon(QIcon(":/myres/images/icons/feiyong.png"));
    h_btn_5->setText("故障管理");
    h_btn_5->setIcon(QIcon(":/myres/images/icons/weixiu.png"));
    h_layout=new QHBoxLayout();
    h_layout->addWidget(h_btn_1);
    h_layout->addWidget(h_btn_2);
    h_layout->addWidget(h_btn_3);
    h_layout->addWidget(h_btn_4);
    h_layout->addWidget(h_btn_5);
    //页面中部
    syzmw=new StaffYeZhuManageWidget;
    skqmw=new StaffKaoQinManageWidget;
    scwmw=new StaffCheWeiManageWidget;
    sfymw=new StaffFeiYongManageWidget;
    sgzmw=new StaffGuZhangManageWidget;
    c_stackedWidget=new QStackedWidget(this);

    c_stackedWidget->addWidget(syzmw);
    c_stackedWidget->addWidget(skqmw);
    c_stackedWidget->addWidget(scwmw);
    c_stackedWidget->addWidget(sfymw);
    c_stackedWidget->addWidget(sgzmw);
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
    connect(h_btn_1,QPushButton::clicked,this,checkoutYeZhu);
    connect(h_btn_2,QPushButton::clicked,this,checkoutKaoQin);
    connect(h_btn_3,QPushButton::clicked,this,checkoutCheWei);
    connect(h_btn_4,QPushButton::clicked,this,checkoutFeiYong);
    connect(h_btn_5,QPushButton::clicked,this,checkoutGuZhang);

}
void StaffForm::checkout(const int &num){
    int index=c_stackedWidget->currentIndex();
    if(index!=num){
        index=num;
        c_stackedWidget->setCurrentIndex(index);
    }
}
void StaffForm::checkoutYeZhu(){
    checkout(0);
}
void StaffForm::checkoutKaoQin(){
    checkout(1);
}
void StaffForm::checkoutCheWei(){
    checkout(2);
}
void StaffForm::checkoutFeiYong(){
    checkout(3);
}
void StaffForm::checkoutGuZhang(){
    checkout(4);
}

void StaffForm::quit(){
    QSqlQuery query;
    QString str=QString("update user set u_flag=0"
                        " where account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("失败"),tr("退出失败!"),QMessageBox::Ok);
        return;
    }
    this->hide();
}
