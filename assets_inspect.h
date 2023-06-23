#ifndef ASSETS_INSPECT_H
#define ASSETS_INSPECT_H

#include "db_connection.h"
#include "textreplacerdelegate.h"

#include <QMainWindow>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>

namespace Ui {
class Assets_inspect;
}

class Assets_inspect : public QMainWindow
{
    Q_OBJECT

public:
    explicit Assets_inspect(QWidget *parent = nullptr);
    ~Assets_inspect();


signals:
    void backSignal();
private slots:
    void receiveData(QString c_id);
    void on_ReturnButton_clicked();

private:
    Ui::Assets_inspect *ui;
    QSqlQueryModel *mdl;
    Ui::DB_connection DB_conn;
    QString client_id;
};

#endif // ASSETS_INSPECT_H
