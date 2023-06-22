#ifndef CONFIRMBOX_H
#define CONFIRMBOX_H

#include <QDialog>

namespace Ui {
class Confirmbox;
}

class Confirmbox : public QDialog
{
    Q_OBJECT

public:
    explicit Confirmbox(QWidget *parent = nullptr);
    explicit Confirmbox(QWidget *parent, QString, QString);
    ~Confirmbox();

private slots:
    void on_NoButton_clicked();

    void on_YesButton_clicked();

private:
    Ui::Confirmbox *ui;
};

#endif // CONFIRMBOX_H
