#include "QPushButton"
#include "staff_chewei_search_widget.h"

StaffCheWeiSearchWidget::StaffCheWeiSearchWidget()
{
    label->setText("车位号");

    //点击之后，发射信号送出key
    connect(this->btn_1,QPushButton::clicked,this,this->sendSignal);
}
