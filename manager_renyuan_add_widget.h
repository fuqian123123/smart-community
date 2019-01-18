#ifndef MANAGERRENYUANADDWIDGET_H
#define MANAGERRENYUANADDWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "base_add_widget.h"

class ManagerRenYuanAddWidget : public BaseAddWidget
{
public:
    ManagerRenYuanAddWidget();
private:
    QLabel* label_1;
    QLabel* label_2;
    QLineEdit* lineEdit_1;
    QLineEdit* lineEdit_2;
    QHBoxLayout* layout_1;
    QHBoxLayout* layout_2;
private slots:
    void enter();
    void clear();
};

#endif // MANAGERRENYUANADDWIDGET_H
