#include "staff_chewei_edit_widget.h"

StaffCheWeiEditWidget::StaffCheWeiEditWidget()
{
    this->resize(380,150);
    this->setWindowIcon(QIcon(":/myres/images/icons/xiugai.png"));

    label_1=new QLabel;
    label_1_1=new QLabel;
    label_2=new QLabel;
    label_2_1=new QLabel;
    label_3=new QLabel;
    label_3_1=new QLabel;
    label_4=new QLabel;
    label_5=new QLabel;
    lineEdit_2=new QLineEdit;
    lineEdit_3=new QLineEdit;
    h_layout_1=new QHBoxLayout;
    h_layout_2=new QHBoxLayout;
    h_layout_3=new QHBoxLayout;
    h_layout_4=new QHBoxLayout;
    h_layout_5=new QHBoxLayout;

    label_1->setText("车位号");
    label_2->setText("车位类型");
    label_3->setText("充电桩状态");
    label_4->setText("出租价格(元)");
    label_5->setText("出售价格(元)");
    //布局
    h_layout_1->addWidget(label_1,1);
    h_layout_1->addWidget(label_1_1,3);
    h_layout_2->addWidget(label_4,1);
    h_layout_2->addWidget(lineEdit_2,3);
    h_layout_3->addWidget(label_5,1);
    h_layout_3->addWidget(lineEdit_3,3);
    h_layout_4->addWidget(label_2,1);
    h_layout_4->addWidget(label_2_1,3);
    h_layout_5->addWidget(label_3,1);
    h_layout_5->addWidget(label_3_1,3);

    layout->addLayout(h_layout_1);
    layout->addLayout(h_layout_4);
    layout->addLayout(h_layout_5);
    layout->addLayout(h_layout_2);
    layout->addLayout(h_layout_3);
    layout->addLayout(b_layout);


    //关联信号和槽
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
}
bool StaffCheWeiEditWidget::isFree(const QString &pp_num){
    QString str_1=QString("select c_status from chewei"
                          " where pp_num=%1").arg(pp_num.toInt());
    QSqlQuery query;
    if(query.exec(str_1)){
        query.next();
        if(query.value(0).toInt() != 0){
            return false;
        }
        else
            return true;
    }
}

void StaffCheWeiEditWidget::loadData(const QString &pp_num){
    //若此车位已出租或出售，则不可修改
    QSqlQuery query;
    QString str_2=QString("select pp_num"
                          " ,case c_type "
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
                          " where pp_num=%1").arg(pp_num.toInt());
    bool flag=query.exec(str_2);
    if(flag){
        query.next();
        label_1_1->setText(query.value(0).toString());
        label_2_1->setText(query.value(1).toString());
        label_3_1->setText(query.value(2).toString());
        lineEdit_2->setText(query.value(3).toString());
        lineEdit_3->setText(query.value(4).toString());
        lineEdit_2->setFocus();
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}

void StaffCheWeiEditWidget::sendSignal(){
    emit editCheWei();
}
void StaffCheWeiEditWidget::enter(){
    if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("出租价格不能为空!"),QMessageBox::Ok);
        lineEdit_2->setFocus();
    }
    else if(lineEdit_3->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("出售价格不能为空!"),QMessageBox::Ok);
        lineEdit_3->setFocus();
    }
    else{
        int pp_num=label_1_1->text().toInt();

        QSqlQuery query;
        int c_price_1=lineEdit_2->text().toInt();
        int c_price_2=lineEdit_3->text().toInt();
        QString str_2=QString("update chewei set c_price_1=%1,c_price_2=%2"
                              " where pp_num=%3")
                              .arg(c_price_1).arg(c_price_2).arg(pp_num);
        qDebug()<<str_2;
        if(query.exec(str_2)){
            QMessageBox::information(this,tr("成功"),tr("修改成功!"),QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this,tr("失败"),tr("修改失败!"),QMessageBox::Ok);
        }
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void StaffCheWeiEditWidget::clear(){
    lineEdit_2->setText("");
    lineEdit_3->setText("");
}
