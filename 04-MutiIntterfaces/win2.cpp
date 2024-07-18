#include "win2.h"
#include "ui_win2.h"

win2::win2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::win2)
{
    ui->setupUi(this);

    QObject::connect(ui->closewin2, &QPushButton::clicked, [=](){
        emit this->back();
    });
}

win2::~win2()
{
    delete ui;
}
