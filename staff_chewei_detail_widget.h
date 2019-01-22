#ifndef STAFF_CHEWEI_DETAIL_WIDGET_H
#define STAFF_CHEWEI_DETAIL_WIDGET_H

#include <QLabel>
#include <QDebug>
#include <QSqlQuery>
#include <QHBoxLayout>
#include <QMessageBox>
#include "base_detail_widget.h"
class StaffCheWeiDetailWidget : public BaseDetailWidget
{
public:
    StaffCheWeiDetailWidget();
    bool loadData(const QString &key);
private:
    QLabel *label_1,*label_1_1;
    QLabel *label_2,*label_2_1;
    QLabel *label_3,*label_3_1;
    QLabel *label_4,*label_4_1;
    QLabel *label_5,*label_5_1;
    QLabel *label_6,*label_6_1;
    QLabel *label_7,*label_7_1;
    QHBoxLayout *h_layout_1,*h_layout_2,*h_layout_3,*h_layout_4,*h_layout_5,*h_layout_6,*h_layout_7;
};

#endif // STAFF_CHEWEI_DETAIL_WIDGET_H
