#ifndef MANAGERRENYUANMANAGEWIDGET_H
#define MANAGERRENYUANMANAGEWIDGET_H

#include <QDebug>
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
    void init();
private slots:
    void add();
    void edit();
    void detail();
    void refreshData();
};

#endif // MANAGERRENYUANMANAGEWIDGET_H
