#include "staff_chewei_manage_widget.h"

StaffCheWeiManageWidget::StaffCheWeiManageWidget()
{
    b_btn_4=new QPushButton;
    b_btn_5=new QPushButton;
    b_btn_6=new QPushButton;
    b_layout_2=new QHBoxLayout;
    label_1=new QLabel;
    label_2=new QLabel;

    label_1->setText("车位管理");
    label_2->setText("车位租售");
    b_btn_1->setText("添加");
    b_btn_1->setIcon(QIcon(":/myres/images/icons/tianjia.png"));
    b_btn_2->setText("修改");
    b_btn_2->setIcon(QIcon(":/myres/images/icons/xiugai.png"));
    b_btn_3->setText("查询");
    b_btn_3->setIcon(QIcon(":/myres/images/icons/chaxun.png"));
    b_btn_4->setText("删除");
    b_btn_4->setIcon(QIcon(":/myres/images/icons/shanchu.png"));
    b_btn_5->setText("出租");
    b_btn_5->setIcon(QIcon(":/myres/images/icons/zulin.png"));
    b_btn_6->setText("出售");
    b_btn_6->setIcon(QIcon(":/myres/images/icons/chushou.png"));

    //为关联信号和槽做准备
    scwaw=new StaffCheWeiAddWidget;
    scwew=new StaffCheWeiEditWidget;
    scwdw=new StaffCheWeiDetailWidget;
    scwsw=new StaffCheWeiSearchWidget;
    bscwhw_1=new BaseStaffCheWeiHandleWidget;
    bscwhw_2=new BaseStaffCheWeiHandleWidget;

    b_layout->addWidget(label_1,2);
    b_layout->addWidget(b_btn_1,3);
    b_layout->addWidget(b_btn_2,3);
    b_layout->addWidget(b_btn_3,3);
    b_layout->addWidget(b_btn_4,3);
    b_layout_2->addWidget(label_2,1);
    b_layout_2->addWidget(b_btn_5,3);
    b_layout_2->addWidget(b_btn_6,3);
    layout->addLayout(b_layout_2);

    //为关联信号和槽做准备
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_2,QPushButton::clicked,this,edit);
    connect(b_btn_3,QPushButton::clicked,this,search);
    connect(b_btn_4,QPushButton::clicked,this,del);
    connect(b_btn_5,QPushButton::clicked,this,chuzu);
    connect(b_btn_6,QPushButton::clicked,this,chushou);
    connect(scwaw,&StaffCheWeiAddWidget::newCheWei,this,refreshData);
    connect(scwew,&StaffCheWeiEditWidget::editCheWei,this,refreshData);
    connect(scwsw,&StaffCheWeiSearchWidget::entered,this,receiveKey);

    this->init();
}
void StaffCheWeiManageWidget::receiveKey(const QString &key){
    scwsw->hide();
    scwsw->clear();
    bool flag=scwdw->loadData(key);
    if(!flag){
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
        return;
    }
    scwdw->setWindowTitle("详情");
    scwdw->setWindowModality(Qt::ApplicationModal);
    scwdw->show();
}

void StaffCheWeiManageWidget::init(){
    QString queryStr=QString("select pp_num"
                             ", case account_num"
                             " when '0' then '空'"
                             " else account_num"
                             " end as account_num"
                             " ,case c_status"
                             " when 0 then '待租/售'"
                             " when 1 then '已租'"
                             " when 2 then '已售'"
                             " end as c_status"
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
                             " where c_del=0");
    this->load(queryStr);
    q_model->setHeaderData(0, Qt::Orientation::Horizontal, "车位号");
    q_model->setHeaderData(1, Qt::Orientation::Horizontal, "业主账号");
    q_model->setHeaderData(2, Qt::Orientation::Horizontal, "租售状态");
    q_model->setHeaderData(3, Qt::Orientation::Horizontal, "车位类型");
    q_model->setHeaderData(4, Qt::Orientation::Horizontal, "充电桩状态");
    q_model->setHeaderData(5, Qt::Orientation::Horizontal, "出租价格(元)");
    q_model->setHeaderData(6, Qt::Orientation::Horizontal, "出售价格(元)");
}
void StaffCheWeiManageWidget::refreshData(){
    this->init();
}
void StaffCheWeiManageWidget::add(){
    scwaw->setWindowTitle("添加");
    scwaw->setWindowModality(Qt::ApplicationModal);
    scwaw->show();
}
void StaffCheWeiManageWidget::edit(){
    QString key;
    setMajorKey(key);
    if(!scwew->isFree(key)){
        QMessageBox::information(this,tr("提示"),tr("已租售车位不可修改!"),QMessageBox::Ok);
        return ;
    }
    scwew->loadData(key);
    scwew->setWindowTitle("修改");
    scwew->setWindowModality(Qt::ApplicationModal);
    scwew->show();
}
void StaffCheWeiManageWidget::search(){
    scwsw->setWindowTitle("查询");
    scwsw->setWindowModality(Qt::ApplicationModal);
    scwsw->show();
}
void StaffCheWeiManageWidget::del(){
    QString key;
    setMajorKey(key);
    QSqlQuery query;
    QString str=QString("select c_status from chewei"
                        " where pp_num=%1").arg(key.toInt());
    bool flag=query.exec(str);
    if(!flag){
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
        return ;
    }
    query.next();
    if(query.value(0).toInt()!=0){
        QMessageBox::information(this,tr("提示"),tr("已租售车位不可删除!"),QMessageBox::Ok);
        return ;
    }
    QMessageBox::StandardButton reply;
    reply = QMessageBox::warning(this, "警告", "确定删除?", QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::No){
        return ;
    }
    QString str_2=QString("update chewei set c_del=1 where pp_num=%1").arg(key);
    query.exec(str_2);
    this->refreshData();
}
void StaffCheWeiManageWidget::handle(BaseStaffCheWeiHandleWidget &bscwhw,int type){
    QString key;
    QString info=type==1?"出租":"出售";
    QString info_2=type==1?"租赁":"购买";
    setMajorKey(key);
    if(key==""){
        QMessageBox::information(this,tr("提示"),tr("请选择车位!"),QMessageBox::Ok);
        return ;
    }
    if(bscwhw.getStatus(key)==1){
        QMessageBox::information(this,tr("提示"),tr("此车位为已租状态!"),QMessageBox::Ok);
        return ;
    }
    else if(bscwhw.getStatus(key)==2){
        QMessageBox::information(this,tr("提示"),tr("此车位为已售状态!"),QMessageBox::Ok);
        return ;
    }
    if(!bscwhw.isApplied(key,type)){
        QMessageBox::information(this,tr("提示"),"暂无业主申请"+info_2+"此车位!",QMessageBox::Ok);
        return ;
    }
    else{
        if(bscwhw.handle(key,type)){
            QMessageBox::information(this,tr("提示"),info+"成功!",QMessageBox::Ok);
            this->refreshData();
        }
        else{
            QMessageBox::information(this,tr("提示"),info+"失败!",QMessageBox::Ok);
        }
    }
}

void StaffCheWeiManageWidget::chuzu(){
    handle(*bscwhw_1,1);
}
void StaffCheWeiManageWidget::chushou(){
    handle(*bscwhw_2,2);
}
