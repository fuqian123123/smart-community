#ifndef MANAGERRENYUANMANAGEWIDGET_H
#define MANAGERRENYUANMANAGEWIDGET_H

#include <QDebug>
#include "base_manage_widget.h"
#include "manager_renyuan_add_widget.h"
#include "manager_renyuan_edit_widget.h"

class ManagerRenYuanManageWidget : public BaseManageWidget
{
public:
    ManagerRenYuanManageWidget();
private:
    ManagerRenYuanAddWidget* mryaw;
    ManagerRenYuanEditWidget* mryew;
    void init();
private slots:
    void add();
    void edit();
    void detail();
};

#endif // MANAGERRENYUANMANAGEWIDGET_H
