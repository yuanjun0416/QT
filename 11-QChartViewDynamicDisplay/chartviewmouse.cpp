#include "chartviewmouse.h"

ChartViewMouse::ChartViewMouse(QWidget *parent)
    : QChartView{parent}
{}


// 鼠标移动事件
void ChartViewMouse::mouseMoveEvent(QMouseEvent *event){
    QPoint point = event->pos();
    emit mouseMovePoint(point);
    QChartView::mouseMoveEvent(event);
}

// 鼠标按下事件
void ChartViewMouse::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){  // 判断按下的是不是左键
        this->setDragMode(QGraphicsView::RubberBandDrag);  // 设置成框选模式
        begin_point = event->pos();  // 获取起点位置
    }
    QChartView::mousePressEvent(event);
}

// 鼠标释放事件
void ChartViewMouse::mouseReleaseEvent(QMouseEvent* event){
    if(event->button() == Qt::LeftButton){  // 判断按下的是不是左键
        end_point = event->pos();  // 获取终点位置
        if(end_point.x() > begin_point.x()){
            QRectF rectf;
            rectf.setTopLeft(begin_point);
            rectf.setBottomRight(end_point);
            this->chart()->zoomIn(rectf);
        }
        else{
            this->chart()->zoomReset();
        }
    }
    QChartView::mouseReleaseEvent(event);
}
