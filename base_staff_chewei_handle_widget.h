#ifndef BASE_STAFF_CHEWEI_HANDLE_WIDGET_H
#define BASE_STAFF_CHEWEI_HANDLE_WIDGET_H

#include <QObject>
#include <QLabel>
#include <QMessageBox>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QSqlQuery>
#include <QHBoxLayout>
#include "base_handle_widget.h"
class BaseStaffCheWeiHandleWidget
{
public:
    BaseStaffCheWeiHandleWidget();
    int getStatus(const QString &key);
    bool isApplied(const QString &key,int type);
    bool handle(const QString &key,int type);
    void sendSignal();
signals:
    void newChuZu();
};

#endif // BASE_STAFF_CHEWEI_HANDLE_WIDGET_H
