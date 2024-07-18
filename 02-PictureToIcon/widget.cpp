#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->radioButton_32->setChecked(true);
    this->width = 32;
    this->height = 32;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::select_radioButton()
{
    if(ui->radioButton_16->isChecked()){
        qDebug() << "16x16";
        this->width = 16;
        this->height = 16;
    }
    else if(ui->radioButton_32->isChecked()){
        qDebug() << "32x32";
        this->width = 32;
        this->height = 32;
    }
    else if(ui->radioButton_64->isChecked()){
        qDebug() << "64x64";
        this->width = 64;
        this->height = 64;
    }
    else if(ui->radioButton_128->isChecked()){
        qDebug() << "128x128";
        this->width = 128;
        this->height = 128;
    }
}

void Widget::on_pushButton_select_clicked()
{
    qDebug() << "on_pushButton_select_clicked";
    select_radioButton();

    filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                ".",
                                                tr("Images (*.png *.xpm *.jpg)"));
    qDebug() << "filename:" << filePath;
    QFileInfo qfileinfo(filePath);
    ui->label_filename->setText(qfileinfo.fileName());

    QPixmap map(filePath);
    newmap = map.scaled(width, height);

    ui->label_preview->setPixmap(newmap);
}


void Widget::on_pushButton_preview_clicked()
{
    select_radioButton();
    newmap = newmap.scaled(width, height);
    ui->label_preview->setPixmap(newmap);
}


void Widget::on_pushButton_delete_clicked()
{
    ui->label_filename->clear();
    ui->label_preview->clear();
    filePath.clear();
}





void Widget::on_pushButton_4_clicked()
{
    select_radioButton();
    QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Save File"),
                                            ".",
                                            tr("Images (*ico)"));
    newmap.save(saveFilePath);
}

