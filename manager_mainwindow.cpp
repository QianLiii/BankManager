#include "manager_mainwindow.h"
#include "ui_manager_mainwindow.h"

Manager_MainWindow::Manager_MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manager_MainWindow),
    fm(0),
    im(1),
    wm(2)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    //    返回按钮通信
    connect(&fm, SIGNAL(backSignal()), this, SLOT(return_from_Fm()));
    connect(&wm, SIGNAL(backSignal()), this, SLOT(return_from_Wm()));
    connect(&im, SIGNAL(backSignal()), this, SLOT(return_from_Im()));
    connect(&ci, SIGNAL(backSignal()), this, SLOT(return_from_Ci()));

    //    加载子窗口
    connect(this, SIGNAL(send_to_Fm()), &fm, SLOT(receiveData()));
    connect(this, SIGNAL(send_to_Wm()), &wm, SLOT(receiveData()));
    connect(this, SIGNAL(send_to_Im()), &im, SLOT(receiveData()));
    connect(this, SIGNAL(send_to_Ci()), &ci, SLOT(receiveData()));

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

//点击事件
void Manager_MainWindow::on_FundButton_clicked()
{
    emit send_to_Fm();
    this->close();
    fm.show();
}


void Manager_MainWindow::on_InsuranceButton_clicked()
{
    emit send_to_Im();
    this->close();
    im.show();
}


void Manager_MainWindow::on_WealthButton_clicked()
{
    emit send_to_Wm();
    this->close();
    wm.show();
}


void Manager_MainWindow::on_AssetsButton_clicked()
{
    emit send_to_Ci();
    this->close();
    ci.show();
}

//接收返回信号的槽
void Manager_MainWindow::return_from_Fm()
{
    this->show();
    fm.close();
}

void Manager_MainWindow::return_from_Im()
{
    this->show();
    im.close();
}

void Manager_MainWindow::return_from_Wm()
{
    this->show();
    wm.close();
}

void Manager_MainWindow::return_from_Ci()
{
    this->show();
    ci.close();
}
