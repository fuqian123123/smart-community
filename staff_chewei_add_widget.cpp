#include "staff_chewei_add_widget.h"

StaffCheWeiAddWidget::StaffCheWeiAddWidget()
{
    this->resize(380,150);

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
    label_4->setText("出租价格");
    label_5->setText("出售价格");
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
}
void StaffCheWeiAddWidget::enter(){

}
void StaffCheWeiAddWidget::clear(){

}
