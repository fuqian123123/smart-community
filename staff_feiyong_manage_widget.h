#ifndef STAFF_FEIYONG_MANAGE_WIDGET_H
#define STAFF_FEIYONG_MANAGE_WIDGET_H

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "staff_feiyong_search_widget.h"
#include "staff_feiyong_add_widget.h"
class StaffFeiYongManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    StaffFeiYongManageWidget();
    void init();
private:
    StaffFeiYongSearchWidget *sfysw;
    StaffFeiYongAddWidget *sfyaw;
public slots:
    void receive(const int &f_type);
    void search();
    void jiaofei();
    void refresh();
};

#endif // STAFF_FEIYONG_MANAGE_WIDGET_H
