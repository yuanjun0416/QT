#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QWidget>

namespace Ui {
class Keyboard;
}

class Keyboard : public QWidget
{
    Q_OBJECT

public:
    explicit Keyboard(QWidget *parent = nullptr);
    ~Keyboard();

private:
    Ui::Keyboard *ui;

signals:
    void keyboardSingal(QString data);

private slots:
    void do_qmlSendSingal(QVariant data);
};

#endif // KEYBOARD_H
