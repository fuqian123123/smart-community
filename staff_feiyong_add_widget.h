#ifndef STAFF_FEIYONG_ADD_WIDGET_H
#define STAFF_FEIYONG_ADD_WIDGET_H

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
class StaffFeiYongAddWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffFeiYongAddWidget();
    void sendSignal();
    void init();
    bool isExisted(const QString &key);
signals:
    void newFeiYong();
private:
    QLabel *label_1,*label_2,*label_3;
    QLineEdit *lineEdit_1,*lineEdit_2;
    QButtonGroup *qbg;
    QRadioButton *radio_btn_1,*radio_btn_2,*radio_btn_3;
    QHBoxLayout *layout_1,*layout_2,*layout_3;
private slots:
    void enter();
    void clear();
};

#endif // STAFF_FEIYONG_ADD_WIDGET_H
