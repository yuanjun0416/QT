#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(switch_test(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switch_test(QString data){
    switch(data.toInt()){
    case 1:
        ui->pushButton->setText("1");
        break;
    case 2:
        ui->pushButton->setText("2");
        break;
    case 3:
        ui->pushButton->setText("3");
        break;
    default :
        ui->pushButton->setText("");
        break;
    }
}
