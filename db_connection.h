#ifndef UI_DB_CONNECTION_H
#define UI_DB_CONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QDebug>

namespace Ui {

class DB_connection
{
public:
    DB_connection();
    static QSqlDatabase db;

};

} // namespace Ui

#endif // UI_DB_CONNECTION_H
