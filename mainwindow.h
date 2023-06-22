#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <user_view.h>
#include <assets_inspect.h>


#include <QMainWindow>
#include <QDebug>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
//    拥有的子窗口
    User_View fu;
    User_View iu;
    User_View wu;
    Assets_inspect ai;
//要传递的信息
    QString client_id;

signals:
//    传递给子窗口的信号
    void send_to_Fu(QString);
    void send_to_Wu(QString);
    void send_to_Iu(QString);
    void send_to_Ai(QString);

    void signOut();

private slots:
    void receiveData(QString c_id, QString name);
    void on_ReturnButton_clicked();
//    接收返回信号
    void return_from_Fu();
    void return_from_Iu();
    void return_from_Wu();
    void return_from_Ai();

//    点击事件
    void on_FundButton_clicked();
    void on_InsuranceButton_clicked();
    void on_WealthButton_clicked();
    void on_AssetsButton_clicked();
};


#endif // MAINWINDOW_H
