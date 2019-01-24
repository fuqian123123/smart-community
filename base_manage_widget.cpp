#include <QHeaderView>
#include <QApplication>
#include <QMessageBox>
#include "base_manage_widget.h"

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    this->setWindowIcon(QIcon(":/myres/images/icons/community.png"));
    this->setWindowTitle("智慧小区");
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
void BaseManageWidget::setMajorKey(QString &key){
    int rowNum=tableView->currentIndex().row();
    QAbstractItemModel *qaim = tableView->model();
    QModelIndex qmi=qaim->index(rowNum,0);
    QVariant qv=qaim->data(qmi);
    key=qv.toString();
}

void BaseManageWidget::init(){}
void BaseManageWidget::add(){}
void BaseManageWidget::edit(){}
void BaseManageWidget::detail(){}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
