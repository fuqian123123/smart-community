#ifndef OWNER_GUZHANG_MANAGE_WIDGET_H
#define OWNER_GUZHANG_MANAGE_WIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "owner_guzhang_add_widget.h"
#include "owner_guzhang_pingjia_widget.h"
class OwnerGuZhangManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    OwnerGuZhangManageWidget();
    void init();
    int getStatus(const QString &faultNum);
private:
    OwnerGuZhangAddWidget *ogzaw;
    OwnerGuZhangPingJiaWidget *ogzpjw;
private slots:
    void refresh();
    void shenbao();
    void pingjia();
};

#endif // OWNER_GUZHANG_MANAGE_WIDGET_H
