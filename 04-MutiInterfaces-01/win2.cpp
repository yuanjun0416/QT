#include "win2.h"
#include "ui_win2.h"

win2::win2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win2)
{
    ui->setupUi(this);
}

win2::~win2()
{
    delete ui;
}

void win2::on_closewin2_clicked()
{
    this->close();
}

void win2::receive_from_mainwindow(QString data){
    ui->win2textBrowser->setText(data);
}


void win2::on_sendtowin1_clicked()
{
    emit this->send_to_mainwindow(ui->win2textEdit->toPlainText());
}

