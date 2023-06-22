#include "manager_mainwindow.h"
#include "ui_manager_mainwindow.h"

Manager_MainWindow::Manager_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manager_MainWindow)
{
    ui->setupUi(this);
}

Manager_MainWindow::~Manager_MainWindow()
{
    delete ui;
}

//登出按钮信号
void Manager_MainWindow::on_ReturnButton_clicked()
{
    emit signOut();
}

