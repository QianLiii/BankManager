#ifndef OKBOX_H
#define OKBOX_H

#include <QDialog>

namespace Ui {
class Okbox;
}

class Okbox : public QDialog
{
    Q_OBJECT

public:
    explicit Okbox(QWidget *parent = nullptr);
    explicit Okbox(QWidget *parent, QString, QString);
    ~Okbox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Okbox *ui;
};

#endif // OKBOX_H
