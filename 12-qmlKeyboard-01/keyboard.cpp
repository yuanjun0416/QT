#include "keyboard.h"
#include "ui_keyboard.h"

Keyboard::Keyboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Keyboard)
{
    ui->setupUi(this);

    ui->keyboard_1->setSource(QUrl("qrc:/keyboard.qml"));

    QObject *key_board = (QObject*) ui->keyboard_1->rootObject();  // 将QQuickItem* 强制转化为 QObject*(必须有这个)
    connect(key_board, SIGNAL(qmlCloseSignal()), this, SLOT(close()));
    connect(key_board, SIGNAL(qmlSendSignal(QVariant)), this, SLOT(do_qmlSendSingal(QVariant)));
}

Keyboard::~Keyboard()
{
    delete ui;
}

void Keyboard::do_qmlSendSingal(QVariant data){
    QString data_1 = data.toString();
    emit keyboardSingal(data_1);  // 发送信号
}
