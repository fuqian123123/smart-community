#ifndef BASEMANAGEWIDGET_H
#define BASEMANAGEWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QTableView>
#include <QSqlQueryModel>


class BaseManageWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BaseManageWidget(QWidget *parent = 0);
    ~BaseManageWidget();    
protected:
    QPushButton* b_btn_1;
    QPushButton* b_btn_2;
    QPushButton* b_btn_3;
    QTableView* tableView;
    QVBoxLayout* layout;
    QHBoxLayout* b_layout;
    QSqlQueryModel* q_model;
    void init();
    void load(const QString &queryStr);
protected slots:
    void add();
    void edit();
    void detail();

};

#endif // BASEMANAGEWIDGET_H
