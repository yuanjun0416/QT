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
};

#endif // CHARTVIEWMOUSE_H
