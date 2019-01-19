#ifndef BASE_DETAIL_WIDGET_H
#define BASE_DETAIL_WIDGET_H

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class BaseDetailWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BaseDetailWidget(QWidget *parent = 0);
    void loadData(const QString &key);
protected:
    QVBoxLayout* layout;
};

#endif // BASE_DETAIL_WIDGET_H
