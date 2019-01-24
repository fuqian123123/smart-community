#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "login_dialog.h"
#include "ui_logindialog.h"
#include "manager_form.h"

/*登录页面*/
QString GLOBAL_ACCOUNT_NUM;
LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/myres/images/icons/community.png"));
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
void LoginDialog::setLogined(const QString &key){
    QSqlQuery query;
    QString str=QString("update user set u_flag=1"
                        " where account_num='%1'").arg(key);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
        return ;
    }
}

void LoginDialog::on_quitBtn_clicked()
{
    exit(0);
}
bool LoginDialog::isLogin(const QString &key){
    QSqlQuery query;
    QString str=QString("select u_flag from user"
                        " where account_num='%1'").arg(key);
    if(!query.exec(str)){
        QMessageBox::information(this,tr("错误"),tr("加载失败!"),QMessageBox::Ok);
        return false;
    }
    query.next();
    int flag=query.value(0).toInt();
    if(flag==0)
        return true;
    return false;
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
            if(!isLogin(account_num)){
                QMessageBox::information(this,tr("提示"),tr("该用户已在线!"),QMessageBox::Ok);
                return ;
            }
            this->setLogined(account_num);
            QMessageBox::information(this,tr("成功"),tr("登录成功!"),QMessageBox::Ok);
            GLOBAL_ACCOUNT_NUM=ui->acntLineEdit->text();//记录登录人员的账号
            switch (type) {
            //管理员
            case 1:
                mf=new ManagerForm;
                mf->show();
                break;
            //工作人员
            case 2:
                sf=new StaffForm;
                sf->show();
                break;
            //业主
            case 3:
                of=new OwnerForm;
                of->show();
                break;
            default:
                break;
            }
            //this->hide();
        }
        else{
            QMessageBox::information(this,tr("失败"),tr("登录失败!"),QMessageBox::Ok);
            ui->pwdLineEdit->setText("");
        }
    }
}
