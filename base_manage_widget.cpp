#include <QHeaderView>
#include <QApplication>
#include <QMessageBox>
#include "base_manage_widget.h"

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    q_model=new QSqlQueryModel;

    layout=new QVBoxLayout(this);

    b_btn_1=new QPushButton;
    b_btn_2=new QPushButton;
    b_btn_3=new QPushButton;
    b_layout=new QHBoxLayout;

    tableView=new QTableView;

    layout->addWidget(tableView);
    layout->addLayout(b_layout);

}
void BaseManageWidget::load(const QString &queryStr){
    q_model->setQuery(queryStr);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->setModel(q_model);
}

void BaseManageWidget::init(){}
void BaseManageWidget::add(){}
void BaseManageWidget::edit(){}
void BaseManageWidget::detail(){}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
