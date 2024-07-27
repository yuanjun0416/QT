#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitBackground();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->centralwidget->setStyleSheet(color);
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    color = arg1;

    QSettings *setting = new QSettings("C:/Qt/09-changeBackgroundColor/setting.ini", QSettings::IniFormat);
    setting->beginGroup("backgroundColor");
    setting->setValue("color", color);
    setting->endGroup();
    delete setting;
}

void MainWindow::InitBackground(){
    QSettings *setting = new QSettings("C:/Qt/09-changeBackgroundColor/setting.ini", QSettings::IniFormat);
    setting->beginGroup("backgroundColor");
    color = setting->value("color", "").toString();
    setting->endGroup();
    delete setting;

    on_pushButton_clicked();
}
