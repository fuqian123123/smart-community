#include <QApplication>
#include <QTextCodec>
#include <QIcon>
#include "login_dialog.h"
#include "sqlmanager.h"
#include "manager_form.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));

    SQLManager sqlmanager("39.107.243.32","smartCommunity","sm<>?123","smart_community");
    sqlmanager.Connect();

    LoginDialog ld;
    ld.show();
    return a.exec();
}
