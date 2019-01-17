#ifndef MANNAGERFORM_H
#define MANNAGERFORM_H

#include <QWidget>

namespace Ui {
class MannagerForm;
}

class MannagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit MannagerForm(QWidget *parent = 0);
    ~MannagerForm();

private slots:
    void on_b_btn1_clicked();

private:
    Ui::MannagerForm *ui;
};

#endif // MANNAGERFORM_H
