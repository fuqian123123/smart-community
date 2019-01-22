#ifndef STAFF_CHEWEI_EDIT_WIDGET_H
#define STAFF_CHEWEI_EDIT_WIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "base_handle_widget.h"

class StaffCheWeiEditWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffCheWeiEditWidget();
    void sendSignal();
    void loadData(const QString &pp_num);
    bool isFree(const QString &pp_num);
signals:
    void editCheWei();
private:
    QLabel *label_1,*label_2,*label_3,*label_4,*label_5,*label_1_1,*label_2_1,*label_3_1;
    QLineEdit *lineEdit_2,*lineEdit_3;
    QHBoxLayout *layout_1,*layout_2;
    QHBoxLayout *h_layout_1,* h_layout_2,* h_layout_3,* h_layout_4,* h_layout_5;
private slots:
    void enter();
    void clear();
};

#endif // STAFF_CHEWEI_EDIT_WIDGET_H
