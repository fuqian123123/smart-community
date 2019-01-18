#ifndef BASEMANAGEWIDGET_H
#define BASEMANAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableView>
#include <QSqlTableModel>
#include "managerrenyuanaddwidget.h"


class BaseManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseManageWidget(QWidget *parent = 0);
    void init(const QString &tableName);
    ~BaseManageWidget();
public slots:
    void add();
    void edit();
    void detail();
protected:
    QPushButton* b_btn_1;
    QPushButton* b_btn_2;
    QPushButton* b_btn_3;
    QTableView* tableView;
    QVBoxLayout* layout;
    QHBoxLayout* b_layout;
    QSqlTableModel* model;
    MannagerRenYuanAddWidget* mryaw;
};

#endif // BASEMANAGEWIDGET_H
