#include "staff_chewei_add_widget.h"

StaffCheWeiAddWidget::StaffCheWeiAddWidget()
{
    this->resize(380,150);
    this->setWindowIcon(QIcon(":/myres/images/icons/tianjia.png"));

    label_1=new QLabel;
    label_2=new QLabel;
    label_3=new QLabel;
    label_4=new QLabel;
    label_5=new QLabel;
    radio_btn_1_1=new QRadioButton;
    radio_btn_1_2=new QRadioButton;
    radio_btn_1_3=new QRadioButton;
    radio_btn_2_1=new QRadioButton;
    radio_btn_2_2=new QRadioButton;
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;
    lineEdit_3=new QLineEdit;
    qbg_1=new QButtonGroup;
    qbg_2=new QButtonGroup;
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
    radio_btn_1_1->setText("小型车位");
    radio_btn_1_2->setText("中型车位");
    radio_btn_1_3->setText("大型车位");
    radio_btn_2_1->setText("无");
    radio_btn_2_2->setText("有");
    //三个radio button初始化
    qbg_1->addButton(radio_btn_1_1);
    qbg_1->addButton(radio_btn_1_2);
    qbg_1->addButton(radio_btn_1_3);
    qbg_1->setId(radio_btn_1_1,1);
    qbg_1->setId(radio_btn_1_2,2);
    qbg_1->setId(radio_btn_1_3,3);
    qbg_2->addButton(radio_btn_2_1);
    qbg_2->addButton(radio_btn_2_2);
    qbg_2->setId(radio_btn_2_1,0);
    qbg_2->setId(radio_btn_2_2,1);
    //布局
    h_layout_1->addWidget(label_1,1);
    h_layout_1->addWidget(lineEdit_1,3);
    h_layout_2->addWidget(label_4,1);
    h_layout_2->addWidget(lineEdit_2,3);
    h_layout_3->addWidget(label_5,1);
    h_layout_3->addWidget(lineEdit_3,3);
    h_layout_4->addWidget(label_2,1);
    h_layout_4->addWidget(radio_btn_1_1,1);
    h_layout_4->addWidget(radio_btn_1_2,1);
    h_layout_4->addWidget(radio_btn_1_3,1);
    h_layout_5->addWidget(label_3,2);
    h_layout_5->addWidget(radio_btn_2_1,3);
    h_layout_5->addWidget(radio_btn_2_2,3);

    layout->addLayout(h_layout_1);
    layout->addLayout(h_layout_4);
    layout->addLayout(h_layout_5);
    layout->addLayout(h_layout_2);
    layout->addLayout(h_layout_3);
    layout->addLayout(b_layout);

    //赋初值
    radio_btn_1_1->setChecked(true);
    radio_btn_2_1->setChecked(true);
    lineEdit_1->setFocus();

    //关联信号和槽
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
}
void StaffCheWeiAddWidget::sendSignal(){
    emit newCheWei();
}
void StaffCheWeiAddWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("车位号不能为空!"),QMessageBox::Ok);
        lineEdit_1->setFocus();
    }
    else if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("出租价格不能为空!"),QMessageBox::Ok);
        lineEdit_2->setFocus();
    }
    else if(lineEdit_3->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("出售价格不能为空!"),QMessageBox::Ok);
        lineEdit_3->setFocus();
    }
    else{
        int pp_num=lineEdit_1->text().toInt();

        QSqlQuery query;
        QString str_1=QString("select count(*) from chewei where pp_num=%1").arg(pp_num);
        if(query.exec(str_1)){
            query.next();
            if(query.value(0).toInt()>0){
                QMessageBox::information(this,tr("错误"),tr("该车位已存在!"),QMessageBox::Ok);
                return ;
            }
            else{
                int c_price_1=lineEdit_2->text().toInt();
                int c_price_2=lineEdit_3->text().toInt();
                int c_type=qbg_1->checkedId();
                int c_chongdian=qbg_2->checkedId();
                QString str_2=QString("insert into chewei"
                                      " (pp_num,c_type,c_chongdian,c_price_1,c_price_2)"
                                      " values (%1,%2,%3,%4,%5)")
                                      .arg(pp_num).arg(c_type).arg(c_chongdian).arg(c_price_1).arg(c_price_2);
                qDebug()<<str_2;
                if(query.exec(str_2)){
                    QMessageBox::information(this,tr("成功"),tr("添加成功!"),QMessageBox::Ok);
                }
                else{
                    QMessageBox::information(this,tr("失败"),tr("添加失败!"),QMessageBox::Ok);
                }
            }
        }
        else{
            QMessageBox::information(this,tr("错误"),tr("数据库错误!"),QMessageBox::Ok);
        }
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void StaffCheWeiAddWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
    lineEdit_3->setText("");
    lineEdit_1->setFocus();
}
