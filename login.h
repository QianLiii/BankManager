#ifndef LOGIN_H
#define LOGIN_H

#include "mainwindow.h"
#include "manager_mainwindow.h"
#include "db_connection.h"
#include "okbox.h"

#include <QDialog>
#include <QString>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QDebug>

namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

signals:
//    给用户MainWindow传信号
    void send_to_MW(QString, QString);

private slots:
    void on_LoginButton_clicked();
    void on_SwitchModeButton_clicked();

//    登出按钮槽
    void return_from_MW();
    void return_from_MNG_MW();

private:
    Ui::Login *ui;
    bool mode;//    界面模式，默认为false用户模式
    MainWindow mw;
    Manager_MainWindow mng_mw;

//    每个需要使用db_connection.h的文件都要拥有一个DB_conn，在它的构造函数里才能完成数据库的连接，否则无法连接到数据库
    Ui::DB_connection DB_conn;
};

#endif // LOGIN_H
