#include <QWidget>
#include <QLabel>
#include <QTableView>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "mannagerform.h"
#include "ui_mannagerform.h"
#include "basemanagewidget.h"

/*管理员主界面*/
MannagerForm::MannagerForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MannagerForm)
{
    ui->setupUi(this);
    this->resize(800,500);

    //页面头部
    ui->h_lable->setText("智慧小区>管理员");
    ui->h_btn1->setText("人员管理");
    ui->h_btn2->setText("考勤管理");
    QHBoxLayout* h_layout1=new QHBoxLayout();
    h_layout1->addWidget(ui->h_btn1);
    h_layout1->addWidget(ui->h_btn2);

    //页面中部
    BaseManageWidget *bmw=new BaseManageWidget;
    QStackedWidget* c_stackedWidget=new QStackedWidget(this);
    c_stackedWidget->addWidget(bmw);

    //页面底部
    QVBoxLayout* layout=new QVBoxLayout(this);
    ui->b_btn1->setText("退出");

    //排版
    layout->addWidget(ui->h_lable);
    layout->addLayout(h_layout1);
    layout->addWidget(c_stackedWidget);
    layout->addWidget(ui->b_btn1);
    layout->setMargin(0);
    layout->setSpacing(15);
    layout->setContentsMargins(10,10,10,10);
}

MannagerForm::~MannagerForm()
{
    delete ui;
}

void MannagerForm::on_b_btn1_clicked()
{
    exit(0);
}
