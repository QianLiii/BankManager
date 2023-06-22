#ifndef MANAGER_MAINWINDOW_H
#define MANAGER_MAINWINDOW_H

#include "manager_view.h"
#include "clients_inspect.h"

#include <QMainWindow>

namespace Ui {
class Manager_MainWindow;
}

class Manager_MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit Manager_MainWindow(QWidget *parent = nullptr);
    ~Manager_MainWindow();

signals:
    //    传递给子窗口的信号（仅起加载界面作用）
    void send_to_Fm();
    void send_to_Wm();
    void send_to_Im();
    void send_to_Ci();

    void signOut();

private slots:
    void on_ReturnButton_clicked();

    //    接收返回信号
    void return_from_Fm();
    void return_from_Im();
    void return_from_Wm();
    void return_from_Ci();

//    点击事件
    void on_FundButton_clicked();
    void on_InsuranceButton_clicked();
    void on_WealthButton_clicked();
    void on_AssetsButton_clicked();

private:
    Ui::Manager_MainWindow *ui;
    //    拥有的子窗口
    Manager_View fm;
    Manager_View im;
    Manager_View wm;
    Clients_inspect ci;

};

#endif // MANAGER_MAINWINDOW_H
