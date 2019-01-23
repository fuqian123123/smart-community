#ifndef OWNER_FORM_H
#define OWNER_FORM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "owner_chewei_manage_widget.h"
#include "owner_feiyong_manage_widget.h"
class OwnerForm : public QWidget
{
    Q_OBJECT
public:
    explicit OwnerForm(QWidget *parent = 0);
    void checkout(const int &num);
private:
    QLabel* h_label;
    QPushButton *h_btn_1,*h_btn_2,*h_btn_3,*b_btn;
    QVBoxLayout* layout;
    QHBoxLayout* h_layout;
    QStackedWidget* c_stackedWidget;
    OwnerCheWeiManageWidget *ocwmw;
    OwnerFeiYongManageWidget *ofymw;
private slots:
    void quit();
    void checkoutCheWei();
    void checkoutFeiYong();
    void checkoutGuZhang();
};

#endif // OWNER_FORM_H
