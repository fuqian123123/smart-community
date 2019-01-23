#ifndef STAFF_GUZHANG_MANAGE_WIDGET_H
#define STAFF_GUZHANG_MANAGE_WIDGET_H

#include <QDebug>
#include <QPushButton>
#include <QDateTime>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "staff_guzhang_edit_widget.h"
class StaffGuZhangManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    StaffGuZhangManageWidget();
    void init();
private:
    StaffGuZhangEditWidget *sgzew;
private slots:
    void refresh();
    void gengxin();
};

#endif // STAFF_GUZHANG_MANAGE_WIDGET_H
