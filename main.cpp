#include "mainwindow.h"
#include "logindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    ld.show();
    //MainWindow w;
    //w.show();

    return a.exec();
}
