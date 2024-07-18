#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    texttospeech = new QTextToSpeech;
    texttospeech->setLocale(QLocale::Chinese);
    texttospeech->setRate(1.0);
    texttospeech->setPitch(1.0);
    texttospeech->setVolume(1.0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_start_clicked(bool checked)
{
    if (checked){
        qDebug("开始");
        texttospeech->say(ui->textEdit->toPlainText());
        ui->start->setText("停止");
    }else{
        qDebug() << "停止";
        texttospeech->stop();
        ui->start->setText("开始");
    }
}


void MainWindow::on_pause_clicked(bool checked)
{
    if (checked){
        texttospeech->pause();
        ui->pause->setText("恢复");
    }else{
        texttospeech->resume();
        ui->pause->setText("暂停");
    }
}


void MainWindow::on_rate_valueChanged(double arg1)
{
    texttospeech->setRate(arg1);
}


void MainWindow::on_pitch_valueChanged(double arg1)
{
    texttospeech->setPitch(arg1);
}




void MainWindow::on_volume_valueChanged(double arg1)
{
    texttospeech->setVolume(arg1);
}

