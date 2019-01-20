#ifndef STAFF_YEZHU_MANAGE_WIDGET_H
#define STAFF_YEZHU_MANAGE_WIDGET_H

#include <QDebug>
#include <QPushButton>
#include "base_manage_widget.h"
#include "staff_yezhu_add_widget.h"

//class StaffYeZhuAddWidget;
class StaffYeZhuManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    StaffYeZhuManageWidget();
private:
    StaffYeZhuAddWidget *syzaw;
    //ManagerRenYuanEditWidget* mryew;
    //ManagerRenYuanDetailWidget* mrydw;
    QPushButton *b_btn_4;
    void init();
    //void setAccountNum(QString &str);
private slots:
    void add();
    void edit();
    void detail();
    void del();
    void refreshData();
};

#endif // STAFF_YEZHU_MANAGE_WIDGET_H
