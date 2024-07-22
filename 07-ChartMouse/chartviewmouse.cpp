#include "chartviewmouse.h"

ChartViewMouse::ChartViewMouse(QWidget *parent)
    : QChartView{parent}
{}

void ChartViewMouse::mouseMoveEvent(QMouseEvent *event){
    QChartView::mouseMoveEvent(event);
    QPoint point = event->pos();
    emit mouseMovePoint(point);
}
