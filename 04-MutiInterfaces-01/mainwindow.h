#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <win2.h>

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
    void on_openwin2_clicked();

    void on_sendtowin2_clicked();

    void receive_from_win2(QString data);

signals:
    void sendtowin2(QString data);

private:
    Ui::MainWindow *ui;
    win2 *win_2;
};
#endif // MAINWINDOW_H
