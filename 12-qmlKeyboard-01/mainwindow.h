#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <keyboard.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void do_keyboardSingal(QString s);

private:
    Ui::MainWindow *ui;
    Keyboard *mykeyboard;
};
#endif // MAINWINDOW_H
