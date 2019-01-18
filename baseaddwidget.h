#ifndef BASEADDWIDGET_H
#define BASEADDWIDGET_H

#include <QLabel>
#include <QObject>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class BaseAddWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseAddWidget(QWidget *parent = 0);
public slots:
    void enter();
    void clear();
protected:
    QPushButton* enter_btn;
    QPushButton* clear_btn;
    QHBoxLayout* b_layout;
    QVBoxLayout* layout;
    void init();
signals:

public slots:
};

#endif // BASEADDWIDGET_H
