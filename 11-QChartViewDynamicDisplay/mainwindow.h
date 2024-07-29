#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QValueAxis>
#include <QLineSeries>
#include <QPointF>
#include <Qtimer>
#include <QDebug>

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
    QChart *chart_1;  // 图
    QValueAxis *axis_x;  // x轴
    QValueAxis *axis_y;  // y轴
    QLineSeries *line;  // 存储值
    QTimer *timer;  // timer

    void chart_init();  // chart初始化
    void time_init();  // time初始化

private slots:
    void do_mouseMoveEvent(QPoint point);  // 移动鼠标事件，显示chart上的位置坐标

    void doTimeOut();  // signal:timeoout() 对应的槽函数
    void on_pushButton_clicked(bool checked);
};
#endif // MAINWINDOW_H
