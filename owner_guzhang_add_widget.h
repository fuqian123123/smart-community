#ifndef OWNER_GUZHANG_ADD_WIDGET_H
#define OWNER_GUZHANG_ADD_WIDGET_H

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
#include "base_handle_widget.h"
class OwnerGuZhangAddWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    OwnerGuZhangAddWidget();
    void sendSignal();
signals:
    void newGuZhang();
private:
    QLabel *label_1,*label_2;
    QLineEdit *lineEdit_1,*lineEdit_2;
    QHBoxLayout *layout_1,*layout_2;
private slots:
    void enter();
    void clear();
};

#endif // OWNER_GUZHANG_ADD_WIDGET_H
