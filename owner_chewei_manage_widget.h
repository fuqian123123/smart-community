#ifndef OWNER_CHEWEI_MANAGE_WIDGET_H
#define OWNER_CHEWEI_MANAGE_WIDGET_H

#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "base_manage_widget.h"
class OwnerCheWeiManageWidget : public BaseManageWidget
{
    Q_OBJECT
public:
    OwnerCheWeiManageWidget();
    void init();
    void cheweixinxi();
    void shenqing(int type);
private:
    QLabel *label_1,*label_2;
    QPushButton *b_btn_4;
    QHBoxLayout *b_layout_2;
private slots:
    void refreshData();
    void shenqingzulin();
    void shenqinggoumai();
    void wodeshenqing();
};

#endif // OWNER_CHEWEI_MANAGE_WIDGET_H
