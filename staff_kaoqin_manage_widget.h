#ifndef STAFF_KAOQIN_MANAGE_WIDGET_H
#define STAFF_KAOQIN_MANAGE_WIDGET_H

#include <QDebug>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "base_manage_widget.h"

class StaffKaoQinManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    StaffKaoQinManageWidget();
private:
    void init();
    void refreshData();
    void getTodayDate(QString &today);
    void setAccountNum(QString &str);
    void handleToday(const int &type);
    bool isFree();
private slots:
    void daka();
    void qingjia();
    void xiaojia();
};

#endif // STAFF_KAOQIN_MANAGE_WIDGET_H
