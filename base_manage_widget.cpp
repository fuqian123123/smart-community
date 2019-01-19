#include <QHeaderView>
#include <QApplication>
#include <QMessageBox>
#include "base_manage_widget.h"

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    model=new QSqlTableModel(this);
    layout=new QVBoxLayout(this);

    b_btn_1=new QPushButton;
    b_btn_2=new QPushButton;
    b_btn_3=new QPushButton;
    b_layout=new QHBoxLayout;

    tableView=new QTableView;

    layout->addWidget(tableView);
    layout->addLayout(b_layout);

}
void BaseManageWidget::loadData(const QString &tableName){
    model->setTable(tableName);
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setModel(model);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->show();
}

void BaseManageWidget::init(){}
void BaseManageWidget::add(){}
void BaseManageWidget::edit(){}
void BaseManageWidget::detail(){}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
