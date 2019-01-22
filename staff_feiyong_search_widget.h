#ifndef STAFF_FEIYONG_SEARCH_WIDGET_H
#define STAFF_FEIYONG_SEARCH_WIDGET_H

#include <QLabel>
#include <QPushButton>
#include <QButtonGroup>
#include <QRadioButton>
#include <QLineEdit>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>
class StaffFeiYongSearchWidget: public QWidget
{
    Q_OBJECT
public:
    explicit StaffFeiYongSearchWidget(QWidget *parent = 0);
private:
    QLabel *label;
    QPushButton *enter_btn;
    QButtonGroup *qbg;
    QRadioButton *radio_btn_1,*radio_btn_2,*radio_btn_3;
    QHBoxLayout *h_layout;
    QVBoxLayout *layout;
signals:
    void newSearch(const int &f_type);
public slots:
    void sendSignal();
};

#endif // STAFF_FEIYONG_SEARCH_WIDGET_H
