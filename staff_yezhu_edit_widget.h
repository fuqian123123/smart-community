#ifndef STAFF_YEZHU_EDIT_WIDGET_H
#define STAFF_YEZHU_EDIT_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include "base_handle_widget.h"
class StaffYeZhuEditWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffYeZhuEditWidget();
    void loadData(const QString &accountNum);
    void sendSignal();
signals:
    void editUser();
private:
    QLabel *label_1,*label_2;
    QLineEdit *lineEdit_1,*lineEdit_2;
    QHBoxLayout *layout_1,*layout_2,*layout_3;
private slots:
    void enter();
    void clear();
};

#endif // STAFF_YEZHU_EDIT_WIDGET_H
