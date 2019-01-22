#ifndef STAFF_CHEWEI_MANAGE_WIDGET_H
#define STAFF_CHEWEI_MANAGE_WIDGET_H

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "base_manage_widget.h"
#include "staff_chewei_add_widget.h"
#include "staff_chewei_edit_widget.h"
#include "staff_chewei_detail_widget.h"
#include "staff_chewei_search_widget.h"

class StaffCheWeiManageWidget : public BaseManageWidget
{
public:
    StaffCheWeiManageWidget();
    void receiveKey(const QString &key);
private:
    QLabel *label_1,*label_2;
    QPushButton *b_btn_4,*b_btn_5,*b_btn_6;
    QHBoxLayout *b_layout_2;
    StaffCheWeiAddWidget *scwaw;
    StaffCheWeiEditWidget *scwew;
    StaffCheWeiDetailWidget *scwdw;
    StaffCheWeiSearchWidget *scwsw;
    void init();
    void refreshData();
private slots:
    void add();
    void edit();
    void search();
    void del();
    void chuzu();
    void chushou();

};

#endif // STAFF_CHEWEI_MANAGE_WIDGET_H
