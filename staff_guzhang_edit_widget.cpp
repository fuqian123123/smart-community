#include "staff_guzhang_edit_widget.h"
#include <QSqlError>
#include <QTextCodec>

StaffGuZhangEditWidget::StaffGuZhangEditWidget()
{
    this->setWindowIcon(QIcon(":/myres/images/icons/xiugai.png"));

    label_1=new QLabel;
    label_1_1=new QLabel;
    label_2=new QLabel;
    label_2_1=new QLabel;
    label_3=new QLabel;
    lineEdit=new QLineEdit;
    h_layout_1=new QHBoxLayout;
    h_layout_2=new QHBoxLayout;
    h_layout_3=new QHBoxLayout;

    label_1->setText("故障号");
    label_2->setText("申报业主账号");
    label_3->setText("详情");

    h_layout_1->addWidget(label_1,1);
    h_layout_1->addWidget(label_1_1,3);
    h_layout_2->addWidget(label_2,1);
    h_layout_2->addWidget(label_2_1,3);
    h_layout_3->addWidget(label_3,1);
    h_layout_3->addWidget(lineEdit,3);
    layout->addLayout(h_layout_1);
    layout->addLayout(h_layout_2);
    layout->addLayout(h_layout_3);
    layout->addLayout(b_layout);

    //关联信号和槽
    connect(this->enter_btn,QPushButton::clicked,this,enter);
    connect(this->clear_btn,QPushButton::clicked,this,clear);
}
int StaffGuZhangEditWidget::getStatus(const QString &fault_num){
    QString str=QString("select g_status from guzhang"
                        " where fault_num=%1").arg(fault_num.toInt());
    QSqlQuery query;
    query.exec(str);
    query.next();
    return query.value(0).toInt();
}

void StaffGuZhangEditWidget::sendSignal(){
    emit editGuZhang();
}
void StaffGuZhangEditWidget::loadData(const QString &fault_num){
    key=fault_num;
    QSqlQuery query;
    QString str=QString("select fault_num,account_num,g_detail"
                        " from guzhang"
                        " where fault_num=%1").arg(fault_num.toInt());
    bool flag=query.exec(str);
    if(flag){
        query.next();
        label_1_1->setText(query.value(0).toString());
        label_2_1->setText(query.value(1).toString());
        lineEdit->setText(query.value(2).toString());
        lineEdit->setFocus();
    }
    else{
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
    }
}
void StaffGuZhangEditWidget::enter(){
    if(lineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("详情不能为空!"),QMessageBox::Ok);
        lineEdit->setFocus();
    }
    else{
        int faultNum=label_1_1->text().toInt();
        int gStatus=getStatus(key);
        if(gStatus==0)
            gStatus=1;
        else if(gStatus==1){
            gStatus=2;
        }
        else if(gStatus==2){
            QMessageBox::information(this,tr("提示"),tr("该故障已处理完成!"),QMessageBox::Ok);
            return ;
        }
        else if(gStatus==3){
            QMessageBox::information(this,tr("提示"),tr("该故障已评价!"),QMessageBox::Ok);
            return ;
        }
        QString detail=lineEdit->text();

        QSqlQuery query;
        QString str_2=QString("update guzhang set g_status=%1,g_detail='%2'"
                              " where fault_num=%3")
                              .arg(gStatus).arg(detail).arg(faultNum);
        if(query.exec(str_2)){
            QMessageBox::information(this,tr("成功"),tr("更新成功!"),QMessageBox::Ok);
        }
        else{
            QMessageBox::information(this,tr("失败"),tr("更新失败!"),QMessageBox::Ok);
            qDebug()<<query.lastError();
        }
    }
    //发送信号，要求更新列表
    this->sendSignal();
}
void StaffGuZhangEditWidget::clear(){
    lineEdit->setText("");
    lineEdit->setFocus();
}
