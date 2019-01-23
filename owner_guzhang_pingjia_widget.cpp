#include "owner_guzhang_pingjia_widget.h"

OwnerGuZhangPingJiaWidget::OwnerGuZhangPingJiaWidget()
{
    label_1=new QLabel;
    lineEdit_1=new QLineEdit;
    layout_1=new QHBoxLayout;

    label_1->setText("评价");
    lineEdit_1->setFocus();

    layout_1->addWidget(label_1,1);
    layout_1->addWidget(lineEdit_1,3);
    layout->addLayout(layout_1);
    layout->addLayout(b_layout);

    connect(enter_btn,QPushButton::clicked,this,enter);
    connect(clear_btn,QPushButton::clicked,this,clear);
}
void OwnerGuZhangPingJiaWidget::sendSignal(){
    emit newGuZhang();
}
void OwnerGuZhangPingJiaWidget::loadData(const QString &key){
    this->faultNum=key;
}
void OwnerGuZhangPingJiaWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("提示"),tr("评价不能为空!"),QMessageBox::Ok);
        return ;
    }
    QString pingjia=lineEdit_1->text();
    QSqlQuery query;
    QString str=QString("update guzhang set g_status=3,g_pingjia='%1'"
                        " where fault_num='%2'").arg(pingjia).arg(this->faultNum);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("失败"),tr("评价失败!"),QMessageBox::Ok);
        return ;
    }
    QMessageBox::information(this,tr("成功"),tr("评价成功!"),QMessageBox::Ok);
    this->sendSignal();
}
void OwnerGuZhangPingJiaWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_1->setFocus();
}
