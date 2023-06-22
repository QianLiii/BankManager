#ifndef MANAGER_VIEW_H
#define MANAGER_VIEW_H

#include "db_connection.h"
#include "okbox.h"
#include "confirmbox.h"

#include <QMainWindow>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QDebug>
#include <QSqlQueryModel>
#include <QDateTime>

namespace Ui {
class Manager_View;
}

class Manager_View : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager_View(int type, QWidget *parent = nullptr);
    ~Manager_View();

private slots:
    void receiveData();
    void on_ReturnButton_clicked();

signals:
    void backSignal();

private:
    Ui::Manager_View *ui;
    //    0-fund, 1-insurance, 2-wealth
    int wd_type;
    Ui::DB_connection DB_conn;
};

#endif // MANAGER_VIEW_H
