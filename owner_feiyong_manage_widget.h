#ifndef OWNER_FEIYONG_MANAGE_WIDGET_H
#define OWNER_FEIYONG_MANAGE_WIDGET_H

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "owner_feiyong_search_widget.h"
#include "owner_feiyong_add_widget.h"
class OwnerFeiYongManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    OwnerFeiYongManageWidget();
    void init();
private:
    OwnerFeiYongSearchWidget *ofysw;
    OwnerFeiYongAddWidget *ofyaw;
public slots:
    void receive(const int &f_type);
    void search();
    void jiaofei();
    void refresh();
};

#endif // OWNER_FEIYONG_MANAGE_WIDGET_H
