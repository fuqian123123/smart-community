#include <QApplication>
#include "logindialog.h"
#include "sqlmanager.h"
#include "managerform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLManager sqlmanager("39.107.243.32","root","mysql--123","smart_community");
    sqlmanager.Connect();

    LoginDialog ld;
    ld.show();
    return a.exec();
}
