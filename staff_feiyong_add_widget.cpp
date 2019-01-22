#include "staff_feiyong_add_widget.h"

StaffFeiYongAddWidget::StaffFeiYongAddWidget()
{
    label_1=new QLabel;
    label_2=new QLabel;
    label_3=new QLabel;
    radio_btn_1=new QRadioButton;
    radio_btn_2=new QRadioButton;
    radio_btn_3=new QRadioButton;
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;
    qbg=new QButtonGroup;
    radio_btn_1=new QRadioButton;
    radio_btn_2=new QRadioButton;
    radio_btn_3=new QRadioButton;
    qbg=new QButtonGroup();
    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    layout_3=new QHBoxLayout;

    label_1->setText("业主账号");
    label_2->setText("缴费类型");
    label_3->setText("缴费数额");
    radio_btn_1->setText("物业费");
    radio_btn_2->setText("车位费");
    radio_btn_3->setText("故障维修费");
    lineEdit_1->setFocus();
    qbg->addButton(radio_btn_1);
    qbg->addButton(radio_btn_2);
    qbg->addButton(radio_btn_3);
    qbg->setId(radio_btn_1,1);
    qbg->setId(radio_btn_2,2);
    qbg->setId(radio_btn_3,3);
    radio_btn_1->setChecked(true);

    layout_1->addWidget(label_1,1);
    layout_1->addWidget(lineEdit_1,3);
    layout_2->addWidget(label_2,1);
    layout_2->addWidget(radio_btn_1,1);
    layout_2->addWidget(radio_btn_2,1);
    layout_2->addWidget(radio_btn_3,1);
    layout_3->addWidget(label_3,1);
    layout_3->addWidget(lineEdit_2,3);

    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(layout_3);
    layout->addLayout(b_layout);

    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
}
void StaffFeiYongAddWidget::init(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
    radio_btn_1->setChecked(true);
}
bool StaffFeiYongAddWidget::isExisted(const QString &key){
    QString str=QString("select count(*) from user"
                        " where u_type=3 and account_num='%1'").arg(key);
    QSqlQuery query;
    if(!query.exec(str)){
        QMessageBox::information(this,tr("错误"),tr("加载错误!"),QMessageBox::Ok);
        return false;
    }
    query.next();
    if(query.value(0).toInt()>0)
        return true;
    return false;
}

void StaffFeiYongAddWidget::sendSignal(){
    emit newFeiYong();
}
void StaffFeiYongAddWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("业主账号不能为空!"),QMessageBox::Ok);
        lineEdit_1->setFocus();
    }
    else if(lineEdit_2->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("缴费数额不能为空!"),QMessageBox::Ok);
        lineEdit_2->setFocus();
    }
    else{
        //判断该业主账号是否已录入
        if(!isExisted(lineEdit_1->text())){
            QMessageBox::information(this,tr("提示"),tr("该业主账号不存在!"),QMessageBox::Ok);
            this->init();
            return ;
        }
        QString accountNum=lineEdit_1->text();
        int f_count=lineEdit_2->text().toInt();
        int f_type=qbg->checkedId();
        QSqlQuery query;
        QString str=QString("insert into feiyong"
                            " (account_num,f_type,f_count,f_date)"
                            " values('%1',%2,%3,now())").arg(accountNum)
                            .arg(f_type).arg(f_count);
        qDebug()<<str;
        if(query.exec(str)){
            QMessageBox::information(this,tr("成功"),tr("添加成功!"),QMessageBox::Ok);
        }
        else
            QMessageBox::information(this,tr("失败"),tr("添加失败!"),QMessageBox::Ok);
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void StaffFeiYongAddWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
    lineEdit_1->setFocus();
}
