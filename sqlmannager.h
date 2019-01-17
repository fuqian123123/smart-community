#ifndef SQLMANNAGER_H
#define SQLMANNAGER_H

#include <QSqlDatabase>
#include <QString>

class SQLMannager
{
private:
    const QString hostName,userName,password,databaseName;
    QSqlDatabase db;

public:
    SQLMannager(const QString &h,const QString &u,const QString &p,const QString &d);
    void Connect();
};

#endif // SQLMANNAGER_H
