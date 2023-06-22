#ifndef MANAGER_MAINWINDOW_H
#define MANAGER_MAINWINDOW_H

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
    void signOut();

private slots:
    void on_ReturnButton_clicked();

private:
    Ui::Manager_MainWindow *ui;
};

#endif // MANAGER_MAINWINDOW_H
