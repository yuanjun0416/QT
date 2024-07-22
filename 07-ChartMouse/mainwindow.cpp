#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart_init();

    connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(do_mouseMoveEvent(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart_init(){

    // 设置标题
    chart_1 = new QChart();
    chart_1->setTitle("y与x关系");
    ui->graphicsView->setChart(chart_1);

    // 设置x轴
    QValueAxis *axis_x = new QValueAxis();
    axis_x->setTitleText("x");
    axis_x->setRange(0, 100);
    chart_1->addAxis(axis_x, Qt::AlignBottom);
    // 设置y轴
    QValueAxis *axis_y = new QValueAxis();
    axis_y->setTitleText("y");
    axis_y->setRange(-1.5, 1.5);
    chart_1->addAxis(axis_y, Qt::AlignLeft);

    // add data line1
    QLineSeries *line1 = new QLineSeries();
    line1->setName("y=sin(0.1x)");
    chart_1->addSeries(line1);
    qreal y1;
    for(qint32 i = 0; i < 100; i++){
        y1 = qSin(0.1*i);
        line1->append(i, y1);
    }
    // 打印line1中的每一个坐标
    for (const QPointF &point : line1->points()) {
        qDebug() << "Point is" << point.x() << point.y();
    }
    // 将line1与X轴和Y轴关联
    line1->attachAxis(axis_x);
    line1->attachAxis(axis_y);

    // add data line2
    QLineSeries *line2 = new QLineSeries();
    line2->setName("y=cos(0.1x)");
    chart_1->addSeries(line2);
    qreal y2;
    for(qint32 i = 0; i < 100; i++){
        y2 = qCos(0.1*i);
        line2->append(i, y2);
    }
    // 打印line2中的每一个坐标
    for (const QPointF &point : line1->points()) {
        qDebug() << "Point is" << point.x() << point.y();
    }
    // 将line2与X轴和Y轴关联
    line2->attachAxis(axis_x);
    line2->attachAxis(axis_y);
}

void MainWindow::do_mouseMoveEvent(QPoint point){
    QPointF pt = chart_1->mapToValue(point);
    QString str = QString::asprintf("x=%.1f, y=%.2f", pt.x(), pt.y());
    ui->label->setText(str);
}
