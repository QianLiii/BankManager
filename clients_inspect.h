#ifndef CLIENTS_INSPECT_H
#define CLIENTS_INSPECT_H

#include "db_connection.h"

#include <QMainWindow>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>

namespace Ui {
class Clients_inspect;
}

class Clients_inspect : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clients_inspect(QWidget *parent = nullptr);
    ~Clients_inspect();

signals:
    void backSignal();

private slots:
    void receiveData();
    void on_ReturnButton_clicked();

private:
    Ui::Clients_inspect *ui;
    Ui::DB_connection DB_conn;

};

#endif // CLIENTS_INSPECT_H
