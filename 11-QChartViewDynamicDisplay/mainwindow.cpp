#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    chart_init();
    time_init();
    connect(timer, SIGNAL(timeout()), this, SLOT(doTimeOut()));

    connect(ui->graphicsView, SIGNAL(mouseMovePoint(QPoint)), this, SLOT(do_mouseMoveEvent(QPoint)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::chart_init(){

    // 设置标题
    chart_1 = new QChart();
    chart_1->setTitle("随机动态演示");
    ui->graphicsView->setChart(chart_1);

    // 设置x轴
    axis_x = new QValueAxis();
    axis_x->setTitleText("时间/100ms");
    axis_x->setRange(0, 100);
    chart_1->addAxis(axis_x, Qt::AlignBottom);
    // 设置y轴
    axis_y = new QValueAxis();
    axis_y->setTitleText("y");
    axis_y->setRange(-1, 11);
    chart_1->addAxis(axis_y, Qt::AlignLeft);

    // add data line1
    line = new QLineSeries();
    line->setName("y=rand() % 10");
    chart_1->addSeries(line);

    // 将line1与X轴和Y轴关联
    line->attachAxis(axis_x);
    line->attachAxis(axis_y);

}

void MainWindow::do_mouseMoveEvent(QPoint point){
    QPointF pt = chart_1->mapToValue(point);
    QString str = QString::asprintf("x=%.1f, y=%.2f", pt.x(), pt.y());
    ui->label->setText(str);
}

void MainWindow::time_init(){
    timer = new QTimer;
    timer->setInterval(100);  // 100ms发送一次timeout()信号
}

void MainWindow::doTimeOut(){
    static int count = 0;
    if(count > 100){  // 只显示100个点
        line->remove(0);  // 删除索引为0处的点
        axis_x->setRange(count-100, count);  // x range设置为动态的
    }
    line->append(QPointF(count, rand() % 10));  // 将新的值添加到line中
    qDebug() << count;
    count++;
}

void MainWindow::on_pushButton_clicked(bool checked)
{
    if(checked){
        ui->pushButton->setText("暂停");
        timer->start();
    }else{
        ui->pushButton->setText("刷新");
        timer->stop();
    }
}

