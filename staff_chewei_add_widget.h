#ifndef STAFF_CHEWEI_ADD_WIDGET_H
#define STAFF_CHEWEI_ADD_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QButtonGroup>
#include "base_handle_widget.h"
class StaffCheWeiAddWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffCheWeiAddWidget();
    void sendSignal();
signals:
    void newCheWei();
private:
    QLabel *label_1,*label_2,*label_3,*label_4,*label_5;
    QLineEdit *lineEdit_1,*lineEdit_2,*lineEdit_3;
    QHBoxLayout *layout_1,*layout_2;
    QButtonGroup *qbg_1,*qbg_2;
    QRadioButton *radio_btn_1_1,*radio_btn_1_2,*radio_btn_1_3;
    QRadioButton *radio_btn_2_1,*radio_btn_2_2;
    QHBoxLayout *h_layout_1,* h_layout_2,* h_layout_3,* h_layout_4,* h_layout_5;
private slots:
    void enter();
    void clear();
};

#endif // STAFF_CHEWEI_ADD_WIDGET_H
