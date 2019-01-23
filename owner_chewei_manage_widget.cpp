#include "owner_chewei_manage_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
OwnerCheWeiManageWidget::OwnerCheWeiManageWidget()
{
    b_btn_1=new QPushButton;
    b_btn_2=new QPushButton;
    b_btn_3=new QPushButton;
    b_btn_4=new QPushButton;

    b_btn_1->setText("申请租赁");
    b_btn_2->setText("申请购买");
    b_btn_3->setText("我的申请");
    b_btn_4->setText("车位信息");

    b_layout->addWidget(b_btn_1,1);
    b_layout->addWidget(b_btn_2,1);
    b_layout->addWidget(b_btn_4,1);
    b_layout->addWidget(b_btn_3,1);
    //为关联信号和槽做准备
    connect(b_btn_1,QPushButton::clicked,this,shenqingzulin);
    connect(b_btn_2,QPushButton::clicked,this,shenqinggoumai);
    connect(b_btn_3,QPushButton::clicked,this,wodeshenqing);
    connect(b_btn_4,QPushButton::clicked,this,cheweixinxi);
    this->init();
}
void OwnerCheWeiManageWidget::init(){
    b_btn_1->show();
    b_btn_2->show();
    b_btn_3->show();
    b_btn_4->hide();
    QString queryStr=QString("select pp_num"
                             " ,case c_type"
                             " when 1 then '小型车位'"
                             " when 2 then '中型车位'"
                             " when 3 then '大型车位'"
                             " end as c_type"
                             " ,case c_chongdian"
                             " when 0 then '无'"
                             " when 1 then '有'"
                             " end as c_chongdian"
                             " ,c_price_1"
                             " ,c_price_2"
                             " from chewei"
                             " where c_del=0"
                             " and c_status=0");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "车位号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "车位类型");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "充电桩状态");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "出租价格(元)");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "出售价格(元)");
}
void OwnerCheWeiManageWidget::cheweixinxi(){
    this->init();
}

void OwnerCheWeiManageWidget::refreshData(){
    this->init();
}
void OwnerCheWeiManageWidget::shenqing(int type){
    QString info=type==1?"租赁":"购买";
    QString ppNum;
    setMajorKey(ppNum);
    QSqlQuery query;
    QString str=QString("insert into chewei_shenqing"
                        " (pp_num,account_num,c_s_type,c_s_date)"
                        " values(%1,'%2',%3,now())")
                        .arg(ppNum.toInt()).arg(GLOBAL_ACCOUNT_NUM).arg(type);
    bool flag=query.exec(str);
    if(!flag){
        QMessageBox::information(this,tr("失败"),info+"失败!",QMessageBox::Ok);
        return ;
    }
    QMessageBox::information(this,tr("成功"),"申请"+info+"成功!",QMessageBox::Ok);
}
void OwnerCheWeiManageWidget::shenqingzulin(){
    QString ppNum;
    setMajorKey(ppNum);
    if(ppNum.toInt()==0){
        QMessageBox::information(this,tr("提示"),"请先选中车位!",QMessageBox::Ok);
        return ;
    }
    this->shenqing(1);
}
void OwnerCheWeiManageWidget::shenqinggoumai(){
    QString ppNum;
    setMajorKey(ppNum);
    if(ppNum.toInt()==0){
        QMessageBox::information(this,tr("提示"),"请先选中车位!",QMessageBox::Ok);
        return ;
    }
    this->shenqing(2);
}
void OwnerCheWeiManageWidget::wodeshenqing(){
    b_btn_1->hide();
    b_btn_2->hide();
    b_btn_3->show();
    b_btn_4->show();

    QString queryStr=QString("select pp_num"
                             " ,case c_s_type"
                             " when 1 then '租赁'"
                             " when 2 then '购买'"
                             " end as c_s_type"
                             " ,c_s_date"
                             " from chewei_shenqing"
                             " where c_s_del=0"
                             " and account_num='%1'").arg(GLOBAL_ACCOUNT_NUM);
    qDebug()<<queryStr;
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "车位号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "申请类型");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "申请日期");
}
