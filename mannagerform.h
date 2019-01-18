#ifndef MANNAGERFORM_H
#define MANNAGERFORM_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QStackedWidget>
#include "basemanagewidget.h"

class MannagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit MannagerForm(QWidget *parent = 0);
    ~MannagerForm();
private:
    QLabel* h_label;
    QPushButton* h_btn1;
    QPushButton* h_btn2;
    QPushButton* b_btn;
    QVBoxLayout* layout;
    QHBoxLayout* h_layout;
    BaseManageWidget *bmw;
    QStackedWidget* c_stackedWidget;
};

#endif // MANNAGERFORM_H
