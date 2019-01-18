#include <QHeaderView>
#include <QApplication>
#include "basemanagewidget.h"

BaseManageWidget::BaseManageWidget(QWidget *parent) :
    QWidget(parent)
{
    model=new QSqlTableModel(this);
    layout=new QVBoxLayout(this);

    b_btn_1=new QPushButton;
    b_btn_2=new QPushButton;
    b_btn_3=new QPushButton;
    b_btn_1->setText("添加");
    b_btn_2->setText("修改");
    b_btn_3->setText("详情");

    b_layout=new QHBoxLayout;
    b_layout->addWidget(b_btn_1);
    b_layout->addWidget(b_btn_2);
    b_layout->addWidget(b_btn_3);

    tableView=new QTableView;

    layout->addWidget(tableView);
    layout->addLayout(b_layout);

    //信号和槽关联
    connect(b_btn_1,QPushButton::clicked,this,add);
    connect(b_btn_2,QPushButton::clicked,this,edit);
    connect(b_btn_3,QPushButton::clicked,this,detail);

}
void BaseManageWidget::init(const QString &tableName){
    model->setTable(tableName);
    //model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->setModel(model);
    tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableView->show();
}
void BaseManageWidget::add(){
    mryaw=new MannagerRenYuanAddWidget;
    mryaw->show();
}
void BaseManageWidget::edit(){
    qDebug("edit");
}
void BaseManageWidget::detail(){
    qDebug("detail");
}

BaseManageWidget::~BaseManageWidget()
{
    //delete ui;
}
