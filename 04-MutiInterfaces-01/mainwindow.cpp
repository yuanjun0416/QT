#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    win_2 = new win2;

    connect(this, SIGNAL(sendtowin2(QString)), win_2, SLOT(receive_from_mainwindow(QString)));

    connect(win_2, SIGNAL(send_to_mainwindow(QString)), this, SLOT(receive_from_win2(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openwin2_clicked()
{
    win_2->show();
}


void MainWindow::on_sendtowin2_clicked()
{
    emit this->sendtowin2(ui->win1textEdit->toPlainText());
}

void MainWindow::receive_from_win2(QString data){
    ui->win1textBrowser->setText(data);
}
