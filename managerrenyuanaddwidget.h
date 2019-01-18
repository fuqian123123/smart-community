#ifndef MANNAGERRENYUANADDWIDGET_H
#define MANNAGERRENYUANADDWIDGET_H

#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include "baseaddwidget.h"

class MannagerRenYuanAddWidget : public BaseAddWidget
{
public:
    MannagerRenYuanAddWidget();
private:
    QLabel* label_1;
    QLabel* label_2;
    QLineEdit* lineEdit_1;
    QLineEdit* lineEdit_2;
    QHBoxLayout* layout_1;
    QHBoxLayout* layout_2;

};

#endif // MANNAGERRENYUANADDWIDGET_H
