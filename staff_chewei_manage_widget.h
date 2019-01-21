#ifndef STAFF_CHEWEI_MANAGE_WIDGET_H
#define STAFF_CHEWEI_MANAGE_WIDGET_H

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "base_manage_widget.h"

class StaffCheWeiManageWidget : public BaseManageWidget
{
public:
    StaffCheWeiManageWidget();
private:
    void init();
    void refreshData();
private slots:
    void chuzu();
    void chushou();

};

#endif // STAFF_CHEWEI_MANAGE_WIDGET_H
