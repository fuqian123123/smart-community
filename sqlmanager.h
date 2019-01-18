#ifndef SQLMANNAGER_H
#define SQLMANNAGER_H

#include <QString>
#include <QSqlDatabase>

class SQLManager
{
private:
    const QString hostName,userName,password,databaseName;
    QSqlDatabase db;

public:
    SQLManager(const QString &h,const QString &u,const QString &p,const QString &d);
    void Connect();
};

#endif // SQLMANNAGER_H
