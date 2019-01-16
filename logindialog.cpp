#include <QMessageBox>
#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    setWindowTitle(tr("登录"));
    ui->acntLineEdit->setFocus();
    ui->loginBtn->setDefault(true);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_quitBtn_clicked()
{
    exit(0);
}

void LoginDialog::on_loginBtn_clicked()
{
    if(ui->acntLineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("请输入用户名"),tr("请输入用户名再登录!"),QMessageBox::Ok);
        ui->acntLineEdit->setFocus();
    }
    else if(ui->pwdLineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("请输入密码"),tr("请输入密码再登录!"),QMessageBox::Ok);
        ui->pwdLineEdit->setFocus();
    }
}
