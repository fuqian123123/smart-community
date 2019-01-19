#ifndef MANAGERRENYUANMANAGEWIDGET_H
#define MANAGERRENYUANMANAGEWIDGET_H

#include <QDebug>
#include <QPushButton>
#include "base_manage_widget.h"
#include "manager_renyuan_add_widget.h"
#include "manager_renyuan_edit_widget.h"
#include "manager_renyuan_detail_widget.h"

class ManagerRenYuanManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    ManagerRenYuanManageWidget();
private:
    ManagerRenYuanAddWidget* mryaw;
    ManagerRenYuanEditWidget* mryew;
    ManagerRenYuanDetailWidget* mrydw;
    QPushButton *b_btn_4;
    void init();
    void setAccountNum(QString &str);
private slots:
    void add();
    void edit();
    void detail();
    void del();
    void refreshData();
};

#endif // MANAGERRENYUANMANAGEWIDGET_H
