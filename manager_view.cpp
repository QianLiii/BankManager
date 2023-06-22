#include "manager_view.h"
#include "ui_manager_view.h"

Manager_View::Manager_View(int type, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Manager_View),
    wd_type(type)
{
    ui->setupUi(this);
}

Manager_View::~Manager_View()
{
    delete ui;
}

void Manager_View::on_ReturnButton_clicked()
{
    emit backSignal();
}

//打开窗口
void Manager_View::receiveData()
{
//    基金
    if(wd_type == 0)
    {

    }
//    保险
    else if(wd_type == 1)
    {

    }
//    理财
    else
    {

    }
}
