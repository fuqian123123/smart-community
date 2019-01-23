#ifndef STAFF_GUZHANG_EDIT_WIDGET_H
#define STAFF_GUZHANG_EDIT_WIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "base_handle_widget.h"
class StaffGuZhangEditWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffGuZhangEditWidget();
    void sendSignal();
    void loadData(const QString &fault_num);
    int getStatus(const QString &fault_num);
signals:
    void editGuZhang();
private:
    QString key;
    QLabel *label_1,*label_1_1,*label_2,*label_2_1,*label_3;
    QLineEdit *lineEdit;
    QHBoxLayout *h_layout_1,* h_layout_2,* h_layout_3;
private slots:
    void enter();
    void clear();
};

#endif // STAFF_GUZHANG_EDIT_WIDGET_H
