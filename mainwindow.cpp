#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      fu(0),
      iu(1),
      wu(2)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
//    返回按钮通信
    connect(&fu, SIGNAL(backSignal()), this, SLOT(return_from_Fu()));
    connect(&wu, SIGNAL(backSignal()), this, SLOT(return_from_Wu()));
    connect(&iu, SIGNAL(backSignal()), this, SLOT(return_from_Iu()));
    connect(&ai, SIGNAL(backSignal()), this, SLOT(return_from_Ai()));

//    将身份信息传给子窗口
    connect(this, SIGNAL(send_to_Fu(QString)), &fu, SLOT(receiveData(QString)));
    connect(this, SIGNAL(send_to_Wu(QString)), &wu, SLOT(receiveData(QString)));
    connect(this, SIGNAL(send_to_Iu(QString)), &iu, SLOT(receiveData(QString)));
    connect(this, SIGNAL(send_to_Ai(QString)), &ai, SLOT(receiveData(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveData(QString c_id, QString name)
{
    ui->Welcome->setText("您好，"+name+"！");
    client_id = c_id;
}

//登出按钮信号
void MainWindow::on_ReturnButton_clicked()
{
    emit signOut();
}

//接收返回信号的槽
void MainWindow::return_from_Fu()
{
    this->show();
    fu.close();
}

void MainWindow::return_from_Iu()
{
    this->show();
    iu.close();
}

void MainWindow::return_from_Wu()
{
    this->show();
    wu.close();
}

void MainWindow::return_from_Ai()
{
    this->show();
    ai.close();
}

//点击按钮事件
void MainWindow::on_FundButton_clicked()
{
    emit send_to_Fu(client_id);
    this->close();
    fu.show();
}


void MainWindow::on_InsuranceButton_clicked()
{
    emit send_to_Iu(client_id);
    this->close();
    iu.show();
}


void MainWindow::on_WealthButton_clicked()
{
    emit send_to_Wu(client_id);
    this->close();
    wu.show();
}


void MainWindow::on_AssetsButton_clicked()
{
    emit send_to_Ai(client_id);
    this->close();
    ai.show();
}




