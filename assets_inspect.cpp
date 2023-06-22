#include "assets_inspect.h"
#include "ui_assets_inspect.h"

Assets_inspect::Assets_inspect(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Assets_inspect)
{
    ui->setupUi(this);

}

Assets_inspect::~Assets_inspect()
{
    delete ui;
}

void Assets_inspect::receiveData(QString c_id)
{
    client_id = c_id;
    mdl = new QSqlQueryModel(this);
    QString sql = QString("select P_NO as '产品编号', F_NAME as '产品名称', STATUS as '资产状态', "
                          "START_DATE as '购买日期', AMOUNT as '数量', PROFIT as '收益' from "
                          "PURCHASE_FUND, FUND where OWNER_ID = '%1' and P_NO = F_NO "
                          "union "
                          "select P_NO as '产品编号', I_NAME as '产品名称', STATUS as '资产状态', "
                          "START_DATE as '购买日期', AMOUNT as '数量', PROFIT as '收益' from "
                          "PURCHASE_INSURANCE, INSURANCE where OWNER_ID = '%1' and P_NO = I_NO "
                          "union "
                          "select P_NO as '产品编号', W_NAME as '产品名称', STATUS as '资产状态', "
                          "START_DATE as '购买日期', AMOUNT as '数量', PROFIT as '收益' from "
                          "PURCHASE_WEALTH, WEALTH_MANAGEMENT where OWNER_ID = '%1' and P_NO = W_NO ").arg(client_id);
    mdl->setQuery(sql, Ui::DB_connection::db);



    ui->tableView->setModel(mdl);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
}

void Assets_inspect::on_ReturnButton_clicked()
{
    emit backSignal();
}
