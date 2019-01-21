#ifndef STAFF_KAOQIN_MANAGE_WIDGET_H
#define STAFF_KAOQIN_MANAGE_WIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "staff_chuqin_detail.h"

class StaffKaoQinManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    StaffKaoQinManageWidget();
private:
    QPushButton *b_btn_4;
    StaffChuQinDetail *scqd;
    void init();
    void refreshData();
    void getTodayDate(QString &today);
    void setAccountNum(QString &str);
    void handleToday(const int &type,const int &allowFlag);
    bool isFree();
private slots:
    void daka();
    void qingjia();
    void xiaojia();
    void chuqin();
};

#endif // STAFF_KAOQIN_MANAGE_WIDGET_H
