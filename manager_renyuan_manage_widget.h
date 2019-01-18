#ifndef MANAGERRENYUANMANAGEWIDGET_H
#define MANAGERRENYUANMANAGEWIDGET_H

#include "base_manage_widget.h"
#include "manager_renyuan_add_widget.h"

class ManagerRenYuanManageWidget : public BaseManageWidget
{
public:
    ManagerRenYuanManageWidget();
private:
    ManagerRenYuanAddWidget* mryaw;
    void init();
private slots:
    void add();
    void edit();
    void detail();
};

#endif // MANAGERRENYUANMANAGEWIDGET_H
