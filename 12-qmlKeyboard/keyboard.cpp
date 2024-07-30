#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    ui->keyboard_1->setSource(QUrl("qrc:/keyboard.qml"));
}

Keyboard::~Keyboard()
{
    delete ui;
}
