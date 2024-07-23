#ifndef CHARTVIEWMOUSE_H
#define CHARTVIEWMOUSE_H

#include <QWidget>
#include <QChartView>

class ChartViewMouse : public QChartView
{
    Q_OBJECT
public:
    explicit ChartViewMouse(QWidget *parent = nullptr);

signals:
    void mouseMovePoint(QPoint point);  // 用来给mainWindow发送信号

protected:
    void mouseMoveEvent(QMouseEvent *event);  // 鼠标移动事件
    void mousePressEvent(QMouseEvent* event); // 鼠标点击事件
    void mouseReleaseEvent(QMouseEvent* event); // 鼠标释放事件

private:
    QPoint begin_point;  // 框选起点, 长方形左上角
    QPoint end_point;  // 框选终点, 长方形右下角
};

#endif // CHARTVIEWMOUSE_H
