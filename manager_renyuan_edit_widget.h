#ifndef MANAGER_RENYUAN_EDIT_WIDGET_H
#define MANAGER_RENYUAN_EDIT_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QSqlTableModel>
#include "base_handle_widget.h"
class ManagerRenYuanEditWidget : public BaseHandleWidget
{
public:
    ManagerRenYuanEditWidget();
    void loadData(const QString &accountNum);
private:
    QLabel *label_1,*label_2;
    QLineEdit *lineEdit_1,*lineEdit_2;
    QHBoxLayout *layout_1,*layout_2,*layout_3;
    QRadioButton *radioBtn_1,*radioBtn_2,*radioBtn_3;
    QButtonGroup *qbg;
    QSqlTableModel *model;
private slots:
    void enter();
    void clear();
};

#endif // MANAGER_RENYUAN_EDIT_WIDGET_H
