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
    Q_OBJECT
public:
    ManagerRenYuanEditWidget();
    void loadData(const QString &accountNum);
    void sendSignal();
signals:
    void editUser();
private:
    QLabel *label_1,*label_2;
    QLineEdit *lineEdit_1,*lineEdit_2;
    QHBoxLayout *layout_1,*layout_2;
private slots:
    void enter();
    void clear();
};

#endif // MANAGER_RENYUAN_EDIT_WIDGET_H
