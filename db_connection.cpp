#include "db_connection.h"

namespace Ui {

QSqlDatabase DB_connection::db = QSqlDatabase::database("QSQLITE");

DB_connection::DB_connection()
{
            if(QSqlDatabase::contains("tiny-connection"))
            {
                db = QSqlDatabase::database("tiny-connection");
            }
            else
            {
                db = QSqlDatabase::addDatabase("QSQLITE", "tiny-connection");
                db.setDatabaseName("bank.db");
            }
            if(!db.open())
            {
                qDebug()<<"Error:"<<db.lastError();
            }
}

} // namespace Ui
