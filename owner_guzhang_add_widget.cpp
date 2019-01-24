#include "owner_guzhang_add_widget.h"

extern QString GLOBAL_ACCOUNT_NUM;
OwnerGuZhangAddWidget::OwnerGuZhangAddWidget()
{
    this->setWindowIcon(QIcon(":/myres/images/icons/tianjia.png"));

    label_1=new QLabel;
    label_2=new QLabel;
    layout_1=new QHBoxLayout;
    layout_2=new QHBoxLayout;
    lineEdit_1=new QLineEdit;
    lineEdit_2=new QLineEdit;

    label_1->setText("故障原因");
    label_2->setText("详情");
    lineEdit_1->setFocus();

    layout_1->addWidget(label_1,1);
    layout_1->addWidget(lineEdit_1,3);
    layout_2->addWidget(label_2,1);
    layout_2->addWidget(lineEdit_2,3);
    layout->addLayout(layout_1);
    layout->addLayout(layout_2);
    layout->addLayout(b_layout);

    connect(enter_btn,QPushButton::clicked,this,enter);
    connect(clear_btn,QPushButton::clicked,this,clear);
}
void OwnerGuZhangAddWidget::sendSignal(){
    emit newGuZhang();
}

void OwnerGuZhangAddWidget::enter(){
    if(lineEdit_1->text().isEmpty()){
        QMessageBox::information(this,tr("错误"),tr("故障原因不能为空!"),QMessageBox::Ok);
        lineEdit_1->setFocus();
    }
    else{
        QString reason=lineEdit_1->text();
        QString detail=lineEdit_2->text();
        QSqlQuery query;
        QString str=QString("insert into guzhang"
                            " (account_num,g_detail,g_reason,g_date)"
                            " values('%1','%2','%3',now())")
                            .arg(GLOBAL_ACCOUNT_NUM).arg(detail).arg(reason);
        if(!query.exec(str)){
            QMessageBox::information(this,tr("失败"),tr("申报失败!"),QMessageBox::Ok);
            return ;
        }
        QMessageBox::information(this,tr("成功"),tr("申报成功!"),QMessageBox::Ok);
        this->sendSignal();
    }
}
void OwnerGuZhangAddWidget::clear(){
    lineEdit_1->setText("");
    lineEdit_2->setText("");
    lineEdit_1->setFocus();
}
