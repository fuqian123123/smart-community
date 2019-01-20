#ifndef MANAGER_KAOQIN_MANAGE_WIDGET_H
#define MANAGER_KAOQIN_MANAGE_WIDGET_H

#include <QMessageBox>
#include <QSqlQuery>
#include <QMessageBox>
#include "base_manage_widget.h"
class ManagerKaoQinManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    ManagerKaoQinManageWidget();
    void init();
    void sendSigal();
    int getKid();
signals:
    void editInfo();
public slots:
    void allow();
    void reject();
    void refreshData();
};

#endif // MANAGER_KAOQIN_MANAGE_WIDGET_H
