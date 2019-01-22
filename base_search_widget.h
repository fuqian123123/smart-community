#ifndef BASE_SEARCH_WIDGET_H
#define BASE_SEARCH_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>

class BaseSearchWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseSearchWidget(QWidget *parent = 0);
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *btn_1,*btn_2;
    QHBoxLayout *h_layout_1,*h_layout_2;
    QVBoxLayout *layout;
    void clear();
signals:
    void entered(const QString &key);
protected slots:
    void sendSignal();
};

#endif // BASE_SEARCH_WIDGET_H
