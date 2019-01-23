#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QButtonGroup>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSqlTableModel>
#include "manager_form.h"
#include "staff_form.h"
#include "owner_form.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_quitBtn_clicked();
    void on_loginBtn_clicked();

private:
    Ui::LoginDialog *ui;
    QButtonGroup* qbg;
    QSqlTableModel *model;
    ManagerForm *mf;
    StaffForm *sf;
    OwnerForm *of;
};

#endif // LOGINDIALOG_H
