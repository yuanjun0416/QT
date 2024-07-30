#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mykeyboard = new Keyboard;

    connect(mykeyboard, &Keyboard::keyboardSingal, this, &MainWindow::do_keyboardSingal);  // 连接信号keyboardSingal与槽do_keyboardSingal
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mykeyboard->show();
}

void MainWindow::do_keyboardSingal(QString s){
    qDebug() << s;
    ui->pushButton->setText(s);  // 显示
}

