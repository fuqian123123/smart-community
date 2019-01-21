#ifndef STAFF_CHUQIN_DETAIL_H
#define STAFF_CHUQIN_DETAIL_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlQuery>
#include <QMessageBox>
#include "base_detail_widget.h"
class StaffChuQinDetail : public BaseDetailWidget
{
public:
    StaffChuQinDetail();
    void loadData(const QString &key);
private:
    QLabel *label_1,*label_2;
    QLabel *label_1_1,*label_2_1;
    QHBoxLayout *layout_1,*layout_2;
};

#endif // STAFF_CHUQIN_DETAIL_H
