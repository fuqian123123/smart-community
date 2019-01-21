#ifndef STAFF_CHEWEI_CHUZU_WIDGET_H
#define STAFF_CHEWEI_CHUZU_WIDGET_H

#include <QLabel>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include "base_handle_widget.h"
class StaffCheWeiChuZuWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    StaffCheWeiChuZuWidget();
    void loadData(const QString &accountNum);
    void sendSignal();
signals:
    void newChuZu();
private:
    QLabel *label_1,*label_2,*label_3;
    QLineEdit *lineEdit_1,*lineEdit_2,*lineEdit_3;
    QHBoxLayout *layout_1,*layout_2,*layout_3;
private slots:
    void enter();
    void cancel();
};

#endif // STAFF_CHEWEI_CHUZU_WIDGET_H
