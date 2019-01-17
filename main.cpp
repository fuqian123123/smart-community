#include <QApplication>
#include "mainwindow.h"
#include "logindialog.h"
#include "sqlmannager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginDialog ld;
    ld.show();
    //MainWindow w;
    //w.show();
    SQLMannager sqlmannager("39.107.243.32","root","mysql--123","smart_community");
    sqlmannager.Connect();
    //qDebug("hehe");
    return a.exec();
}
