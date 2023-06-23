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
    if(mdl->isDirty())
    {
        Confirmbox box(this, "提示", "确认要退出吗？所有未保存的修改将会丢失。");
        if(box.exec() == 1)
        {
            emit backSignal();
        }
    }
    else
    {
        emit backSignal();
    }

}

//打开窗口
void Manager_View::receiveData()
{
    mdl = new QSqlTableModel(this, Ui::DB_connection::db);
    mdl->setEditStrategy(QSqlTableModel::OnManualSubmit);
    ui->tableView->setModel(mdl);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    基金
    if(wd_type == 0)
    {
        mdl->setTable("fund");
        mdl->select();
    }
//    保险
    else if(wd_type == 1)
    {
        mdl->setTable("insurance");
        mdl->select();
    }
//    理财
    else if(wd_type == 2)
    {
        mdl->setTable("wealth_management");
        mdl->select();
    }
//    客户
    else
    {
        mdl->setTable("client");
        mdl->select();
        ui->tableView->setColumnHidden(5, true);
    }
}

void Manager_View::on_InsertButton_clicked()
{
    mdl->insertRow(mdl->rowCount());
}


void Manager_View::on_DeleteButton_clicked()
{
    mdl->removeRow(ui->tableView->currentIndex().row());
}


void Manager_View::on_SaveButton_clicked()
{
    if(!mdl->submitAll())
    {
        qDebug()<<mdl->lastError();
        Okbox failedbox(this, "提示", "保存失败，请检查数据有效性！");
    }
    else
    {
        Okbox okbox(this, "提示", "保存成功！");
        okbox.exec();
    }
}

