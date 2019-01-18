#include <QMessageBox>
#include <QSqlDatabase>
#include "logindialog.h"
#include "ui_logindialog.h"
#include "managerform.h"

/*登录页面*/
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    setFixedSize(400,300);
    setWindowTitle(tr("登录"));

    //三个radio button初始化
    qbg=new QButtonGroup();
    qbg->addButton(ui->adminRadioBtn);
    qbg->addButton(ui->staffRadioBtn);
    qbg->addButton(ui->ownerRadioBtn);
    qbg->setId(ui->adminRadioBtn,1);
    qbg->setId(ui->staffRadioBtn,2);
    qbg->setId(ui->ownerRadioBtn,3);

    //model初始化
    model=new QSqlTableModel(this);

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
        QMessageBox::information(this,tr("请输入账号"),tr("请输入账号再登录!"),QMessageBox::Ok);
        ui->acntLineEdit->setFocus();
    }
    else if(ui->pwdLineEdit->text().isEmpty()){
        QMessageBox::information(this,tr("请输入密码"),tr("请输入密码再登录!"),QMessageBox::Ok);
        ui->pwdLineEdit->setFocus();
    }
    else{
        QString account_num=ui->acntLineEdit->text();
        QString password=ui->pwdLineEdit->text();

        quint16 type=qbg->checkedId();
        model->setTable("user");
        QString filter=QString("account_num='%1'and u_password='%2' and u_type='%3'")
                .arg(account_num,password,QString::number(type,10));
        model->setFilter(filter);
        model->select();
        if(model->rowCount()>0){
            QMessageBox::information(this,tr("成功"),tr("登录成功!"),QMessageBox::Ok);
            switch (type) {
            //管理员
            case 1:
                mf=new MannagerForm;
                mf->show();
                break;
            //工作人员
            case 2:
                break;
            //业主
            case 3:
                break;
            default:
                break;
            }
            this->hide();
        }
        else{
            QMessageBox::information(this,tr("失败"),tr("登录失败!"),QMessageBox::Ok);
            ui->pwdLineEdit->setText("");
        }
    }
}
