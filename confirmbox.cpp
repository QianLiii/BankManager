#include "confirmbox.h"
#include "ui_confirmbox.h"

Confirmbox::Confirmbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Confirmbox)
{
    ui->setupUi(this);
}

Confirmbox::Confirmbox(QWidget *parent, QString title, QString text) :
QDialog(parent),
  ui(new Ui::Confirmbox)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    this->setWindowTitle(title);
    ui->textBrowser->setText(text);
}

Confirmbox::~Confirmbox()
{
    delete ui;
}

void Confirmbox::on_NoButton_clicked()
{
    this->close();
}


void Confirmbox::on_YesButton_clicked()
{
    this->done(1);
}

