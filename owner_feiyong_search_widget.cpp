#include "owner_feiyong_search_widget.h"

OwnerFeiYongSearchWidget::OwnerFeiYongSearchWidget(QWidget *parent) :
    QWidget(parent)
{

    label=new QLabel;
    h_layout=new QHBoxLayout;
    layout=new QVBoxLayout(this);
    enter_btn=new QPushButton;
    radio_btn_1=new QRadioButton;
    radio_btn_2=new QRadioButton;
    radio_btn_3=new QRadioButton;
    qbg=new QButtonGroup();
    qbg->addButton(radio_btn_1);
    qbg->addButton(radio_btn_2);
    qbg->addButton(radio_btn_3);
    qbg->setId(radio_btn_1,1);
    qbg->setId(radio_btn_2,2);
    qbg->setId(radio_btn_3,3);

    h_layout->addWidget(label);
    h_layout->addWidget(radio_btn_1);
    h_layout->addWidget(radio_btn_2);
    h_layout->addWidget(radio_btn_3);

    enter_btn->setText("确定");
    radio_btn_1->setChecked(true);
    label->setText("缴费类型");
    radio_btn_1->setText("物业费");
    radio_btn_2->setText("车位费");
    radio_btn_3->setText("故障维修费");

    layout->addLayout(h_layout);
    layout->addWidget(enter_btn);
    //点击之后，发射信号送出key
    connect(this->enter_btn,QPushButton::clicked,this,this->sendSignal);
}
void OwnerFeiYongSearchWidget::sendSignal(){
    emit newSearch(qbg->checkedId());
}
