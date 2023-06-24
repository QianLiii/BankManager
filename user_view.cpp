#include "user_view.h"
#include "ui_user_view.h"

User_View::User_View(int type, QWidget *parent) :
    QMainWindow(parent),
    wd_type(type),
    ui(new Ui::User_View)
{
    ui->setupUi(this);

}

User_View::~User_View()
{
    delete ui;
}

//打开窗口时，创建tableview
void User_View::receiveData(QString c_id)
{
    client_id = c_id;
    ui->PurchaseButton->setEnabled(false);
    mdl = new QSqlQueryModel(this);
    ui->tableView->setModel(mdl);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
//    项目委托
    TextReplacerDelegate* del = new TextReplacerDelegate(wd_type, this);
    ui->tableView->setItemDelegate(del);
//    选择模型
    sel_mdl = new QItemSelectionModel(mdl);
    ui->tableView->setSelectionModel(sel_mdl);
    connect(sel_mdl, SIGNAL(selectionChanged(QItemSelection,QItemSelection)), this, SLOT(selection_check()));

    if(wd_type == 0)
    {
        mdl->setQuery("select * from fund", Ui::DB_connection::db);
        mdl->setHeaderData(0, Qt::Horizontal, "编号");
        mdl->setHeaderData(1, Qt::Horizontal, "产品名称");
        mdl->setHeaderData(2, Qt::Horizontal, "产品类型");
        mdl->setHeaderData(3, Qt::Horizontal, "风险等级");
        mdl->setHeaderData(4, Qt::Horizontal, "发行者");
        mdl->setHeaderData(5, Qt::Horizontal, "金额");
    }
    else if(wd_type == 1)
    {
        mdl->setQuery("select * from insurance", Ui::DB_connection::db);
        mdl->setHeaderData(0, Qt::Horizontal, "编号");
        mdl->setHeaderData(1, Qt::Horizontal, "产品名称");
        mdl->setHeaderData(2, Qt::Horizontal, "适用人群");
        mdl->setHeaderData(3, Qt::Horizontal, "产品类型");
        mdl->setHeaderData(4, Qt::Horizontal, "保险年限");
        mdl->setHeaderData(5, Qt::Horizontal, "金额");
    }
    else
    {
        mdl->setQuery("select * from wealth_management", Ui::DB_connection::db);
        mdl->setHeaderData(0, Qt::Horizontal, "编号");
        mdl->setHeaderData(1, Qt::Horizontal, "产品名称");
        mdl->setHeaderData(2, Qt::Horizontal, "产品描述");
        mdl->setHeaderData(3, Qt::Horizontal, "产品年限");
        mdl->setHeaderData(4, Qt::Horizontal, "金额");
    }

}

void User_View::on_ReturnButton_clicked()
{
    emit backSignal();

}

void User_View::on_PurchaseButton_clicked()
{
    int current_row = ui->tableView->currentIndex().row();
    QString product_id = mdl->data(mdl->index(current_row, 0)).toString();
    qDebug()<<product_id<<" "<<client_id;
//    得到产品编号product_id， 用户编号client_id
    Confirmbox msgBox(this, "提示", "确认购买？");
    int ret = msgBox.exec();
    qDebug()<<ret;
    if(ret == 1){
        //插入一条数据
        QSqlQuery q_purchase(Ui::DB_connection::db);
        QString type_name;
        if(wd_type == 0)
        {
            type_name = "fund";
        }
        else if(wd_type == 1)
        {
            type_name = "insurance";
        }
        else
        {
            type_name = "wealth";
        }
//        已经存在，份数+1
        q_purchase.exec(QString("select * from purchase_%1 where P_NO='%2' and OWNER_ID='%3'")
                        .arg(type_name).arg(product_id).arg(client_id));
//        判断上面的查询是否有至少一条记录
        if(q_purchase.next())
        {
            q_purchase.exec(QString("update purchase_%1 set AMOUNT = AMOUNT+1 where P_NO='%1' and OWNER_ID='%2'")
                            .arg(type_name).arg(product_id).arg(client_id));
        }
//        没买过，则新建记录
        else
        {
            QString cur_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            QString sql = QString("insert into purchase_%1 values('%2', '%3', 1, '%4', 1, 0)")
                    .arg(type_name).arg(product_id).arg(client_id).arg(cur_time);
            if(!q_purchase.exec(sql))
            {
                qDebug()<<q_purchase.lastError();
            }
        }
        Okbox okBox(this, "提示", "购买成功！");
        okBox.exec();
    }
}

void User_View::selection_check()
{
    if(sel_mdl->hasSelection())
    {
        qDebug()<<"haha1";
        ui->PurchaseButton->setEnabled(true);
    }
    else
    {
        qDebug()<<"haha2";
        ui->PurchaseButton->setEnabled(false);
    }
}
