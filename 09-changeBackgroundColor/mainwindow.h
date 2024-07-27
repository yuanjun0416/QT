#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

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

    void InitBackground();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;

    QString color = "background-color: rgb(170, 255, 255)";
};
#endif // MAINWINDOW_H
