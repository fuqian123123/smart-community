#include "base_detail_widget.h"

BaseDetailWidget::BaseDetailWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(350,100);
}
void BaseDetailWidget::loadData(const QString &key){}
