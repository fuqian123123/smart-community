#ifndef MANAGER_RENYUAN_DETAIL_WIDGET_H
#define MANAGER_RENYUAN_DETAIL_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include "base_detail_widget.h"
class ManagerRenYuanDetailWidget : public BaseDetailWidget
{
public:
    ManagerRenYuanDetailWidget();
    void loadData(const QString &key);
private:
    QLabel *label_1,*label_2,*label_3;
    QLabel *label_1_1,*label_2_1,*label_3_1;
    QHBoxLayout *layout_1,*layout_2,*layout_3;
    QSqlTableModel* model;
};

#endif // MANAGER_RENYUAN_DETAIL_WIDGET_H
