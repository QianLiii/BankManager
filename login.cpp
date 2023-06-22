#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login),
    mode(false)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
    this->setWindowTitle("登录");
    connect(&mw, SIGNAL(signOut()), this, SLOT(return_from_MW()));
    connect(&mng_mw, SIGNAL(signOut()), this, SLOT(return_from_MNG_MW()));

}

Login::~Login()
{
    delete ui;
}

void Login::on_LoginButton_clicked()
{
    //    判断用户名、密码是否为空
    if(ui->Username->text() == "" || ui->Password->text() == "")
    {
        Okbox okbox(this, "错误", "用户名或密码不能为空！");
        okbox.exec();
        ui->Username->clear();
        ui->Password->clear();
        ui->Username->setFocus();
    }
    else
    {
        QSqlDatabase db = Ui::DB_connection::db;
        QSqlQuery q1(Ui::DB_connection::db);
        //    用户登录
        if(mode == false)
        {

            if(!q1.exec("select CLIENT_ID,PASSWORD from client"))
            {
               qDebug()<<"error:"<<q1.lastError();
            }
            else
            {
                 // 切换界面
                 q1.last();
                 int count = q1.at()+1;
                 q1.first();
                 q1.previous();
                 while(q1.next())
                 {
                     QString CLIENT_ID = q1.value(0).toString();
                     QString PASSWORD = q1.value(1).toString();
                     if(ui->Username->text() == CLIENT_ID && ui->Password->text() == PASSWORD)
                     {
                         QSqlQuery q_name(Ui::DB_connection::db);
                         if(!q_name.exec(QString("select CLIENT_NAME from client where CLIENT_ID = %1").arg(CLIENT_ID)))
                         {
                             qDebug()<<q_name.lastError();
                         }
                         else
                         {
                             q_name.next();
                             QString NAME = q_name.value(0).toString();
                             connect(this, SIGNAL(send_to_MW(QString, QString)), &mw, SLOT(receiveData(QString, QString)));
                             emit send_to_MW(CLIENT_ID, NAME);
                             this->close();
                             mw.show();
                             break;
                         }
                     }
                     --count;
                 }
                 if(count == 0)
                 {
                     Okbox okbox(this, "错误", "用户名或密码错误！");
                     okbox.exec();
                     ui->Username->clear();
                     ui->Password->clear();
                     ui->Username->setFocus();
                 }
            }


        }
        //    管理员登录
        else
        {
            if(!q1.exec("select ADMIN_NAME,PASSWORD from administrator"))
            {
               qDebug()<<"error:"<<q1.lastError();
            }
            else
            {
                 // 切换界面
                 q1.last();
                 int count = q1.at()+1;
                 q1.first();
                 q1.previous();
                 while(q1.next())
                 {
                     QString ADMIN_NAME = q1.value(0).toString();
                     QString PASSWORD = q1.value(1).toString();
                     if(ui->Username->text() == ADMIN_NAME && ui->Password->text() == PASSWORD)
                     {
                         this->close();
                         mng_mw.show();
                         break;
                     }
                     --count;
                 }
                 if(count == 0)
                 {
                     Okbox okbox(this, "错误", "账号或密码错误！");
                     okbox.exec();
                     ui->Username->clear();
                     ui->Password->clear();
                     ui->Username->setFocus();
                 }
            }
        }
    }

}

//登出信号槽
void Login::return_from_MW()
{
    mw.close();
    this->show();
    ui->Username->clear();
    ui->Password->clear();
    ui->Username->setFocus();
}

void Login::return_from_MNG_MW()
{
    mng_mw.close();
    this->show();
    ui->Username->clear();
    ui->Password->clear();
    ui->Username->setFocus();
}

//切换登录模式
void Login::on_SwitchModeButton_clicked()
{
    mode = !mode;
    if(mode == true)
    {
        ui->label->setText("管理ID");
        ui->SwitchModeButton->setText("用户模式");
    }
    else
    {
        ui->label->setText("用户名");
        ui->SwitchModeButton->setText("管理员模式");
    }

}

