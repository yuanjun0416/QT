#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtTextToSpeech/QTextToSpeech>
#include <qdebug.h>

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

    void on_start_clicked(bool checked);

    void on_pause_clicked(bool checked);

    void on_rate_valueChanged(double arg1);

    void on_pitch_valueChanged(double arg1);

    void on_volume_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    QTextToSpeech * texttospeech;
};
#endif // MAINWINDOW_H
