#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValueAxis>
#include <QLineSeries>
#include <QPointF>

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

private:
    Ui::MainWindow *ui;
    void chart_init();
    QChart *chart_1;

private slots:
    void do_mouseMoveEvent(QPoint point);
};
#endif // MAINWINDOW_H
