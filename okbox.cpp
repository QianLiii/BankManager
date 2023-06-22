#include "okbox.h"
#include "ui_okbox.h"

Okbox::Okbox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Okbox)
{
    ui->setupUi(this);
}

Okbox::Okbox(QWidget *parent, QString title, QString text) :
QDialog(parent),
  ui(new Ui::Okbox)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    this->setWindowTitle(title);
    ui->textBrowser->setText(text);
}

Okbox::~Okbox()
{
    delete ui;
}

void Okbox::on_pushButton_clicked()
{
    this->close();
}

