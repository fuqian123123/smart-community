#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "manager_renyuan_manage_widget.h"
#include "manager_kaoqin_manage_widget.h"
#include "manager_chuqin_manage_widget.h"

class ManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerForm(QWidget *parent = 0);
    ~ManagerForm();
private:
    QLabel* h_label;
    QPushButton *h_btn_1,*h_btn_2,*h_btn_3;
    QPushButton* b_btn;
    QVBoxLayout* layout;
    QHBoxLayout* h_layout;
    ManagerRenYuanManageWidget *mrymw;
    ManagerKaoQinManageWidget *mkqmw;
    ManagerChuQinManageWidget *mcqmw;
    QStackedWidget* c_stackedWidget;
private slots:
    void quit();
    void checkoutRenYuan();
    void checkoutKaoQin();
    void checkoutChuQin();
};
#endif // MANAGERFORM_H
