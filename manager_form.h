#ifndef MANAGERFORM_H
#define MANAGERFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "manager_renyuan_manage_widget.h"

class ManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ManagerForm(QWidget *parent = 0);
    ~ManagerForm();
private:
    QLabel* h_label;
    QPushButton* h_btn1;
    QPushButton* h_btn2;
    QPushButton* b_btn;
    QVBoxLayout* layout;
    QHBoxLayout* h_layout;
    ManagerRenYuanManageWidget *mrymw;
    QStackedWidget* c_stackedWidget;
private slots:
    void quit();
};
#endif // MANAGERFORM_H
