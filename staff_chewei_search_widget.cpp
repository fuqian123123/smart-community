#include "QPushButton"
#include "staff_chewei_search_widget.h"

StaffCheWeiSearchWidget::StaffCheWeiSearchWidget()
{
    this->setWindowIcon(QIcon(":/myres/images/icons/chaxun.png"));

    label->setText("车位号");

    //点击之后，发射信号送出key
    connect(this->btn_1,QPushButton::clicked,this,this->sendSignal);
}
