#ifndef OWNER_GUZHANG_PINGJIA_WIDGET_H
#define OWNER_GUZHANG_PINGJIA_WIDGET_H

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
class OwnerGuZhangPingJiaWidget : public BaseHandleWidget
{
    Q_OBJECT
public:
    OwnerGuZhangPingJiaWidget();
    void sendSignal();
    void loadData(const QString &key);
signals:
    void newGuZhang();
private:
    QString faultNum;
    QLabel *label_1;
    QLineEdit *lineEdit_1;
    QHBoxLayout *layout_1;
private slots:
    void enter();
    void clear();
};

#endif // OWNER_GUZHANG_PINGJIA_WIDGET_H
