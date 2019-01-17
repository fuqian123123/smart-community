#include <QApplication>
#include "logindialog.h"
#include "sqlmannager.h"
#include "mannagerform.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SQLMannager sqlmannager("39.107.243.32","root","mysql--123","smart_community");
    sqlmannager.Connect();

    LoginDialog ld;
    ld.show();
    return a.exec();
}
