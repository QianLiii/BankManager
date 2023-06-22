#include "clients_inspect.h"
#include "ui_clients_inspect.h"

Clients_inspect::Clients_inspect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clients_inspect)
{
    ui->setupUi(this);
}

Clients_inspect::~Clients_inspect()
{
    delete ui;
}

void Clients_inspect::receiveData()
{

}

void Clients_inspect::on_ReturnButton_clicked()
{
    emit backSignal();
}

