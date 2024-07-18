#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->win_2=new win2;

    QObject::connect(ui->openwin2, &QPushButton::clicked, [=](){
        this->hide();

        win_2->show();
    });

    QObject::connect(this->win_2, &win2::back, [=](){
        win_2->hide();
        this->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
