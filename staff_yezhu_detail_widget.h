#ifndef STAFF_YEZHU_DETAIL_WIDGET_H
#define STAFF_YEZHU_DETAIL_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include "base_detail_widget.h"
class StaffYeZhuDetailWidget : public BaseDetailWidget
{
public:
    StaffYeZhuDetailWidget();
    void loadData(const QString &key);
private:
    QLabel *label_1,*label_2;
    QLabel *label_1_1,*label_2_1;
    QHBoxLayout *layout_1,*layout_2;
};

#endif // STAFF_YEZHU_DETAIL_WIDGET_H
