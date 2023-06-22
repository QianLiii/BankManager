#ifndef USER_VIEW_H
#define USER_VIEW_H

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
class User_View;
}

class User_View : public QMainWindow
{
    Q_OBJECT

public:
    explicit User_View(int type, QWidget *parent = nullptr);
    ~User_View();

private slots:
    void receiveData(QString c_id);
    void on_ReturnButton_clicked();


    void on_PurchaseButton_clicked();

signals:
    void backSignal();
private:
//    0-fund, 1-insurance, 2-wealth
    int wd_type;

    Ui::User_View *ui;
    QSqlQueryModel *mdl;
    Ui::DB_connection DB_conn;
    QString client_id;
};

#endif // USER_VIEW_H
