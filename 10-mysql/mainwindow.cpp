#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connectsql();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectsql()
{
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");  // 也可以使用 db.setHostName("localhost"); HostName一般的IP地址为127.0.0.1
    db.setPort(3306);  // 端口
    db.setDatabaseName("qt");  // Data Source name, 不是DatabaseName
    db.setUserName("root");  // 用户名
    db.setPassword("**********");  // 用户名密码
    db.open();
    bool ok=db.open();
    if(ok)
    {
        qDebug()<<"数据库连接成功！";
    }
    else
    {
        QMessageBox::information(this,"infor", "link failed");
        qDebug()<<"error open database because"<<db.lastError().text();
    }
}
